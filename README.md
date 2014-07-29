BingTranslator
==============

Bing Translator in c++ using JNI

Microsoft's Bing Translator is an API which can do a variety of functions:  <br>

1. Translate text between 2 langauges.<br>
2. Detect the native language of given text.
3. Generating and playing a WAV of given text spoken in a chosen dialect  <br>


Since the Google Translate API is no more free, it makes sense in using the
Bing Translate API.

The Bing Tranlate API is free for only 2,000,000 Characters/month.
For further charges, refer 
https://datamarket.azure.com/dataset/1899a118-d202-492c-aa16-ba21c33c06cb

Since the API is by Microsoft, it is bound to be written in C#.
There is also a PHP and Java version of the API.

However, I wanted to use the translator in C/C++ in my Linux system as a part of 
my Speech to Speech Translation project.<br>
I was able to use the Bing translator using JNI in my C++ code and calling 
the functions of the Java API.<br>
In my code, I have only covered the function to Translate text between 2 langauges.

##--------------------------------------------------##
Requirements for using the code.
--------------------------------

1. Java 1.5 or greater
2. A Windows Azure Marketplace Client ID and Client Secret

Follow first 2 steps of http://msdn.microsoft.com/en-us/library/hh454950.aspx

Store the Client ID and Client Secret.

##-----------------------------------------------------##

Source Code:
----------------------------
<b>BingTranslator.h </b><br>
<b>BingTranslator.cc </b> --> contains all the necessary C++ functions. <br>
<b>example.cc </b> --> Shows a demo example. <br>
folder <b>com</b> and <b>jason</b> --> The Java source code for Bing API <br>
<b>TranslateExample.class</b> and <b>TranslateExample.java</b> --> Java functions used by my C++ code <br>

I have included the JAVA APIs in my file. You can download them
separately from
https://code.google.com/p/microsoft-translator-java-api/downloads/list

##----------------------------------------------------##

Before using the code-> <br>
-------------------------------------

<b> Export the Java JVM libraries </b> <br>

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/jvm/default-java/jre/lib/amd64/:/usr/lib/jvm/default-java/jre/lib/amd64/server/;
<br>
Generally, this is the common path where the JRE libraries will be stored if you have multiple JRE versions.
In case they are stored at a different location, do the appropriate changes. <br>
In general cases, it will be stored in /usr/lib/jvm/java-version/.... <br>
e.g. /usr/lib/jvm/java-1.7.0-openjdk-amd64/... <br>
<br>
If the above path in not present in your directory, you may need to install Java-open JDK using the following command:<br>
sudo apt-get install openjdk-7-jdk


You can add this line to the end of the ~/.bashrc file as well. <br>

<b>Add the client ID and the client secret in the demoExample.cc file </b> <br>

Compiling the file
------------------

g++ -g demoExample.cc BingTranslator.cc -I /usr/lib/jvm/default-java/include/ -I /usr/lib/jvm/default-java/include/linux/ -L /usr/lib/jvm/default-java/jre/lib/amd64/ -L /usr/lib/jvm/default-java/jre/lib/amd64/server/ -ljvm -o demoExample

In place of example.cc, you can have your own C++ files. <br>
Include the file "BingTranslator.h" in your source code and follow the syntax used in demoExample.cc.

Run the file
-----------------
./demoExample


##------------------------------------------------------##







