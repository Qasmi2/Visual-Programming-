#pragma once
#include "NetStatusCodeType.h"

namespace Mntone { namespace Rtmp {

	ref class RtmpHelper sealed
	{
	internal:
		static Mntone::Data::Amf::AmfArray^ ParseAmf( std::vector<uint8> data );

		static NetStatusCodeType ParseNetConnectionConnectCode( const std::wstring code );
		static NetStatusCodeType ParseNetStreamCode( const std::wstring code );

		static uint32 ReadUint24( Windows::Storage::Streams::DataReader^ reader );
	};

} }