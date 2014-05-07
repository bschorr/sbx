SBX: OpenFrameworks
===================

SBX provides easy methods to deal with Spacebrew  Custom Data Types. Please visit the main [README](https://github.com/bschorr/sbx) for more info on Custom Data Types and SBX.

###How to use
Include the SBX source files in your openFrameworks project. Put the JSON file for your SBX in your data folder.

In this explanation we'll consider a 3D position data type, loading from a vec3.json file that has these contents, the same as in the included example _sbx_OF_simple_:

```
{
"x": 0,
"y": 0,
"z": 0
}
```

#####In ofApp.h (or testApp.h)
Declare an sbx::custom object:

```
sbx::custom myVector
```

#####In ofApp.cpp (or testApp.cpp)
In setup, you configure your SBX:

```
myVector.setName("myVector");



myVector.setValue (“x”, 42);



```
void ofApp::onMessage( Spacebrew::Message & m ){
```

To send values, use the send function of your spacebrew instance:

```
sb.send(myVector);
```

int foo = myVector.getInt (“x”);
###Dependencies
[ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew)

[ofxLibWebSockets](https://github.com/labatrockwell/ofxLibwebsockets)