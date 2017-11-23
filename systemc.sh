export SYSTEMC_HOME=/usr/local/systemc2.3
g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o sc sc_main.cpp -lsystemc -lm -std=c++11
./sc
