
#include "BingTranslator.h"


JavaVM *Translator::jvm = NULL;
int Translator::count = 0;
using namespace std;

/*
This function is called by the translateData() function. 
This function translates the string *lang1* to the desired language.
Input parameters:
lang1 : string which needs to be translated.
cliendID : Microsoft Client ID.
clientSec : Microsoft Client Secret Key.
translateFrom : Language of the string *lang1* [REMEMBER: This has to be the codeword of the corresponding
language. For list of code-words, refer *list_of_languages.txt* file]
translateTo: Language in which the translation is to be done.

*/
string translateTextData(string lang1, string clientID, string clientSec, string translateFrom, string translateTo){

    jclass classID = NULL;  
    jmethodID methodID = NULL;
    jobject result = NULL;
    JNIEnv* env;

    //Attach thread
    (Translator::jvm)->AttachCurrentThread((void**)&env, NULL);

    //--- Set the parameters to be sent to the Java code--------//
    jstring jstr = env->NewStringUTF(lang1.c_str());
    jstring jclientID = env->NewStringUTF(clientID.c_str());
    jstring jclientSec = env->NewStringUTF(clientSec.c_str());
    jstring jtranslateFrom = env->NewStringUTF(translateFrom.c_str());
    jstring jtranslateTo = env->NewStringUTF(translateTo.c_str());

    //--------------------------------//

    
    //Get Class ID
    classID = env->FindClass("TranslateExample");

    //Get Method ID
    if (classID != NULL){
        methodID = env->GetStaticMethodID(classID,"translateTextData","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    }
    else{
        printf("\nUnable to find the requested class\n"); 
    }

    //Get the object ID of the class
    if (methodID != NULL){
        result = (jstring) env->CallStaticObjectMethod(classID, methodID, jstr,jclientID, jclientSec, jtranslateFrom, jtranslateTo);
    }
    else{
        printf("\nUnable to find the requested Method\n"); 
    }

    // Get a C-style string
    const char* str = env->GetStringUTFChars((jstring) result, NULL);

    // printf("%s\n", str);
    std::string lang2 = (std::string)str;

    // Clean up
    (env)->ReleaseStringUTFChars(jstr, str);

    (Translator::jvm)->DetachCurrentThread();
    return lang2;
}

/*
This function created the virtual machine.
*/
void create_vm() {
    JNIEnv *env;
    JavaVMInitArgs vm_args;
    JavaVMOption options;
    //Path where the Java class file is located
    std::string text = "-Djava.class.path=.";
    char* str = &text[0];
    options.optionString = str;  //Path to the java source code
    vm_args.version = JNI_VERSION_1_6; //JDK version. This indicates version 1.6
    vm_args.nOptions = 1;
    vm_args.options = &options;
    vm_args.ignoreUnrecognized = 0;
    
    int ret = JNI_CreateJavaVM(&Translator::jvm, (void**)&env, &vm_args);
    if(ret < 0)
        printf("\nUnable to Launch JVM\n");     
}

/*
This is the function which has to be called by the *main* routine to translate the text
from one language to other. 
This function makes sure that the VM is created just once.
*/

string Translator::translateData(string lang1, string clientID, string clientSec, string tranlateFrom, string translateTo){

    //Create VM just once
    if(Translator::count == 0){
       create_vm();
    }
    ++Translator::count;

    string lang2 = translateTextData(lang1,clientID,clientSec,tranlateFrom,translateTo);
    return lang2;
}
