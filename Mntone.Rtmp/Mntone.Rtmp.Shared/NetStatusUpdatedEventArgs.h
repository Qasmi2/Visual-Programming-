#pragma once
#include "NetStatusCodeType.h"

namespace Mntone { namespace Rtmp {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NetStatusUpdatedEventArgs sealed
	{
	internal:
		NetStatusUpdatedEventArgs( NetStatusCodeType netStatusCode );

	public:
		property NetStatusCodeType NetStatusCode
		{
			NetStatusCodeType get() { return NetStatusCode_; }
		}

	private:
		NetStatusCodeType NetStatusCode_;
	};

} }