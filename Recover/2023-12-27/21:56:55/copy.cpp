#include "../include/copy.h"
#include "../include/huffman.h"
#include <fcntl.h>

std::string rltv(std::string abs,std::string base) {
    int base_len = base.size();
    std::string tmp;
    for( int i = base.size() ; i < abs.size() ; i++ ) {
        tmp += abs[i];
    }

    return tmp;
}

bool copyMetadata_exclu_slink(const char* sourcePath, const char* destinationPath,int sym) {
    struct stat sourceInfo;
    if (stat(sourcePath, &sourceInfo) != 0) {
        perror("stat");
        return false;
    }

    // 获取源文件的权限和时间戳
    mode_t permissions = sourceInfo.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);

    // 创建目标文件，保留源文件的权限
    // if(S_ISFIFO(sourceInfo.st_mode)) {
    //     if (mkfifo(destinationPath, permissions) == 0) {
    //         std::cout << "FIFO created successfully." << std::endl;
    //     } 
    //     else {
    //         perror("mkfifo");
    //         std::cerr << "Error creating FIFO: " << strerror(errno) << std::endl;
    //         return 1;
    //     }
    // }
    int destinationFd = open(destinationPath, O_WRONLY | O_CREAT | O_TRUNC, permissions);
    if (destinationFd == -1) {
        perror("open");
        return false;
    }
    // 关闭目标文件
    close(destinationFd);

    //判断复制的类型
    if(sym == SYM_ZIP) {
        //复制并压缩文件至指定位置
        zipToCode( sourcePath, destinationPath);
    }
    else if(sym == SYM_REC) {
        //解压文件至指定位置
        recoverFromCode(sourcePath,destinationPath);
    }

   


    // 设置目标文件的权限
    if (chmod(destinationPath, permissions) != 0) {
        perror("chmod");
        return false;
    }

    // 设置目标文件的时间戳
    struct utimbuf times;
    times.actime = sourceInfo.st_atime;
    times.modtime = sourceInfo.st_mtime;
    if (utime(destinationPath, &times) != 0) {
        perror("utime");
        return false;
    }

    // 获取源文件的属主和属组
    uid_t owner = sourceInfo.st_uid;
    gid_t group = sourceInfo.st_gid;

    // 设置目标文件的属主和属组
    if (chown(destinationPath, owner, group) != 0) {
        perror("chown");
        return false;
    }

    return true;
}

bool copyMetadata_slink(const char* sourcePath, const char* destinationPath) {
    // 读取符号链接的目标路径
    char targetPath[1024];
    ssize_t len = readlink(sourcePath, targetPath, sizeof(targetPath) - 1);
    // std::cout<< "##" << targetPath << std::endl;
    if (len == -1) {
        perror("readlink");
        return false;
    }
    targetPath[len] = '\0';

    // 获取目标文件的元数据
    struct stat sourceInfo;
    if (stat(sourcePath, &sourceInfo) != 0) {
        perror("stat");
        return false;
    }

    // 创建符号链接
    if (symlink(targetPath, destinationPath) != 0) {
        perror("symlink");
        return false;
    }

    // 设置符号链接的权限
    if (chmod(destinationPath, sourceInfo.st_mode) != 0) {
        perror("chmod");
        return false;
    }

    // 设置符号链接的时间戳
                                        // struct utimbuf times;
                                        // times.actime = sourceInfo.st_atime;
                                        // times.modtime = sourceInfo.st_mtime;

                                        // std::cout<<times.actime<<std::endl;
                                        // std::cout<<times.modtime<<std::endl;
                                        // if (utime(destinationPath, &times) != 0) {
                                        //         perror("utime");
                                        //         return false;
                                        //     }
    struct timeval times[2];
    times[0].tv_sec = sourceInfo.st_atime;
    times[0].tv_usec = 0;
    times[1].tv_sec = sourceInfo.st_mtime;
    times[1].tv_usec = 0;

    //TODO : 修改软链接的访问时间，使其与源文件一致

    // std::cout<<"destinationPath:"<<destinationPath<<std::endl;

    if(utimes(destinationPath,times) != 0){
        perror("utimes");
        return 1;
    }

    

    // 设置符号链接的属主和属组
    if (chown(destinationPath, sourceInfo.st_uid, sourceInfo.st_gid) != 0) {
        perror("chown");
        return false;
    }

    return true;
}

