#ifndef IVIDEOSERVER_H
#define IVIDEOSERVER_H
#include <Windows.h>
#include <windef.h>
#include <vector>
#include <map>
#include <string>
#include <mutex>


#if defined(VIDEOSERVER_LIBRARY)
#  define VIDEOSERVER_EXPORT __declspec(dllexport)
#else
#  define VIDEOSERVER_EXPORT __declspec(dllimport)
#endif

#define SHE_BEGING __try{ std::cout<<"she try beg"<<std::endl;

#define SHE_END  std::cout<<"she try end"<<std::endl;}__except(EXCEPTION_EXECUTE_HANDLER) \
{ \
    addLog("unkonw error!", __LINE__);\
}

#define SHE_END_RETURN(returnValue) }__except(EXCEPTION_EXECUTE_HANDLER) \
{ \
    addLog("unkonw error!", __LINE__);\
   return returnValue; \
}

#define SHE_END_RETURN_FALSE SHE_END_RETURN(false)


typedef long long  download_handle_t;
typedef long long  play_handle_t;

//厂商ID
enum DeviceFactory
{
	ETIM_IPC_DH = 0,                                  // 大华
	ETIM_IPC_GZLL = 1,                                // 广州利凌
	ETIM_IPC_DIZHIPU = 2,							  // 迪智浦
	ETIM_IPC_HAISHITAI = 3,							  // 海视泰
	ETIM_IPC_XINDAGONGCHUANG = 4,					  // 新达共创
	ETIM_IPC_XP = 5,								  // 鑫鹏安防
	ETIM_IPC_BLUESKY = 6,							  // 蓝色星际
	ETIM_IPC_DEJIALA = 7,							  // 德加拉
	ETIM_IPC_JUNMINGSHI = 8,                          // 俊明视
	ETIM_IPC_JIUAN = 9,							      // 九安光电
	ETIM_IPC_LIANDA = 10,							  // 立安达
	ETIM_IPC_SILANG = 11,							  // 深圳思浪
	ETIM_IPC_JIRUI = 12,							  // 吉锐
	ETIM_IPC_TAIKANGWEIYE = 13,					      // 泰康伟业
	ETIM_IPC_XINWANGRUIJIE = 14,				      // 星网锐捷
	ETIM_IPC_ZHONGTIANANBAO = 15,				      // 中田安保
	ETIM_IPC_TIANSHIDA = 16,			    	      // 天视达
	ETIM_IPC_DOANGYANG = 17,			    	      // 东阳国际
	ETIM_IPC_YUNDIANSHI = 18,			    	      // 云典视
	ETIM_IPC_KUANGSHIAN = 19,			    	      // 旷视安
	ETIM_IPC_HONGKANGWEISHI = 20,			    	  // 宏康威视
	ETIM_IPC_SHENZHENTONGWEI = 21,			    	  // 深圳同为
	ETIM_IPC_DALIKEJI = 22,			    	          // 大立科技
	ETIM_IPC_SHIXINGANFANG = 23,			    	  // 世星安防
	ETIM_IPC_SHOUWEIZHE = 24,			         	  // 守卫者
	ETIM_IPC_HUONIWEIER = 25,			         	  // 霍尼韦尔
	ETIM_IPC_NANNINGGUANGTAI = 26,			          // 南宁冠泰
	ETIM_IPC_GUANGDONGLINYU = 27,			          // 广东领域
	ETIM_IPC_HANGJINGKEJI = 28,		     	          // 航景科技

	ETIM_IPC_BAOXINGSHENG = 29,		     	          // 宝欣盛
	ETIM_IPC_LANDAOEMHK = 30,		     	          // 立安达OEM海康
	ETIM_IPC_XIANHAIFANG = 31,		     	          // 西安海方OEM海康
	ETIM_IPC_BEIJINGZHENGFANG = 32,		     	      // 北京正方时代OEM海康
	ETIM_IPC_TAIKANGWEIYEOEMHK = 33,		     	  // 泰康伟业OEM海康
	ETIM_IPC_TIANMIN = 34,		     	              // 天敏
	ETIM_IPC_KEEN = 35,		     	                  // 科恩
	ETIM_IPC_MEIFANGWEIYE = 36,		     	          // 美防伟业
	ETIM_IPC_GUANGZHOUBANGSHI = 37,		     	      // 广州邦世电子
	ETIM_IPC_GUANGZHOUSHIAN = 38,		     	      // 广州视安安防
	ETIM_IPC_QIAOAN = 39,		     	              // 乔安
	ETIM_IPC_LANGSHIXIN = 40,		     	          // 朗视兴
	ETIM_IPC_YAAN = 41,		     	                  // 亚安
	ETIM_IPC_TAIWEIGAOKE = 42,		     	          // 泰威高科
	ETIM_IPC_HUABANGHAISHI = 43,		     	      // 华邦海视
	ETIM_IPC_GUANGZHOUYISHI = 44,		     	      // 广州亿视
	ETIM_IPC_HONGKANGWEISHIOEMXM = 45,		     	  // 深圳宏康威视OEM雄迈
	ETIM_IPC_ANJULIAO = 46,		     	              // 安居鸟
	ETIM_IPC_YIRONGGUANSHI = 47,		     	      // 北京益融冠世
	ETIM_IPC_DONGDAJIZHI = 48,		     	          // 东大金智平台
	ETIM_IPC_GERECORDER = 49,		     	          // GE硬盘录像机

