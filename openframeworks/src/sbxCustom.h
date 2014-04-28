//
//  customType.h
//  example_custom_object
//
//  Created by Bernardo Santos Schorr on 4/15/14.
//
//

#pragma once

//this is where we put in the name of our custom type and variables it will use. Remember to use the same name in testApp/ofApp!

#define CUSTOM_TYPE custom //change 'custom' to whatever name you like!

//ugly hack to stringify preprocessor constants
#define STR1(x) #x
#define STR2(x) STR1(x)
#define CUSTOM_TYPE_STR STR2(CUSTOM_TYPE)

#include "ofMain.h"
#include "ofxSpacebrew.h"

namespace sbx {
    
    class CUSTOM_TYPE : public Spacebrew::Message {
    public:
        
        //constructor
        CUSTOM_TYPE( string _name="", string _type=CUSTOM_TYPE_STR, string _val="");
        
        void loadType ( string path );
        void setName ( string _name );
        void setType ( string _type );
        
        //setting the values
        template <typename T>
        void setValue ( string varName, T incomingValue ) {
            Json::Value v;
            Json::Reader reader;
            reader.parse(value, v);
            
            if (typeModel.isMember(varName)) {
                v[varName] = incomingValue;
                value = v.toStyledString();
            } else {
                cout << "Unable to set value! Variable \"" + varName + "\"" + " is not a member of this custom type!" << endl;
            }
        }
        
        //setting the values, 2nd level
        template <typename T>
        void setValue ( string topVar, string varName, T incomingValue ) {
            Json::Value v;
            Json::Reader reader;
            reader.parse(value, v);
            
            if (typeModel.isMember(topVar)) {
                if (typeModel[topVar].isMember(varName)) {
                    v[topVar][varName] = incomingValue;
                    value = v.toStyledString();
                } else {
                    cout << "Unable to set value! Variable \"" + varName + "\"" + " is not a member of " + topVar + " in this custom type!" << endl;
                }
            } else {
                cout << "Unable to set value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
            }
        }
        
        //setting the values, 3rd level
        template <typename T>
        void setValue ( string topVar, string interVar, string varName, T incomingValue ) {
            Json::Value v;
            Json::Reader reader;
            reader.parse(value, v);
            
            if (typeModel.isMember(topVar)) {
                if (typeModel[topVar].isMember(interVar)) {
                    if (typeModel[topVar][interVar].isMember(varName)) {
                        v[topVar][interVar][varName] = incomingValue;
                        value = v.toStyledString();
                    } else {
                        cout << "Unable to set value! Variable \"" + varName + "\"" + " is not a member of " + interVar + " in this custom type!" << endl;
                    }
                } else {
                    cout << "Unable to set value! Variable \"" + interVar + "\"" + " is not a member of \"" + topVar + "\" in this custom type!" << endl;
                }
            } else {
                cout << "Unable to set value! Variable \"" + topVar + "\"" + " is not a member of this custom type!" << endl;
            }
        }
        
        //setting them from incoming message
        void setValue ( Spacebrew::Message & m );
    
        //getting values for sbx object
        bool getBool( string varName );
        int getInt( string varName );
        float getFloat( string varName );
        string getString( string varName );
        
        //getting values for sbx object in 2nd level deep
        bool getBool( string topVar, string varName );
        int getInt( string topVar, string varName );
        float getFloat( string topVar, string varName );
        string getString( string topVar, string varName );
        
        //getting values for sbx object in 3rd level deep
        bool getBool( string topVar, string interVar, string varName );
        int getInt( string topVar, string interVar, string varName );
        float getFloat( string topVar, string interVar, string varName );
        string getString( string topVar, string interVar, string varName );
        
        
    private:
        
        Json::Value typeModel;
        
    };

}