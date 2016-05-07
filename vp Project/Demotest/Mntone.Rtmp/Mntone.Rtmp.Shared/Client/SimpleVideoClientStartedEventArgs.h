#pragma once

namespace Mntone { namespace Rtmp { namespace Client {

	[Windows::Foundation::Metadata::Threading( Windows::Foundation::Metadata::ThreadingModel::Both )]
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SimpleVideoClientStartedEventArgs sealed
	{
	internal:
		SimpleVideoClientStartedEventArgs( Windows::Media::Core::MediaStreamSource^ mediaStreamSource );

	public:
		property Windows::Media::Core::MediaStreamSource^ MediaStreamSource
		{
			Windows::Media::Core::MediaStreamSource^ get() { return MediaStreamSource_; }
		}

	private:
		Windows::Media::Core::MediaStreamSource^ MediaStreamSource_;
	};

} } }