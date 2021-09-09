echo Running
mkdir build
cd build
cmake ..
make -j
echo "\n ---------- TESTS --------- \n"
ctest
# ./test/test_name.cpp
cd ..
rm -r -f build