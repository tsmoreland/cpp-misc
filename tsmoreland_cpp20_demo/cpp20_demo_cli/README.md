# project changes

* change language version to c++latest for all targets
* change output path to ```$(SolutionDir)bin\$(Configuration)\$(Platform)```
* modify c++ \ general enabling:
   * Scan sources for module dependencies
   * Translate includes to imports
* enable experimental module support

## Build/linking work

* add project reference to static/dynamic libs
* static seems to work without too much effort, presently the module is self contains so that may be why (need to try again with impl moved to cpp file)
* dynamic didn't work initially, reqeuired updates to consumer project file to add additional module dependency - need to include full path to the mdoule filename + .ifc extension
  i.e.; ```multilib.ixx.ifc```