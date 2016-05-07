#include "pch.h"
#include "RtmpUri.h"

using namespace Platform;
using namespace Mntone::Rtmp;

RtmpUri::RtmpUri()
{ }

RtmpUri::RtmpUri( Platform::String^ uri )
{
	Parse( ref new Windows::Foundation::Uri( uri ) );
}

RtmpUri::RtmpUri( Windows::Foundation::Uri^ uri )
{
	Parse( uri );
}

void RtmpUri::Parse( Windows::Foundation::Uri^ uri )
{
	ParseScheme( uri->SchemeName );
	Host_ = uri->Host;
	ParsePort( uri->Port );
	ParsePath( uri->Path + uri->Query );
}

void RtmpUri::ParseScheme( Platform::String^ schemeName )
{
	if( schemeName == "rtmp" )
	{
		Scheme_ = RtmpScheme::Rtmp;
		return;
	}
	else if( schemeName == "rtmps" )
	{
		Scheme_ = RtmpScheme::Rtmps;
		return;
	}

	throw ref new Platform::InvalidArgumentException( "Invalid scheme name." );
}

void RtmpUri::ParsePort( int32 port )
{
	if( port == 0 )
	{
		switch( Scheme_ )
		{
		case RtmpScheme::Rtmp: Port_ = 1935; break;
		case RtmpScheme::Rtmps: Port_ = 443; break;
		case RtmpScheme::Rtmpe: Port_ = 1935; break;
		case RtmpScheme::Rtmpt: Port_ = 80; break;
		case RtmpScheme::Rtmpte: Port_ = 80; break;
		default: throw ref new Platform::InvalidArgumentException( "Invalid port." );
		}
	}
	else
	{
		Port_ = port;
	}
}

void RtmpUri::ParsePath( String^ path )
{
	std::wstring p( path->Data() );

	if( p[0] != '/' )
		throw ref new InvalidArgumentException( "Invalid path." );

	auto spos1 = p.find( L'/', 1 );
	if( spos1 == std::wstring::npos )
	{
		auto app = p.substr( 1 );
		App_ = StringReference( app.c_str(), app.length() );
		return;
	}

	auto app = p.substr( 1, spos1 - 1 );
	App_ = StringReference( app.c_str(), app.length() );

	auto spos2 = p.find( L'/', spos1 );
	auto instance = p.substr( spos1 + 1, spos2 != spos1 ? spos2 : p.length() - spos1 - 1 );
	Instance_ = StringReference( instance.c_str(), instance.length() );
}

Platform::String^ RtmpUri::ToString()
{
	std::wostringstream buf;

	auto scheme = Scheme_.ToString();
	buf.write( scheme->Data(), scheme->Length() );

	buf.write( L"://", 3 );

	buf.write( Host_->Data(), Host_->Length() );

	buf.put( ':' );
	
	auto port = Port_.ToString();
	buf.write( port->Data(), port->Length() );

	buf.put( '/' );
	buf.write( App_->Data(), App_->Length() );

	if( !Instance_->IsEmpty() )
	{
		buf.put( '/' );
		buf.write( Instance_->Data(), Instance_->Length() );
	}

	auto str = buf.str();
	return ref new Platform::String( str.c_str(), static_cast<uint32>( str.length() ) );
}