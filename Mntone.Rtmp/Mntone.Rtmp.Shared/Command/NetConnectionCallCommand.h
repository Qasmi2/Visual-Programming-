#pragma once
#include "IRtmpCommand.h"

namespace Mntone { namespace Rtmp { namespace Command {

	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NetConnectionCallCommand sealed
		: public IRtmpCommand
	{
	public:
		NetConnectionCallCommand( Platform::String^ commandName );

		virtual Mntone::Data::Amf::AmfArray^ Commandify();

		// IStringable
		virtual Platform::String^ ToString() override sealed;

	public:
		property Platform::String^ Type
		{
			virtual Platform::String^ get() { return "call"; }
		}
		property Platform::String^ CommandName
		{
			Platform::String^ get() { return CommandName_; }
			void set( Platform::String^ value ) { CommandName_ = value; }
		}
		property Mntone::Data::Amf::IAmfValue^ CommandObject
		{
			Mntone::Data::Amf::IAmfValue^ get() { return CommandObject_; }
			void set( Mntone::Data::Amf::IAmfValue^ value ) { CommandObject_ = value; }
		}
		property Windows::Foundation::Collections::IVector<Mntone::Data::Amf::IAmfValue^>^ OptionalArguments
		{
			Windows::Foundation::Collections::IVector<Mntone::Data::Amf::IAmfValue^>^ get() { return OptionalArguments_; }
		}

	internal:
		property uint32 TransactionId
		{
			uint32 get() { return TransactionId_; }
			void set( uint32 value ) { TransactionId_ = value; }
		}

	private:
		Platform::String^ CommandName_;
		uint32 TransactionId_;
		Mntone::Data::Amf::IAmfValue^ CommandObject_;
		Platform::Collections::Vector<Mntone::Data::Amf::IAmfValue^>^ OptionalArguments_;
	};

} } }