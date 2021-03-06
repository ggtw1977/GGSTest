#ifndef _GG_NETINIT_H
#define _GG_NET_INIT

class GGNetInit
{
	public:
		GGNetInit(){ _Initialize(); }
		~GGNetInit(){}
	protected:
		bool _Initialize()
		{
				
			#ifdef _WIN32

				WORD wVersionReq = MAKEWORD(2, 2);
				WSADATA wData;
				int errCode;

				errCode = WSAStartup(wVersionReq, &wData);

				if (errCode != 0)
				{
					//GGTO: Add failure handling here
					return false;
				}

				if (LOBYTE(wData.wVersion) != 2 || HIBYTE(wData.wVersion) != 2)
				{
					//GGTO: Add failure handling here
					WSACleanup(); //Initialized but not 2,2 , gotta release
					return false;
				}
			#else

			#endif
			retun true;
		}

		bool _CleanUp()
		{
			#ifdef _WIN32

			int iErrCode=WSACleanup();
			if(iErrCode!=0)
			{
				return false;
			}
			#else

			#endif


			return true;
		}
};


#endif