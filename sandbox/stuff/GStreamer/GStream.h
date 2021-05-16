#if !defined(_GSTREAM__INCLUDED)
#define _GSTREAM__INCLUDED

#ifdef USE_GSTREAMER

// *** I N C L U D E S ****************************************************************************
//
#include "glib.h"
#include "gst/gst.h"
#include "gst/gstbuffer.h"
#include "gst/gstbus.h"
#include "gst/pbutils/pbutils.h"
#include "gst/base/gstbasesink.h"
#include "gst/video/video-info.h"
#include "gst/video/video.h"
#include "gst/audio/audio-info.h"
#include "gst/audio/audio.h"
#include "gdk-pixbuf.h"
#include <gst/app/gstappsrc.h>
#include "gst/app/gstappsink.h"



// *** D E F I N E S ******************************************************************************
//
#define GSTREAM_SIGNATURE				0x23233232

// <ExportMask GSTRM.Flags>
//
#define GSTREAM_FLAG_VOID_PENDING		0x00000000
#define GSTREAM_FLAG_NULL				0x00000001
#define GSTREAM_FLAG_READY				0x00000002
#define GSTREAM_FLAG_PAUSED				0x00000003
#define GSTREAM_FLAG_PLAYING			0x00000004
#define GSTREAM_FLAG_STREAMING			0x00000008
#define GSTREAM_FLAG_STATE_MASK			0x0000000F
#define GSTREAM_FLAG_SIZE_KNOWN			0x00000010
#define GSTREAM_FLAG_POS_KNOWN			0x00000020
#define GSTREAM_FLAG_DUR_KNOWN			0x00000040
#define GSTREAM_FLAG_TEARDOWN			0x00000080
#define GSTREAM_FLAG_STOP_PENDING		0x00000100
#define GSTREAM_FLAG_END_PIPELINE		0x00000200
#define GSTREAM_FLAG_USER_MASK			0xFFFF0000
//
// </Export>

// <ExportMask GSTRM.Types>
//
#define GSTREAM_TYPE_INVALID			0x00			// Invalid Type
#define GSTREAM_TYPE_WEBCAM				0x01			// ksvideosrc -> AppSink
#define GSTREAM_TYPE_URI				0x02			// uridecodebin -> AppSink
#define GSTREAM_TYPE_VIDEO				0x03			// v4l2src -> AppSink
//
// </Export>

#define GST_TIME_ARGmS(t) \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) (((GstClockTime)(t)) / (GST_SECOND * 60 * 60)) : 99, \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) ((((GstClockTime)(t)) / (GST_SECOND * 60)) % 60) : 99, \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) ((((GstClockTime)(t)) / GST_SECOND) % 60) : 99, \
        GST_CLOCK_TIME_IS_VALID (t) ? \
        (guint) ((((GstClockTime)(t)) % GST_SECOND) / GST_MSECOND) : 999

#define GNULL	(gpointer*)0


// *** F O R E C A S T ****************************************************************************
//
class CGStream;


// *** T Y P E D E F S ****************************************************************************
//

typedef struct GstVideoInfoDEF
{
	gint					width;
	gint					height;
	gint					fps_n;
	gint					fps_d;
	gfloat					fps;
	gchar					szFormat[30];
	GstVideoFormat			format;
	gint					bpp;
	
} GstVideoInfoDEF;


