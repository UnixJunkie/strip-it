# replace /home/berengfc by what you need
cmake \
    -DCMAKE_INSTALL_PREFIX:PATH=/home/berengfc/usr \
    -DOPENBABEL2_INCLUDE_DIRS=/home/berengfc/usr/include/openbabel-2.0 \
    -DOPENBABEL2_LIBRARIES=/home/berengfc/usr/lib/libopenbabel.so \
    ../
make -j4
make install
echo
echo "### PUT THIS SCRIPT INTO YOUR PATH ####"
echo "### AND NAME IT strip-it           ####"
echo "### AND MAKE IT EXECUTABLE         ####"
echo "# -------------------------------------"
cat <<EOF
#!/bin/bash

export LD_LIBRARY_PATH=~/usr/lib
~/usr/bin/strip-it "$@"
EOF
echo "# -------------------------------------"
