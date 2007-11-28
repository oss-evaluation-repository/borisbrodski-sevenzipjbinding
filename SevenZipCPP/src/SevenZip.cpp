#include "StdAfx.h"

#include <windows.h>

#include "SevenZipJBinding.h"

#include "Java/net_sf_sevenzip_SevenZip.h"

// Load 7-Zip DLL.
// Return: NULL - ok, else error message
static char * load7ZipLibrary(CreateObjectFunc * createObjectFunc)
{
	HINSTANCE lib = LoadLibraryA(DLLFILENAME);

	if (NULL == lib)
		return "Error loading 7-Zip library: " DLLFILENAME;

	*createObjectFunc = (CreateObjectFunc)GetProcAddress(lib,
			"CreateObject");

	if (NULL == *createObjectFunc)
		return "Not a 7-Zip Library. Missing 'CreateObject' export name";
	
	return NULL;
}

/*
 * Class:     net_sf_sevenzip_SevenZip
 * Method:    openArchive
 * Signature: (Ljava/lang/String;)Lnet/sf/sevenzip/SevenZip;
 */
JNIEXPORT jobject JNICALL Java_net_sf_sevenzip_SevenZip_openArchive
  (JNIEnv * env, jclass thisclzz, jstring name) {
    
	printf("Java_net_sf_sevenzip_SevenZip_openArchive()\n");
	fflush(stdout);

	const char *mfile = env->GetStringUTFChars(
	                name, NULL);

	printf("Filename: '%s'\n", mfile);
	fflush(stdout);
	
	env->ReleaseStringUTFChars(name, mfile);
	
//	jb=(*env)->NewByteArray(env, finfo.st_size);
//	    (*env)->SetByteArrayRegion(env, jb, 0, 
//		finfo.st_size, (jbyte *)m);
	
	return NULL;
}

CreateObjectFunc createObjectFunc;

/*
 * Class:     net_sf_sevenzip_SevenZip
 * Method:    initSevenZipLibrary
 * Signature: ()V
 */
JNIEXPORT jstring JNICALL Java_net_sf_sevenzip_SevenZip_initSevenZipLibrary
  (JNIEnv * env, jclass clazz)
{
	char * msg = load7ZipLibrary(&createObjectFunc);

	if (msg)
		return env->NewStringUTF(msg);
	return NULL; 
}