// PipelineDEF ************************************************************************************
//
typedef struct PipelineDEF
{
	CGStream*				pGStream;
	GstElement*				pPipeline;
	GstBus*					pBus;
	uint32					u32Flags;

	// Basics (GStreamURI/Webcam/Video)
	//
	GstElement*				pAudioSource;
	GstElement*				pAudioQueue;
	GstElement*				pAudioConverter;
	GstElement*				pAudioVolume;
	GstElement*				pASinkQueue;
	GstElement*				pAudioSink;
	
	GstElement*				pVideoSource;
	GstElement*				pVideoCapsFilter;
	GstElement*				pVideoTee1;
	GstElement*				pInputQueue;
	GstElement*				pVideoQueue;
	GstElement*				pDecodeBin;
	GstElement*				pVideoConvert;
	GstElement*				pConvertCapsFilter;
	GstElement*				pVideoConvert2;
	GstElement*				pConvertCapsFilter2;
	GstElement*				pVideoScaler;
	GstElement*				pVideoRate;
	GstElement*				pVideoEncoder;
	GstElement*				pVideoDecoder;
	GstElement*				pVSinkQueue;
	GstElement*				pVideoSink;
	
	// Video Format, etc.
	//
	GstVideoInfoDEF			gstVideoInfo;
	
	char					szState[MAX_PATH];

	uint32					u32PosTime_ms; 			// Position in Milliseconds
	uint32					u32LenTime_ms;			// Length in Milliseconds

	uint32					u32AudioTime_ms; 		// Time to push audio (milliseconds)

	uint32					u32StreamTimeout_ms;	// Time at which to Timeout (milliseconds)
	
	uint32					u32StartTimeout_ms; 	// Time at which to start caring about resolution (milliseconds)
	
	
} PipelineDEF;


// *** P R O T O T Y P E S ************************************************************************
//
void        GSSVReadHandler(uint16 uState, SVEntryDEF* pSV, SVHndDEF* pSVHnd);
gboolean    StaticAutoPlugContinueHandler(GstElement* bin, GstPad* newPad, GstCaps* caps, PipelineDEF pData);
void        StaticPadAddedHandler(GstElement* bin, GstPad* newPad, PipelineDEF* pData);
void        StaticNoMorePadsHandler(GstElement* bin, PipelineDEF* pData);
void        StaticSourceSetupHandler(GstElement* bin, GstElement* src, PipelineDEF* pData);
void        StaticUnknownTypeHandler(GstElement* bin, GstPad* newPad, GstCaps* caps, PipelineDEF* pData);

// *** CGStream ************************************************************************
//
class CGStream
{
public:

    // Static Members
    
    static CGStream*                pAll;
    
public:

    // Static Functions
    
    static BOOL                     ClassInit(void);
    static BOOL                     ClassShutdown(void);
    static BOOL                     ClassDestroy(void);
    static CGStream*                FindStreamWithBus(GstBus* pBus);
    static CGStream*                FindStreamWithPipeline(GstElement* pPipeline);
    static CGStream*                FindStreamNamed(char* szName);
    static void                     Convert24To32RGB(uint8* p32Bits, uint8* p24Bits, uint32 u32Len24Bits);
    static gboolean                 NotifyVideoCapsHandler(GstPad* pPadVideo, GstPad* pPadPeer CGStream* pGStream);
    static GstBusSyncReply          HandleSyncMessage(GstBus* pBus, GstMessage* pMsg, GstPipeline* pPipeline);
    static gboolean                 print_field(GQuark field, const GValue* value, gpointer pfx);
    static void                     print_caps(const GstCaps* caps, const gchar* pfx);
    static void                     print_pad_templates_information(GstElementFactory* factory);
    static void                     print_pad_capabilities(GstElement* element, gchar* pad_name);
    
public:

    // Public Functions

                                    CGStream(uint8 u8Type, VideoSource_Context* pSourceContext);
    virtual                         ~CGStream();
    
    // Virtual Functions
    
    virtual void                    OnSVReadChange(uint8 uState, SVEntryDEF* pSV, SVHndDEF* pHnd);
    virtual void                    AttachSYS(void);
    virtual void                    OnManagerThread(void);
    virtual void                    Start(void);
    virtual void                    Stop(void);
    virtual BOOL                    BuildPipeline(void);
    virtual void                    Shutdown(void);
    virtual void                    Destroy(void);
    virtual void                    setSize(int32 x, int32 y, uint32 u32Width, uint32 u32Height);
    virtual void                    endPipeline(GstBus*pBus, GstMessage* pMsg);
    virtual void                    endPipeline(void);
    virtual gboolean                AutoPlugContinueHandler(GstElement* bin, GstPad* newPad, GstCaps* caps);
    virtual void                    PadAddedHandler(GstElement* bin, GstPad* newPad);
    virtual void                    NoMorePadsHandler(GstElement* bin);
    virtual void                    SourceSetupHandler(GstElement* bin, GstElement* src);
    virtual void                    UnknownTypeHandler(GstElement* bin, GstPad* newPad, GstCaps* caps);
    virtual void                    OnWatchdog(void);
    virtual void                    OnEOS(void);
    virtual void                    OnPlay(GstMessage* pMsg);
    virtual void                    OnPause(void);
    virtual void                    OnSizeKnown(void);
    virtual void                    OnStreamTimeout(void);
    virtual GstFlowReturn           onNewSample(CGStream* pGStream, GstElement* pAppsink);
    
