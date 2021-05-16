// *** I N C L U D E S ****************************************************************************
//
#ifdef USE_GSTREAMER

//	#define DEBUG_DROP_DOT
	#define DEBUG_DROP_DOT_READY
	#define DEBUG_DROP_DOT_PAUSED
	#define DEBUG_DROP_DOT_PLAYING

extern "C" {
	#include "Base.h"
	#include "UtilString.h"
	#include "CRC.h"
	#include "SystemThreads.h"
}

#include "SDLWrapper.h"

#include "UI_Color.h"
#include "UI_Font.h"
#include "UI_Pen.h"
#include "UI_Point.h"
#include "UI_Rect.h"
#include "UI_Surface.h"

#include "Monitor.h"

#include "GStream.h"

#ifndef UNDER_LIN
#pragma comment(lib, "gobject-2.0.lib")
#pragma comment(lib, "glib-2.0.lib")
#pragma comment(lib, "gdk_pixbuf-2.0.lib")
#pragma comment(lib, "gstbase-1.0.lib")
#pragma comment(lib, "gstreamer-1.0.lib")
#pragma comment(lib, "gstpbutils-1.0.lib")
#pragma comment(lib, "gstvideo-1.0.lib")
#pragma comment(lib, "gstaudio-1.0.lib")
#pragma comment(lib, "gstapp-1.0.lib")

#pragma comment(lib, "gstnet-1.0.lib")
#pragma comment(lib, "soup-2.4.lib")
#endif


// *** D E F I N E S ******************************************************************************
//
#define TAG_MODULE		"CGStream"

#define	TRACEGSTREAM		NOTRACE
#define TRACEGSTREAMSTATE	NOTRACE
#define TRACEGSTREAMSTATUS	NOTRACE


// *** S T A T I C S ******************************************************************************
//
CGStream*		CGStream::pAll = NULL;
BOOL			bv116orgreater = FALSE;

// *** P R O T O T Y P E S ************************************************************************
//
static unsigned long __stdcall	ManagerThread(void* vpStream);


// ************************************************************************************************
//
//	Function:	ClassInit
//
//	Usage:		Class Initializer
//
//	Params:		
//
//	Returns:	
//
//	Notes:
//
// ************************************************************************************************
//
BOOL CGStream::ClassInit(void)
{
    const gchar*    nano_str = NULL;
    guint           major = 0;
    guint           minor = 0;
    guint           micro = 0;
    guint           nano = 0;
//  DWORD           dwLen;
//  TCHAR           szPathW[MAX_PATH];
    int             argc = 0;
    
    /*
	// GSTREAMER_1_0_ROOT_X86_64=C:\gstreamer\1.0\x86_64\
	//
	dwLen = 0;
	dwLen = GetEnvironmentVariable(TEXT("GSTREAMER_1_0_ROOT_X86_64"), szPathW, MAX_PATH);
    if (dwLen)
    {
        StringWSwapChar(szPathW, PATH_SEP, '\\');
        StringWAppendSlash(szPathW);
        StringWCat(szPathW, TEXT("Bin"), MAX_PATH);
        if (SetDllDirectory(szPathW) == FALSE)
        {
            PostMsg(MSG_DEBUG, CStr, "Failed to add %w to DLL Search Path", szPathW);
        }
    }
    */
    
    //	gst_debug_set_default_threshold(GST_LEVEL_WARNING);
//	gst_debug_set_default_threshold(GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("GST_TRACER", GST_LEVEL_TRACE);
//	gst_debug_set_threshold_for_name("v4l2src", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("nvoverlaysink*", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("alsasrc*", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("alsasink*", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("appsink", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("v4l2src", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("v4l2src", GST_LEVEL_DEBUG);
//	gst_debug_set_threshold_for_name("v4l2src", GST_LEVEL_DEBUG);
//	gst_debug_add_log_function() 

	// Init gst and show Version
	//
	gst_init(&argc, NULL);
	gst_version(&major, &minor, &micro, &nano);
	if (nano == 1)
	    nano_str = "(CVS)";
	else if (nano == 2)
	    nano_str = "(Prerelease)";
	else    
	    nano_str = "";
	    
	PostMsg(MSG_INFO, CStr, "This program is linked against GStreamer %d.%d.%d %s", major, minor, micro, nano_str);
	
	if (minor > = 16)
	    bv116orgreater = TRUE;
	else
	    bv116orgreater = FALSE;
	
	return TRU;
}
// ClassInit()

