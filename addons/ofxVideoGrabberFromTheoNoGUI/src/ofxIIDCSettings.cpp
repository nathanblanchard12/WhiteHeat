#include "ofxIIDCSettings.h"
#include "ofxVideoGrabberSDK.h"


inline void spaceReplace(std::string & myStr)
{
        /* replace all spaces in the name to satisfy XML*/
        size_t found;
        found=myStr.find_first_of(" ");
        while (found!=string::npos)
        {
            //myStr.erase(found,1);
            myStr[found]='_';

            found=myStr.find_first_of(" ",found+1);
        }
}

ofxIIDCSettings::ofxIIDCSettings()
{

}

ofxIIDCSettings::~ofxIIDCSettings()
{

}



//void ofxIIDCSettings::setupGUI()
//{
//    videoGrabber->getAllFeatureValues();
//
//		//panel->setup("ofxIIDCSettings", 0, 0, 480, ofGetHeight());
//		//panel.loadFont("myFont.ttf", 10);
//    panel->addPanel("Camera Settings", 2, false);
//	panel->setWhichPanel("Camera Settings");
//    panel->setWhichColumn(0);
//
//    /* set the gui callback */
//    callback.SetCallback( this, &ofxIIDCSettings::parameterCallback);
//
//	int tmp_index = -1;
//	int tmp_featureID = -1;
//	bool whitebalance = false;
//	int featureID = -1;
//
//    /* setup feature gui sliders */
//    for (int i=0; i < videoGrabber->availableFeatureAmount; ++i)
//    {
//        if(videoGrabber->featureVals[i].isPresent) {
//            featureID = videoGrabber->featureVals[i].feature;
//
//            if( featureID == FEATURE_WHITE_BALANCE) {
//                tmp_index = i;
//                tmp_featureID = featureID;
//                whitebalance = true;
//            }
//            else if(featureID == FEATURE_TRIGGER) {
//                //not using any features above this
//                break;
//            }
//            else {
//                string name = videoGrabber->featureVals[i].name;
//                string xmlName = name;
//                transform(xmlName.begin(), xmlName.end(), xmlName.begin(), ::toupper);
//
//                float minVal = videoGrabber->featureVals[i].minVal;
//                float maxVal = videoGrabber->featureVals[i].maxVal;
//                float currVal = videoGrabber->featureVals[i].currVal;
//                panel->addButtonSlider(name,xmlName, currVal, minVal, maxVal, true,&callback,featureID);
//            }
//        }
//    }
//
//    /* setup white balance 2d slider */
//    if(whitebalance)
//    {
//        string name = videoGrabber->featureVals[tmp_index].name;
//        string xmlName = name;
//        transform(xmlName.begin(), xmlName.end(), xmlName.begin(), ::toupper);
//        spaceReplace(xmlName);
//
//
//        float minVal = videoGrabber->featureVals[tmp_index].minVal;
//        float maxVal = videoGrabber->featureVals[tmp_index].maxVal;
//        float currVal = videoGrabber->featureVals[tmp_index].currVal;
//        float currVal2 = videoGrabber->featureVals[tmp_index].currVal2;
//        panel->addSlider2D(name,xmlName, currVal, currVal2, minVal, maxVal, minVal, maxVal, false, &callback,tmp_featureID);
//
//    }
//
//    panel->setWhichColumn(1);
//
//    /* setup features modes */
//    for (int i=0; i < videoGrabber->availableFeatureAmount; ++i)
//    {
//        if(videoGrabber->featureVals[i].isPresent) {
//            featureID = videoGrabber->featureVals[i].feature;
//
//            if (featureID == FEATURE_TRIGGER)
//            {
//                //not using any features above this
//                break;
//            }
//            if( featureID != FEATURE_WHITE_BALANCE)
//            {
//                string name = videoGrabber->featureVals[i].name + " mode";
//                string xmlName = name;
//
//                transform(xmlName.begin(), xmlName.end(), xmlName.begin(), ::toupper);
//                spaceReplace(xmlName);
//
//                int defaultval = FEATURE_MODE_MANUAL;
//
////                if(videoGrabber->featureVals[i].hasAutoModeActive) {
////                    defaultval = FEATURE_MODE_AUTO;
////					videoGrabber->setFeatureMode(FEATURE_MODE_AUTO, featureID );
////                } else {
//					videoGrabber->setFeatureMode(FEATURE_MODE_MANUAL, featureID );
////				}
//                vector <string> modelist;
//                modelist.push_back("MANUAL");
//
//
//                if(videoGrabber->featureVals[i].hasAutoMode)
//                {
//                    modelist.push_back("AUTO");
//                    if(videoGrabber->featureVals[i].hasOnePush )
//                    {
//                        modelist.push_back("ONE PUSH AUTO");
//                    }
//                }
//
//                panel->addTextDropDown(name,xmlName, defaultval, modelist,&callback,featureID);
//            }
//        }
//    }
//
//    /* setup whitebalance modes */
//    if(whitebalance)
//    {
//                featureID = FEATURE_WHITE_BALANCE;
//                string name = videoGrabber->featureVals[tmp_index].name + " mode";
//                string xmlName = name;
//                transform(xmlName.begin(), xmlName.end(), xmlName.begin(), ::toupper);
//                spaceReplace(xmlName);
//
//                int defaultval = FEATURE_MODE_MANUAL;
////                if(videoGrabber->featureVals[tmp_index].hasAutoModeActive) {
////                    defaultval = FEATURE_MODE_AUTO;
////					videoGrabber->setFeatureMode(FEATURE_MODE_AUTO, featureID );
////                } else {
//					videoGrabber->setFeatureMode(FEATURE_MODE_MANUAL, featureID );
////				}
//                vector <string> modelist;
//                modelist.push_back("MANUAL");
//
//                if(videoGrabber->featureVals[tmp_index].hasAutoMode)
//                {
//                    modelist.push_back("AUTO");
//                    if(videoGrabber->featureVals[tmp_index].hasOnePush )
//                    {
//                        modelist.push_back("ONE PUSH AUTO");
//                    }
//                }
//
//                panel->addTextDropDown(name,xmlName, defaultval, modelist,&callback,tmp_featureID);
//
//    }
//	
//	if(panel->currentXmlFile != ""){
//		panel->loadSettings(panel->currentXmlFile);
//	}
//    //Example of how to set up toggles
//    /*
//    string name = "myToggle";
//    string xmlName = "MY_TOGGLE";
//    bool currVal = false;
//    panel.addToggle(name,xmlName,currVal,&callback,666);
//
//    name = "myMultiToggle";
//    xmlName = "MY_MULTI_TOGGLE";
//    currVal = 2;
//    vector<string> boxnames;
//    boxnames.push_back("box1");
//    boxnames.push_back("box2");
//    boxnames.push_back("box3");
//    panel.addMultiToggle(name,xmlName,currVal,boxnames, &callback,667);
//    */
//}

//--------------------------------------------------------------------
void ofxIIDCSettings::draw()
{
		//panel.draw();
}

//--------------------------------------------------------------------
void ofxIIDCSettings::update()
{
		//panel.update();
}

//void ofxIIDCSettings::parameterCallback(float param1, float param2, int param_mode, int param_id)
//{
//
//    if(param_mode != NULL_MODE)
//    {
//        //cout << "set mode called: "  << param_mode << " param_id = " << param_id << endl;
//        videoGrabber->setFeatureMode(param_mode, param_id);
//    }
//    else {
//        if(param_id == FEATURE_WHITE_BALANCE) {
//            videoGrabber->setFeatureValue(param1, param2, param_id);
//        }
//        else {x
//            //cout << "set feature called: " << param1 << " " << param_id << endl;
//            videoGrabber->setFeatureValue(param1, param_id);
//        }
//    }
//
//}