    virtual	void					OnBusMessageEOS(GstBus* pBus, GstMessage* pMsg);
	//virtual	void					OnBusMessageError(GstBus* pBus, GstMessage* pMsg);
	//virtual	void					OnBusMessageWarning(GstBus* pBus, GstMessage* pMsg);
	//virtual	void					OnBusMessageInfo(GstBus* pBus, GstMessage* pMsg);
	//virtual	void					OnBusMessageTag(GstBus* pBus, GstMessage* pMsg);
	//virtual	void					OnBusMessageBuffering(GstBus* pBus, GstMessage* pMsg);
	
	
	// Public Functions   
	
	void                            InstallReadHandler(uint8 uSVReadFlags, uint8 uState, SVEntryDEF* pSV, uintSV uSVMask);
	BOOL                            LinkElementsWithFilter(GstElement* pUpStream, GstElement* pDownStream, GstCaps* caps);
	BOOL                            LinkElements(GstElement* pUpStream, GstElement* pDownStream);
	uint32                          SetFlags(uint32 u32On, uint32 u32Off);
	uint32                          GetFlags(uint32 u32Mask);
	uint32                          TestFlags(uint32 u32Mask);
	gboolean                        HandleBusMsg(GstBus* pBus, GstMessage* pMsg);
	GetStateChangeReturn            Set_State(GstElement* element, GstState* newState);
	void                            Play(void);
	void                            Pause(void);
	void                            Ready(void);
	BOOL                            SetPosition(uint32 u32Pos_ms);
	BOOL                            SetRelPosition(int32 s32RelPos_ms);
	void                            Step(void);
	float                           GetProgress(void);
	void                            SamplePosition(void);
	BOOL                            isStreaming(void);
	BOOL                            isMuted(void);
	void                            Mute(BOOL bState);
	FrameBufferDEF*                 GetLiveFrame(void);
	
public:

    // Public Members
    
    uint8                           usVideoIn;
    VideoSourceDEF*                 pMyVideoSource;
    
    SVEntryDEF*                     pSYS_Status;
    SVEntryDEF*                     pSYS_TimeStamp;
    SVEntryDEF*                     pSYS_UserMsgStr[4];
    SVEntryDEF*                     pSYS_UserMsgCtrl;
    SVEntryDEF*                     PSYS_VideoModes[2];
    SVEntryDEF*                     pSYS_AudioLevels[4];
    
    SVEntryDEF*                     pVID_MediaCtrl;
    SVEntryDEF*                     pVID_MediaStatus;
    SVEntryDEF*                     pVID_VideoStatusStr;
    SVEntryDEF*                     pVID_VideoGraphFlags;
    SVEntryDEF*                     pVID_VideoSource;
    SVEntryDEF*                     pVid_PlaySpeed;
    
    SVBlobStreamDEF                 SVBlobStreamInfo;
    
    uint32                          u32Signature;
    uint8                           u8Type;
    char                            szName[32];
    PipelineDEF                     tsPipeline;
    BOOL                            bVidSys;
    BOOL                            bVidInp;
    VideoSource_Context*            pSourceContext;
    SYSThreadDEF*                   pThread;
    BOOL                            bBuilt;
    BOOL                            bStarted;
    
    uint16                          u16Width;
    uint16                          u16Height;
    
    FrameBufferDEF*                 pFrame[2];
    uint8                           u8ActiveFrame;
    uint32                          u32Frames;
    
    uint32							u32Sample_ms;			// last sample time (milliseconds)
	uint32							u32Last_ms;				// last sample time (milliseconds)
	
	BOOL                            bSettingUpdate;
	
	CGStream*                       pPrev;
	CGStream*                       pNext;
};
// CGStream


#endif // USE_GSTREAMER
#endif // _GSTREAM_INCLUDED

// GStreamer.h