SBX
===

_Disclaimer: **SBX** currently has methods only for the [openFrameworks Spacebrew Library](https://github.com/Spacebrew/ofxSpacebrew). Methods for the Processing and Javascript libraries to come soon._

**SBX** stands for ***[spacebrew](http://docs.spacebrew.cc/) datatype extension***. It provides an easy interface to send and receive custom datatypes among spacebrew instances.

**SBX** is based in a local json file containing the elements that will be part of your custom datatype. It's particularly useful when sending data that is wrapped in one object but contains multiple attributes, such as position or color.

For example, if I want to send a position in 3D space, I would write a vec3.json file that looks like this:

```
{
"x": 0;
"y": 0;
"z": 0;
}
```
If maybe I want to send a color, with an alpha value included, I would write a color.json file that looks like this:

```
{
"r": 0;
"g": 0;
"b": 0;
"a": 0;
}
```

Search the folders README.md files to see the methods and download examples for SBX usage in each different Spacebrew implementation.