	ETIM_IPC_MIKA61 = 50,		     	              // 广州米卡61系列
	ETIM_IPC_MIKA8081 = 51,		     	              // 广州米卡8081系列NVR
	ETIM_IPC_HENGYI = 52,		     	              // 恒忆
	ETIM_IPC_BAAN = 53,		         	              // 深圳八安
	ETIM_IPC_BAIHUI = 54,		         	          // 深圳百汇
	ETIM_IPC_HAISHIAN = 55,		         	          // 深圳海视安
	ETIM_IPC_JUFU = 56,		            	          // 深圳巨罦
	ETIM_IPC_SAIQING = 57,		         	          // 深圳赛清
	ETIM_IPC_XINGKEAN = 58,		         	          // 深圳兴科安
	ETIM_IPC_TIANTIANYOU = 59,		         	      // 天天佑

	ETIM_IPC_HB = 60,                                 // 汉邦
	ETIM_IPC_TDWY = 61,                               // 天地伟业
	ETIM_IPC_XM = 62,                                 // 雄迈
	ETIM_IPC_GZHX = 63,   						      // 广州宏翔
	ETIM_IPC_SNA = 64,   						      // 施耐安
	ETIM_IPC_JF = 65,   						      // 巨峰
	ETIM_IPC_SALX = 66,   						      // 狮安联讯
	ETIM_IPC_WSD = 67,   						      // 沃仕达
	ETIM_IPC_HIKVISION = 100,                         // 海康
	ETIM_IPC_ZHONGWEI = 101,                          // 中维

	ETIM_IPC_TEST = 9998,
    ETIM_IPC_UNDEFINE = 9999,                         // 未定义
};

// 设备信息
struct DeviceInfo
{
    DeviceInfo()
    {
        Factory = ETIM_IPC_UNDEFINE;
		szIP = "";
        nPort = 0;
    }

    DeviceInfo(const DeviceInfo &other)
    {
        Factory = other.Factory;
        szIP = other.szIP;
        nPort = other.nPort;
    }
    DeviceInfo& operator = (const DeviceInfo &other)
    {
        if (this != &other)
        {
            Factory = other.Factory;
            szIP = other.szIP;
            nPort = other.nPort;
         }

        return *this;
    }

    DeviceFactory Factory;
    std::string szIP;
    __int32 nPort;
};

struct IVideoServer;
struct IVideoServerFactory
{
	IVideoServerFactory() : m_init(false)
	{
		m_OemFlag = false;
	}
	virtual ~IVideoServerFactory()
	{
	}
	virtual void destroy()
	{
		delete this;
	}

	//初始化SDK
	virtual bool init()
	{
		return false;
	}
	/*
	 * 释放SDK
	 */
	virtual void clean()
	{
		return;
	}
	//创建视频服务器
	virtual IVideoServer* create()
	{
		return NULL;
	}
    //厂商名称
    virtual const char* name()
	{
		return NULL;
	}
    //厂商ID
	virtual DeviceFactory factory()
	{
		return ETIM_IPC_UNDEFINE;
	}
    //视频后缀
	virtual void videoFileExterns(std::vector<std::string>& externs)
	{
		return;
	}
    virtual const char* getLastError()
    {
        return m_sLastError.c_str();
    }
    //默认端口
	virtual int defaultPort()
	{
		return 0;
	}
    //默认用户
	virtual const char* defaultUser()
	{
		return NULL;
	}
    //默认密码
	virtual const char* defaultPasswords()
	{
		return NULL;
	}
	
	virtual bool IsOEMFac()
	{
		return m_OemFlag;
	}
protected:
    bool m_init;
    std::string  m_sLastError;

protected:
	bool m_OemFlag;
};
//单个视频文件信息
struct RecordFile
{
    RecordFile()
    {
        channel = 0;
        size = 0;
        pPrivateData = nullptr;
        PrivateDataDataSize = 0;
    }

    ~RecordFile()
    {
        if (nullptr != pPrivateData)
        {
            delete pPrivateData;
            pPrivateData = nullptr;
            PrivateDataDataSize = 0;
        }
    }

    RecordFile(const RecordFile& other)
    {
        channel = other.channel;
        size = other.size;
        name = other.name;
        beginTime = other.beginTime;
        endTime = other.endTime;
        pPrivateData = nullptr;
        PrivateDataDataSize = 0;
        setPrivateData(other.pPrivateData, other.PrivateDataDataSize);
    }