void copy_directory(const fs::path& source, const fs::path& destination, int sym) {
    try {
        //获取时间
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

        // 将时间点转换为时间结构
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // 使用 localtime 函数将时间结构转换为本地时间
        std::tm* localTime = std::localtime(&currentTime);

        // 使用 strftime 函数将本地时间格式化为字符串
        char timeStr[1024]; // 适当大小的字符数组来容纳格式化后的时间字符串
        std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d/%H:%M:%S", localTime);

        // 创建目标目录（唯一性：目录+创建时间）
        std::string ps(timeStr);
        std::string tmp;
        tmp += destination.string()+"/"+ps;
        std::filesystem::path destination = tmp;
        fs::create_directories(destination);

        // 遍历源目录
        for (const auto& entry : fs::recursive_directory_iterator(source)) {
            fs::path relative_path = fs::relative(entry.path(), source);

            // std::cout<<"destination before:"<<destination<<std::endl;

            fs::path dest_path = destination / relative_path;

            // std::cout<<"destination after:"<<destination<<std::endl;

            // 如果是目录，创建目录
            if (fs::is_directory(entry.status())) {
                fs::create_directories(dest_path);
            }
            // 如果是文件，复制文件
            else {
                int fd = 0;
                
                //如果是普通文件
                // if (fs::is_regular_file(entry.status())) {
                //     fs::copy_file(entry.path(), dest_path, fs::copy_options::overwrite_existing);
                //     std::cout<<entry.path()<<" has been copied "<<std::endl;
                // }
                std::string fp = entry.path();
                const char* filePath = fp.c_str();
                struct stat stat_buf;
                int ret = lstat(filePath, &stat_buf);

                if(S_ISLNK(stat_buf.st_mode )){
                    // std::cout<<entry.path()<<"is symlink"<<std::endl;

                    std::string rltv_path = rltv(entry.path(),source);
                    relative_path = rltv_path;

                    // std::cout<<"detination_path:"<<destination<<std::endl;

                    std::string tmp = destination ;
                    tmp += relative_path;

                    // std::cout<<"detination_path:"<<destination<<std::endl;

                    dest_path = tmp;
                    
                    // std::cout<<"entry_path:"<<entry.path()<<std::endl;
                    // std::cout<<"source_path:"<<source<<std::endl;
                    // std::cout<<"rltv_path:"<<rltv_path<<std::endl;
                    // std::cout<<"symlink_dest_path:"<<dest_path<<std::endl;
                    // std::cout<<"detination_path:"<<destination<<std::endl;
                    // std::cout<<"relative_path:"<<relative_path<<std::endl;

                    if(copyMetadata_slink(entry.path().c_str(), dest_path.c_str()) == true){
                        std::cout<<entry.path()<<" has been copied to"<< dest_path.c_str() <<std::endl;
                    }
                    else{
                        // std::cout<<"&&"<<destination<<std::endl;
                        // std::cout<<"%%"<<dest_path.c_str()<<std::endl;
                        std::cout<<entry.path()<<" copy failed "<<std::endl;
                    }
                    continue;
                }
                else{
                    // std::cout<<entry.path()<<"is not symlink"<<std::endl;
                    copyMetadata_exclu_slink(entry.path().c_str(), dest_path.c_str(),sym);
                    std::cout<<entry.path()<<" has been copied to"<<dest_path.c_str()<<std::endl;
                }            
            }
        }

        std::cout << "Backup completed." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}