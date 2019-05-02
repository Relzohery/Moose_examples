## MOOSE installation:
1- **System requirement:**
*  C++11 compliant compiler (GCC 4.8.4, Clang 3.4.0 or greater.

2- **Required packages:**
 build-essential , gfortran , tcl ,  git , m4 , freeglut3 , doxygen \
  libblas-dev , liblapack-dev ,  libx11-dev ,  libnuma-dev , libcurl4-gnutls-dev , zlib1g-dev , libhwloc-dev.
 
3- **Download any of the following packaged based on your mint version:**
		[mint 19 ](moose-environment_ubuntu-18.04_20181203_x86_64.deb)
		[mint 18](moose-environment_ubuntu-16.04_20181203_x86_64.deb)
**4- To install the package :** ( this will take some time and most likely your computer will freeze)
    `sudo dpkg -i moose-environment_ubuntu-*.rpm`
  you will need to add this to your bashrc:
  ```bash
if [ -f /opt/moose/environments/moose_profile ]; then
    . /opt/moose/environments/moose_profile
fi
```
**Important**: close any opened terminals and re-open them

**5-Cloning MOOSE**
Go to where you want to install moose and do the following:
```bash
git clone https://github.com/idaholab/moose.git
cd moose
git checkout master
```
**5-Compile libMesh** ( this will take some time (30 -1 hr)
```bash
cd your path/moose
./scripts/update_and_rebuild_libmesh.sh
```
**6-Compile and Test MOOSE**
```bash
cd your path/moose/test
make -j 4
./run_tests -j 4
```
