1. 编译前需要将 CMakeLists.txt 中
   set_target_properties(bp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
   这一项里${CMAKE_CURRENT_SOURCE_DIR}改为工作目录，生成的目录树就是这个目录的。
2. 编译命令：
   mkdir build
   cd build
   cmake ..
   make
   cd 工作目录
   ./bp
3. 推送命令：
   git remote add origin git@github.com:The-Lyc/FileBackup.git

4. cryptopp库 下载及编译安装：
   git clone https://github.com/weidai11/cryptopp.git
   cd cryptopp
   make
   sudo make install
