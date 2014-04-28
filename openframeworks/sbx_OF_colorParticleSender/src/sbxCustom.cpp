//
//  customType.cpp
//  example_custom_object
//
//  Created by Bernardo Santos Schorr on 4/15/14.
//
//

#include "sbxCustom.h"

namespace sbx {
    
    CUSTOM_TYPE::CUSTOM_TYPE (string _name, string _type, string _val) {
        
        name = _name;
        type = _type;
        _default = value = _val;
        
    }
    
    void CUSTOM_TYPE::loadType( string path ) {
        string loadModel = ofBufferFromFile(path);
        Json::Reader reader;
        reader.parse(loadModel, typeModel);
    }
    
    void CUSTOM_TYPE::setName(string _name) {
        name = _name;
    }
    
    void CUSTOM_TYPE::setType( string _type ) {
        type = _type;
    }
    
    void CUSTOM_TYPE::setValue( Spacebrew::Message & m ) {
        if ( m.type == type ){
            Json::Value v;
            Json::Reader reader;
            reader.parse(m.value, v);
            value = v.toStyledString();
        } else {
            "Type \"" + m.type + "\"" + " is not compatible!";
        }
    }
    
    bool CUSTOM_TYPE::getBool( string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(varName)) {
            return v[varName].asBool();
        } else {
            cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    bool CUSTOM_TYPE::getBool( string topVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(varName)) {
                return v[topVar][varName].asBool();
            } else {
                cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    bool CUSTOM_TYPE::getBool( string topVar, string interVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(interVar)) {
                if (v[topVar][interVar].isMember(varName)) {
                    return v[topVar][interVar][varName].asBool();
                } else {
                    cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + interVar + " in this custom type!" << endl;
                }
            } else {
                cout << "Unable to retrieve value! Variable \"" + interVar + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
        
    }
    
    int CUSTOM_TYPE::getInt( string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(varName)) {
            return v[varName].asInt();
        } else {
            cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    int CUSTOM_TYPE::getInt( string topVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(varName)) {
                return v[topVar][varName].asInt();
            } else {
                cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    int CUSTOM_TYPE::getInt( string topVar, string interVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(interVar)) {
                if (v[topVar][interVar].isMember(varName)) {
                    return v[topVar][interVar][varName].asInt();
                } else {
                    cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + interVar + " in this custom type!" << endl;
                }
            } else {
                cout << "Unable to retrieve value! Variable \"" + interVar + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
        
    }
    
    float CUSTOM_TYPE::getFloat( string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(varName)) {
            return v[varName].asFloat();
        } else {
            cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    float CUSTOM_TYPE::getFloat( string topVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(varName)) {
                return v[topVar][varName].asFloat();
            } else {
                cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    float CUSTOM_TYPE::getFloat( string topVar, string interVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(interVar)) {
                if (v[topVar][interVar].isMember(varName)) {
                    return v[topVar][interVar][varName].asFloat();
                } else {
                    cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + interVar + " in this custom type!" << endl;
                }
            } else {
                cout << "Unable to retrieve value! Variable \"" + interVar + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
        
    }
    
    string CUSTOM_TYPE::getString( string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(varName)) {
            return v[varName].asString();
        } else {
            cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    string CUSTOM_TYPE::getString( string topVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(varName)) {
                return v[topVar][varName].asString();
            } else {
                cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
    }
    
    string CUSTOM_TYPE::getString( string topVar, string interVar, string varName ) {
        Json::Value  v;
        Json::Reader reader;
        reader.parse(value, v);
        
        if (v.isMember(topVar)) {
            if (v[topVar].isMember(interVar)) {
                if (v[topVar][interVar].isMember(varName)) {
                    return v[topVar][interVar][varName].asString();
                } else {
                    cout << "Unable to retrieve value! Variable \"" + varName + "\"" + " is not a member of " + interVar + " in this custom type!" << endl;
                }
            } else {
                cout << "Unable to retrieve value! Variable \"" + interVar + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
            }
        } else {
            cout << "Unable to retrieve value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
        }
        
    }
    
}