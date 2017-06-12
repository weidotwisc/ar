cmake -E make_directory build && cd build && cmake .. && make
mkdir -p $AR_HOME/lua/ar
cp $AR_HOME/lua/init.lua $AR_HOME/lua/ar
cp $AR_HOME/lua/build/liblar.so $AR_HOME/lua/ar
