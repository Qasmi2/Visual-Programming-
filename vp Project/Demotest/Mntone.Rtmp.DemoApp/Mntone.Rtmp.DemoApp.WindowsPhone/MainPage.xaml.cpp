﻿#include "pch.h"
#include "MainPage.xaml.h"

using namespace Platform;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Mntone::Rtmp::Client;
using namespace Mntone::Rtmp::DemoApp;

void MainPage::OnMediaButtonPressed( Windows::Media::SystemMediaTransportControls^ sender, Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs^ e )
{
	if( e->Button == Windows::Media::SystemMediaTransportControlsButton::Pause
		|| e->Button == Windows::Media::SystemMediaTransportControlsButton::Stop )
	{
		Dispatcher->RunAsync( CoreDispatcherPriority::Low, ref new DispatchedHandler( [this]
		{
			mediaElement->Source = nullptr;

			auto smtc = Windows::Media::SystemMediaTransportControls::GetForCurrentView();
			smtc->PlaybackStatus = Windows::Media::MediaPlaybackStatus::Closed;
		} ) );
	}
}