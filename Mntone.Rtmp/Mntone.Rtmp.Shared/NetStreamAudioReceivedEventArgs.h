#pragma once
#include "Media/AudioInfo.h"

namespace Mntone { namespace Rtmp {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NetStreamAudioReceivedEventArgs sealed
	{
	internal:
		NetStreamAudioReceivedEventArgs();

		void SetTimestamp( int64 timestamp );
		void SetData( std::vector<uint8> data, const size_t offset = 0 );

		Windows::Media::Core::MediaStreamSample^ CreateSample();

	public:
		property Media::AudioInfo^ Info
		{
			Media::AudioInfo^ get() { return Info_; }
		internal:
			void set( Media::AudioInfo^ value ) { Info_ = value; }
		}
		property Windows::Foundation::TimeSpan Timestamp
		{
			Windows::Foundation::TimeSpan get() { return Timestamp_; }
		}
		property Windows::Storage::Streams::IBuffer^ Data
		{
			Windows::Storage::Streams::IBuffer^ get() { return Data_; }
		}

	private:
		Media::AudioInfo^ Info_;
		Windows::Foundation::TimeSpan Timestamp_;
		Windows::Storage::Streams::IBuffer^ Data_;
	};

} }