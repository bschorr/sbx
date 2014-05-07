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

####In ofApp.h (or testApp.h):
Declare an sbx::custom object:

```
sbx::custom myVector
```

####In ofApp.cpp (or testApp.cpp):
In setup, you configure your SBX:

```
myVector.setName("myVector");myVector.setType("vec3");myVector.loadType("vec3.json");config.addSubscribe(myVector);config.addPublish(myVector)```
To set values, up to 3 levels deep in the JSON:
```
myVector.setValue (“x”, 42);```
if you have a more complex JSON, such as in the _sbx_OF_colorParticle_ examples, you can set values by including the 2 levels in your function:```myVector.setValue("color", "r", 236);```
Or you can set the value for all attributes of the SBX by receiving incoming values from Spacebrew, using the onMessage function:

```
void ofApp::onMessage( Spacebrew::Message & m ){    myVector.setValue(m);}
```

To send values, use the send function of your spacebrew instance:

```
sb.send(myVector);
```To use the values of the received SBX in your ofApp, use the methods to extract the values, specifying which kinf of variable you want it casted in:
```
int foo = myVector.getInt (“x”);float foo = myVector.getFloat (“x”);bool foo = myVector.getBool (“x”);string foo = myVector.getString (“x”);``` 
###Dependencies
[ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew)

[ofxLibWebSockets](https://github.com/labatrockwell/ofxLibwebsockets)