    RecordFile& operator= (const RecordFile& other)
    {
        if (&other == this)
        {
            return *this;
        }
        channel = other.channel;
        size = other.size;
        name = other.name;
        beginTime = other.beginTime;
        endTime = other.endTime;
        setPrivateData(other.pPrivateData, other.PrivateDataDataSize);
        return *this;
    }

    void setPrivateData(void* pData, int size)
    {
        if (nullptr != pPrivateData)
        {
            delete pPrivateData;
            pPrivateData = nullptr;
            PrivateDataDataSize = 0;
        }


        if (size > 0)
        {
            pPrivateData = new char[size];
            PrivateDataDataSize = size;
            memcpy(pPrivateData, pData, size);
        }
    }
    //取得私有数据
    void* getPrivateData() const
    {
        return pPrivateData;
    }
    __int32 getPrivateDataSize() const
    {
        return PrivateDataDataSize;
    }

    __int32 channel;      //通道
    __int64 size;         //文件大小(byte)
    std::string  name;    //文件名称
    __time64_t beginTime; //本地时间
    __time64_t endTime;   //本地时间
    char* pPrivateData;   //私有数据
    __int32 PrivateDataDataSize;//私有数据大小
};

struct IVideoServer
{

	IVideoServer() : m_lLoginHandle(0)
	{

	}

	virtual void destroy()
	{
		delete this;
	}

	virtual ~IVideoServer()
	{
	}

	virtual const char* getLastError()
	{
		return m_sLastError.c_str();
	}
	//深度克隆一个服务器
	virtual IVideoServer* clone()
	{
		return false;
	}
	/*
	 *  登录函数
	 *  @param [in] IP 登录的IP
	 *  @param [in] port 端口号
	 *  @param [in] user 用户名
	 *  @param [in] password 密码
	 *  @param [out] channels 通道号
	 *  @return 是否成功
	 */
	virtual bool login(const char* IP, __int32 port, const char* user,
		const char* password, std::map<__int32, std::string>& channels)
	{
		return false;
	}
	//退出
	virtual bool logout()
	{
		return false;
	}
	/*
	 * 获取文件列表
	 *  @param [out] files 文件列表
	 *  @param [in] nChannelId 通道号
	 *  @param [in] timeStart 开始时间
	 *  @param [in] timeEnd 结束时间
	 *  @return 是否成功
	 */
	virtual bool GetRecordFileList(std::vector<RecordFile>& files, /*__int32 nChannelId*/std::vector<int>& channelVec, __time64_t timeStart,
		__time64_t timeEnd)
	{
		return false;
	}
	/*
	 * 文件下载
	 *  @param [in] saveFileName 保存文件名（全路径）
	 *  @param [in] file 视频文件信息
	 *  @param [out] hdl 返回下载ID
	 *  @return 成功与否
	 */
	virtual bool downLoadByRecordFile(const char* saveFileName, const RecordFile& file, download_handle_t& hdl)
	{
		return false;
	}
	/*
	 *  停止下载
	 *  @param [in] h downLoadByRecordFile返回的下载ID
	 *  @return 返回true/false
	 */
	virtual bool stopDownload(download_handle_t h)
	{
		return false;
	}
	/*
	 *  视频预览
	 *  @param [in] file 视频文件信息
	 *  @param [in] hwnd 播放窗口句柄
	 *  @param [out] playbackHandle 返回播放ID
	 *  @return 返回true/false
	 */
	virtual bool  PlayBackByRecordFile(const RecordFile& file, HWND hwnd, play_handle_t& playbackHandle)
	{
		return false;
	}

    /*
     *  设置播放位置
     *  @param [in] playbackHandle PlayBackByRecordFile返回的播放ID
     *  @param [in] pos （0 - 100）
     *  @return 返回true/false
     */
	virtual bool SetPlayBack(__int64 playbackHandle, __int32 pos)
	{
		return false;
	}
    /*
     *  停止视频预览
     *  @param [in] playbackHandle PlayBackByRecordFile返回的播放ID
     *  @param [in] mPause 是否是暂停 1是暂停 0不是
     *  @return 返回true/false
     */
	virtual bool StopPlayBack(__int64 playbackHandle, __int32 mPause)
	{
		return false;
	}
    virtual bool getPlayBackPos(__int64 playbackHandle, __int32* pos)
    {
        return false;
    }

    virtual bool getDownloadPos(download_handle_t h, __int64* totalSize, __int64* currentSize, bool* failed)
    {
        return false;
    }

protected:
    std::string m_sLastError;
    long m_lLoginHandle;
    std::recursive_mutex m_mutexDownload;
};

#if defined(VIDEOSERVER_LIBRARY)
extern "C" VIDEOSERVER_EXPORT IVideoServerFactory* VideoServerFactory();
#else

typedef void* (*pfExternFun)(IVideoServer* server, void* externParams);

//是否能预览视频
//externParams 类型 忽略
//返回值类型 bool (默认true)
#define EXTERN_FUN_CAN_PLAY_BACK "canPlayBack"


typedef IVideoServerFactory* (*pfGetVideoServerFactory)();
#endif


#endif // IVIDEOSERVER_H