#include "pch-cpp.hpp"





template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		R ret;
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3;
struct Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B;
struct CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0;
struct DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IFormatProvider_tC202922D43BFF3525109ABF3FB79625F5646AB52;
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct StringBuilder_t;
struct TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869;
IL2CPP_EXTERN_C String_t* _stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F;
IL2CPP_EXTERN_C String_t* _stringLiteralE310274B02A605A3985345944A620D7D2E019A1A;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0  : public RuntimeObject
{
	bool ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	bool ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	String_t* ___m_name;
	String_t* ___englishname;
	String_t* ___nativename;
	String_t* ___iso3lang;
	String_t* ___iso2lang;
	String_t* ___win3lang;
	String_t* ___territory;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___parent_culture;
	bool ___constructed;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D* ___m_cultureData;
	bool ___m_isInherited;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke
{
	int32_t ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	int32_t ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	char* ___m_name;
	char* ___englishname;
	char* ___nativename;
	char* ___iso3lang;
	char* ___iso2lang;
	char* ___win3lang;
	char* ___territory;
	char** ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke* ___parent_culture;
	int32_t ___constructed;
	Il2CppSafeArray* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke* ___m_cultureData;
	int32_t ___m_isInherited;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com
{
	int32_t ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	int32_t ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	Il2CppChar* ___m_name;
	Il2CppChar* ___englishname;
	Il2CppChar* ___nativename;
	Il2CppChar* ___iso3lang;
	Il2CppChar* ___iso2lang;
	Il2CppChar* ___win3lang;
	Il2CppChar* ___territory;
	Il2CppChar** ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com* ___parent_culture;
	int32_t ___constructed;
	Il2CppSafeArray* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com* ___m_cultureData;
	int32_t ___m_isInherited;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___numberGroupSizes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___currencyGroupSizes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___percentGroupSizes;
	String_t* ___positiveSign;
	String_t* ___negativeSign;
	String_t* ___numberDecimalSeparator;
	String_t* ___numberGroupSeparator;
	String_t* ___currencyGroupSeparator;
	String_t* ___currencyDecimalSeparator;
	String_t* ___currencySymbol;
	String_t* ___ansiCurrencySymbol;
	String_t* ___nanSymbol;
	String_t* ___positiveInfinitySymbol;
	String_t* ___negativeInfinitySymbol;
	String_t* ___percentDecimalSeparator;
	String_t* ___percentGroupSeparator;
	String_t* ___percentSymbol;
	String_t* ___perMilleSymbol;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___nativeDigits;
	int32_t ___m_dataItem;
	int32_t ___numberDecimalDigits;
	int32_t ___currencyDecimalDigits;
	int32_t ___currencyPositivePattern;
	int32_t ___currencyNegativePattern;
	int32_t ___numberNegativePattern;
	int32_t ___percentPositivePattern;
	int32_t ___percentNegativePattern;
	int32_t ___percentDecimalDigits;
	int32_t ___digitSubstitution;
	bool ___isReadOnly;
	bool ___m_useUserOverride;
	bool ___m_isInvariant;
	bool ___validForParseAsNumber;
	bool ___validForParseAsCurrency;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct StringBuilder_t  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars;
	StringBuilder_t* ___m_ChunkPrevious;
	int32_t ___m_ChunkLength;
	int32_t ___m_ChunkOffset;
	int32_t ___m_MaxCapacity;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___byte_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___byte_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_1_OffsetPadding[1];
			uint8_t ___byte_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___byte_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_2_OffsetPadding[2];
			uint8_t ___byte_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___byte_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_3_OffsetPadding[3];
			uint8_t ___byte_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___byte_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_4_OffsetPadding[4];
			uint8_t ___byte_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___byte_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_5_OffsetPadding[5];
			uint8_t ___byte_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___byte_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_6_OffsetPadding[6];
			uint8_t ___byte_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___byte_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_7_OffsetPadding[7];
			uint8_t ___byte_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___byte_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_8_OffsetPadding[8];
			uint8_t ___byte_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_8_OffsetPadding_forAlignmentOnly[8];
			uint8_t ___byte_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_9_OffsetPadding[9];
			uint8_t ___byte_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_9_OffsetPadding_forAlignmentOnly[9];
			uint8_t ___byte_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_10_OffsetPadding[10];
			uint8_t ___byte_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_10_OffsetPadding_forAlignmentOnly[10];
			uint8_t ___byte_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_11_OffsetPadding[11];
			uint8_t ___byte_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_11_OffsetPadding_forAlignmentOnly[11];
			uint8_t ___byte_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_12_OffsetPadding[12];
			uint8_t ___byte_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_12_OffsetPadding_forAlignmentOnly[12];
			uint8_t ___byte_12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_13_OffsetPadding[13];
			uint8_t ___byte_13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_13_OffsetPadding_forAlignmentOnly[13];
			uint8_t ___byte_13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_14_OffsetPadding[14];
			uint8_t ___byte_14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_14_OffsetPadding_forAlignmentOnly[14];
			uint8_t ___byte_14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_15_OffsetPadding[15];
			uint8_t ___byte_15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_15_OffsetPadding_forAlignmentOnly[15];
			uint8_t ___byte_15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___sbyte_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___sbyte_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_1_OffsetPadding[1];
			int8_t ___sbyte_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___sbyte_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_2_OffsetPadding[2];
			int8_t ___sbyte_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___sbyte_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_3_OffsetPadding[3];
			int8_t ___sbyte_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___sbyte_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_4_OffsetPadding[4];
			int8_t ___sbyte_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___sbyte_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_5_OffsetPadding[5];
			int8_t ___sbyte_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___sbyte_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_6_OffsetPadding[6];
			int8_t ___sbyte_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___sbyte_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_7_OffsetPadding[7];
			int8_t ___sbyte_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___sbyte_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_8_OffsetPadding[8];
			int8_t ___sbyte_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_8_OffsetPadding_forAlignmentOnly[8];
			int8_t ___sbyte_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_9_OffsetPadding[9];
			int8_t ___sbyte_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_9_OffsetPadding_forAlignmentOnly[9];
			int8_t ___sbyte_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_10_OffsetPadding[10];
			int8_t ___sbyte_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_10_OffsetPadding_forAlignmentOnly[10];
			int8_t ___sbyte_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_11_OffsetPadding[11];
			int8_t ___sbyte_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_11_OffsetPadding_forAlignmentOnly[11];
			int8_t ___sbyte_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_12_OffsetPadding[12];
			int8_t ___sbyte_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_12_OffsetPadding_forAlignmentOnly[12];
			int8_t ___sbyte_12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_13_OffsetPadding[13];
			int8_t ___sbyte_13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_13_OffsetPadding_forAlignmentOnly[13];
			int8_t ___sbyte_13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_14_OffsetPadding[14];
			int8_t ___sbyte_14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_14_OffsetPadding_forAlignmentOnly[14];
			int8_t ___sbyte_14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_15_OffsetPadding[15];
			int8_t ___sbyte_15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_15_OffsetPadding_forAlignmentOnly[15];
			int8_t ___sbyte_15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___uint16_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___uint16_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_1_OffsetPadding[2];
			uint16_t ___uint16_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___uint16_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_2_OffsetPadding[4];
			uint16_t ___uint16_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___uint16_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_3_OffsetPadding[6];
			uint16_t ___uint16_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___uint16_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_4_OffsetPadding[8];
			uint16_t ___uint16_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_4_OffsetPadding_forAlignmentOnly[8];
			uint16_t ___uint16_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_5_OffsetPadding[10];
			uint16_t ___uint16_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_5_OffsetPadding_forAlignmentOnly[10];
			uint16_t ___uint16_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_6_OffsetPadding[12];
			uint16_t ___uint16_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_6_OffsetPadding_forAlignmentOnly[12];
			uint16_t ___uint16_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_7_OffsetPadding[14];
			uint16_t ___uint16_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_7_OffsetPadding_forAlignmentOnly[14];
			uint16_t ___uint16_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___int16_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___int16_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_1_OffsetPadding[2];
			int16_t ___int16_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___int16_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_2_OffsetPadding[4];
			int16_t ___int16_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___int16_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_3_OffsetPadding[6];
			int16_t ___int16_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___int16_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_4_OffsetPadding[8];
			int16_t ___int16_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_4_OffsetPadding_forAlignmentOnly[8];
			int16_t ___int16_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_5_OffsetPadding[10];
			int16_t ___int16_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_5_OffsetPadding_forAlignmentOnly[10];
			int16_t ___int16_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_6_OffsetPadding[12];
			int16_t ___int16_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_6_OffsetPadding_forAlignmentOnly[12];
			int16_t ___int16_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_7_OffsetPadding[14];
			int16_t ___int16_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_7_OffsetPadding_forAlignmentOnly[14];
			int16_t ___int16_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___uint32_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___uint32_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_1_OffsetPadding[4];
			uint32_t ___uint32_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___uint32_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_2_OffsetPadding[8];
			uint32_t ___uint32_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_2_OffsetPadding_forAlignmentOnly[8];
			uint32_t ___uint32_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_3_OffsetPadding[12];
			uint32_t ___uint32_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_3_OffsetPadding_forAlignmentOnly[12];
			uint32_t ___uint32_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___int32_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___int32_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_1_OffsetPadding[4];
			int32_t ___int32_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___int32_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_2_OffsetPadding[8];
			int32_t ___int32_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_2_OffsetPadding_forAlignmentOnly[8];
			int32_t ___int32_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_3_OffsetPadding[12];
			int32_t ___int32_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_3_OffsetPadding_forAlignmentOnly[12];
			int32_t ___int32_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___uint64_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___uint64_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint64_1_OffsetPadding[8];
			uint64_t ___uint64_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint64_1_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___uint64_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___int64_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___int64_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int64_1_OffsetPadding[8];
			int64_t ___int64_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int64_1_OffsetPadding_forAlignmentOnly[8];
			int64_t ___int64_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___single_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___single_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_1_OffsetPadding[4];
			float ___single_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_1_OffsetPadding_forAlignmentOnly[4];
			float ___single_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_2_OffsetPadding[8];
			float ___single_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_2_OffsetPadding_forAlignmentOnly[8];
			float ___single_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_3_OffsetPadding[12];
			float ___single_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_3_OffsetPadding_forAlignmentOnly[12];
			float ___single_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___double_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___double_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___double_1_OffsetPadding[8];
			double ___double_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___double_1_OffsetPadding_forAlignmentOnly[8];
			double ___double_1_forAlignmentOnly;
		};
	};
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct VectorSizeHelper_tF54ACCE947CB8A38047BEB642392A4E7345A157D 
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ____placeholder;
	uint8_t ____byte;
};
struct VectorSizeHelper_tAB183E4966E0B97A19A75D213EDAE51037A6BF3C 
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ____placeholder;
	uint8_t ____byte;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticFields
{
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___invariant_culture_info;
	RuntimeObject* ___shared_table_lock;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___default_current_culture;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentUICulture;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentCulture;
	Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3* ___shared_by_number;
	Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28* ___shared_by_name;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_UserPreferredCultureInfoInAppX;
	bool ___IsTaiwanSku;
};
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472_StaticFields
{
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___invariantInfo;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields
{
	int32_t ___s_count;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_zero;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_one;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_allOnes;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields
{
	int32_t ___s_count;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_zero;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_one;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_allOnes;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared_inline (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09 (String_t* ___0_resourceFormat, RuntimeObject* ___1_p1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425 (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92 (uint64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7 (int32_t ___0_h1, int32_t ___1_h2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F (RuntimeObject* ___0_formatProvider, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline (NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1 (StringBuilder_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* UInt64_ToString_m779041C8FDD58BF8617838B00CD041788DB2F1A3 (uint64_t* __this, String_t* ___0_format, RuntimeObject* ___1_provider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
inline void Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_inline (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, RuntimeObject*, const RuntimeMethod*))Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared_inline)(__this, ___0_obj, method);
}
inline bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method)
{
	return ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_fshared)(__this, ___0_other, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678 (uint8_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF (int8_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200 (uint16_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1 (int16_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC (uint32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496 (int64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2 (float* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline (double* __this, const RuntimeMethod* method) ;
inline int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, const RuntimeMethod*))Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_fshared)(__this, method);
}
inline String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, const RuntimeMethod*))Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_fshared)(__this, method);
}
inline String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, String_t*, RuntimeObject*, const RuntimeMethod*))Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_fshared)(__this, ___0_format, ___1_formatProvider, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline (const RuntimeMethod* method) ;
inline void Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, void*, const RuntimeMethod*))Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001_fshared)(__this, ___0_dataPointer, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline (const RuntimeMethod* method) ;
inline void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
inline void Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Il2CppFullySharedGenericStruct, const RuntimeMethod*))Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2_fshared)((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)__this, ___0_value, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline (double ___0_value, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_get_Zero_m052680C155E15387C16A5E044176ACB59DF53359 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A (const RuntimeMethod* method) 
{
	VectorSizeHelper_tF54ACCE947CB8A38047BEB642392A4E7345A157D V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B21_0 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B8_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B13_0 = 0;
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* L_0 = (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*)(&(&V_0)->____placeholder);
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&L_0->___register);
		uint8_t* L_2 = (uint8_t*)(&L_1->___byte_0);
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_2,NULL));
		V_1 = (uint8_t*)L_3;
		uint8_t* L_4 = (uint8_t*)(&(&V_0)->____byte);
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		uint8_t* L_6 = V_1;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,uint8_t*,intptr_t,false,false>(((uint8_t*)((intptr_t)((uint8_t*)il2cpp_codegen_subtract((intptr_t)L_5, (intptr_t)L_6))/1)),NULL));
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_7,NULL));
		V_2 = (-1);
		G_B2_0 = L_8;
		goto IL_0045;
	}

IL_0045:
	{
		G_B4_0 = G_B2_0;
		goto IL_0067;
	}

IL_0067:
	{
		G_B6_0 = G_B4_0;
		goto IL_0089;
	}

IL_0089:
	{
		G_B8_0 = G_B6_0;
		goto IL_00ab;
	}

IL_00ab:
	{
		G_B10_0 = G_B8_0;
		goto IL_00cd;
	}

IL_00cd:
	{
		G_B12_0 = G_B10_0;
		goto IL_00ef;
	}

IL_00ef:
	{
		G_B13_0 = G_B12_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B13_0;
		goto IL_0176;
	}

IL_0176:
	{
		int32_t L_9 = V_2;
		return ((int32_t)(G_B21_0/L_9));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int8_t* V_3 = NULL;
	int8_t* V_4 = NULL;
	int32_t V_5 = 0;
	uint16_t* V_6 = NULL;
	uint16_t* V_7 = NULL;
	int32_t V_8 = 0;
	int16_t* V_9 = NULL;
	int16_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint32_t* V_12 = NULL;
	uint32_t* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t* V_15 = NULL;
	int32_t* V_16 = NULL;
	int32_t V_17 = 0;
	uint64_t* V_18 = NULL;
	uint64_t* V_19 = NULL;
	int32_t V_20 = 0;
	int64_t* V_21 = NULL;
	int64_t* V_22 = NULL;
	int32_t V_23 = 0;
	float* V_24 = NULL;
	float* V_25 = NULL;
	int32_t V_26 = 0;
	double* V_27 = NULL;
	double* V_28 = NULL;
	int32_t V_29 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A));
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0386;
		}
	}
	{
		goto IL_005e;
	}

IL_005e:
	{
		goto IL_00b3;
	}

IL_00b3:
	{
		goto IL_010d;
	}

IL_010d:
	{
		goto IL_0167;
	}

IL_0167:
	{
		goto IL_01c1;
	}

IL_01c1:
	{
		goto IL_021b;
	}

IL_021b:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_2 = (uint64_t*)(&L_1->___uint64_0);
		V_19 = L_2;
		uint64_t* L_3 = V_19;
		uintptr_t L_4 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_3,NULL));
		V_18 = (uint64_t*)L_4;
		V_20 = 0;
		goto IL_0267;
	}

IL_024d:
	{
		uint64_t* L_5 = V_18;
		int32_t L_6 = V_20;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		uint64_t L_8 = ___0_value;
		il2cpp_codegen_stind<int64_t>((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 8)))), (int64_t)L_8);
		int32_t L_9 = V_20;
		V_20 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0267:
	{
		int32_t L_10 = V_20;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_024d;
		}
	}
	{
		uintptr_t L_12 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_19 = (uint64_t*)L_12;
		return;
	}

IL_0386:
	{
		goto IL_0505;
	}

IL_0505:
	{
		goto IL_0684;
	}

IL_0684:
	{
		goto IL_0753;
	}

IL_0753:
	{
		goto IL_0822;
	}

IL_0822:
	{
		goto IL_0896;
	}

IL_0896:
	{
		goto IL_090a;
	}

IL_090a:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_13 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_14 = ___0_value;
		L_13->___uint64_0 = L_14;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_16 = ___0_value;
		L_15->___uint64_1 = L_16;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		void* L_0 = ___0_dataPointer;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B(__this, L_0, 0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mB3EB022FA5067096F41350560FA447FBA16BFF2B (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	int8_t* V_4 = NULL;
	int8_t* V_5 = NULL;
	int8_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint16_t* V_8 = NULL;
	uint16_t* V_9 = NULL;
	uint16_t* V_10 = NULL;
	int32_t V_11 = 0;
	int16_t* V_12 = NULL;
	int16_t* V_13 = NULL;
	int16_t* V_14 = NULL;
	int32_t V_15 = 0;
	uint32_t* V_16 = NULL;
	uint32_t* V_17 = NULL;
	uint32_t* V_18 = NULL;
	int32_t V_19 = 0;
	int32_t* V_20 = NULL;
	int32_t* V_21 = NULL;
	int32_t* V_22 = NULL;
	int32_t V_23 = 0;
	uint64_t* V_24 = NULL;
	uint64_t* V_25 = NULL;
	uint64_t* V_26 = NULL;
	int32_t V_27 = 0;
	int64_t* V_28 = NULL;
	int64_t* V_29 = NULL;
	int64_t* V_30 = NULL;
	int32_t V_31 = 0;
	float* V_32 = NULL;
	float* V_33 = NULL;
	float* V_34 = NULL;
	int32_t V_35 = 0;
	double* V_36 = NULL;
	double* V_37 = NULL;
	double* V_38 = NULL;
	int32_t V_39 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A));
		goto IL_0053;
	}

IL_0053:
	{
		goto IL_00ae;
	}

IL_00ae:
	{
		goto IL_0112;
	}

IL_0112:
	{
		goto IL_0176;
	}

IL_0176:
	{
		goto IL_01da;
	}

IL_01da:
	{
		goto IL_023e;
	}

IL_023e:
	{
	}
	{
		void* L_0 = ___0_dataPointer;
		V_24 = (uint64_t*)L_0;
		uint64_t* L_1 = V_24;
		int32_t L_2 = ___1_offset;
		intptr_t L_3 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_2,NULL));
		V_24 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_1, ((intptr_t)il2cpp_codegen_multiply(L_3, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_4 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_5 = (uint64_t*)(&L_4->___uint64_0);
		V_26 = L_5;
		uint64_t* L_6 = V_26;
		uintptr_t L_7 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_6,NULL));
		V_25 = (uint64_t*)L_7;
		V_27 = 0;
		goto IL_0294;
	}

IL_027c:
	{
		uint64_t* L_8 = V_25;
		int32_t L_9 = V_27;
		intptr_t L_10 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_9,NULL));
		uint64_t* L_11 = V_24;
		int32_t L_12 = V_27;
		intptr_t L_13 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_12,NULL));
		int64_t L_14 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_11, ((intptr_t)il2cpp_codegen_multiply(L_13, 8))))));
		il2cpp_codegen_stind<int64_t>((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_8, ((intptr_t)il2cpp_codegen_multiply(L_10, 8)))), (int64_t)L_14);
		int32_t L_15 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_0294:
	{
		int32_t L_16 = V_27;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_17;
		L_17 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_16) < ((int32_t)L_17)))
		{
			goto IL_027c;
		}
	}
	{
		uintptr_t L_18 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_26 = (uint64_t*)L_18;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	uint8_t* V_0 = NULL;
	int8_t* V_1 = NULL;
	uint16_t* V_2 = NULL;
	int16_t* V_3 = NULL;
	uint32_t* V_4 = NULL;
	int32_t* V_5 = NULL;
	uint64_t* V_6 = NULL;
	int64_t* V_7 = NULL;
	float* V_8 = NULL;
	double* V_9 = NULL;
	{
		int32_t L_0 = ___0_index;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_000c;
		}
	}
	{
		int32_t L_2 = ___0_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}

IL_000c:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F)), L_5, NULL);
		IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* L_7 = (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var)));
		IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0022:
	{
		goto IL_0059;
	}

IL_0059:
	{
		goto IL_0090;
	}

IL_0090:
	{
		goto IL_00ca;
	}

IL_00ca:
	{
		goto IL_0104;
	}

IL_0104:
	{
		goto IL_0140;
	}

IL_0140:
	{
		goto IL_017c;
	}

IL_017c:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_8 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_9 = (uint64_t*)(&L_8->___uint64_0);
		V_6 = L_9;
		uint64_t* L_10 = V_6;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_10,NULL));
		int32_t L_12 = ___0_index;
		intptr_t L_13 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_12,NULL));
		int64_t L_14 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_11, ((intptr_t)il2cpp_codegen_multiply(L_13, 8))))));
		return L_14;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27(__this, ((*(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	int32_t V_0 = 0;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0031;
		}
	}
	{
		V_0 = 0;
		goto IL_0027;
	}

IL_000b:
	{
		int32_t L_1 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_2;
		L_2 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_3 = V_0;
		uint64_t L_4;
		L_4 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99((&___0_other), L_3, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_5;
		L_5 = Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline(L_2, L_4, NULL);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		return (bool)0;
	}

IL_0023:
	{
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0027:
	{
		int32_t L_7 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_0031:
	{
		goto IL_01f0;
	}

IL_01f0:
	{
		goto IL_03af;
	}

IL_03af:
	{
		goto IL_0496;
	}

IL_0496:
	{
		goto IL_057d;
	}

IL_057d:
	{
		goto IL_05fb;
	}

IL_05fb:
	{
		goto IL_0679;
	}

IL_0679:
	{
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_9 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_10 = L_9->___uint64_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_11 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_12 = L_11.___register;
		uint64_t L_13 = L_12.___uint64_0;
		if ((!(((uint64_t)L_10) == ((uint64_t)L_13))))
		{
			goto IL_06c5;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_14 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_15 = L_14->___uint64_1;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_16 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_17 = L_16.___register;
		uint64_t L_18 = L_17.___uint64_1;
		return (bool)((((int64_t)L_15) == ((int64_t)L_18))? 1 : 0);
	}

IL_06c5:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27_AdjustorThunk (RuntimeObject* __this, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_other, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	CHECKED_LOCAL(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint8_t V_2 = 0x0;
	int32_t V_3 = 0;
	int8_t V_4 = 0x0;
	int32_t V_5 = 0;
	uint16_t V_6 = 0;
	int32_t V_7 = 0;
	int16_t V_8 = 0;
	int32_t V_9 = 0;
	uint32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int64_t V_16 = 0;
	int32_t V_17 = 0;
	float V_18 = 0.0f;
	int32_t V_19 = 0;
	double V_20 = 0.0;
	{
		V_0 = 0;
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_034a;
		}
	}
	{
		goto IL_0059;
	}

IL_0059:
	{
		goto IL_00a7;
	}

IL_00a7:
	{
		goto IL_00fa;
	}

IL_00fa:
	{
		goto IL_014d;
	}

IL_014d:
	{
		goto IL_01a0;
	}

IL_01a0:
	{
		goto IL_01f3;
	}

IL_01f3:
	{
	}
	{
		V_13 = 0;
		goto IL_023b;
	}

IL_0213:
	{
		int32_t L_1 = V_0;
		int32_t L_2 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_3;
		L_3 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, L_2, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		V_14 = L_3;
		int32_t L_4;
		L_4 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92((&V_14), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_5;
		L_5 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_1, L_4, NULL);
		V_0 = L_5;
		int32_t L_6 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_023b:
	{
		int32_t L_7 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_0213;
		}
	}
	{
		int32_t L_9 = V_0;
		return L_9;
	}

IL_034a:
	{
		goto IL_04da;
	}

IL_04da:
	{
		goto IL_066a;
	}

IL_066a:
	{
		goto IL_0742;
	}

IL_0742:
	{
		goto IL_081a;
	}

IL_081a:
	{
		goto IL_0893;
	}

IL_0893:
	{
		goto IL_090c;
	}

IL_090c:
	{
	}
	{
		int32_t L_10 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_11 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_12 = (uint64_t*)(&L_11->___uint64_0);
		int32_t L_13;
		L_13 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_12, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_14;
		L_14 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_10, L_13, NULL);
		V_0 = L_14;
		int32_t L_15 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_16 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_17 = (uint64_t*)(&L_16->___uint64_1);
		int32_t L_18;
		L_18 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_17, NULL);
		int32_t L_19;
		L_19 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_15, L_18, NULL);
		V_0 = L_19;
		int32_t L_20 = V_0;
		return L_20;
	}
}
IL2CPP_EXTERN_C  int32_t Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	int32_t _returnValue;
	_returnValue = Vector_1_GetHashCode_mEC951E56E2DC500CF877DFAD5542E0920B73B00A(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit);
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit,(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_0;
		L_0 = CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5(NULL);
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_1;
		L_1 = Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C(__this, _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869, L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		return L_1;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m3EBF88D3E195BD2C4B0D1CCBD9F71E32233CA4F4(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		RuntimeObject* L_1 = ___1_formatProvider;
		NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* L_2;
		L_2 = NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F(L_1, NULL);
		String_t* L_3;
		L_3 = NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline(L_2, NULL);
		V_1 = L_3;
		StringBuilder_t* L_4 = V_0;
		StringBuilder_t* L_5;
		L_5 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_4, ((int32_t)60), NULL);
		V_2 = 0;
		goto IL_0053;
	}

IL_001f:
	{
		StringBuilder_t* L_6 = V_0;
		int32_t L_7 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_8;
		L_8 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, L_7, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		uint64_t L_9 = L_8;
		RuntimeObject* L_10 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_9);
		String_t* L_11 = ___0_format;
		RuntimeObject* L_12 = ___1_formatProvider;
		String_t* L_13;
		L_13 = UInt64_ToString_m779041C8FDD58BF8617838B00CD041788DB2F1A3((uint64_t*)UnBox(L_10), L_11, L_12, NULL);
		StringBuilder_t* L_14;
		L_14 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_6, L_13, NULL);
		StringBuilder_t* L_15 = V_0;
		String_t* L_16 = V_1;
		StringBuilder_t* L_17;
		L_17 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_15, L_16, NULL);
		StringBuilder_t* L_18 = V_0;
		StringBuilder_t* L_19;
		L_19 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_18, ((int32_t)32), NULL);
		int32_t L_20 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_20, 1));
	}

IL_0053:
	{
		int32_t L_21 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_22;
		L_22 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_21) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_22, 1)))))
		{
			goto IL_001f;
		}
	}
	{
		StringBuilder_t* L_23 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_24;
		L_24 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uint64_t L_25;
		L_25 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99(__this, ((int32_t)il2cpp_codegen_subtract(L_24, 1)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		uint64_t L_26 = L_25;
		RuntimeObject* L_27 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), &L_26);
		String_t* L_28 = ___0_format;
		RuntimeObject* L_29 = ___1_formatProvider;
		String_t* L_30;
		L_30 = UInt64_ToString_m779041C8FDD58BF8617838B00CD041788DB2F1A3((uint64_t*)UnBox(L_27), L_28, L_29, NULL);
		StringBuilder_t* L_31;
		L_31 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_23, L_30, NULL);
		StringBuilder_t* L_32 = V_0;
		StringBuilder_t* L_33;
		L_33 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_32, ((int32_t)62), NULL);
		StringBuilder_t* L_34 = V_0;
		String_t* L_35;
		L_35 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_34);
		return L_35;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C_AdjustorThunk (RuntimeObject* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m8F20119DB8CF7117F2D6E4D165C4A843F7D3586C(_thisAdjusted, ___0_format, ___1_formatProvider, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Inequality_m4963768CF3F7944DA5E519ADB8668431198BBC36 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ___0_left;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_Equals_m10063846A51F9D722BC0A8999A9F6B12C37988FF (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int8_t* V_2 = NULL;
	int32_t V_3 = 0;
	uint16_t* V_4 = NULL;
	int32_t V_5 = 0;
	int16_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint32_t* V_8 = NULL;
	int32_t V_9 = 0;
	int32_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint64_t* V_12 = NULL;
	int32_t V_13 = 0;
	int64_t* V_14 = NULL;
	int32_t V_15 = 0;
	float* V_16 = NULL;
	int32_t V_17 = 0;
	double* V_18 = NULL;
	int32_t V_19 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A V_20;
	memset((&V_20), 0, sizeof(V_20));
	uint64_t* G_B53_0 = NULL;
	uint64_t* G_B52_0 = NULL;
	uint64_t G_B54_0 = 0;
	uint64_t* G_B54_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B265_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B264_0 = NULL;
	uint64_t G_B266_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B266_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B268_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B267_0 = NULL;
	uint64_t G_B269_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B269_1 = NULL;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0447;
		}
	}
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_00c6;
	}

IL_00c6:
	{
		goto IL_0133;
	}

IL_0133:
	{
		goto IL_01a0;
	}

IL_01a0:
	{
		goto IL_020d;
	}

IL_020d:
	{
		goto IL_027a;
	}

IL_027a:
	{
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_1,NULL));
		if ((uintptr_t)L_2 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_3 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_2, 8));
		int8_t* L_4;
		if (L_3 == 0)
		{
			L_4 = NULL;
		}
		else
		{
			L_4 = (int8_t*)alloca(L_3);
			memset(L_4, 0, L_3);
		}
		V_12 = (uint64_t*)L_4;
		V_13 = 0;
		goto IL_02d7;
	}

IL_02a6:
	{
		uint64_t* L_5 = V_12;
		int32_t L_6 = V_13;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint64_t L_9;
		L_9 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99((&___0_left), L_8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_10 = V_13;
		uint64_t L_11;
		L_11 = Vector_1_get_Item_m685EA4A01E8AF51DC7B5F78DE0583F8FD4997C99((&___1_right), L_10, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_12;
		L_12 = Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline(L_9, L_11, NULL);
		if (L_12)
		{
			G_B53_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 8))));
			goto IL_02cb;
		}
		G_B52_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 8))));
	}
	{
		int64_t L_13 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B54_0 = ((uint64_t)(L_13));
		G_B54_1 = G_B52_0;
		goto IL_02d0;
	}

IL_02cb:
	{
		uint64_t L_14;
		L_14 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B54_0 = L_14;
		G_B54_1 = G_B53_0;
	}

IL_02d0:
	{
		il2cpp_codegen_stind<int64_t>((int64_t*)G_B54_1, (int64_t)G_B54_0);
		int32_t L_15 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_15, 1));
	}

IL_02d7:
	{
		int32_t L_16 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_17;
		L_17 = Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_16) < ((int32_t)L_17)))
		{
			goto IL_02a6;
		}
	}
	{
		uint64_t* L_18 = V_12;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_19;
		memset((&L_19), 0, sizeof(L_19));
		Vector_1__ctor_mBEC18AF78DE340D929AD22019717DE9ED57A4CCA((&L_19), (void*)L_18, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_19;
	}

IL_0447:
	{
		il2cpp_codegen_initobj((&V_20), sizeof(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A));
		goto IL_06e5;
	}

IL_06e5:
	{
		goto IL_097b;
	}

IL_097b:
	{
		goto IL_0ad9;
	}

IL_0ad9:
	{
		goto IL_0c37;
	}

IL_0c37:
	{
		goto IL_0cf9;
	}

IL_0cf9:
	{
		goto IL_0dbb;
	}

IL_0dbb:
	{
	}
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_20 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_21 = L_20.___register;
		uint64_t L_22 = L_21.___uint64_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_23 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_24 = L_23.___register;
		uint64_t L_25 = L_24.___uint64_0;
		if ((((int64_t)L_22) == ((int64_t)L_25)))
		{
			G_B265_0 = (&V_20);
			goto IL_0df4;
		}
		G_B264_0 = (&V_20);
	}
	{
		int64_t L_26 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B266_0 = ((uint64_t)(L_26));
		G_B266_1 = G_B264_0;
		goto IL_0df9;
	}

IL_0df4:
	{
		uint64_t L_27;
		L_27 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B266_0 = L_27;
		G_B266_1 = G_B265_0;
	}

IL_0df9:
	{
		G_B266_1->___uint64_0 = G_B266_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_28 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_29 = L_28.___register;
		uint64_t L_30 = L_29.___uint64_1;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_31 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_32 = L_31.___register;
		uint64_t L_33 = L_32.___uint64_1;
		if ((((int64_t)L_30) == ((int64_t)L_33)))
		{
			G_B268_0 = (&V_20);
			goto IL_0e1c;
		}
		G_B267_0 = (&V_20);
	}
	{
		int64_t L_34 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B269_0 = ((uint64_t)(L_34));
		G_B269_1 = G_B267_0;
		goto IL_0e21;
	}

IL_0e1c:
	{
		uint64_t L_35;
		L_35 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B269_0 = L_35;
		G_B269_1 = G_B268_0;
	}

IL_0e21:
	{
		G_B269_1->___uint64_1 = G_B269_0;
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_36;
		memset((&L_36), 0, sizeof(L_36));
		Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606((&L_36), (&V_20), NULL);
		return L_36;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) 
{
	{
		goto IL_0034;
	}

IL_0034:
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00d0;
	}

IL_00d0:
	{
		goto IL_0104;
	}

IL_0104:
	{
		goto IL_0138;
	}

IL_0138:
	{
	}
	{
		uint64_t L_0 = ___0_left;
		uint64_t L_1 = ___1_right;
		return (bool)((((int64_t)L_0) == ((int64_t)L_1))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288 (const RuntimeMethod* method) 
{
	{
		goto IL_0027;
	}

IL_0027:
	{
		goto IL_004e;
	}

IL_004e:
	{
		goto IL_0075;
	}

IL_0075:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00c3;
	}

IL_00c3:
	{
		goto IL_00ea;
	}

IL_00ea:
	{
	}
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0 (const RuntimeMethod* method) 
{
	{
		goto IL_002b;
	}

IL_002b:
	{
		goto IL_0056;
	}

IL_0056:
	{
		goto IL_0081;
	}

IL_0081:
	{
		goto IL_00ac;
	}

IL_00ac:
	{
		goto IL_00d7;
	}

IL_00d7:
	{
		goto IL_0102;
	}

IL_0102:
	{
	}
	{
		uint64_t L_0;
		L_0 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__cctor_m152F538F7C3F6DB8EA8C03902F8A68FF06A70109 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		int32_t L_0;
		L_0 = Vector_1_InitializeCount_mE29E088973A17B81B830C30831075135FC8E263A(NULL);
		((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count = L_0;
		il2cpp_codegen_initobj((&((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero), sizeof(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A));
		uint64_t L_1;
		L_1 = Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline(NULL);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_2;
		memset((&L_2), 0, sizeof(L_2));
		Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6((&L_2), L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_one = L_2;
		uint64_t L_3;
		L_3 = Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline(NULL);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector_1__ctor_m1B5D6A9264B4450B3C14BD8FF9430354A337F2D6((&L_4), L_3, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_allOnes = L_4;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m3432B49FF8435F45396666AA8B4724CF478EC0A1_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 Vector_1_get_Zero_m3384DC19FF560B5C07194EB2690C6AE65E910311_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_m504CE8338E1C01BCEFF3CBA1A65D3F27AB0D6E93_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	VectorSizeHelper_tAB183E4966E0B97A19A75D213EDAE51037A6BF3C V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B21_0 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B8_0 = 0;
	int32_t G_B7_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B11_0 = 0;
	int32_t G_B14_0 = 0;
	int32_t G_B13_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B15_0 = 0;
	int32_t G_B18_0 = 0;
	int32_t G_B17_0 = 0;
	int32_t G_B20_0 = 0;
	int32_t G_B19_0 = 0;
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* L_0 = (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)(&(&V_0)->____placeholder);
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&L_0->___register);
		uint8_t* L_2 = (uint8_t*)(&L_1->___byte_0);
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_2,NULL));
		V_1 = (uint8_t*)L_3;
		uint8_t* L_4 = (uint8_t*)(&(&V_0)->____byte);
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		uint8_t* L_6 = V_1;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,uint8_t*,intptr_t,false,false>(((uint8_t*)((intptr_t)((uint8_t*)il2cpp_codegen_subtract((intptr_t)L_5, (intptr_t)L_6))/1)),NULL));
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_7,NULL));
		V_2 = (-1);
		bool L_9 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_9)
		{
			G_B2_0 = L_8;
			goto IL_0045;
		}
		G_B1_0 = L_8;
	}
	{
		V_2 = 1;
		G_B21_0 = G_B1_0;
		goto IL_0176;
	}

IL_0045:
	{
		bool L_10 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_10)
		{
			G_B4_0 = G_B2_0;
			goto IL_0067;
		}
		G_B3_0 = G_B2_0;
	}
	{
		V_2 = 1;
		G_B21_0 = G_B3_0;
		goto IL_0176;
	}

IL_0067:
	{
		bool L_11 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_11)
		{
			G_B6_0 = G_B4_0;
			goto IL_0089;
		}
		G_B5_0 = G_B4_0;
	}
	{
		V_2 = 2;
		G_B21_0 = G_B5_0;
		goto IL_0176;
	}

IL_0089:
	{
		bool L_12 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			G_B8_0 = G_B6_0;
			goto IL_00ab;
		}
		G_B7_0 = G_B6_0;
	}
	{
		V_2 = 2;
		G_B21_0 = G_B7_0;
		goto IL_0176;
	}

IL_00ab:
	{
		bool L_13 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_13)
		{
			G_B10_0 = G_B8_0;
			goto IL_00cd;
		}
		G_B9_0 = G_B8_0;
	}
	{
		V_2 = 4;
		G_B21_0 = G_B9_0;
		goto IL_0176;
	}

IL_00cd:
	{
		bool L_14 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_14)
		{
			G_B12_0 = G_B10_0;
			goto IL_00ef;
		}
		G_B11_0 = G_B10_0;
	}
	{
		V_2 = 4;
		G_B21_0 = G_B11_0;
		goto IL_0176;
	}

IL_00ef:
	{
		bool L_15 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_15)
		{
			G_B14_0 = G_B12_0;
			goto IL_010e;
		}
		G_B13_0 = G_B12_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B13_0;
		goto IL_0176;
	}

IL_010e:
	{
		bool L_16 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_16)
		{
			G_B16_0 = G_B14_0;
			goto IL_012d;
		}
		G_B15_0 = G_B14_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B15_0;
		goto IL_0176;
	}

IL_012d:
	{
		bool L_17 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_17)
		{
			G_B18_0 = G_B16_0;
			goto IL_014c;
		}
		G_B17_0 = G_B16_0;
	}
	{
		V_2 = 4;
		G_B21_0 = G_B17_0;
		goto IL_0176;
	}

IL_014c:
	{
		bool L_18 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_18)
		{
			G_B20_0 = G_B18_0;
			goto IL_016b;
		}
		G_B19_0 = G_B18_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B19_0;
		goto IL_0176;
	}

IL_016b:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_19 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_0176:
	{
		int32_t L_20 = V_2;
		return ((int32_t)(G_B21_0/L_20));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_21 = L_8;
	const Il2CppFullySharedGenericStruct L_35 = L_8;
	const Il2CppFullySharedGenericStruct L_49 = L_8;
	const Il2CppFullySharedGenericStruct L_63 = L_8;
	const Il2CppFullySharedGenericStruct L_77 = L_8;
	const Il2CppFullySharedGenericStruct L_91 = L_8;
	const Il2CppFullySharedGenericStruct L_105 = L_8;
	const Il2CppFullySharedGenericStruct L_119 = L_8;
	const Il2CppFullySharedGenericStruct L_133 = L_8;
	const Il2CppFullySharedGenericStruct L_141 = L_8;
	const Il2CppFullySharedGenericStruct L_190 = L_8;
	const Il2CppFullySharedGenericStruct L_239 = L_8;
	const Il2CppFullySharedGenericStruct L_264 = L_8;
	const Il2CppFullySharedGenericStruct L_289 = L_8;
	const Il2CppFullySharedGenericStruct L_302 = L_8;
	const Il2CppFullySharedGenericStruct L_315 = L_8;
	const Il2CppFullySharedGenericStruct L_322 = L_8;
	const Il2CppFullySharedGenericStruct L_329 = L_8;
	const Il2CppFullySharedGenericStruct L_342 = L_8;
	const Il2CppFullySharedGenericStruct L_144 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_193 = L_144;
	const Il2CppFullySharedGenericStruct L_242 = L_144;
	const Il2CppFullySharedGenericStruct L_267 = L_144;
	const Il2CppFullySharedGenericStruct L_292 = L_144;
	const Il2CppFullySharedGenericStruct L_305 = L_144;
	const Il2CppFullySharedGenericStruct L_318 = L_144;
	const Il2CppFullySharedGenericStruct L_325 = L_144;
	const Il2CppFullySharedGenericStruct L_332 = L_144;
	const Il2CppFullySharedGenericStruct L_345 = L_144;
	const Il2CppFullySharedGenericStruct L_147 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_196 = L_147;
	const Il2CppFullySharedGenericStruct L_245 = L_147;
	const Il2CppFullySharedGenericStruct L_270 = L_147;
	const Il2CppFullySharedGenericStruct L_295 = L_147;
	const Il2CppFullySharedGenericStruct L_308 = L_147;
	const Il2CppFullySharedGenericStruct L_335 = L_147;
	const Il2CppFullySharedGenericStruct L_150 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_199 = L_150;
	const Il2CppFullySharedGenericStruct L_248 = L_150;
	const Il2CppFullySharedGenericStruct L_273 = L_150;
	const Il2CppFullySharedGenericStruct L_298 = L_150;
	const Il2CppFullySharedGenericStruct L_311 = L_150;
	const Il2CppFullySharedGenericStruct L_338 = L_150;
	const Il2CppFullySharedGenericStruct L_153 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_202 = L_153;
	const Il2CppFullySharedGenericStruct L_251 = L_153;
	const Il2CppFullySharedGenericStruct L_276 = L_153;
	const Il2CppFullySharedGenericStruct L_156 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_205 = L_156;
	const Il2CppFullySharedGenericStruct L_254 = L_156;
	const Il2CppFullySharedGenericStruct L_279 = L_156;
	const Il2CppFullySharedGenericStruct L_159 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_208 = L_159;
	const Il2CppFullySharedGenericStruct L_257 = L_159;
	const Il2CppFullySharedGenericStruct L_282 = L_159;
	const Il2CppFullySharedGenericStruct L_162 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_211 = L_162;
	const Il2CppFullySharedGenericStruct L_260 = L_162;
	const Il2CppFullySharedGenericStruct L_285 = L_162;
	const Il2CppFullySharedGenericStruct L_165 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_214 = L_165;
	const Il2CppFullySharedGenericStruct L_168 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_217 = L_168;
	const Il2CppFullySharedGenericStruct L_171 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_220 = L_171;
	const Il2CppFullySharedGenericStruct L_174 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_223 = L_174;
	const Il2CppFullySharedGenericStruct L_177 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_226 = L_177;
	const Il2CppFullySharedGenericStruct L_180 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_229 = L_180;
	const Il2CppFullySharedGenericStruct L_183 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_232 = L_183;
	const Il2CppFullySharedGenericStruct L_186 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_235 = L_186;
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int8_t* V_3 = NULL;
	int8_t* V_4 = NULL;
	int32_t V_5 = 0;
	uint16_t* V_6 = NULL;
	uint16_t* V_7 = NULL;
	int32_t V_8 = 0;
	int16_t* V_9 = NULL;
	int16_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint32_t* V_12 = NULL;
	uint32_t* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t* V_15 = NULL;
	int32_t* V_16 = NULL;
	int32_t V_17 = 0;
	uint64_t* V_18 = NULL;
	uint64_t* V_19 = NULL;
	int32_t V_20 = 0;
	int64_t* V_21 = NULL;
	int64_t* V_22 = NULL;
	int32_t V_23 = 0;
	float* V_24 = NULL;
	float* V_25 = NULL;
	int32_t V_26 = 0;
	double* V_27 = NULL;
	double* V_28 = NULL;
	int32_t V_29 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2));
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0386;
		}
	}
	{
		bool L_1 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_1)
		{
			goto IL_005e;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_2 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_3 = (uint8_t*)(&L_2->___byte_0);
		V_1 = L_3;
		uint8_t* L_4 = V_1;
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		V_0 = (uint8_t*)L_5;
		V_2 = 0;
		goto IL_0052;
	}

IL_003f:
	{
		uint8_t* L_6 = V_0;
		int32_t L_7 = V_2;
		il2cpp_codegen_memcpy(L_8, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_9;
		il2cpp_codegen_box_unbox(L_8, (&L_9), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int8_t>((int8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, L_7)), (int8_t)L_9);
		int32_t L_10 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0052:
	{
		int32_t L_11 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_12;
		L_12 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_11) < ((int32_t)L_12)))
		{
			goto IL_003f;
		}
	}
	{
		uintptr_t L_13 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_1 = (uint8_t*)L_13;
		return;
	}

IL_005e:
	{
		bool L_14 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_14)
		{
			goto IL_00b3;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_16 = (int8_t*)(&L_15->___sbyte_0);
		V_4 = L_16;
		int8_t* L_17 = V_4;
		uintptr_t L_18 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>(L_17,NULL));
		V_3 = (int8_t*)L_18;
		V_5 = 0;
		goto IL_00a5;
	}

IL_008f:
	{
		int8_t* L_19 = V_3;
		int32_t L_20 = V_5;
		il2cpp_codegen_memcpy(L_21, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_22;
		il2cpp_codegen_box_unbox(L_21, (&L_22), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int8_t>((int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_19, L_20)), (int8_t)L_22);
		int32_t L_23 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_25;
		L_25 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_008f;
		}
	}
	{
		uintptr_t L_26 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_4 = (int8_t*)L_26;
		return;
	}

IL_00b3:
	{
		bool L_27 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_27)
		{
			goto IL_010d;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_28 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_29 = (uint16_t*)(&L_28->___uint16_0);
		V_7 = L_29;
		uint16_t* L_30 = V_7;
		uintptr_t L_31 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_30,NULL));
		V_6 = (uint16_t*)L_31;
		V_8 = 0;
		goto IL_00ff;
	}

IL_00e5:
	{
		uint16_t* L_32 = V_6;
		int32_t L_33 = V_8;
		intptr_t L_34 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_33,NULL));
		il2cpp_codegen_memcpy(L_35, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_36;
		il2cpp_codegen_box_unbox(L_35, (&L_36), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int16_t>((int16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_32, ((intptr_t)il2cpp_codegen_multiply(L_34, 2)))), (int16_t)L_36);
		int32_t L_37 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_37, 1));
	}

IL_00ff:
	{
		int32_t L_38 = V_8;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_39;
		L_39 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_38) < ((int32_t)L_39)))
		{
			goto IL_00e5;
		}
	}
	{
		uintptr_t L_40 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_7 = (uint16_t*)L_40;
		return;
	}

IL_010d:
	{
		bool L_41 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_41)
		{
			goto IL_0167;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_42 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_43 = (int16_t*)(&L_42->___int16_0);
		V_10 = L_43;
		int16_t* L_44 = V_10;
		uintptr_t L_45 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>(L_44,NULL));
		V_9 = (int16_t*)L_45;
		V_11 = 0;
		goto IL_0159;
	}

IL_013f:
	{
		int16_t* L_46 = V_9;
		int32_t L_47 = V_11;
		intptr_t L_48 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_47,NULL));
		il2cpp_codegen_memcpy(L_49, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_50;
		il2cpp_codegen_box_unbox(L_49, (&L_50), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int16_t>((int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_46, ((intptr_t)il2cpp_codegen_multiply(L_48, 2)))), (int16_t)L_50);
		int32_t L_51 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_0159:
	{
		int32_t L_52 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_53;
		L_53 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_013f;
		}
	}
	{
		uintptr_t L_54 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_10 = (int16_t*)L_54;
		return;
	}

IL_0167:
	{
		bool L_55 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_55)
		{
			goto IL_01c1;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_56 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_57 = (uint32_t*)(&L_56->___uint32_0);
		V_13 = L_57;
		uint32_t* L_58 = V_13;
		uintptr_t L_59 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>(L_58,NULL));
		V_12 = (uint32_t*)L_59;
		V_14 = 0;
		goto IL_01b3;
	}

IL_0199:
	{
		uint32_t* L_60 = V_12;
		int32_t L_61 = V_14;
		intptr_t L_62 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_61,NULL));
		il2cpp_codegen_memcpy(L_63, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_64;
		il2cpp_codegen_box_unbox(L_63, (&L_64), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int32_t>((int32_t*)((uint32_t*)il2cpp_codegen_add((intptr_t)L_60, ((intptr_t)il2cpp_codegen_multiply(L_62, 4)))), (int32_t)L_64);
		int32_t L_65 = V_14;
		V_14 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_01b3:
	{
		int32_t L_66 = V_14;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_67;
		L_67 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0199;
		}
	}
	{
		uintptr_t L_68 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_13 = (uint32_t*)L_68;
		return;
	}

IL_01c1:
	{
		bool L_69 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_69)
		{
			goto IL_021b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_70 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_71 = (int32_t*)(&L_70->___int32_0);
		V_16 = L_71;
		int32_t* L_72 = V_16;
		uintptr_t L_73 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_72,NULL));
		V_15 = (int32_t*)L_73;
		V_17 = 0;
		goto IL_020d;
	}

IL_01f3:
	{
		int32_t* L_74 = V_15;
		int32_t L_75 = V_17;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		il2cpp_codegen_memcpy(L_77, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_78;
		il2cpp_codegen_box_unbox(L_77, (&L_78), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int32_t>((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4)))), (int32_t)L_78);
		int32_t L_79 = V_17;
		V_17 = ((int32_t)il2cpp_codegen_add(L_79, 1));
	}

IL_020d:
	{
		int32_t L_80 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_81;
		L_81 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_80) < ((int32_t)L_81)))
		{
			goto IL_01f3;
		}
	}
	{
		uintptr_t L_82 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_16 = (int32_t*)L_82;
		return;
	}

IL_021b:
	{
		bool L_83 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_83)
		{
			goto IL_0275;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_84 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_85 = (uint64_t*)(&L_84->___uint64_0);
		V_19 = L_85;
		uint64_t* L_86 = V_19;
		uintptr_t L_87 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_86,NULL));
		V_18 = (uint64_t*)L_87;
		V_20 = 0;
		goto IL_0267;
	}

IL_024d:
	{
		uint64_t* L_88 = V_18;
		int32_t L_89 = V_20;
		intptr_t L_90 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_89,NULL));
		il2cpp_codegen_memcpy(L_91, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_92;
		il2cpp_codegen_box_unbox(L_91, (&L_92), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int64_t>((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_88, ((intptr_t)il2cpp_codegen_multiply(L_90, 8)))), (int64_t)L_92);
		int32_t L_93 = V_20;
		V_20 = ((int32_t)il2cpp_codegen_add(L_93, 1));
	}

IL_0267:
	{
		int32_t L_94 = V_20;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_95;
		L_95 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_94) < ((int32_t)L_95)))
		{
			goto IL_024d;
		}
	}
	{
		uintptr_t L_96 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_19 = (uint64_t*)L_96;
		return;
	}

IL_0275:
	{
		bool L_97 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_97)
		{
			goto IL_02cf;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_98 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_99 = (int64_t*)(&L_98->___int64_0);
		V_22 = L_99;
		int64_t* L_100 = V_22;
		uintptr_t L_101 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>(L_100,NULL));
		V_21 = (int64_t*)L_101;
		V_23 = 0;
		goto IL_02c1;
	}

IL_02a7:
	{
		int64_t* L_102 = V_21;
		int32_t L_103 = V_23;
		intptr_t L_104 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_103,NULL));
		il2cpp_codegen_memcpy(L_105, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_106;
		il2cpp_codegen_box_unbox(L_105, (&L_106), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<int64_t>((int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_102, ((intptr_t)il2cpp_codegen_multiply(L_104, 8)))), (int64_t)L_106);
		int32_t L_107 = V_23;
		V_23 = ((int32_t)il2cpp_codegen_add(L_107, 1));
	}

IL_02c1:
	{
		int32_t L_108 = V_23;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_109;
		L_109 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_108) < ((int32_t)L_109)))
		{
			goto IL_02a7;
		}
	}
	{
		uintptr_t L_110 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_22 = (int64_t*)L_110;
		return;
	}

IL_02cf:
	{
		bool L_111 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_111)
		{
			goto IL_0329;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_112 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_113 = (float*)(&L_112->___single_0);
		V_25 = L_113;
		float* L_114 = V_25;
		uintptr_t L_115 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>(L_114,NULL));
		V_24 = (float*)L_115;
		V_26 = 0;
		goto IL_031b;
	}

IL_0301:
	{
		float* L_116 = V_24;
		int32_t L_117 = V_26;
		intptr_t L_118 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_117,NULL));
		il2cpp_codegen_memcpy(L_119, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_120;
		il2cpp_codegen_box_unbox(L_119, (&L_120), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<float>((float*)((float*)il2cpp_codegen_add((intptr_t)L_116, ((intptr_t)il2cpp_codegen_multiply(L_118, 4)))), (float)L_120);
		int32_t L_121 = V_26;
		V_26 = ((int32_t)il2cpp_codegen_add(L_121, 1));
	}

IL_031b:
	{
		int32_t L_122 = V_26;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_123;
		L_123 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_122) < ((int32_t)L_123)))
		{
			goto IL_0301;
		}
	}
	{
		uintptr_t L_124 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_25 = (float*)L_124;
		return;
	}

IL_0329:
	{
		bool L_125 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_125)
		{
			goto IL_0a55;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_126 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_127 = (double*)(&L_126->___double_0);
		V_28 = L_127;
		double* L_128 = V_28;
		uintptr_t L_129 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>(L_128,NULL));
		V_27 = (double*)L_129;
		V_29 = 0;
		goto IL_0378;
	}

IL_035e:
	{
		double* L_130 = V_27;
		int32_t L_131 = V_29;
		intptr_t L_132 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_131,NULL));
		il2cpp_codegen_memcpy(L_133, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_134;
		il2cpp_codegen_box_unbox(L_133, (&L_134), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		il2cpp_codegen_stind<double>((double*)((double*)il2cpp_codegen_add((intptr_t)L_130, ((intptr_t)il2cpp_codegen_multiply(L_132, 8)))), (double)L_134);
		int32_t L_135 = V_29;
		V_29 = ((int32_t)il2cpp_codegen_add(L_135, 1));
	}

IL_0378:
	{
		int32_t L_136 = V_29;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_137;
		L_137 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_136) < ((int32_t)L_137)))
		{
			goto IL_035e;
		}
	}
	{
		uintptr_t L_138 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_28 = (double*)L_138;
		return;
	}

IL_0386:
	{
		bool L_139 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_139)
		{
			goto IL_0505;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_140 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_141, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_142;
		il2cpp_codegen_box_unbox(L_141, (&L_142), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_140->___byte_0 = L_142;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_143 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_144, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_145;
		il2cpp_codegen_box_unbox(L_144, (&L_145), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_143->___byte_1 = L_145;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_146 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_147, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_148;
		il2cpp_codegen_box_unbox(L_147, (&L_148), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_146->___byte_2 = L_148;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_149 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_150, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_151;
		il2cpp_codegen_box_unbox(L_150, (&L_151), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_149->___byte_3 = L_151;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_152 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_153, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_154;
		il2cpp_codegen_box_unbox(L_153, (&L_154), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_152->___byte_4 = L_154;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_155 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_156, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_157;
		il2cpp_codegen_box_unbox(L_156, (&L_157), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_155->___byte_5 = L_157;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_158 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_159, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_160;
		il2cpp_codegen_box_unbox(L_159, (&L_160), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_158->___byte_6 = L_160;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_161 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_162, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_163;
		il2cpp_codegen_box_unbox(L_162, (&L_163), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_161->___byte_7 = L_163;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_164 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_165, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_166;
		il2cpp_codegen_box_unbox(L_165, (&L_166), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_164->___byte_8 = L_166;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_167 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_168, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_169;
		il2cpp_codegen_box_unbox(L_168, (&L_169), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_167->___byte_9 = L_169;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_170 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_171, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_172;
		il2cpp_codegen_box_unbox(L_171, (&L_172), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_170->___byte_10 = L_172;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_173 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_174, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_175;
		il2cpp_codegen_box_unbox(L_174, (&L_175), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_173->___byte_11 = L_175;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_176 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_177, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_178;
		il2cpp_codegen_box_unbox(L_177, (&L_178), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_176->___byte_12 = L_178;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_179 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_180, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_181;
		il2cpp_codegen_box_unbox(L_180, (&L_181), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_179->___byte_13 = L_181;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_182 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_183, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_184;
		il2cpp_codegen_box_unbox(L_183, (&L_184), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_182->___byte_14 = L_184;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_185 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_186, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_187;
		il2cpp_codegen_box_unbox(L_186, (&L_187), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_185->___byte_15 = L_187;
		return;
	}

IL_0505:
	{
		bool L_188 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_188)
		{
			goto IL_0684;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_189 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_190, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_191;
		il2cpp_codegen_box_unbox(L_190, (&L_191), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_189->___sbyte_0 = L_191;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_192 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_193, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_194;
		il2cpp_codegen_box_unbox(L_193, (&L_194), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_192->___sbyte_1 = L_194;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_195 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_196, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_197;
		il2cpp_codegen_box_unbox(L_196, (&L_197), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_195->___sbyte_2 = L_197;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_198 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_199, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_200;
		il2cpp_codegen_box_unbox(L_199, (&L_200), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_198->___sbyte_3 = L_200;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_201 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_202, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_203;
		il2cpp_codegen_box_unbox(L_202, (&L_203), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_201->___sbyte_4 = L_203;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_204 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_205, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_206;
		il2cpp_codegen_box_unbox(L_205, (&L_206), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_204->___sbyte_5 = L_206;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_207 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_208, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_209;
		il2cpp_codegen_box_unbox(L_208, (&L_209), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_207->___sbyte_6 = L_209;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_210 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_211, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_212;
		il2cpp_codegen_box_unbox(L_211, (&L_212), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_210->___sbyte_7 = L_212;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_213 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_214, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_215;
		il2cpp_codegen_box_unbox(L_214, (&L_215), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_213->___sbyte_8 = L_215;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_216 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_217, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_218;
		il2cpp_codegen_box_unbox(L_217, (&L_218), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_216->___sbyte_9 = L_218;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_219 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_220, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_221;
		il2cpp_codegen_box_unbox(L_220, (&L_221), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_219->___sbyte_10 = L_221;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_222 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_223, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_224;
		il2cpp_codegen_box_unbox(L_223, (&L_224), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_222->___sbyte_11 = L_224;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_225 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_226, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_227;
		il2cpp_codegen_box_unbox(L_226, (&L_227), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_225->___sbyte_12 = L_227;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_228 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_229, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_230;
		il2cpp_codegen_box_unbox(L_229, (&L_230), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_228->___sbyte_13 = L_230;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_231 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_232, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_233;
		il2cpp_codegen_box_unbox(L_232, (&L_233), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_231->___sbyte_14 = L_233;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_234 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_235, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_236;
		il2cpp_codegen_box_unbox(L_235, (&L_236), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_234->___sbyte_15 = L_236;
		return;
	}

IL_0684:
	{
		bool L_237 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_237)
		{
			goto IL_0753;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_238 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_239, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_240;
		il2cpp_codegen_box_unbox(L_239, (&L_240), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_238->___uint16_0 = L_240;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_241 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_242, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_243;
		il2cpp_codegen_box_unbox(L_242, (&L_243), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_241->___uint16_1 = L_243;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_244 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_245, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_246;
		il2cpp_codegen_box_unbox(L_245, (&L_246), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_244->___uint16_2 = L_246;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_247 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_248, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_249;
		il2cpp_codegen_box_unbox(L_248, (&L_249), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_247->___uint16_3 = L_249;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_250 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_251, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_252;
		il2cpp_codegen_box_unbox(L_251, (&L_252), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_250->___uint16_4 = L_252;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_253 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_254, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_255;
		il2cpp_codegen_box_unbox(L_254, (&L_255), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_253->___uint16_5 = L_255;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_256 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_257, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_258;
		il2cpp_codegen_box_unbox(L_257, (&L_258), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_256->___uint16_6 = L_258;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_259 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_260, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_261;
		il2cpp_codegen_box_unbox(L_260, (&L_261), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_259->___uint16_7 = L_261;
		return;
	}

IL_0753:
	{
		bool L_262 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_262)
		{
			goto IL_0822;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_263 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_264, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_265;
		il2cpp_codegen_box_unbox(L_264, (&L_265), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_263->___int16_0 = L_265;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_266 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_267, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_268;
		il2cpp_codegen_box_unbox(L_267, (&L_268), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_266->___int16_1 = L_268;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_269 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_270, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_271;
		il2cpp_codegen_box_unbox(L_270, (&L_271), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_269->___int16_2 = L_271;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_272 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_273, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_274;
		il2cpp_codegen_box_unbox(L_273, (&L_274), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_272->___int16_3 = L_274;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_275 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_276, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_277;
		il2cpp_codegen_box_unbox(L_276, (&L_277), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_275->___int16_4 = L_277;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_278 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_279, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_280;
		il2cpp_codegen_box_unbox(L_279, (&L_280), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_278->___int16_5 = L_280;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_281 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_282, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_283;
		il2cpp_codegen_box_unbox(L_282, (&L_283), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_281->___int16_6 = L_283;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_284 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_285, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_286;
		il2cpp_codegen_box_unbox(L_285, (&L_286), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_284->___int16_7 = L_286;
		return;
	}

IL_0822:
	{
		bool L_287 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_287)
		{
			goto IL_0896;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_288 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_289, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_290;
		il2cpp_codegen_box_unbox(L_289, (&L_290), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_288->___uint32_0 = L_290;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_291 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_292, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_293;
		il2cpp_codegen_box_unbox(L_292, (&L_293), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_291->___uint32_1 = L_293;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_294 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_295, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_296;
		il2cpp_codegen_box_unbox(L_295, (&L_296), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_294->___uint32_2 = L_296;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_297 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_298, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_299;
		il2cpp_codegen_box_unbox(L_298, (&L_299), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_297->___uint32_3 = L_299;
		return;
	}

IL_0896:
	{
		bool L_300 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_300)
		{
			goto IL_090a;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_301 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_302, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_303;
		il2cpp_codegen_box_unbox(L_302, (&L_303), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_301->___int32_0 = L_303;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_304 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_305, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_306;
		il2cpp_codegen_box_unbox(L_305, (&L_306), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_304->___int32_1 = L_306;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_307 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_308, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_309;
		il2cpp_codegen_box_unbox(L_308, (&L_309), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_307->___int32_2 = L_309;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_310 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_311, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_312;
		il2cpp_codegen_box_unbox(L_311, (&L_312), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_310->___int32_3 = L_312;
		return;
	}

IL_090a:
	{
		bool L_313 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_313)
		{
			goto IL_0952;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_314 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_315, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_316;
		il2cpp_codegen_box_unbox(L_315, (&L_316), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		L_314->___uint64_0 = L_316;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_317 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_318, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_319;
		il2cpp_codegen_box_unbox(L_318, (&L_319), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		L_317->___uint64_1 = L_319;
		return;
	}

IL_0952:
	{
		bool L_320 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_320)
		{
			goto IL_099a;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_321 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_322, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_323;
		il2cpp_codegen_box_unbox(L_322, (&L_323), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		L_321->___int64_0 = L_323;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_324 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_325, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_326;
		il2cpp_codegen_box_unbox(L_325, (&L_326), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		L_324->___int64_1 = L_326;
		return;
	}

IL_099a:
	{
		bool L_327 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_327)
		{
			goto IL_0a0e;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_328 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_329, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_330;
		il2cpp_codegen_box_unbox(L_329, (&L_330), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_328->___single_0 = L_330;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_331 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_332, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_333;
		il2cpp_codegen_box_unbox(L_332, (&L_333), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_331->___single_1 = L_333;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_334 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_335, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_336;
		il2cpp_codegen_box_unbox(L_335, (&L_336), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_334->___single_2 = L_336;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_337 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_338, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_339;
		il2cpp_codegen_box_unbox(L_338, (&L_339), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_337->___single_3 = L_339;
		return;
	}

IL_0a0e:
	{
		bool L_340 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_340)
		{
			goto IL_0a55;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_341 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_342, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_343;
		il2cpp_codegen_box_unbox(L_342, (&L_343), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		L_341->___double_0 = L_343;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_344 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_345, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_346;
		il2cpp_codegen_box_unbox(L_345, (&L_346), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		L_344->___double_1 = L_346;
	}

IL_0a55:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		void* L_0 = ___0_dataPointer;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, void*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))(__this, L_0, 0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mAD567DC632B01A95C6F418F1C6265F295D1EB0A9_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	int8_t* V_4 = NULL;
	int8_t* V_5 = NULL;
	int8_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint16_t* V_8 = NULL;
	uint16_t* V_9 = NULL;
	uint16_t* V_10 = NULL;
	int32_t V_11 = 0;
	int16_t* V_12 = NULL;
	int16_t* V_13 = NULL;
	int16_t* V_14 = NULL;
	int32_t V_15 = 0;
	uint32_t* V_16 = NULL;
	uint32_t* V_17 = NULL;
	uint32_t* V_18 = NULL;
	int32_t V_19 = 0;
	int32_t* V_20 = NULL;
	int32_t* V_21 = NULL;
	int32_t* V_22 = NULL;
	int32_t V_23 = 0;
	uint64_t* V_24 = NULL;
	uint64_t* V_25 = NULL;
	uint64_t* V_26 = NULL;
	int32_t V_27 = 0;
	int64_t* V_28 = NULL;
	int64_t* V_29 = NULL;
	int64_t* V_30 = NULL;
	int32_t V_31 = 0;
	float* V_32 = NULL;
	float* V_33 = NULL;
	float* V_34 = NULL;
	int32_t V_35 = 0;
	double* V_36 = NULL;
	double* V_37 = NULL;
	double* V_38 = NULL;
	int32_t V_39 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2));
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_0053;
		}
	}
	{
		void* L_1 = ___0_dataPointer;
		V_0 = (uint8_t*)L_1;
		uint8_t* L_2 = V_0;
		int32_t L_3 = ___1_offset;
		V_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_2, L_3));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_4 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_5 = (uint8_t*)(&L_4->___byte_0);
		V_2 = L_5;
		uint8_t* L_6 = V_2;
		uintptr_t L_7 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_6,NULL));
		V_1 = (uint8_t*)L_7;
		V_3 = 0;
		goto IL_0047;
	}

IL_003b:
	{
		uint8_t* L_8 = V_1;
		int32_t L_9 = V_3;
		uint8_t* L_10 = V_0;
		int32_t L_11 = V_3;
		int32_t L_12 = il2cpp_codegen_ldind<int32_t, uint8_t>(((uint8_t*)il2cpp_codegen_add((intptr_t)L_10, L_11)));
		il2cpp_codegen_stind<int8_t>((int8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_8, L_9)), (int8_t)L_12);
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0047:
	{
		int32_t L_14 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_15;
		L_15 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_003b;
		}
	}
	{
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_2 = (uint8_t*)L_16;
		return;
	}

IL_0053:
	{
		bool L_17 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_17)
		{
			goto IL_00ae;
		}
	}
	{
		void* L_18 = ___0_dataPointer;
		V_4 = (int8_t*)L_18;
		int8_t* L_19 = V_4;
		int32_t L_20 = ___1_offset;
		V_4 = ((int8_t*)il2cpp_codegen_add((intptr_t)L_19, L_20));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_21 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_22 = (int8_t*)(&L_21->___sbyte_0);
		V_6 = L_22;
		int8_t* L_23 = V_6;
		uintptr_t L_24 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>(L_23,NULL));
		V_5 = (int8_t*)L_24;
		V_7 = 0;
		goto IL_00a0;
	}

IL_008e:
	{
		int8_t* L_25 = V_5;
		int32_t L_26 = V_7;
		int8_t* L_27 = V_4;
		int32_t L_28 = V_7;
		int32_t L_29 = il2cpp_codegen_ldind<int32_t, int8_t>(((int8_t*)il2cpp_codegen_add((intptr_t)L_27, L_28)));
		il2cpp_codegen_stind<int8_t>((int8_t*)((int8_t*)il2cpp_codegen_add((intptr_t)L_25, L_26)), (int8_t)L_29);
		int32_t L_30 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00a0:
	{
		int32_t L_31 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_32;
		L_32 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_008e;
		}
	}
	{
		uintptr_t L_33 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_6 = (int8_t*)L_33;
		return;
	}

IL_00ae:
	{
		bool L_34 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_34)
		{
			goto IL_0112;
		}
	}
	{
		void* L_35 = ___0_dataPointer;
		V_8 = (uint16_t*)L_35;
		uint16_t* L_36 = V_8;
		int32_t L_37 = ___1_offset;
		intptr_t L_38 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_37,NULL));
		V_8 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_36, ((intptr_t)il2cpp_codegen_multiply(L_38, 2))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_39 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_40 = (uint16_t*)(&L_39->___uint16_0);
		V_10 = L_40;
		uint16_t* L_41 = V_10;
		uintptr_t L_42 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_41,NULL));
		V_9 = (uint16_t*)L_42;
		V_11 = 0;
		goto IL_0104;
	}

IL_00ec:
	{
		uint16_t* L_43 = V_9;
		int32_t L_44 = V_11;
		intptr_t L_45 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_44,NULL));
		uint16_t* L_46 = V_8;
		int32_t L_47 = V_11;
		intptr_t L_48 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_47,NULL));
		int32_t L_49 = il2cpp_codegen_ldind<int32_t, uint16_t>(((uint16_t*)il2cpp_codegen_add((intptr_t)L_46, ((intptr_t)il2cpp_codegen_multiply(L_48, 2)))));
		il2cpp_codegen_stind<int16_t>((int16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_43, ((intptr_t)il2cpp_codegen_multiply(L_45, 2)))), (int16_t)L_49);
		int32_t L_50 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_50, 1));
	}

IL_0104:
	{
		int32_t L_51 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_52;
		L_52 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_51) < ((int32_t)L_52)))
		{
			goto IL_00ec;
		}
	}
	{
		uintptr_t L_53 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_10 = (uint16_t*)L_53;
		return;
	}

IL_0112:
	{
		bool L_54 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_54)
		{
			goto IL_0176;
		}
	}
	{
		void* L_55 = ___0_dataPointer;
		V_12 = (int16_t*)L_55;
		int16_t* L_56 = V_12;
		int32_t L_57 = ___1_offset;
		intptr_t L_58 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_57,NULL));
		V_12 = ((int16_t*)il2cpp_codegen_add((intptr_t)L_56, ((intptr_t)il2cpp_codegen_multiply(L_58, 2))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_59 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_60 = (int16_t*)(&L_59->___int16_0);
		V_14 = L_60;
		int16_t* L_61 = V_14;
		uintptr_t L_62 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>(L_61,NULL));
		V_13 = (int16_t*)L_62;
		V_15 = 0;
		goto IL_0168;
	}

IL_0150:
	{
		int16_t* L_63 = V_13;
		int32_t L_64 = V_15;
		intptr_t L_65 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_64,NULL));
		int16_t* L_66 = V_12;
		int32_t L_67 = V_15;
		intptr_t L_68 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_67,NULL));
		int32_t L_69 = il2cpp_codegen_ldind<int32_t, int16_t>(((int16_t*)il2cpp_codegen_add((intptr_t)L_66, ((intptr_t)il2cpp_codegen_multiply(L_68, 2)))));
		il2cpp_codegen_stind<int16_t>((int16_t*)((int16_t*)il2cpp_codegen_add((intptr_t)L_63, ((intptr_t)il2cpp_codegen_multiply(L_65, 2)))), (int16_t)L_69);
		int32_t L_70 = V_15;
		V_15 = ((int32_t)il2cpp_codegen_add(L_70, 1));
	}

IL_0168:
	{
		int32_t L_71 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_72;
		L_72 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_71) < ((int32_t)L_72)))
		{
			goto IL_0150;
		}
	}
	{
		uintptr_t L_73 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_14 = (int16_t*)L_73;
		return;
	}

IL_0176:
	{
		bool L_74 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_74)
		{
			goto IL_01da;
		}
	}
	{
		void* L_75 = ___0_dataPointer;
		V_16 = (uint32_t*)L_75;
		uint32_t* L_76 = V_16;
		int32_t L_77 = ___1_offset;
		intptr_t L_78 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_77,NULL));
		V_16 = ((uint32_t*)il2cpp_codegen_add((intptr_t)L_76, ((intptr_t)il2cpp_codegen_multiply(L_78, 4))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_79 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_80 = (uint32_t*)(&L_79->___uint32_0);
		V_18 = L_80;
		uint32_t* L_81 = V_18;
		uintptr_t L_82 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>(L_81,NULL));
		V_17 = (uint32_t*)L_82;
		V_19 = 0;
		goto IL_01cc;
	}

IL_01b4:
	{
		uint32_t* L_83 = V_17;
		int32_t L_84 = V_19;
		intptr_t L_85 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_84,NULL));
		uint32_t* L_86 = V_16;
		int32_t L_87 = V_19;
		intptr_t L_88 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_87,NULL));
		int32_t L_89 = il2cpp_codegen_ldind<int32_t, uint32_t>(((uint32_t*)il2cpp_codegen_add((intptr_t)L_86, ((intptr_t)il2cpp_codegen_multiply(L_88, 4)))));
		il2cpp_codegen_stind<int32_t>((int32_t*)((uint32_t*)il2cpp_codegen_add((intptr_t)L_83, ((intptr_t)il2cpp_codegen_multiply(L_85, 4)))), (int32_t)L_89);
		int32_t L_90 = V_19;
		V_19 = ((int32_t)il2cpp_codegen_add(L_90, 1));
	}

IL_01cc:
	{
		int32_t L_91 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_92;
		L_92 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_91) < ((int32_t)L_92)))
		{
			goto IL_01b4;
		}
	}
	{
		uintptr_t L_93 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_18 = (uint32_t*)L_93;
		return;
	}

IL_01da:
	{
		bool L_94 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_94)
		{
			goto IL_023e;
		}
	}
	{
		void* L_95 = ___0_dataPointer;
		V_20 = (int32_t*)L_95;
		int32_t* L_96 = V_20;
		int32_t L_97 = ___1_offset;
		intptr_t L_98 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_97,NULL));
		V_20 = ((int32_t*)il2cpp_codegen_add((intptr_t)L_96, ((intptr_t)il2cpp_codegen_multiply(L_98, 4))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_99 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_100 = (int32_t*)(&L_99->___int32_0);
		V_22 = L_100;
		int32_t* L_101 = V_22;
		uintptr_t L_102 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_101,NULL));
		V_21 = (int32_t*)L_102;
		V_23 = 0;
		goto IL_0230;
	}

IL_0218:
	{
		int32_t* L_103 = V_21;
		int32_t L_104 = V_23;
		intptr_t L_105 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_104,NULL));
		int32_t* L_106 = V_20;
		int32_t L_107 = V_23;
		intptr_t L_108 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_107,NULL));
		int32_t L_109 = il2cpp_codegen_ldind<int32_t, int32_t>(((int32_t*)il2cpp_codegen_add((intptr_t)L_106, ((intptr_t)il2cpp_codegen_multiply(L_108, 4)))));
		il2cpp_codegen_stind<int32_t>((int32_t*)((int32_t*)il2cpp_codegen_add((intptr_t)L_103, ((intptr_t)il2cpp_codegen_multiply(L_105, 4)))), (int32_t)L_109);
		int32_t L_110 = V_23;
		V_23 = ((int32_t)il2cpp_codegen_add(L_110, 1));
	}

IL_0230:
	{
		int32_t L_111 = V_23;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_112;
		L_112 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_111) < ((int32_t)L_112)))
		{
			goto IL_0218;
		}
	}
	{
		uintptr_t L_113 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_22 = (int32_t*)L_113;
		return;
	}

IL_023e:
	{
		bool L_114 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_114)
		{
			goto IL_02a2;
		}
	}
	{
		void* L_115 = ___0_dataPointer;
		V_24 = (uint64_t*)L_115;
		uint64_t* L_116 = V_24;
		int32_t L_117 = ___1_offset;
		intptr_t L_118 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_117,NULL));
		V_24 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_116, ((intptr_t)il2cpp_codegen_multiply(L_118, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_119 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_120 = (uint64_t*)(&L_119->___uint64_0);
		V_26 = L_120;
		uint64_t* L_121 = V_26;
		uintptr_t L_122 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_121,NULL));
		V_25 = (uint64_t*)L_122;
		V_27 = 0;
		goto IL_0294;
	}

IL_027c:
	{
		uint64_t* L_123 = V_25;
		int32_t L_124 = V_27;
		intptr_t L_125 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_124,NULL));
		uint64_t* L_126 = V_24;
		int32_t L_127 = V_27;
		intptr_t L_128 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_127,NULL));
		int64_t L_129 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_126, ((intptr_t)il2cpp_codegen_multiply(L_128, 8))))));
		il2cpp_codegen_stind<int64_t>((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_123, ((intptr_t)il2cpp_codegen_multiply(L_125, 8)))), (int64_t)L_129);
		int32_t L_130 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_130, 1));
	}

IL_0294:
	{
		int32_t L_131 = V_27;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_132;
		L_132 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_131) < ((int32_t)L_132)))
		{
			goto IL_027c;
		}
	}
	{
		uintptr_t L_133 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_26 = (uint64_t*)L_133;
		return;
	}

IL_02a2:
	{
		bool L_134 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_134)
		{
			goto IL_0306;
		}
	}
	{
		void* L_135 = ___0_dataPointer;
		V_28 = (int64_t*)L_135;
		int64_t* L_136 = V_28;
		int32_t L_137 = ___1_offset;
		intptr_t L_138 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_137,NULL));
		V_28 = ((int64_t*)il2cpp_codegen_add((intptr_t)L_136, ((intptr_t)il2cpp_codegen_multiply(L_138, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_139 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_140 = (int64_t*)(&L_139->___int64_0);
		V_30 = L_140;
		int64_t* L_141 = V_30;
		uintptr_t L_142 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>(L_141,NULL));
		V_29 = (int64_t*)L_142;
		V_31 = 0;
		goto IL_02f8;
	}

IL_02e0:
	{
		int64_t* L_143 = V_29;
		int32_t L_144 = V_31;
		intptr_t L_145 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_144,NULL));
		int64_t* L_146 = V_28;
		int32_t L_147 = V_31;
		intptr_t L_148 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_147,NULL));
		int64_t L_149 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)il2cpp_codegen_add((intptr_t)L_146, ((intptr_t)il2cpp_codegen_multiply(L_148, 8)))));
		il2cpp_codegen_stind<int64_t>((int64_t*)((int64_t*)il2cpp_codegen_add((intptr_t)L_143, ((intptr_t)il2cpp_codegen_multiply(L_145, 8)))), (int64_t)L_149);
		int32_t L_150 = V_31;
		V_31 = ((int32_t)il2cpp_codegen_add(L_150, 1));
	}

IL_02f8:
	{
		int32_t L_151 = V_31;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_152;
		L_152 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_151) < ((int32_t)L_152)))
		{
			goto IL_02e0;
		}
	}
	{
		uintptr_t L_153 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_30 = (int64_t*)L_153;
		return;
	}

IL_0306:
	{
		bool L_154 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_154)
		{
			goto IL_036a;
		}
	}
	{
		void* L_155 = ___0_dataPointer;
		V_32 = (float*)L_155;
		float* L_156 = V_32;
		int32_t L_157 = ___1_offset;
		intptr_t L_158 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_157,NULL));
		V_32 = ((float*)il2cpp_codegen_add((intptr_t)L_156, ((intptr_t)il2cpp_codegen_multiply(L_158, 4))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_159 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_160 = (float*)(&L_159->___single_0);
		V_34 = L_160;
		float* L_161 = V_34;
		uintptr_t L_162 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>(L_161,NULL));
		V_33 = (float*)L_162;
		V_35 = 0;
		goto IL_035c;
	}

IL_0344:
	{
		float* L_163 = V_33;
		int32_t L_164 = V_35;
		intptr_t L_165 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_164,NULL));
		float* L_166 = V_32;
		int32_t L_167 = V_35;
		intptr_t L_168 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_167,NULL));
		float L_169 = il2cpp_codegen_ldind<float, float>(((float*)il2cpp_codegen_add((intptr_t)L_166, ((intptr_t)il2cpp_codegen_multiply(L_168, 4)))));
		il2cpp_codegen_stind<float>((float*)((float*)il2cpp_codegen_add((intptr_t)L_163, ((intptr_t)il2cpp_codegen_multiply(L_165, 4)))), (float)L_169);
		int32_t L_170 = V_35;
		V_35 = ((int32_t)il2cpp_codegen_add(L_170, 1));
	}

IL_035c:
	{
		int32_t L_171 = V_35;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_172;
		L_172 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_171) < ((int32_t)L_172)))
		{
			goto IL_0344;
		}
	}
	{
		uintptr_t L_173 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_34 = (float*)L_173;
		return;
	}

IL_036a:
	{
		bool L_174 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_174)
		{
			goto IL_03ce;
		}
	}
	{
		void* L_175 = ___0_dataPointer;
		V_36 = (double*)L_175;
		double* L_176 = V_36;
		int32_t L_177 = ___1_offset;
		intptr_t L_178 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_177,NULL));
		V_36 = ((double*)il2cpp_codegen_add((intptr_t)L_176, ((intptr_t)il2cpp_codegen_multiply(L_178, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_179 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_180 = (double*)(&L_179->___double_0);
		V_38 = L_180;
		double* L_181 = V_38;
		uintptr_t L_182 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>(L_181,NULL));
		V_37 = (double*)L_182;
		V_39 = 0;
		goto IL_03c0;
	}

IL_03a8:
	{
		double* L_183 = V_37;
		int32_t L_184 = V_39;
		intptr_t L_185 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_184,NULL));
		double* L_186 = V_36;
		int32_t L_187 = V_39;
		intptr_t L_188 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_187,NULL));
		double L_189 = il2cpp_codegen_ldind<double, double>(((double*)il2cpp_codegen_add((intptr_t)L_186, ((intptr_t)il2cpp_codegen_multiply(L_188, 8)))));
		il2cpp_codegen_stind<double>((double*)((double*)il2cpp_codegen_add((intptr_t)L_183, ((intptr_t)il2cpp_codegen_multiply(L_185, 8)))), (double)L_189);
		int32_t L_190 = V_39;
		V_39 = ((int32_t)il2cpp_codegen_add(L_190, 1));
	}

IL_03c0:
	{
		int32_t L_191 = V_39;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_192;
		L_192 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_191) < ((int32_t)L_192)))
		{
			goto IL_03a8;
		}
	}
	{
		uintptr_t L_193 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_38 = (double*)L_193;
		return;
	}

IL_03ce:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_194 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_194, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_194, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method) 
{
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_0 = ___0_existingRegister;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_1 = (*(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)L_0);
		__this->___register = L_1;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1_get_Item_m301D7183D2063DC97710DCD2CEF970E7A67EB21C_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, int32_t ___0_index, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_16 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_25 = L_16;
	const Il2CppFullySharedGenericStruct L_35 = L_16;
	const Il2CppFullySharedGenericStruct L_45 = L_16;
	const Il2CppFullySharedGenericStruct L_55 = L_16;
	const Il2CppFullySharedGenericStruct L_65 = L_16;
	const Il2CppFullySharedGenericStruct L_75 = L_16;
	const Il2CppFullySharedGenericStruct L_85 = L_16;
	const Il2CppFullySharedGenericStruct L_95 = L_16;
	const Il2CppFullySharedGenericStruct L_105 = L_16;
	uint8_t* V_0 = NULL;
	int8_t* V_1 = NULL;
	uint16_t* V_2 = NULL;
	int16_t* V_3 = NULL;
	uint32_t* V_4 = NULL;
	int32_t* V_5 = NULL;
	uint64_t* V_6 = NULL;
	int64_t* V_7 = NULL;
	float* V_8 = NULL;
	double* V_9 = NULL;
	{
		int32_t L_0 = ___0_index;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_000c;
		}
	}
	{
		int32_t L_2 = ___0_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}

IL_000c:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F)), L_5, NULL);
		IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* L_7 = (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var)));
		IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0022:
	{
		bool L_8 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_8)
		{
			goto IL_0059;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_9 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_10 = (uint8_t*)(&L_9->___byte_0);
		V_0 = L_10;
		uint8_t* L_11 = V_0;
		uintptr_t L_12 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_11,NULL));
		int32_t L_13 = ___0_index;
		int32_t L_14 = il2cpp_codegen_ldind<int32_t, uint8_t>(((uint8_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_12, L_13))));
		uint8_t L_15 = L_14;
		il2cpp_codegen_box_unbox((&L_15), L_16, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_16, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0059:
	{
		bool L_17 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_17)
		{
			goto IL_0090;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_18 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_19 = (int8_t*)(&L_18->___sbyte_0);
		V_1 = L_19;
		int8_t* L_20 = V_1;
		uintptr_t L_21 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>(L_20,NULL));
		int32_t L_22 = ___0_index;
		int32_t L_23 = il2cpp_codegen_ldind<int32_t, int8_t>(((int8_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_21, L_22))));
		int8_t L_24 = L_23;
		il2cpp_codegen_box_unbox((&L_24), L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0090:
	{
		bool L_26 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_26)
		{
			goto IL_00ca;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_27 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_28 = (uint16_t*)(&L_27->___uint16_0);
		V_2 = L_28;
		uint16_t* L_29 = V_2;
		uintptr_t L_30 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_29,NULL));
		int32_t L_31 = ___0_index;
		intptr_t L_32 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_31,NULL));
		int32_t L_33 = il2cpp_codegen_ldind<int32_t, uint16_t>(((uint16_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_30, ((intptr_t)il2cpp_codegen_multiply(L_32, 2))))));
		uint16_t L_34 = L_33;
		il2cpp_codegen_box_unbox((&L_34), L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00ca:
	{
		bool L_36 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_36)
		{
			goto IL_0104;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_37 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_38 = (int16_t*)(&L_37->___int16_0);
		V_3 = L_38;
		int16_t* L_39 = V_3;
		uintptr_t L_40 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>(L_39,NULL));
		int32_t L_41 = ___0_index;
		intptr_t L_42 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_41,NULL));
		int32_t L_43 = il2cpp_codegen_ldind<int32_t, int16_t>(((int16_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_40, ((intptr_t)il2cpp_codegen_multiply(L_42, 2))))));
		int16_t L_44 = L_43;
		il2cpp_codegen_box_unbox((&L_44), L_45, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_45, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0104:
	{
		bool L_46 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_46)
		{
			goto IL_0140;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_47 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_48 = (uint32_t*)(&L_47->___uint32_0);
		V_4 = L_48;
		uint32_t* L_49 = V_4;
		uintptr_t L_50 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>(L_49,NULL));
		int32_t L_51 = ___0_index;
		intptr_t L_52 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_51,NULL));
		int32_t L_53 = il2cpp_codegen_ldind<int32_t, uint32_t>(((uint32_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_50, ((intptr_t)il2cpp_codegen_multiply(L_52, 4))))));
		uint32_t L_54 = L_53;
		il2cpp_codegen_box_unbox((&L_54), L_55, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_55, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0140:
	{
		bool L_56 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_56)
		{
			goto IL_017c;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_57 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_58 = (int32_t*)(&L_57->___int32_0);
		V_5 = L_58;
		int32_t* L_59 = V_5;
		uintptr_t L_60 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_59,NULL));
		int32_t L_61 = ___0_index;
		intptr_t L_62 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_61,NULL));
		int32_t L_63 = il2cpp_codegen_ldind<int32_t, int32_t>(((int32_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_60, ((intptr_t)il2cpp_codegen_multiply(L_62, 4))))));
		int32_t L_64 = L_63;
		il2cpp_codegen_box_unbox((&L_64), L_65, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_65, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_017c:
	{
		bool L_66 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_66)
		{
			goto IL_01b8;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_67 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_68 = (uint64_t*)(&L_67->___uint64_0);
		V_6 = L_68;
		uint64_t* L_69 = V_6;
		uintptr_t L_70 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_69,NULL));
		int32_t L_71 = ___0_index;
		intptr_t L_72 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_71,NULL));
		int64_t L_73 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_70, ((intptr_t)il2cpp_codegen_multiply(L_72, 8))))));
		uint64_t L_74 = L_73;
		il2cpp_codegen_box_unbox((&L_74), L_75, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_75, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_01b8:
	{
		bool L_76 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_76)
		{
			goto IL_01f4;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_77 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_78 = (int64_t*)(&L_77->___int64_0);
		V_7 = L_78;
		int64_t* L_79 = V_7;
		uintptr_t L_80 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>(L_79,NULL));
		int32_t L_81 = ___0_index;
		intptr_t L_82 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_81,NULL));
		int64_t L_83 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_80, ((intptr_t)il2cpp_codegen_multiply(L_82, 8))))));
		int64_t L_84 = L_83;
		il2cpp_codegen_box_unbox((&L_84), L_85, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_85, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_01f4:
	{
		bool L_86 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_86)
		{
			goto IL_0230;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_87 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_88 = (float*)(&L_87->___single_0);
		V_8 = L_88;
		float* L_89 = V_8;
		uintptr_t L_90 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>(L_89,NULL));
		int32_t L_91 = ___0_index;
		intptr_t L_92 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_91,NULL));
		float L_93 = il2cpp_codegen_ldind<float, float>(((float*)((intptr_t)il2cpp_codegen_add((intptr_t)L_90, ((intptr_t)il2cpp_codegen_multiply(L_92, 4))))));
		float L_94 = L_93;
		il2cpp_codegen_box_unbox((&L_94), L_95, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_95, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0230:
	{
		bool L_96 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_96)
		{
			goto IL_026c;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_97 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_98 = (double*)(&L_97->___double_0);
		V_9 = L_98;
		double* L_99 = V_9;
		uintptr_t L_100 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>(L_99,NULL));
		int32_t L_101 = ___0_index;
		intptr_t L_102 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_101,NULL));
		double L_103 = il2cpp_codegen_ldind<double, double>(((double*)((intptr_t)il2cpp_codegen_add((intptr_t)L_100, ((intptr_t)il2cpp_codegen_multiply(L_102, 8))))));
		double L_104 = L_103;
		il2cpp_codegen_box_unbox((&L_104), L_105, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_105, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_026c:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_106 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_106, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_106, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))(__this, ((*(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_inline(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	int32_t V_0 = 0;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0031;
		}
	}
	{
		V_0 = 0;
		goto IL_0027;
	}

IL_000b:
	{
		int32_t L_1 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_1, (Il2CppFullySharedGenericStruct*)L_2);
		int32_t L_3 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_other), L_3, (Il2CppFullySharedGenericStruct*)L_4);
		bool L_5;
		L_5 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_2, L_4);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		return (bool)0;
	}

IL_0023:
	{
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0027:
	{
		int32_t L_7 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_0031:
	{
		bool L_9 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_9)
		{
			goto IL_01f0;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_10 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_11 = L_10->___byte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_12 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_13 = L_12.___register;
		uint8_t L_14 = L_13.___byte_0;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_14))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_16 = L_15->___byte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_17 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_18 = L_17.___register;
		uint8_t L_19 = L_18.___byte_1;
		if ((!(((uint32_t)L_16) == ((uint32_t)L_19))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_20 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_21 = L_20->___byte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_22 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_23 = L_22.___register;
		uint8_t L_24 = L_23.___byte_2;
		if ((!(((uint32_t)L_21) == ((uint32_t)L_24))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_25 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_26 = L_25->___byte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_27 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_28 = L_27.___register;
		uint8_t L_29 = L_28.___byte_3;
		if ((!(((uint32_t)L_26) == ((uint32_t)L_29))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_30 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_31 = L_30->___byte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_32 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_33 = L_32.___register;
		uint8_t L_34 = L_33.___byte_4;
		if ((!(((uint32_t)L_31) == ((uint32_t)L_34))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_35 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_36 = L_35->___byte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_37 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_38 = L_37.___register;
		uint8_t L_39 = L_38.___byte_5;
		if ((!(((uint32_t)L_36) == ((uint32_t)L_39))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_40 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_41 = L_40->___byte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_42 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_43 = L_42.___register;
		uint8_t L_44 = L_43.___byte_6;
		if ((!(((uint32_t)L_41) == ((uint32_t)L_44))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_45 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_46 = L_45->___byte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_47 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_48 = L_47.___register;
		uint8_t L_49 = L_48.___byte_7;
		if ((!(((uint32_t)L_46) == ((uint32_t)L_49))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_50 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_51 = L_50->___byte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_52 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_53 = L_52.___register;
		uint8_t L_54 = L_53.___byte_8;
		if ((!(((uint32_t)L_51) == ((uint32_t)L_54))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_55 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_56 = L_55->___byte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_57 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_58 = L_57.___register;
		uint8_t L_59 = L_58.___byte_9;
		if ((!(((uint32_t)L_56) == ((uint32_t)L_59))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_60 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_61 = L_60->___byte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_62 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_63 = L_62.___register;
		uint8_t L_64 = L_63.___byte_10;
		if ((!(((uint32_t)L_61) == ((uint32_t)L_64))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_65 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_66 = L_65->___byte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_67 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_68 = L_67.___register;
		uint8_t L_69 = L_68.___byte_11;
		if ((!(((uint32_t)L_66) == ((uint32_t)L_69))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_70 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_71 = L_70->___byte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_72 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_73 = L_72.___register;
		uint8_t L_74 = L_73.___byte_12;
		if ((!(((uint32_t)L_71) == ((uint32_t)L_74))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_75 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_76 = L_75->___byte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_77 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_78 = L_77.___register;
		uint8_t L_79 = L_78.___byte_13;
		if ((!(((uint32_t)L_76) == ((uint32_t)L_79))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_80 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_81 = L_80->___byte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_82 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_83 = L_82.___register;
		uint8_t L_84 = L_83.___byte_14;
		if ((!(((uint32_t)L_81) == ((uint32_t)L_84))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_85 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_86 = L_85->___byte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_87 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_88 = L_87.___register;
		uint8_t L_89 = L_88.___byte_15;
		return (bool)((((int32_t)L_86) == ((int32_t)L_89))? 1 : 0);
	}

IL_01ee:
	{
		return (bool)0;
	}

IL_01f0:
	{
		bool L_90 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_90)
		{
			goto IL_03af;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_91 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_92 = L_91->___sbyte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_93 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_94 = L_93.___register;
		int8_t L_95 = L_94.___sbyte_0;
		if ((!(((uint32_t)L_92) == ((uint32_t)L_95))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_96 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_97 = L_96->___sbyte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_98 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_99 = L_98.___register;
		int8_t L_100 = L_99.___sbyte_1;
		if ((!(((uint32_t)L_97) == ((uint32_t)L_100))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_101 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_102 = L_101->___sbyte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_103 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_104 = L_103.___register;
		int8_t L_105 = L_104.___sbyte_2;
		if ((!(((uint32_t)L_102) == ((uint32_t)L_105))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_106 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_107 = L_106->___sbyte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_108 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_109 = L_108.___register;
		int8_t L_110 = L_109.___sbyte_3;
		if ((!(((uint32_t)L_107) == ((uint32_t)L_110))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_111 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_112 = L_111->___sbyte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_113 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_114 = L_113.___register;
		int8_t L_115 = L_114.___sbyte_4;
		if ((!(((uint32_t)L_112) == ((uint32_t)L_115))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_116 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_117 = L_116->___sbyte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_118 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_119 = L_118.___register;
		int8_t L_120 = L_119.___sbyte_5;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_120))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_121 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_122 = L_121->___sbyte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_123 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_124 = L_123.___register;
		int8_t L_125 = L_124.___sbyte_6;
		if ((!(((uint32_t)L_122) == ((uint32_t)L_125))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_126 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_127 = L_126->___sbyte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_128 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_129 = L_128.___register;
		int8_t L_130 = L_129.___sbyte_7;
		if ((!(((uint32_t)L_127) == ((uint32_t)L_130))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_131 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_132 = L_131->___sbyte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_133 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_134 = L_133.___register;
		int8_t L_135 = L_134.___sbyte_8;
		if ((!(((uint32_t)L_132) == ((uint32_t)L_135))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_136 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_137 = L_136->___sbyte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_138 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_139 = L_138.___register;
		int8_t L_140 = L_139.___sbyte_9;
		if ((!(((uint32_t)L_137) == ((uint32_t)L_140))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_141 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_142 = L_141->___sbyte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_143 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_144 = L_143.___register;
		int8_t L_145 = L_144.___sbyte_10;
		if ((!(((uint32_t)L_142) == ((uint32_t)L_145))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_146 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_147 = L_146->___sbyte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_148 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_149 = L_148.___register;
		int8_t L_150 = L_149.___sbyte_11;
		if ((!(((uint32_t)L_147) == ((uint32_t)L_150))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_151 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_152 = L_151->___sbyte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_153 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_154 = L_153.___register;
		int8_t L_155 = L_154.___sbyte_12;
		if ((!(((uint32_t)L_152) == ((uint32_t)L_155))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_156 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_157 = L_156->___sbyte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_158 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_159 = L_158.___register;
		int8_t L_160 = L_159.___sbyte_13;
		if ((!(((uint32_t)L_157) == ((uint32_t)L_160))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_161 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_162 = L_161->___sbyte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_163 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_164 = L_163.___register;
		int8_t L_165 = L_164.___sbyte_14;
		if ((!(((uint32_t)L_162) == ((uint32_t)L_165))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_166 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_167 = L_166->___sbyte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_168 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_169 = L_168.___register;
		int8_t L_170 = L_169.___sbyte_15;
		return (bool)((((int32_t)L_167) == ((int32_t)L_170))? 1 : 0);
	}

IL_03ad:
	{
		return (bool)0;
	}

IL_03af:
	{
		bool L_171 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_171)
		{
			goto IL_0496;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_172 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_173 = L_172->___uint16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_174 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_175 = L_174.___register;
		uint16_t L_176 = L_175.___uint16_0;
		if ((!(((uint32_t)L_173) == ((uint32_t)L_176))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_177 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_178 = L_177->___uint16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_179 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_180 = L_179.___register;
		uint16_t L_181 = L_180.___uint16_1;
		if ((!(((uint32_t)L_178) == ((uint32_t)L_181))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_182 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_183 = L_182->___uint16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_184 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_185 = L_184.___register;
		uint16_t L_186 = L_185.___uint16_2;
		if ((!(((uint32_t)L_183) == ((uint32_t)L_186))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_187 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_188 = L_187->___uint16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_189 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_190 = L_189.___register;
		uint16_t L_191 = L_190.___uint16_3;
		if ((!(((uint32_t)L_188) == ((uint32_t)L_191))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_192 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_193 = L_192->___uint16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_194 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_195 = L_194.___register;
		uint16_t L_196 = L_195.___uint16_4;
		if ((!(((uint32_t)L_193) == ((uint32_t)L_196))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_197 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_198 = L_197->___uint16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_199 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_200 = L_199.___register;
		uint16_t L_201 = L_200.___uint16_5;
		if ((!(((uint32_t)L_198) == ((uint32_t)L_201))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_202 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_203 = L_202->___uint16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_204 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_205 = L_204.___register;
		uint16_t L_206 = L_205.___uint16_6;
		if ((!(((uint32_t)L_203) == ((uint32_t)L_206))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_207 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_208 = L_207->___uint16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_209 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_210 = L_209.___register;
		uint16_t L_211 = L_210.___uint16_7;
		return (bool)((((int32_t)L_208) == ((int32_t)L_211))? 1 : 0);
	}

IL_0494:
	{
		return (bool)0;
	}

IL_0496:
	{
		bool L_212 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_212)
		{
			goto IL_057d;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_213 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_214 = L_213->___int16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_215 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_216 = L_215.___register;
		int16_t L_217 = L_216.___int16_0;
		if ((!(((uint32_t)L_214) == ((uint32_t)L_217))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_218 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_219 = L_218->___int16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_220 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_221 = L_220.___register;
		int16_t L_222 = L_221.___int16_1;
		if ((!(((uint32_t)L_219) == ((uint32_t)L_222))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_223 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_224 = L_223->___int16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_225 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_226 = L_225.___register;
		int16_t L_227 = L_226.___int16_2;
		if ((!(((uint32_t)L_224) == ((uint32_t)L_227))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_228 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_229 = L_228->___int16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_230 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_231 = L_230.___register;
		int16_t L_232 = L_231.___int16_3;
		if ((!(((uint32_t)L_229) == ((uint32_t)L_232))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_233 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_234 = L_233->___int16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_235 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_236 = L_235.___register;
		int16_t L_237 = L_236.___int16_4;
		if ((!(((uint32_t)L_234) == ((uint32_t)L_237))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_238 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_239 = L_238->___int16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_240 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_241 = L_240.___register;
		int16_t L_242 = L_241.___int16_5;
		if ((!(((uint32_t)L_239) == ((uint32_t)L_242))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_243 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_244 = L_243->___int16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_245 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_246 = L_245.___register;
		int16_t L_247 = L_246.___int16_6;
		if ((!(((uint32_t)L_244) == ((uint32_t)L_247))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_248 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_249 = L_248->___int16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_250 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_251 = L_250.___register;
		int16_t L_252 = L_251.___int16_7;
		return (bool)((((int32_t)L_249) == ((int32_t)L_252))? 1 : 0);
	}

IL_057b:
	{
		return (bool)0;
	}

IL_057d:
	{
		bool L_253 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_253)
		{
			goto IL_05fb;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_254 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_255 = L_254->___uint32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_256 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_257 = L_256.___register;
		uint32_t L_258 = L_257.___uint32_0;
		if ((!(((uint32_t)L_255) == ((uint32_t)L_258))))
		{
			goto IL_05f9;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_259 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_260 = L_259->___uint32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_261 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_262 = L_261.___register;
		uint32_t L_263 = L_262.___uint32_1;
		if ((!(((uint32_t)L_260) == ((uint32_t)L_263))))
		{
			goto IL_05f9;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_264 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_265 = L_264->___uint32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_266 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_267 = L_266.___register;
		uint32_t L_268 = L_267.___uint32_2;
		if ((!(((uint32_t)L_265) == ((uint32_t)L_268))))
		{
			goto IL_05f9;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_269 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_270 = L_269->___uint32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_271 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_272 = L_271.___register;
		uint32_t L_273 = L_272.___uint32_3;
		return (bool)((((int32_t)L_270) == ((int32_t)L_273))? 1 : 0);
	}

IL_05f9:
	{
		return (bool)0;
	}

IL_05fb:
	{
		bool L_274 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_274)
		{
			goto IL_0679;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_275 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_276 = L_275->___int32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_277 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_278 = L_277.___register;
		int32_t L_279 = L_278.___int32_0;
		if ((!(((uint32_t)L_276) == ((uint32_t)L_279))))
		{
			goto IL_0677;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_280 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_281 = L_280->___int32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_282 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_283 = L_282.___register;
		int32_t L_284 = L_283.___int32_1;
		if ((!(((uint32_t)L_281) == ((uint32_t)L_284))))
		{
			goto IL_0677;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_285 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_286 = L_285->___int32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_287 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_288 = L_287.___register;
		int32_t L_289 = L_288.___int32_2;
		if ((!(((uint32_t)L_286) == ((uint32_t)L_289))))
		{
			goto IL_0677;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_290 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_291 = L_290->___int32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_292 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_293 = L_292.___register;
		int32_t L_294 = L_293.___int32_3;
		return (bool)((((int32_t)L_291) == ((int32_t)L_294))? 1 : 0);
	}

IL_0677:
	{
		return (bool)0;
	}

IL_0679:
	{
		bool L_295 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_295)
		{
			goto IL_06c7;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_296 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_297 = L_296->___uint64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_298 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_299 = L_298.___register;
		uint64_t L_300 = L_299.___uint64_0;
		if ((!(((uint64_t)L_297) == ((uint64_t)L_300))))
		{
			goto IL_06c5;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_301 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_302 = L_301->___uint64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_303 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_304 = L_303.___register;
		uint64_t L_305 = L_304.___uint64_1;
		return (bool)((((int64_t)L_302) == ((int64_t)L_305))? 1 : 0);
	}

IL_06c5:
	{
		return (bool)0;
	}

IL_06c7:
	{
		bool L_306 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_306)
		{
			goto IL_0715;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_307 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t L_308 = L_307->___int64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_309 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_310 = L_309.___register;
		int64_t L_311 = L_310.___int64_0;
		if ((!(((uint64_t)L_308) == ((uint64_t)L_311))))
		{
			goto IL_0713;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_312 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t L_313 = L_312->___int64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_314 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_315 = L_314.___register;
		int64_t L_316 = L_315.___int64_1;
		return (bool)((((int64_t)L_313) == ((int64_t)L_316))? 1 : 0);
	}

IL_0713:
	{
		return (bool)0;
	}

IL_0715:
	{
		bool L_317 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_317)
		{
			goto IL_0793;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_318 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_319 = L_318->___single_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_320 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_321 = L_320.___register;
		float L_322 = L_321.___single_0;
		if ((!(((float)L_319) == ((float)L_322))))
		{
			goto IL_0791;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_323 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_324 = L_323->___single_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_325 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_326 = L_325.___register;
		float L_327 = L_326.___single_1;
		if ((!(((float)L_324) == ((float)L_327))))
		{
			goto IL_0791;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_328 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_329 = L_328->___single_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_330 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_331 = L_330.___register;
		float L_332 = L_331.___single_2;
		if ((!(((float)L_329) == ((float)L_332))))
		{
			goto IL_0791;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_333 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_334 = L_333->___single_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_335 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_336 = L_335.___register;
		float L_337 = L_336.___single_3;
		return (bool)((((float)L_334) == ((float)L_337))? 1 : 0);
	}

IL_0791:
	{
		return (bool)0;
	}

IL_0793:
	{
		bool L_338 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_338)
		{
			goto IL_07e1;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_339 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double L_340 = L_339->___double_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_341 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_342 = L_341.___register;
		double L_343 = L_342.___double_0;
		if ((!(((double)L_340) == ((double)L_343))))
		{
			goto IL_07df;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_344 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double L_345 = L_344->___double_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_346 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_347 = L_346.___register;
		double L_348 = L_347.___double_1;
		return (bool)((((double)L_345) == ((double)L_348))? 1 : 0);
	}

IL_07df:
	{
		return (bool)0;
	}

IL_07e1:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_349 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_349, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_349, method);
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_AdjustorThunk (RuntimeObject* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	CHECKED_LOCAL(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_15 = L_4;
	const Il2CppFullySharedGenericStruct L_26 = L_4;
	const Il2CppFullySharedGenericStruct L_37 = L_4;
	const Il2CppFullySharedGenericStruct L_48 = L_4;
	const Il2CppFullySharedGenericStruct L_59 = L_4;
	const Il2CppFullySharedGenericStruct L_70 = L_4;
	const Il2CppFullySharedGenericStruct L_81 = L_4;
	const Il2CppFullySharedGenericStruct L_92 = L_4;
	const Il2CppFullySharedGenericStruct L_103 = L_4;
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint8_t V_2 = 0x0;
	int32_t V_3 = 0;
	int8_t V_4 = 0x0;
	int32_t V_5 = 0;
	uint16_t V_6 = 0;
	int32_t V_7 = 0;
	int16_t V_8 = 0;
	int32_t V_9 = 0;
	uint32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int64_t V_16 = 0;
	int32_t V_17 = 0;
	float V_18 = 0.0f;
	int32_t V_19 = 0;
	double V_20 = 0.0;
	{
		V_0 = 0;
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_034a;
		}
	}
	{
		bool L_1 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_1)
		{
			goto IL_0059;
		}
	}
	{
		V_1 = 0;
		goto IL_004f;
	}

IL_002b:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_3, (Il2CppFullySharedGenericStruct*)L_4);
		uint8_t L_5;
		il2cpp_codegen_box_unbox(L_4, (&L_5), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		V_2 = L_5;
		int32_t L_6;
		L_6 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678((&V_2), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_2, L_6, NULL);
		V_0 = L_7;
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_004f:
	{
		int32_t L_9 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_10;
		L_10 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_11 = V_0;
		return L_11;
	}

IL_0059:
	{
		bool L_12 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			goto IL_00a7;
		}
	}
	{
		V_3 = 0;
		goto IL_009d;
	}

IL_0078:
	{
		int32_t L_13 = V_0;
		int32_t L_14 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_14, (Il2CppFullySharedGenericStruct*)L_15);
		int8_t L_16;
		il2cpp_codegen_box_unbox(L_15, (&L_16), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		V_4 = L_16;
		int32_t L_17;
		L_17 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF((&V_4), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_18;
		L_18 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_13, L_17, NULL);
		V_0 = L_18;
		int32_t L_19 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_009d:
	{
		int32_t L_20 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_21;
		L_21 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_0078;
		}
	}
	{
		int32_t L_22 = V_0;
		return L_22;
	}

IL_00a7:
	{
		bool L_23 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_23)
		{
			goto IL_00fa;
		}
	}
	{
		V_5 = 0;
		goto IL_00ef;
	}

IL_00c7:
	{
		int32_t L_24 = V_0;
		int32_t L_25 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_25, (Il2CppFullySharedGenericStruct*)L_26);
		uint16_t L_27;
		il2cpp_codegen_box_unbox(L_26, (&L_27), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		V_6 = L_27;
		int32_t L_28;
		L_28 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200((&V_6), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_29;
		L_29 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_24, L_28, NULL);
		V_0 = L_29;
		int32_t L_30 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00ef:
	{
		int32_t L_31 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_32;
		L_32 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_00c7;
		}
	}
	{
		int32_t L_33 = V_0;
		return L_33;
	}

IL_00fa:
	{
		bool L_34 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_34)
		{
			goto IL_014d;
		}
	}
	{
		V_7 = 0;
		goto IL_0142;
	}

IL_011a:
	{
		int32_t L_35 = V_0;
		int32_t L_36 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_36, (Il2CppFullySharedGenericStruct*)L_37);
		int16_t L_38;
		il2cpp_codegen_box_unbox(L_37, (&L_38), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		V_8 = L_38;
		int32_t L_39;
		L_39 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1((&V_8), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_40;
		L_40 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_35, L_39, NULL);
		V_0 = L_40;
		int32_t L_41 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_41, 1));
	}

IL_0142:
	{
		int32_t L_42 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_43;
		L_43 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_42) < ((int32_t)L_43)))
		{
			goto IL_011a;
		}
	}
	{
		int32_t L_44 = V_0;
		return L_44;
	}

IL_014d:
	{
		bool L_45 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_45)
		{
			goto IL_01a0;
		}
	}
	{
		V_9 = 0;
		goto IL_0195;
	}

IL_016d:
	{
		int32_t L_46 = V_0;
		int32_t L_47 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_47, (Il2CppFullySharedGenericStruct*)L_48);
		uint32_t L_49;
		il2cpp_codegen_box_unbox(L_48, (&L_49), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		V_10 = L_49;
		int32_t L_50;
		L_50 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC((&V_10), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_51;
		L_51 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_46, L_50, NULL);
		V_0 = L_51;
		int32_t L_52 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_52, 1));
	}

IL_0195:
	{
		int32_t L_53 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_54;
		L_54 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_53) < ((int32_t)L_54)))
		{
			goto IL_016d;
		}
	}
	{
		int32_t L_55 = V_0;
		return L_55;
	}

IL_01a0:
	{
		bool L_56 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_56)
		{
			goto IL_01f3;
		}
	}
	{
		V_11 = 0;
		goto IL_01e8;
	}

IL_01c0:
	{
		int32_t L_57 = V_0;
		int32_t L_58 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_58, (Il2CppFullySharedGenericStruct*)L_59);
		int32_t L_60;
		il2cpp_codegen_box_unbox(L_59, (&L_60), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		V_12 = L_60;
		int32_t L_61;
		L_61 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&V_12), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_62;
		L_62 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_57, L_61, NULL);
		V_0 = L_62;
		int32_t L_63 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_63, 1));
	}

IL_01e8:
	{
		int32_t L_64 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_65;
		L_65 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_64) < ((int32_t)L_65)))
		{
			goto IL_01c0;
		}
	}
	{
		int32_t L_66 = V_0;
		return L_66;
	}

IL_01f3:
	{
		bool L_67 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_67)
		{
			goto IL_0246;
		}
	}
	{
		V_13 = 0;
		goto IL_023b;
	}

IL_0213:
	{
		int32_t L_68 = V_0;
		int32_t L_69 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_69, (Il2CppFullySharedGenericStruct*)L_70);
		uint64_t L_71;
		il2cpp_codegen_box_unbox(L_70, (&L_71), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		V_14 = L_71;
		int32_t L_72;
		L_72 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92((&V_14), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_73;
		L_73 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_68, L_72, NULL);
		V_0 = L_73;
		int32_t L_74 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_74, 1));
	}

IL_023b:
	{
		int32_t L_75 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_76;
		L_76 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_75) < ((int32_t)L_76)))
		{
			goto IL_0213;
		}
	}
	{
		int32_t L_77 = V_0;
		return L_77;
	}

IL_0246:
	{
		bool L_78 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_78)
		{
			goto IL_0299;
		}
	}
	{
		V_15 = 0;
		goto IL_028e;
	}

IL_0266:
	{
		int32_t L_79 = V_0;
		int32_t L_80 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_80, (Il2CppFullySharedGenericStruct*)L_81);
		int64_t L_82;
		il2cpp_codegen_box_unbox(L_81, (&L_82), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		V_16 = L_82;
		int32_t L_83;
		L_83 = Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496((&V_16), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_84;
		L_84 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_79, L_83, NULL);
		V_0 = L_84;
		int32_t L_85 = V_15;
		V_15 = ((int32_t)il2cpp_codegen_add(L_85, 1));
	}

IL_028e:
	{
		int32_t L_86 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_87;
		L_87 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_86) < ((int32_t)L_87)))
		{
			goto IL_0266;
		}
	}
	{
		int32_t L_88 = V_0;
		return L_88;
	}

IL_0299:
	{
		bool L_89 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_89)
		{
			goto IL_02ec;
		}
	}
	{
		V_17 = 0;
		goto IL_02e1;
	}

IL_02b9:
	{
		int32_t L_90 = V_0;
		int32_t L_91 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_91, (Il2CppFullySharedGenericStruct*)L_92);
		float L_93;
		il2cpp_codegen_box_unbox(L_92, (&L_93), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		V_18 = L_93;
		int32_t L_94;
		L_94 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2((&V_18), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_95;
		L_95 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_90, L_94, NULL);
		V_0 = L_95;
		int32_t L_96 = V_17;
		V_17 = ((int32_t)il2cpp_codegen_add(L_96, 1));
	}

IL_02e1:
	{
		int32_t L_97 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_98;
		L_98 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_97) < ((int32_t)L_98)))
		{
			goto IL_02b9;
		}
	}
	{
		int32_t L_99 = V_0;
		return L_99;
	}

IL_02ec:
	{
		bool L_100 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_100)
		{
			goto IL_033f;
		}
	}
	{
		V_19 = 0;
		goto IL_0334;
	}

IL_030c:
	{
		int32_t L_101 = V_0;
		int32_t L_102 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_102, (Il2CppFullySharedGenericStruct*)L_103);
		double L_104;
		il2cpp_codegen_box_unbox(L_103, (&L_104), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		V_20 = L_104;
		int32_t L_105;
		L_105 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline((&V_20), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_106;
		L_106 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_101, L_105, NULL);
		V_0 = L_106;
		int32_t L_107 = V_19;
		V_19 = ((int32_t)il2cpp_codegen_add(L_107, 1));
	}

IL_0334:
	{
		int32_t L_108 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_109;
		L_109 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_108) < ((int32_t)L_109)))
		{
			goto IL_030c;
		}
	}
	{
		int32_t L_110 = V_0;
		return L_110;
	}

IL_033f:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_111 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_111, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_111, method);
	}

IL_034a:
	{
		bool L_112 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_112)
		{
			goto IL_04da;
		}
	}
	{
		int32_t L_113 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_114 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_115 = (uint8_t*)(&L_114->___byte_0);
		int32_t L_116;
		L_116 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_115, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_117;
		L_117 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_113, L_116, NULL);
		V_0 = L_117;
		int32_t L_118 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_119 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_120 = (uint8_t*)(&L_119->___byte_1);
		int32_t L_121;
		L_121 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_120, NULL);
		int32_t L_122;
		L_122 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_118, L_121, NULL);
		V_0 = L_122;
		int32_t L_123 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_124 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_125 = (uint8_t*)(&L_124->___byte_2);
		int32_t L_126;
		L_126 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_125, NULL);
		int32_t L_127;
		L_127 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_123, L_126, NULL);
		V_0 = L_127;
		int32_t L_128 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_129 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_130 = (uint8_t*)(&L_129->___byte_3);
		int32_t L_131;
		L_131 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_130, NULL);
		int32_t L_132;
		L_132 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_128, L_131, NULL);
		V_0 = L_132;
		int32_t L_133 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_134 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_135 = (uint8_t*)(&L_134->___byte_4);
		int32_t L_136;
		L_136 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_135, NULL);
		int32_t L_137;
		L_137 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_133, L_136, NULL);
		V_0 = L_137;
		int32_t L_138 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_139 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_140 = (uint8_t*)(&L_139->___byte_5);
		int32_t L_141;
		L_141 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_140, NULL);
		int32_t L_142;
		L_142 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_138, L_141, NULL);
		V_0 = L_142;
		int32_t L_143 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_144 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_145 = (uint8_t*)(&L_144->___byte_6);
		int32_t L_146;
		L_146 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_145, NULL);
		int32_t L_147;
		L_147 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_143, L_146, NULL);
		V_0 = L_147;
		int32_t L_148 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_149 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_150 = (uint8_t*)(&L_149->___byte_7);
		int32_t L_151;
		L_151 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_150, NULL);
		int32_t L_152;
		L_152 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_148, L_151, NULL);
		V_0 = L_152;
		int32_t L_153 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_154 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_155 = (uint8_t*)(&L_154->___byte_8);
		int32_t L_156;
		L_156 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_155, NULL);
		int32_t L_157;
		L_157 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_153, L_156, NULL);
		V_0 = L_157;
		int32_t L_158 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_159 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_160 = (uint8_t*)(&L_159->___byte_9);
		int32_t L_161;
		L_161 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_160, NULL);
		int32_t L_162;
		L_162 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_158, L_161, NULL);
		V_0 = L_162;
		int32_t L_163 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_164 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_165 = (uint8_t*)(&L_164->___byte_10);
		int32_t L_166;
		L_166 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_165, NULL);
		int32_t L_167;
		L_167 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_163, L_166, NULL);
		V_0 = L_167;
		int32_t L_168 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_169 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_170 = (uint8_t*)(&L_169->___byte_11);
		int32_t L_171;
		L_171 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_170, NULL);
		int32_t L_172;
		L_172 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_168, L_171, NULL);
		V_0 = L_172;
		int32_t L_173 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_174 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_175 = (uint8_t*)(&L_174->___byte_12);
		int32_t L_176;
		L_176 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_175, NULL);
		int32_t L_177;
		L_177 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_173, L_176, NULL);
		V_0 = L_177;
		int32_t L_178 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_179 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_180 = (uint8_t*)(&L_179->___byte_13);
		int32_t L_181;
		L_181 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_180, NULL);
		int32_t L_182;
		L_182 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_178, L_181, NULL);
		V_0 = L_182;
		int32_t L_183 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_184 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_185 = (uint8_t*)(&L_184->___byte_14);
		int32_t L_186;
		L_186 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_185, NULL);
		int32_t L_187;
		L_187 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_183, L_186, NULL);
		V_0 = L_187;
		int32_t L_188 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_189 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_190 = (uint8_t*)(&L_189->___byte_15);
		int32_t L_191;
		L_191 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_190, NULL);
		int32_t L_192;
		L_192 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_188, L_191, NULL);
		V_0 = L_192;
		int32_t L_193 = V_0;
		return L_193;
	}

IL_04da:
	{
		bool L_194 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_194)
		{
			goto IL_066a;
		}
	}
	{
		int32_t L_195 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_196 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_197 = (int8_t*)(&L_196->___sbyte_0);
		int32_t L_198;
		L_198 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_197, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_199;
		L_199 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_195, L_198, NULL);
		V_0 = L_199;
		int32_t L_200 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_201 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_202 = (int8_t*)(&L_201->___sbyte_1);
		int32_t L_203;
		L_203 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_202, NULL);
		int32_t L_204;
		L_204 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_200, L_203, NULL);
		V_0 = L_204;
		int32_t L_205 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_206 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_207 = (int8_t*)(&L_206->___sbyte_2);
		int32_t L_208;
		L_208 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_207, NULL);
		int32_t L_209;
		L_209 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_205, L_208, NULL);
		V_0 = L_209;
		int32_t L_210 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_211 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_212 = (int8_t*)(&L_211->___sbyte_3);
		int32_t L_213;
		L_213 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_212, NULL);
		int32_t L_214;
		L_214 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_210, L_213, NULL);
		V_0 = L_214;
		int32_t L_215 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_216 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_217 = (int8_t*)(&L_216->___sbyte_4);
		int32_t L_218;
		L_218 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_217, NULL);
		int32_t L_219;
		L_219 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_215, L_218, NULL);
		V_0 = L_219;
		int32_t L_220 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_221 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_222 = (int8_t*)(&L_221->___sbyte_5);
		int32_t L_223;
		L_223 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_222, NULL);
		int32_t L_224;
		L_224 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_220, L_223, NULL);
		V_0 = L_224;
		int32_t L_225 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_226 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_227 = (int8_t*)(&L_226->___sbyte_6);
		int32_t L_228;
		L_228 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_227, NULL);
		int32_t L_229;
		L_229 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_225, L_228, NULL);
		V_0 = L_229;
		int32_t L_230 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_231 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_232 = (int8_t*)(&L_231->___sbyte_7);
		int32_t L_233;
		L_233 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_232, NULL);
		int32_t L_234;
		L_234 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_230, L_233, NULL);
		V_0 = L_234;
		int32_t L_235 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_236 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_237 = (int8_t*)(&L_236->___sbyte_8);
		int32_t L_238;
		L_238 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_237, NULL);
		int32_t L_239;
		L_239 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_235, L_238, NULL);
		V_0 = L_239;
		int32_t L_240 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_241 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_242 = (int8_t*)(&L_241->___sbyte_9);
		int32_t L_243;
		L_243 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_242, NULL);
		int32_t L_244;
		L_244 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_240, L_243, NULL);
		V_0 = L_244;
		int32_t L_245 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_246 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_247 = (int8_t*)(&L_246->___sbyte_10);
		int32_t L_248;
		L_248 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_247, NULL);
		int32_t L_249;
		L_249 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_245, L_248, NULL);
		V_0 = L_249;
		int32_t L_250 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_251 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_252 = (int8_t*)(&L_251->___sbyte_11);
		int32_t L_253;
		L_253 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_252, NULL);
		int32_t L_254;
		L_254 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_250, L_253, NULL);
		V_0 = L_254;
		int32_t L_255 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_256 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_257 = (int8_t*)(&L_256->___sbyte_12);
		int32_t L_258;
		L_258 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_257, NULL);
		int32_t L_259;
		L_259 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_255, L_258, NULL);
		V_0 = L_259;
		int32_t L_260 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_261 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_262 = (int8_t*)(&L_261->___sbyte_13);
		int32_t L_263;
		L_263 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_262, NULL);
		int32_t L_264;
		L_264 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_260, L_263, NULL);
		V_0 = L_264;
		int32_t L_265 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_266 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_267 = (int8_t*)(&L_266->___sbyte_14);
		int32_t L_268;
		L_268 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_267, NULL);
		int32_t L_269;
		L_269 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_265, L_268, NULL);
		V_0 = L_269;
		int32_t L_270 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_271 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_272 = (int8_t*)(&L_271->___sbyte_15);
		int32_t L_273;
		L_273 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_272, NULL);
		int32_t L_274;
		L_274 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_270, L_273, NULL);
		V_0 = L_274;
		int32_t L_275 = V_0;
		return L_275;
	}

IL_066a:
	{
		bool L_276 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_276)
		{
			goto IL_0742;
		}
	}
	{
		int32_t L_277 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_278 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_279 = (uint16_t*)(&L_278->___uint16_0);
		int32_t L_280;
		L_280 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_279, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_281;
		L_281 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_277, L_280, NULL);
		V_0 = L_281;
		int32_t L_282 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_283 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_284 = (uint16_t*)(&L_283->___uint16_1);
		int32_t L_285;
		L_285 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_284, NULL);
		int32_t L_286;
		L_286 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_282, L_285, NULL);
		V_0 = L_286;
		int32_t L_287 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_288 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_289 = (uint16_t*)(&L_288->___uint16_2);
		int32_t L_290;
		L_290 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_289, NULL);
		int32_t L_291;
		L_291 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_287, L_290, NULL);
		V_0 = L_291;
		int32_t L_292 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_293 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_294 = (uint16_t*)(&L_293->___uint16_3);
		int32_t L_295;
		L_295 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_294, NULL);
		int32_t L_296;
		L_296 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_292, L_295, NULL);
		V_0 = L_296;
		int32_t L_297 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_298 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_299 = (uint16_t*)(&L_298->___uint16_4);
		int32_t L_300;
		L_300 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_299, NULL);
		int32_t L_301;
		L_301 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_297, L_300, NULL);
		V_0 = L_301;
		int32_t L_302 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_303 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_304 = (uint16_t*)(&L_303->___uint16_5);
		int32_t L_305;
		L_305 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_304, NULL);
		int32_t L_306;
		L_306 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_302, L_305, NULL);
		V_0 = L_306;
		int32_t L_307 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_308 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_309 = (uint16_t*)(&L_308->___uint16_6);
		int32_t L_310;
		L_310 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_309, NULL);
		int32_t L_311;
		L_311 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_307, L_310, NULL);
		V_0 = L_311;
		int32_t L_312 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_313 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_314 = (uint16_t*)(&L_313->___uint16_7);
		int32_t L_315;
		L_315 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_314, NULL);
		int32_t L_316;
		L_316 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_312, L_315, NULL);
		V_0 = L_316;
		int32_t L_317 = V_0;
		return L_317;
	}

IL_0742:
	{
		bool L_318 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_318)
		{
			goto IL_081a;
		}
	}
	{
		int32_t L_319 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_320 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_321 = (int16_t*)(&L_320->___int16_0);
		int32_t L_322;
		L_322 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_321, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_323;
		L_323 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_319, L_322, NULL);
		V_0 = L_323;
		int32_t L_324 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_325 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_326 = (int16_t*)(&L_325->___int16_1);
		int32_t L_327;
		L_327 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_326, NULL);
		int32_t L_328;
		L_328 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_324, L_327, NULL);
		V_0 = L_328;
		int32_t L_329 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_330 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_331 = (int16_t*)(&L_330->___int16_2);
		int32_t L_332;
		L_332 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_331, NULL);
		int32_t L_333;
		L_333 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_329, L_332, NULL);
		V_0 = L_333;
		int32_t L_334 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_335 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_336 = (int16_t*)(&L_335->___int16_3);
		int32_t L_337;
		L_337 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_336, NULL);
		int32_t L_338;
		L_338 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_334, L_337, NULL);
		V_0 = L_338;
		int32_t L_339 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_340 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_341 = (int16_t*)(&L_340->___int16_4);
		int32_t L_342;
		L_342 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_341, NULL);
		int32_t L_343;
		L_343 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_339, L_342, NULL);
		V_0 = L_343;
		int32_t L_344 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_345 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_346 = (int16_t*)(&L_345->___int16_5);
		int32_t L_347;
		L_347 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_346, NULL);
		int32_t L_348;
		L_348 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_344, L_347, NULL);
		V_0 = L_348;
		int32_t L_349 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_350 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_351 = (int16_t*)(&L_350->___int16_6);
		int32_t L_352;
		L_352 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_351, NULL);
		int32_t L_353;
		L_353 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_349, L_352, NULL);
		V_0 = L_353;
		int32_t L_354 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_355 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_356 = (int16_t*)(&L_355->___int16_7);
		int32_t L_357;
		L_357 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_356, NULL);
		int32_t L_358;
		L_358 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_354, L_357, NULL);
		V_0 = L_358;
		int32_t L_359 = V_0;
		return L_359;
	}

IL_081a:
	{
		bool L_360 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_360)
		{
			goto IL_0893;
		}
	}
	{
		int32_t L_361 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_362 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_363 = (uint32_t*)(&L_362->___uint32_0);
		int32_t L_364;
		L_364 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_363, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_365;
		L_365 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_361, L_364, NULL);
		V_0 = L_365;
		int32_t L_366 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_367 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_368 = (uint32_t*)(&L_367->___uint32_1);
		int32_t L_369;
		L_369 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_368, NULL);
		int32_t L_370;
		L_370 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_366, L_369, NULL);
		V_0 = L_370;
		int32_t L_371 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_372 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_373 = (uint32_t*)(&L_372->___uint32_2);
		int32_t L_374;
		L_374 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_373, NULL);
		int32_t L_375;
		L_375 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_371, L_374, NULL);
		V_0 = L_375;
		int32_t L_376 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_377 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_378 = (uint32_t*)(&L_377->___uint32_3);
		int32_t L_379;
		L_379 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_378, NULL);
		int32_t L_380;
		L_380 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_376, L_379, NULL);
		V_0 = L_380;
		int32_t L_381 = V_0;
		return L_381;
	}

IL_0893:
	{
		bool L_382 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_382)
		{
			goto IL_090c;
		}
	}
	{
		int32_t L_383 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_384 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_385 = (int32_t*)(&L_384->___int32_0);
		int32_t L_386;
		L_386 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_385, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_387;
		L_387 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_383, L_386, NULL);
		V_0 = L_387;
		int32_t L_388 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_389 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_390 = (int32_t*)(&L_389->___int32_1);
		int32_t L_391;
		L_391 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_390, NULL);
		int32_t L_392;
		L_392 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_388, L_391, NULL);
		V_0 = L_392;
		int32_t L_393 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_394 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_395 = (int32_t*)(&L_394->___int32_2);
		int32_t L_396;
		L_396 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_395, NULL);
		int32_t L_397;
		L_397 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_393, L_396, NULL);
		V_0 = L_397;
		int32_t L_398 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_399 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_400 = (int32_t*)(&L_399->___int32_3);
		int32_t L_401;
		L_401 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_400, NULL);
		int32_t L_402;
		L_402 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_398, L_401, NULL);
		V_0 = L_402;
		int32_t L_403 = V_0;
		return L_403;
	}

IL_090c:
	{
		bool L_404 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_404)
		{
			goto IL_0957;
		}
	}
	{
		int32_t L_405 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_406 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_407 = (uint64_t*)(&L_406->___uint64_0);
		int32_t L_408;
		L_408 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_407, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_409;
		L_409 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_405, L_408, NULL);
		V_0 = L_409;
		int32_t L_410 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_411 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_412 = (uint64_t*)(&L_411->___uint64_1);
		int32_t L_413;
		L_413 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_412, NULL);
		int32_t L_414;
		L_414 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_410, L_413, NULL);
		V_0 = L_414;
		int32_t L_415 = V_0;
		return L_415;
	}

IL_0957:
	{
		bool L_416 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_416)
		{
			goto IL_09a2;
		}
	}
	{
		int32_t L_417 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_418 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_419 = (int64_t*)(&L_418->___int64_0);
		int32_t L_420;
		L_420 = Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496(L_419, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_421;
		L_421 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_417, L_420, NULL);
		V_0 = L_421;
		int32_t L_422 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_423 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_424 = (int64_t*)(&L_423->___int64_1);
		int32_t L_425;
		L_425 = Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496(L_424, NULL);
		int32_t L_426;
		L_426 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_422, L_425, NULL);
		V_0 = L_426;
		int32_t L_427 = V_0;
		return L_427;
	}

IL_09a2:
	{
		bool L_428 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_428)
		{
			goto IL_0a1b;
		}
	}
	{
		int32_t L_429 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_430 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_431 = (float*)(&L_430->___single_0);
		int32_t L_432;
		L_432 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_431, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_433;
		L_433 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_429, L_432, NULL);
		V_0 = L_433;
		int32_t L_434 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_435 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_436 = (float*)(&L_435->___single_1);
		int32_t L_437;
		L_437 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_436, NULL);
		int32_t L_438;
		L_438 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_434, L_437, NULL);
		V_0 = L_438;
		int32_t L_439 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_440 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_441 = (float*)(&L_440->___single_2);
		int32_t L_442;
		L_442 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_441, NULL);
		int32_t L_443;
		L_443 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_439, L_442, NULL);
		V_0 = L_443;
		int32_t L_444 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_445 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_446 = (float*)(&L_445->___single_3);
		int32_t L_447;
		L_447 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_446, NULL);
		int32_t L_448;
		L_448 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_444, L_447, NULL);
		V_0 = L_448;
		int32_t L_449 = V_0;
		return L_449;
	}

IL_0a1b:
	{
		bool L_450 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_450)
		{
			goto IL_0a66;
		}
	}
	{
		int32_t L_451 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_452 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_453 = (double*)(&L_452->___double_0);
		int32_t L_454;
		L_454 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline(L_453, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_455;
		L_455 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_451, L_454, NULL);
		V_0 = L_455;
		int32_t L_456 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_457 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_458 = (double*)(&L_457->___double_1);
		int32_t L_459;
		L_459 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline(L_458, NULL);
		int32_t L_460;
		L_460 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_456, L_459, NULL);
		V_0 = L_460;
		int32_t L_461 = V_0;
		return L_461;
	}

IL_0a66:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_462 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_462, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_462, method);
	}
}
IL2CPP_EXTERN_C  int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	int32_t _returnValue;
	_returnValue = Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit);
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit,(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_0;
		L_0 = CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5(NULL);
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_1;
		L_1 = ((  String_t* (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, String_t*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8)))(__this, _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869, L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		return L_1;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A(_thisAdjusted, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_24 = L_8;
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		RuntimeObject* L_1 = ___1_formatProvider;
		NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* L_2;
		L_2 = NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F(L_1, NULL);
		String_t* L_3;
		L_3 = NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline(L_2, NULL);
		V_1 = L_3;
		StringBuilder_t* L_4 = V_0;
		StringBuilder_t* L_5;
		L_5 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_4, ((int32_t)60), NULL);
		V_2 = 0;
		goto IL_0053;
	}

IL_001f:
	{
		StringBuilder_t* L_6 = V_0;
		int32_t L_7 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_7, (Il2CppFullySharedGenericStruct*)L_8);
		RuntimeObject* L_9 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_8);
		String_t* L_10 = ___0_format;
		RuntimeObject* L_11 = ___1_formatProvider;
		String_t* L_12;
		L_12 = InterfaceFuncInvoker2< String_t*, String_t*, RuntimeObject* >::Invoke(0, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var, ((RuntimeObject*)Castclass((RuntimeObject*)L_9, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var)), L_10, L_11);
		StringBuilder_t* L_13;
		L_13 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_6, L_12, NULL);
		StringBuilder_t* L_14 = V_0;
		String_t* L_15 = V_1;
		StringBuilder_t* L_16;
		L_16 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_14, L_15, NULL);
		StringBuilder_t* L_17 = V_0;
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_17, ((int32_t)32), NULL);
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0053:
	{
		int32_t L_20 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_21;
		L_21 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_20) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_21, 1)))))
		{
			goto IL_001f;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_23;
		L_23 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, ((int32_t)il2cpp_codegen_subtract(L_23, 1)), (Il2CppFullySharedGenericStruct*)L_24);
		RuntimeObject* L_25 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_24);
		String_t* L_26 = ___0_format;
		RuntimeObject* L_27 = ___1_formatProvider;
		String_t* L_28;
		L_28 = InterfaceFuncInvoker2< String_t*, String_t*, RuntimeObject* >::Invoke(0, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var, ((RuntimeObject*)Castclass((RuntimeObject*)L_25, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var)), L_26, L_27);
		StringBuilder_t* L_29;
		L_29 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_22, L_28, NULL);
		StringBuilder_t* L_30 = V_0;
		StringBuilder_t* L_31;
		L_31 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_30, ((int32_t)62), NULL);
		StringBuilder_t* L_32 = V_0;
		String_t* L_33;
		L_33 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_32);
		return L_33;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_AdjustorThunk (RuntimeObject* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F(_thisAdjusted, ___0_format, ___1_formatProvider, method);
	return _returnValue;
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD9D7F968EF2059FD426D9AB1B5252CF82BD4F4EF_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Inequality_mA9CAF8F4CFD39F3FFFD040F57C0FA7EAD5508999_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ___0_left;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9)))(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_op_Explicit_mEFC640DAE334AF4ED540F354F6FCDF25F74E95A2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_value, const RuntimeMethod* method) 
{
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_0 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&(&___0_value)->___register);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_1;
		memset((&L_1), 0, sizeof(L_1));
		Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606((&L_1), L_0, NULL);
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 Vector_1_Equals_m96E39C24E7761FC3F454C5A26242AE329FDEFC99_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_9 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_27 = L_9;
	const Il2CppFullySharedGenericStruct L_46 = L_9;
	const Il2CppFullySharedGenericStruct L_65 = L_9;
	const Il2CppFullySharedGenericStruct L_84 = L_9;
	const Il2CppFullySharedGenericStruct L_103 = L_9;
	const Il2CppFullySharedGenericStruct L_122 = L_9;
	const Il2CppFullySharedGenericStruct L_142 = L_9;
	const Il2CppFullySharedGenericStruct L_162 = L_9;
	const Il2CppFullySharedGenericStruct L_181 = L_9;
	const Il2CppFullySharedGenericStruct L_11 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_29 = L_11;
	const Il2CppFullySharedGenericStruct L_48 = L_11;
	const Il2CppFullySharedGenericStruct L_67 = L_11;
	const Il2CppFullySharedGenericStruct L_86 = L_11;
	const Il2CppFullySharedGenericStruct L_105 = L_11;
	const Il2CppFullySharedGenericStruct L_124 = L_11;
	const Il2CppFullySharedGenericStruct L_144 = L_11;
	const Il2CppFullySharedGenericStruct L_164 = L_11;
	const Il2CppFullySharedGenericStruct L_183 = L_11;
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int8_t* V_2 = NULL;
	int32_t V_3 = 0;
	uint16_t* V_4 = NULL;
	int32_t V_5 = 0;
	int16_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint32_t* V_8 = NULL;
	int32_t V_9 = 0;
	int32_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint64_t* V_12 = NULL;
	int32_t V_13 = 0;
	int64_t* V_14 = NULL;
	int32_t V_15 = 0;
	float* V_16 = NULL;
	int32_t V_17 = 0;
	double* V_18 = NULL;
	int32_t V_19 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A V_20;
	memset((&V_20), 0, sizeof(V_20));
	uint8_t* G_B5_0 = NULL;
	uint8_t* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	uint8_t* G_B6_1 = NULL;
	int8_t* G_B13_0 = NULL;
	int8_t* G_B12_0 = NULL;
	int32_t G_B14_0 = 0;
	int8_t* G_B14_1 = NULL;
	uint16_t* G_B21_0 = NULL;
	uint16_t* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	uint16_t* G_B22_1 = NULL;
	int16_t* G_B29_0 = NULL;
	int16_t* G_B28_0 = NULL;
	int32_t G_B30_0 = 0;
	int16_t* G_B30_1 = NULL;
	uint32_t* G_B37_0 = NULL;
	uint32_t* G_B36_0 = NULL;
	uint32_t G_B38_0 = 0;
	uint32_t* G_B38_1 = NULL;
	int32_t* G_B45_0 = NULL;
	int32_t* G_B44_0 = NULL;
	int32_t G_B46_0 = 0;
	int32_t* G_B46_1 = NULL;
	uint64_t* G_B53_0 = NULL;
	uint64_t* G_B52_0 = NULL;
	uint64_t G_B54_0 = 0;
	uint64_t* G_B54_1 = NULL;
	int64_t* G_B61_0 = NULL;
	int64_t* G_B60_0 = NULL;
	int64_t G_B62_0 = 0;
	int64_t* G_B62_1 = NULL;
	float* G_B69_0 = NULL;
	float* G_B68_0 = NULL;
	float G_B70_0 = 0.0f;
	float* G_B70_1 = NULL;
	double* G_B77_0 = NULL;
	double* G_B76_0 = NULL;
	double G_B78_0 = 0.0;
	double* G_B78_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B85_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B84_0 = NULL;
	int32_t G_B86_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B86_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B88_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B87_0 = NULL;
	int32_t G_B89_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B89_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B91_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B90_0 = NULL;
	int32_t G_B92_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B92_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B94_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B93_0 = NULL;
	int32_t G_B95_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B95_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B97_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B96_0 = NULL;
	int32_t G_B98_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B98_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B100_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B99_0 = NULL;
	int32_t G_B101_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B101_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B103_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B102_0 = NULL;
	int32_t G_B104_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B104_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B106_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B105_0 = NULL;
	int32_t G_B107_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B107_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B109_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B108_0 = NULL;
	int32_t G_B110_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B110_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B112_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B111_0 = NULL;
	int32_t G_B113_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B113_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B115_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B114_0 = NULL;
	int32_t G_B116_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B116_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B118_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B117_0 = NULL;
	int32_t G_B119_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B119_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B121_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B120_0 = NULL;
	int32_t G_B122_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B122_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B124_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B123_0 = NULL;
	int32_t G_B125_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B125_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B127_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B126_0 = NULL;
	int32_t G_B128_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B128_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B130_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B129_0 = NULL;
	int32_t G_B131_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B131_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B135_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B134_0 = NULL;
	int32_t G_B136_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B136_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B138_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B137_0 = NULL;
	int32_t G_B139_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B139_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B141_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B140_0 = NULL;
	int32_t G_B142_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B142_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B144_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B143_0 = NULL;
	int32_t G_B145_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B145_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B147_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B146_0 = NULL;
	int32_t G_B148_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B148_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B150_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B149_0 = NULL;
	int32_t G_B151_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B151_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B153_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B152_0 = NULL;
	int32_t G_B154_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B154_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B156_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B155_0 = NULL;
	int32_t G_B157_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B157_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B159_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B158_0 = NULL;
	int32_t G_B160_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B160_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B162_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B161_0 = NULL;
	int32_t G_B163_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B163_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B165_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B164_0 = NULL;
	int32_t G_B166_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B166_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B168_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B167_0 = NULL;
	int32_t G_B169_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B169_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B171_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B170_0 = NULL;
	int32_t G_B172_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B172_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B174_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B173_0 = NULL;
	int32_t G_B175_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B175_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B177_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B176_0 = NULL;
	int32_t G_B178_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B178_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B180_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B179_0 = NULL;
	int32_t G_B181_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B181_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B185_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B184_0 = NULL;
	int32_t G_B186_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B186_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B188_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B187_0 = NULL;
	int32_t G_B189_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B189_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B191_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B190_0 = NULL;
	int32_t G_B192_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B192_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B194_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B193_0 = NULL;
	int32_t G_B195_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B195_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B197_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B196_0 = NULL;
	int32_t G_B198_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B198_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B200_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B199_0 = NULL;
	int32_t G_B201_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B201_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B203_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B202_0 = NULL;
	int32_t G_B204_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B204_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B206_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B205_0 = NULL;
	int32_t G_B207_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B207_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B211_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B210_0 = NULL;
	int32_t G_B212_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B212_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B214_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B213_0 = NULL;
	int32_t G_B215_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B215_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B217_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B216_0 = NULL;
	int32_t G_B218_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B218_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B220_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B219_0 = NULL;
	int32_t G_B221_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B221_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B223_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B222_0 = NULL;
	int32_t G_B224_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B224_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B226_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B225_0 = NULL;
	int32_t G_B227_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B227_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B229_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B228_0 = NULL;
	int32_t G_B230_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B230_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B232_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B231_0 = NULL;
	int32_t G_B233_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B233_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B237_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B236_0 = NULL;
	uint32_t G_B238_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B238_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B240_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B239_0 = NULL;
	uint32_t G_B241_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B241_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B243_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B242_0 = NULL;
	uint32_t G_B244_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B244_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B246_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B245_0 = NULL;
	uint32_t G_B247_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B247_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B251_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B250_0 = NULL;
	int32_t G_B252_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B252_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B254_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B253_0 = NULL;
	int32_t G_B255_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B255_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B257_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B256_0 = NULL;
	int32_t G_B258_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B258_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B260_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B259_0 = NULL;
	int32_t G_B261_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B261_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B265_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B264_0 = NULL;
	uint64_t G_B266_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B266_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B268_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B267_0 = NULL;
	uint64_t G_B269_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B269_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B273_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B272_0 = NULL;
	int64_t G_B274_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B274_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B276_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B275_0 = NULL;
	int64_t G_B277_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B277_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B281_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B280_0 = NULL;
	float G_B282_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B282_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B284_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B283_0 = NULL;
	float G_B285_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B285_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B287_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B286_0 = NULL;
	float G_B288_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B288_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B290_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B289_0 = NULL;
	float G_B291_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B291_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B295_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B294_0 = NULL;
	double G_B296_0 = 0.0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B296_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B298_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B297_0 = NULL;
	double G_B299_0 = 0.0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B299_1 = NULL;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0447;
		}
	}
	{
		bool L_1 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_1)
		{
			goto IL_0068;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_2;
		L_2 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_2,NULL));
		uintptr_t L_4 = L_3;
		int8_t* L_5;
		if (L_4 == 0)
		{
			L_5 = NULL;
		}
		else
		{
			L_5 = (int8_t*)alloca(L_4);
			memset(L_5, 0, L_4);
		}
		V_0 = (uint8_t*)L_5;
		V_1 = 0;
		goto IL_0059;
	}

IL_0032:
	{
		uint8_t* L_6 = V_0;
		int32_t L_7 = V_1;
		int32_t L_8 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_8, (Il2CppFullySharedGenericStruct*)L_9);
		int32_t L_10 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_10, (Il2CppFullySharedGenericStruct*)L_11);
		bool L_12;
		L_12 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_9, L_11);
		if (L_12)
		{
			G_B5_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, L_7));
			goto IL_004f;
		}
		G_B4_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, L_7));
	}
	{
		G_B6_0 = 0;
		G_B6_1 = G_B4_0;
		goto IL_0054;
	}

IL_004f:
	{
		uint8_t L_13;
		L_13 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B6_0 = ((int32_t)(L_13));
		G_B6_1 = G_B5_0;
	}

IL_0054:
	{
		il2cpp_codegen_stind<int8_t>((int8_t*)G_B6_1, (int8_t)G_B6_0);
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0059:
	{
		int32_t L_15 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_16;
		L_16 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0032;
		}
	}
	{
		uint8_t* L_17 = V_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_18;
		memset((&L_18), 0, sizeof(L_18));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_18), (void*)L_17, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_18;
	}

IL_0068:
	{
		bool L_19 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_19)
		{
			goto IL_00c6;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_20;
		L_20 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_21 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_20,NULL));
		uintptr_t L_22 = L_21;
		int8_t* L_23;
		if (L_22 == 0)
		{
			L_23 = NULL;
		}
		else
		{
			L_23 = (int8_t*)alloca(L_22);
			memset(L_23, 0, L_22);
		}
		V_2 = L_23;
		V_3 = 0;
		goto IL_00b7;
	}

IL_0090:
	{
		int8_t* L_24 = V_2;
		int32_t L_25 = V_3;
		int32_t L_26 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_26, (Il2CppFullySharedGenericStruct*)L_27);
		int32_t L_28 = V_3;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_28, (Il2CppFullySharedGenericStruct*)L_29);
		bool L_30;
		L_30 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_27, L_29);
		if (L_30)
		{
			G_B13_0 = ((int8_t*)il2cpp_codegen_add((intptr_t)L_24, L_25));
			goto IL_00ad;
		}
		G_B12_0 = ((int8_t*)il2cpp_codegen_add((intptr_t)L_24, L_25));
	}
	{
		G_B14_0 = 0;
		G_B14_1 = G_B12_0;
		goto IL_00b2;
	}

IL_00ad:
	{
		int8_t L_31;
		L_31 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B14_0 = ((int32_t)(L_31));
		G_B14_1 = G_B13_0;
	}

IL_00b2:
	{
		il2cpp_codegen_stind<int8_t>((int8_t*)G_B14_1, (int8_t)G_B14_0);
		int32_t L_32 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_32, 1));
	}

IL_00b7:
	{
		int32_t L_33 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_34;
		L_34 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0090;
		}
	}
	{
		int8_t* L_35 = V_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_36;
		memset((&L_36), 0, sizeof(L_36));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_36), (void*)L_35, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_36;
	}

IL_00c6:
	{
		bool L_37 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_37)
		{
			goto IL_0133;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_38;
		L_38 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_39 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_38,NULL));
		if ((uintptr_t)L_39 * (uintptr_t)2 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_40 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_39, 2));
		int8_t* L_41;
		if (L_40 == 0)
		{
			L_41 = NULL;
		}
		else
		{
			L_41 = (int8_t*)alloca(L_40);
			memset(L_41, 0, L_40);
		}
		V_4 = (uint16_t*)L_41;
		V_5 = 0;
		goto IL_0122;
	}

IL_00f2:
	{
		uint16_t* L_42 = V_4;
		int32_t L_43 = V_5;
		intptr_t L_44 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_43,NULL));
		int32_t L_45 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_45, (Il2CppFullySharedGenericStruct*)L_46);
		int32_t L_47 = V_5;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_47, (Il2CppFullySharedGenericStruct*)L_48);
		bool L_49;
		L_49 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_46, L_48);
		if (L_49)
		{
			G_B21_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_42, ((intptr_t)il2cpp_codegen_multiply(L_44, 2))));
			goto IL_0116;
		}
		G_B20_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_42, ((intptr_t)il2cpp_codegen_multiply(L_44, 2))));
	}
	{
		G_B22_0 = 0;
		G_B22_1 = G_B20_0;
		goto IL_011b;
	}

IL_0116:
	{
		uint16_t L_50;
		L_50 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B22_0 = ((int32_t)(L_50));
		G_B22_1 = G_B21_0;
	}

IL_011b:
	{
		il2cpp_codegen_stind<int16_t>((int16_t*)G_B22_1, (int16_t)G_B22_0);
		int32_t L_51 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_0122:
	{
		int32_t L_52 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_53;
		L_53 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_00f2;
		}
	}
	{
		uint16_t* L_54 = V_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_55;
		memset((&L_55), 0, sizeof(L_55));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_55), (void*)L_54, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_55;
	}

IL_0133:
	{
		bool L_56 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_56)
		{
			goto IL_01a0;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_57;
		L_57 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_58 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_57,NULL));
		if ((uintptr_t)L_58 * (uintptr_t)2 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_59 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_58, 2));
		int8_t* L_60;
		if (L_59 == 0)
		{
			L_60 = NULL;
		}
		else
		{
			L_60 = (int8_t*)alloca(L_59);
			memset(L_60, 0, L_59);
		}
		V_6 = (int16_t*)L_60;
		V_7 = 0;
		goto IL_018f;
	}

IL_015f:
	{
		int16_t* L_61 = V_6;
		int32_t L_62 = V_7;
		intptr_t L_63 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_62,NULL));
		int32_t L_64 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_64, (Il2CppFullySharedGenericStruct*)L_65);
		int32_t L_66 = V_7;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_66, (Il2CppFullySharedGenericStruct*)L_67);
		bool L_68;
		L_68 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_65, L_67);
		if (L_68)
		{
			G_B29_0 = ((int16_t*)il2cpp_codegen_add((intptr_t)L_61, ((intptr_t)il2cpp_codegen_multiply(L_63, 2))));
			goto IL_0183;
		}
		G_B28_0 = ((int16_t*)il2cpp_codegen_add((intptr_t)L_61, ((intptr_t)il2cpp_codegen_multiply(L_63, 2))));
	}
	{
		G_B30_0 = 0;
		G_B30_1 = G_B28_0;
		goto IL_0188;
	}

IL_0183:
	{
		int16_t L_69;
		L_69 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B30_0 = ((int32_t)(L_69));
		G_B30_1 = G_B29_0;
	}

IL_0188:
	{
		il2cpp_codegen_stind<int16_t>((int16_t*)G_B30_1, (int16_t)G_B30_0);
		int32_t L_70 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_70, 1));
	}

IL_018f:
	{
		int32_t L_71 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_72;
		L_72 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_71) < ((int32_t)L_72)))
		{
			goto IL_015f;
		}
	}
	{
		int16_t* L_73 = V_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_74;
		memset((&L_74), 0, sizeof(L_74));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_74), (void*)L_73, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_74;
	}

IL_01a0:
	{
		bool L_75 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_75)
		{
			goto IL_020d;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_76;
		L_76 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_77 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_76,NULL));
		if ((uintptr_t)L_77 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_78 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_77, 4));
		int8_t* L_79;
		if (L_78 == 0)
		{
			L_79 = NULL;
		}
		else
		{
			L_79 = (int8_t*)alloca(L_78);
			memset(L_79, 0, L_78);
		}
		V_8 = (uint32_t*)L_79;
		V_9 = 0;
		goto IL_01fc;
	}

IL_01cc:
	{
		uint32_t* L_80 = V_8;
		int32_t L_81 = V_9;
		intptr_t L_82 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_81,NULL));
		int32_t L_83 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_83, (Il2CppFullySharedGenericStruct*)L_84);
		int32_t L_85 = V_9;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_85, (Il2CppFullySharedGenericStruct*)L_86);
		bool L_87;
		L_87 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_84, L_86);
		if (L_87)
		{
			G_B37_0 = ((uint32_t*)il2cpp_codegen_add((intptr_t)L_80, ((intptr_t)il2cpp_codegen_multiply(L_82, 4))));
			goto IL_01f0;
		}
		G_B36_0 = ((uint32_t*)il2cpp_codegen_add((intptr_t)L_80, ((intptr_t)il2cpp_codegen_multiply(L_82, 4))));
	}
	{
		G_B38_0 = ((uint32_t)(0));
		G_B38_1 = G_B36_0;
		goto IL_01f5;
	}

IL_01f0:
	{
		uint32_t L_88;
		L_88 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B38_0 = L_88;
		G_B38_1 = G_B37_0;
	}

IL_01f5:
	{
		il2cpp_codegen_stind<int32_t>((int32_t*)G_B38_1, (int32_t)G_B38_0);
		int32_t L_89 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_89, 1));
	}

IL_01fc:
	{
		int32_t L_90 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_91;
		L_91 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_90) < ((int32_t)L_91)))
		{
			goto IL_01cc;
		}
	}
	{
		uint32_t* L_92 = V_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_93;
		memset((&L_93), 0, sizeof(L_93));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_93), (void*)L_92, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_93;
	}

IL_020d:
	{
		bool L_94 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_94)
		{
			goto IL_027a;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_95;
		L_95 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_96 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_95,NULL));
		if ((uintptr_t)L_96 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_97 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_96, 4));
		int8_t* L_98;
		if (L_97 == 0)
		{
			L_98 = NULL;
		}
		else
		{
			L_98 = (int8_t*)alloca(L_97);
			memset(L_98, 0, L_97);
		}
		V_10 = (int32_t*)L_98;
		V_11 = 0;
		goto IL_0269;
	}

IL_0239:
	{
		int32_t* L_99 = V_10;
		int32_t L_100 = V_11;
		intptr_t L_101 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_100,NULL));
		int32_t L_102 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_102, (Il2CppFullySharedGenericStruct*)L_103);
		int32_t L_104 = V_11;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_104, (Il2CppFullySharedGenericStruct*)L_105);
		bool L_106;
		L_106 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_103, L_105);
		if (L_106)
		{
			G_B45_0 = ((int32_t*)il2cpp_codegen_add((intptr_t)L_99, ((intptr_t)il2cpp_codegen_multiply(L_101, 4))));
			goto IL_025d;
		}
		G_B44_0 = ((int32_t*)il2cpp_codegen_add((intptr_t)L_99, ((intptr_t)il2cpp_codegen_multiply(L_101, 4))));
	}
	{
		G_B46_0 = 0;
		G_B46_1 = G_B44_0;
		goto IL_0262;
	}

IL_025d:
	{
		int32_t L_107;
		L_107 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B46_0 = L_107;
		G_B46_1 = G_B45_0;
	}

IL_0262:
	{
		il2cpp_codegen_stind<int32_t>((int32_t*)G_B46_1, (int32_t)G_B46_0);
		int32_t L_108 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_108, 1));
	}

IL_0269:
	{
		int32_t L_109 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_110;
		L_110 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_109) < ((int32_t)L_110)))
		{
			goto IL_0239;
		}
	}
	{
		int32_t* L_111 = V_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_112;
		memset((&L_112), 0, sizeof(L_112));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_112), (void*)L_111, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_112;
	}

IL_027a:
	{
		bool L_113 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_113)
		{
			goto IL_02e8;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_114;
		L_114 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_115 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_114,NULL));
		if ((uintptr_t)L_115 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_116 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_115, 8));
		int8_t* L_117;
		if (L_116 == 0)
		{
			L_117 = NULL;
		}
		else
		{
			L_117 = (int8_t*)alloca(L_116);
			memset(L_117, 0, L_116);
		}
		V_12 = (uint64_t*)L_117;
		V_13 = 0;
		goto IL_02d7;
	}

IL_02a6:
	{
		uint64_t* L_118 = V_12;
		int32_t L_119 = V_13;
		intptr_t L_120 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_119,NULL));
		int32_t L_121 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_121, (Il2CppFullySharedGenericStruct*)L_122);
		int32_t L_123 = V_13;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_123, (Il2CppFullySharedGenericStruct*)L_124);
		bool L_125;
		L_125 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_122, L_124);
		if (L_125)
		{
			G_B53_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_118, ((intptr_t)il2cpp_codegen_multiply(L_120, 8))));
			goto IL_02cb;
		}
		G_B52_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_118, ((intptr_t)il2cpp_codegen_multiply(L_120, 8))));
	}
	{
		int64_t L_126 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B54_0 = ((uint64_t)(L_126));
		G_B54_1 = G_B52_0;
		goto IL_02d0;
	}

IL_02cb:
	{
		uint64_t L_127;
		L_127 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B54_0 = L_127;
		G_B54_1 = G_B53_0;
	}

IL_02d0:
	{
		il2cpp_codegen_stind<int64_t>((int64_t*)G_B54_1, (int64_t)G_B54_0);
		int32_t L_128 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_128, 1));
	}

IL_02d7:
	{
		int32_t L_129 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_130;
		L_130 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_129) < ((int32_t)L_130)))
		{
			goto IL_02a6;
		}
	}
	{
		uint64_t* L_131 = V_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_132;
		memset((&L_132), 0, sizeof(L_132));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_132), (void*)L_131, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_132;
	}

IL_02e8:
	{
		bool L_133 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_133)
		{
			goto IL_0356;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_134;
		L_134 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_135 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_134,NULL));
		if ((uintptr_t)L_135 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_136 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_135, 8));
		int8_t* L_137;
		if (L_136 == 0)
		{
			L_137 = NULL;
		}
		else
		{
			L_137 = (int8_t*)alloca(L_136);
			memset(L_137, 0, L_136);
		}
		V_14 = (int64_t*)L_137;
		V_15 = 0;
		goto IL_0345;
	}

IL_0314:
	{
		int64_t* L_138 = V_14;
		int32_t L_139 = V_15;
		intptr_t L_140 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_139,NULL));
		int32_t L_141 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_141, (Il2CppFullySharedGenericStruct*)L_142);
		int32_t L_143 = V_15;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_143, (Il2CppFullySharedGenericStruct*)L_144);
		bool L_145;
		L_145 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_142, L_144);
		if (L_145)
		{
			G_B61_0 = ((int64_t*)il2cpp_codegen_add((intptr_t)L_138, ((intptr_t)il2cpp_codegen_multiply(L_140, 8))));
			goto IL_0339;
		}
		G_B60_0 = ((int64_t*)il2cpp_codegen_add((intptr_t)L_138, ((intptr_t)il2cpp_codegen_multiply(L_140, 8))));
	}
	{
		int64_t L_146 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B62_0 = L_146;
		G_B62_1 = G_B60_0;
		goto IL_033e;
	}

IL_0339:
	{
		int64_t L_147;
		L_147 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		G_B62_0 = L_147;
		G_B62_1 = G_B61_0;
	}

IL_033e:
	{
		il2cpp_codegen_stind<int64_t>((int64_t*)G_B62_1, (int64_t)G_B62_0);
		int32_t L_148 = V_15;
		V_15 = ((int32_t)il2cpp_codegen_add(L_148, 1));
	}

IL_0345:
	{
		int32_t L_149 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_150;
		L_150 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_149) < ((int32_t)L_150)))
		{
			goto IL_0314;
		}
	}
	{
		int64_t* L_151 = V_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_152;
		memset((&L_152), 0, sizeof(L_152));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_152), (void*)L_151, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_152;
	}

IL_0356:
	{
		bool L_153 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_153)
		{
			goto IL_03c7;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_154;
		L_154 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_155 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_154,NULL));
		if ((uintptr_t)L_155 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_156 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_155, 4));
		int8_t* L_157;
		if (L_156 == 0)
		{
			L_157 = NULL;
		}
		else
		{
			L_157 = (int8_t*)alloca(L_156);
			memset(L_157, 0, L_156);
		}
		V_16 = (float*)L_157;
		V_17 = 0;
		goto IL_03b6;
	}

IL_0382:
	{
		float* L_158 = V_16;
		int32_t L_159 = V_17;
		intptr_t L_160 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_159,NULL));
		int32_t L_161 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_161, (Il2CppFullySharedGenericStruct*)L_162);
		int32_t L_163 = V_17;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_163, (Il2CppFullySharedGenericStruct*)L_164);
		bool L_165;
		L_165 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_162, L_164);
		if (L_165)
		{
			G_B69_0 = ((float*)il2cpp_codegen_add((intptr_t)L_158, ((intptr_t)il2cpp_codegen_multiply(L_160, 4))));
			goto IL_03aa;
		}
		G_B68_0 = ((float*)il2cpp_codegen_add((intptr_t)L_158, ((intptr_t)il2cpp_codegen_multiply(L_160, 4))));
	}
	{
		G_B70_0 = (0.0f);
		G_B70_1 = G_B68_0;
		goto IL_03af;
	}

IL_03aa:
	{
		float L_166;
		L_166 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B70_0 = L_166;
		G_B70_1 = G_B69_0;
	}

IL_03af:
	{
		il2cpp_codegen_stind<float>((float*)G_B70_1, (float)G_B70_0);
		int32_t L_167 = V_17;
		V_17 = ((int32_t)il2cpp_codegen_add(L_167, 1));
	}

IL_03b6:
	{
		int32_t L_168 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_169;
		L_169 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_168) < ((int32_t)L_169)))
		{
			goto IL_0382;
		}
	}
	{
		float* L_170 = V_16;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_171;
		memset((&L_171), 0, sizeof(L_171));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_171), (void*)L_170, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_171;
	}

IL_03c7:
	{
		bool L_172 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_172)
		{
			goto IL_043c;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_173;
		L_173 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_174 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_173,NULL));
		if ((uintptr_t)L_174 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_175 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_174, 8));
		int8_t* L_176;
		if (L_175 == 0)
		{
			L_176 = NULL;
		}
		else
		{
			L_176 = (int8_t*)alloca(L_175);
			memset(L_176, 0, L_175);
		}
		V_18 = (double*)L_176;
		V_19 = 0;
		goto IL_042b;
	}

IL_03f3:
	{
		double* L_177 = V_18;
		int32_t L_178 = V_19;
		intptr_t L_179 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_178,NULL));
		int32_t L_180 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_180, (Il2CppFullySharedGenericStruct*)L_181);
		int32_t L_182 = V_19;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_182, (Il2CppFullySharedGenericStruct*)L_183);
		bool L_184;
		L_184 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_181, L_183);
		if (L_184)
		{
			G_B77_0 = ((double*)il2cpp_codegen_add((intptr_t)L_177, ((intptr_t)il2cpp_codegen_multiply(L_179, 8))));
			goto IL_041f;
		}
		G_B76_0 = ((double*)il2cpp_codegen_add((intptr_t)L_177, ((intptr_t)il2cpp_codegen_multiply(L_179, 8))));
	}
	{
		G_B78_0 = (0.0);
		G_B78_1 = G_B76_0;
		goto IL_0424;
	}

IL_041f:
	{
		double L_185;
		L_185 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		G_B78_0 = L_185;
		G_B78_1 = G_B77_0;
	}

IL_0424:
	{
		il2cpp_codegen_stind<double>((double*)G_B78_1, (double)G_B78_0);
		int32_t L_186 = V_19;
		V_19 = ((int32_t)il2cpp_codegen_add(L_186, 1));
	}

IL_042b:
	{
		int32_t L_187 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_188;
		L_188 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_187) < ((int32_t)L_188)))
		{
			goto IL_03f3;
		}
	}
	{
		double* L_189 = V_18;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_190;
		memset((&L_190), 0, sizeof(L_190));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_190), (void*)L_189, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_190;
	}

IL_043c:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_191 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_191, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_191, method);
	}

IL_0447:
	{
		il2cpp_codegen_initobj((&V_20), sizeof(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A));
		bool L_192 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_192)
		{
			goto IL_06e5;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_193 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_194 = L_193.___register;
		uint8_t L_195 = L_194.___byte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_196 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_197 = L_196.___register;
		uint8_t L_198 = L_197.___byte_0;
		if ((((int32_t)L_195) == ((int32_t)L_198)))
		{
			G_B85_0 = (&V_20);
			goto IL_048a;
		}
		G_B84_0 = (&V_20);
	}
	{
		G_B86_0 = 0;
		G_B86_1 = G_B84_0;
		goto IL_048f;
	}

IL_048a:
	{
		uint8_t L_199;
		L_199 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B86_0 = ((int32_t)(L_199));
		G_B86_1 = G_B85_0;
	}

IL_048f:
	{
		G_B86_1->___byte_0 = (uint8_t)G_B86_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_200 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_201 = L_200.___register;
		uint8_t L_202 = L_201.___byte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_203 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_204 = L_203.___register;
		uint8_t L_205 = L_204.___byte_1;
		if ((((int32_t)L_202) == ((int32_t)L_205)))
		{
			G_B88_0 = (&V_20);
			goto IL_04b1;
		}
		G_B87_0 = (&V_20);
	}
	{
		G_B89_0 = 0;
		G_B89_1 = G_B87_0;
		goto IL_04b6;
	}

IL_04b1:
	{
		uint8_t L_206;
		L_206 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B89_0 = ((int32_t)(L_206));
		G_B89_1 = G_B88_0;
	}

IL_04b6:
	{
		G_B89_1->___byte_1 = (uint8_t)G_B89_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_207 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_208 = L_207.___register;
		uint8_t L_209 = L_208.___byte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_210 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_211 = L_210.___register;
		uint8_t L_212 = L_211.___byte_2;
		if ((((int32_t)L_209) == ((int32_t)L_212)))
		{
			G_B91_0 = (&V_20);
			goto IL_04d8;
		}
		G_B90_0 = (&V_20);
	}
	{
		G_B92_0 = 0;
		G_B92_1 = G_B90_0;
		goto IL_04dd;
	}

IL_04d8:
	{
		uint8_t L_213;
		L_213 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B92_0 = ((int32_t)(L_213));
		G_B92_1 = G_B91_0;
	}

IL_04dd:
	{
		G_B92_1->___byte_2 = (uint8_t)G_B92_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_214 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_215 = L_214.___register;
		uint8_t L_216 = L_215.___byte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_217 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_218 = L_217.___register;
		uint8_t L_219 = L_218.___byte_3;
		if ((((int32_t)L_216) == ((int32_t)L_219)))
		{
			G_B94_0 = (&V_20);
			goto IL_04ff;
		}
		G_B93_0 = (&V_20);
	}
	{
		G_B95_0 = 0;
		G_B95_1 = G_B93_0;
		goto IL_0504;
	}

IL_04ff:
	{
		uint8_t L_220;
		L_220 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B95_0 = ((int32_t)(L_220));
		G_B95_1 = G_B94_0;
	}

IL_0504:
	{
		G_B95_1->___byte_3 = (uint8_t)G_B95_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_221 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_222 = L_221.___register;
		uint8_t L_223 = L_222.___byte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_224 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_225 = L_224.___register;
		uint8_t L_226 = L_225.___byte_4;
		if ((((int32_t)L_223) == ((int32_t)L_226)))
		{
			G_B97_0 = (&V_20);
			goto IL_0526;
		}
		G_B96_0 = (&V_20);
	}
	{
		G_B98_0 = 0;
		G_B98_1 = G_B96_0;
		goto IL_052b;
	}

IL_0526:
	{
		uint8_t L_227;
		L_227 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B98_0 = ((int32_t)(L_227));
		G_B98_1 = G_B97_0;
	}

IL_052b:
	{
		G_B98_1->___byte_4 = (uint8_t)G_B98_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_228 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_229 = L_228.___register;
		uint8_t L_230 = L_229.___byte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_231 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_232 = L_231.___register;
		uint8_t L_233 = L_232.___byte_5;
		if ((((int32_t)L_230) == ((int32_t)L_233)))
		{
			G_B100_0 = (&V_20);
			goto IL_054d;
		}
		G_B99_0 = (&V_20);
	}
	{
		G_B101_0 = 0;
		G_B101_1 = G_B99_0;
		goto IL_0552;
	}

IL_054d:
	{
		uint8_t L_234;
		L_234 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B101_0 = ((int32_t)(L_234));
		G_B101_1 = G_B100_0;
	}

IL_0552:
	{
		G_B101_1->___byte_5 = (uint8_t)G_B101_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_235 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_236 = L_235.___register;
		uint8_t L_237 = L_236.___byte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_238 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_239 = L_238.___register;
		uint8_t L_240 = L_239.___byte_6;
		if ((((int32_t)L_237) == ((int32_t)L_240)))
		{
			G_B103_0 = (&V_20);
			goto IL_0574;
		}
		G_B102_0 = (&V_20);
	}
	{
		G_B104_0 = 0;
		G_B104_1 = G_B102_0;
		goto IL_0579;
	}

IL_0574:
	{
		uint8_t L_241;
		L_241 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B104_0 = ((int32_t)(L_241));
		G_B104_1 = G_B103_0;
	}

IL_0579:
	{
		G_B104_1->___byte_6 = (uint8_t)G_B104_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_242 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_243 = L_242.___register;
		uint8_t L_244 = L_243.___byte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_245 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_246 = L_245.___register;
		uint8_t L_247 = L_246.___byte_7;
		if ((((int32_t)L_244) == ((int32_t)L_247)))
		{
			G_B106_0 = (&V_20);
			goto IL_059b;
		}
		G_B105_0 = (&V_20);
	}
	{
		G_B107_0 = 0;
		G_B107_1 = G_B105_0;
		goto IL_05a0;
	}

IL_059b:
	{
		uint8_t L_248;
		L_248 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B107_0 = ((int32_t)(L_248));
		G_B107_1 = G_B106_0;
	}

IL_05a0:
	{
		G_B107_1->___byte_7 = (uint8_t)G_B107_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_249 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_250 = L_249.___register;
		uint8_t L_251 = L_250.___byte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_252 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_253 = L_252.___register;
		uint8_t L_254 = L_253.___byte_8;
		if ((((int32_t)L_251) == ((int32_t)L_254)))
		{
			G_B109_0 = (&V_20);
			goto IL_05c2;
		}
		G_B108_0 = (&V_20);
	}
	{
		G_B110_0 = 0;
		G_B110_1 = G_B108_0;
		goto IL_05c7;
	}

IL_05c2:
	{
		uint8_t L_255;
		L_255 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B110_0 = ((int32_t)(L_255));
		G_B110_1 = G_B109_0;
	}

IL_05c7:
	{
		G_B110_1->___byte_8 = (uint8_t)G_B110_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_256 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_257 = L_256.___register;
		uint8_t L_258 = L_257.___byte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_259 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_260 = L_259.___register;
		uint8_t L_261 = L_260.___byte_9;
		if ((((int32_t)L_258) == ((int32_t)L_261)))
		{
			G_B112_0 = (&V_20);
			goto IL_05e9;
		}
		G_B111_0 = (&V_20);
	}
	{
		G_B113_0 = 0;
		G_B113_1 = G_B111_0;
		goto IL_05ee;
	}

IL_05e9:
	{
		uint8_t L_262;
		L_262 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B113_0 = ((int32_t)(L_262));
		G_B113_1 = G_B112_0;
	}

IL_05ee:
	{
		G_B113_1->___byte_9 = (uint8_t)G_B113_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_263 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_264 = L_263.___register;
		uint8_t L_265 = L_264.___byte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_266 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_267 = L_266.___register;
		uint8_t L_268 = L_267.___byte_10;
		if ((((int32_t)L_265) == ((int32_t)L_268)))
		{
			G_B115_0 = (&V_20);
			goto IL_0610;
		}
		G_B114_0 = (&V_20);
	}
	{
		G_B116_0 = 0;
		G_B116_1 = G_B114_0;
		goto IL_0615;
	}

IL_0610:
	{
		uint8_t L_269;
		L_269 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B116_0 = ((int32_t)(L_269));
		G_B116_1 = G_B115_0;
	}

IL_0615:
	{
		G_B116_1->___byte_10 = (uint8_t)G_B116_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_270 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_271 = L_270.___register;
		uint8_t L_272 = L_271.___byte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_273 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_274 = L_273.___register;
		uint8_t L_275 = L_274.___byte_11;
		if ((((int32_t)L_272) == ((int32_t)L_275)))
		{
			G_B118_0 = (&V_20);
			goto IL_0637;
		}
		G_B117_0 = (&V_20);
	}
	{
		G_B119_0 = 0;
		G_B119_1 = G_B117_0;
		goto IL_063c;
	}

IL_0637:
	{
		uint8_t L_276;
		L_276 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B119_0 = ((int32_t)(L_276));
		G_B119_1 = G_B118_0;
	}

IL_063c:
	{
		G_B119_1->___byte_11 = (uint8_t)G_B119_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_277 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_278 = L_277.___register;
		uint8_t L_279 = L_278.___byte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_280 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_281 = L_280.___register;
		uint8_t L_282 = L_281.___byte_12;
		if ((((int32_t)L_279) == ((int32_t)L_282)))
		{
			G_B121_0 = (&V_20);
			goto IL_065e;
		}
		G_B120_0 = (&V_20);
	}
	{
		G_B122_0 = 0;
		G_B122_1 = G_B120_0;
		goto IL_0663;
	}

IL_065e:
	{
		uint8_t L_283;
		L_283 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B122_0 = ((int32_t)(L_283));
		G_B122_1 = G_B121_0;
	}

IL_0663:
	{
		G_B122_1->___byte_12 = (uint8_t)G_B122_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_284 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_285 = L_284.___register;
		uint8_t L_286 = L_285.___byte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_287 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_288 = L_287.___register;
		uint8_t L_289 = L_288.___byte_13;
		if ((((int32_t)L_286) == ((int32_t)L_289)))
		{
			G_B124_0 = (&V_20);
			goto IL_0685;
		}
		G_B123_0 = (&V_20);
	}
	{
		G_B125_0 = 0;
		G_B125_1 = G_B123_0;
		goto IL_068a;
	}

IL_0685:
	{
		uint8_t L_290;
		L_290 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B125_0 = ((int32_t)(L_290));
		G_B125_1 = G_B124_0;
	}

IL_068a:
	{
		G_B125_1->___byte_13 = (uint8_t)G_B125_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_291 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_292 = L_291.___register;
		uint8_t L_293 = L_292.___byte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_294 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_295 = L_294.___register;
		uint8_t L_296 = L_295.___byte_14;
		if ((((int32_t)L_293) == ((int32_t)L_296)))
		{
			G_B127_0 = (&V_20);
			goto IL_06ac;
		}
		G_B126_0 = (&V_20);
	}
	{
		G_B128_0 = 0;
		G_B128_1 = G_B126_0;
		goto IL_06b1;
	}

IL_06ac:
	{
		uint8_t L_297;
		L_297 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B128_0 = ((int32_t)(L_297));
		G_B128_1 = G_B127_0;
	}

IL_06b1:
	{
		G_B128_1->___byte_14 = (uint8_t)G_B128_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_298 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_299 = L_298.___register;
		uint8_t L_300 = L_299.___byte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_301 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_302 = L_301.___register;
		uint8_t L_303 = L_302.___byte_15;
		if ((((int32_t)L_300) == ((int32_t)L_303)))
		{
			G_B130_0 = (&V_20);
			goto IL_06d3;
		}
		G_B129_0 = (&V_20);
	}
	{
		G_B131_0 = 0;
		G_B131_1 = G_B129_0;
		goto IL_06d8;
	}

IL_06d3:
	{
		uint8_t L_304;
		L_304 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B131_0 = ((int32_t)(L_304));
		G_B131_1 = G_B130_0;
	}

IL_06d8:
	{
		G_B131_1->___byte_15 = (uint8_t)G_B131_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_305;
		memset((&L_305), 0, sizeof(L_305));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_305), (&V_20), NULL);
		return L_305;
	}

IL_06e5:
	{
		bool L_306 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_306)
		{
			goto IL_097b;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_307 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_308 = L_307.___register;
		int8_t L_309 = L_308.___sbyte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_310 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_311 = L_310.___register;
		int8_t L_312 = L_311.___sbyte_0;
		if ((((int32_t)L_309) == ((int32_t)L_312)))
		{
			G_B135_0 = (&V_20);
			goto IL_0720;
		}
		G_B134_0 = (&V_20);
	}
	{
		G_B136_0 = 0;
		G_B136_1 = G_B134_0;
		goto IL_0725;
	}

IL_0720:
	{
		int8_t L_313;
		L_313 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B136_0 = ((int32_t)(L_313));
		G_B136_1 = G_B135_0;
	}

IL_0725:
	{
		G_B136_1->___sbyte_0 = (int8_t)G_B136_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_314 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_315 = L_314.___register;
		int8_t L_316 = L_315.___sbyte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_317 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_318 = L_317.___register;
		int8_t L_319 = L_318.___sbyte_1;
		if ((((int32_t)L_316) == ((int32_t)L_319)))
		{
			G_B138_0 = (&V_20);
			goto IL_0747;
		}
		G_B137_0 = (&V_20);
	}
	{
		G_B139_0 = 0;
		G_B139_1 = G_B137_0;
		goto IL_074c;
	}

IL_0747:
	{
		int8_t L_320;
		L_320 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B139_0 = ((int32_t)(L_320));
		G_B139_1 = G_B138_0;
	}

IL_074c:
	{
		G_B139_1->___sbyte_1 = (int8_t)G_B139_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_321 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_322 = L_321.___register;
		int8_t L_323 = L_322.___sbyte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_324 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_325 = L_324.___register;
		int8_t L_326 = L_325.___sbyte_2;
		if ((((int32_t)L_323) == ((int32_t)L_326)))
		{
			G_B141_0 = (&V_20);
			goto IL_076e;
		}
		G_B140_0 = (&V_20);
	}
	{
		G_B142_0 = 0;
		G_B142_1 = G_B140_0;
		goto IL_0773;
	}

IL_076e:
	{
		int8_t L_327;
		L_327 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B142_0 = ((int32_t)(L_327));
		G_B142_1 = G_B141_0;
	}

IL_0773:
	{
		G_B142_1->___sbyte_2 = (int8_t)G_B142_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_328 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_329 = L_328.___register;
		int8_t L_330 = L_329.___sbyte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_331 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_332 = L_331.___register;
		int8_t L_333 = L_332.___sbyte_3;
		if ((((int32_t)L_330) == ((int32_t)L_333)))
		{
			G_B144_0 = (&V_20);
			goto IL_0795;
		}
		G_B143_0 = (&V_20);
	}
	{
		G_B145_0 = 0;
		G_B145_1 = G_B143_0;
		goto IL_079a;
	}

IL_0795:
	{
		int8_t L_334;
		L_334 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B145_0 = ((int32_t)(L_334));
		G_B145_1 = G_B144_0;
	}

IL_079a:
	{
		G_B145_1->___sbyte_3 = (int8_t)G_B145_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_335 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_336 = L_335.___register;
		int8_t L_337 = L_336.___sbyte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_338 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_339 = L_338.___register;
		int8_t L_340 = L_339.___sbyte_4;
		if ((((int32_t)L_337) == ((int32_t)L_340)))
		{
			G_B147_0 = (&V_20);
			goto IL_07bc;
		}
		G_B146_0 = (&V_20);
	}
	{
		G_B148_0 = 0;
		G_B148_1 = G_B146_0;
		goto IL_07c1;
	}

IL_07bc:
	{
		int8_t L_341;
		L_341 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B148_0 = ((int32_t)(L_341));
		G_B148_1 = G_B147_0;
	}

IL_07c1:
	{
		G_B148_1->___sbyte_4 = (int8_t)G_B148_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_342 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_343 = L_342.___register;
		int8_t L_344 = L_343.___sbyte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_345 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_346 = L_345.___register;
		int8_t L_347 = L_346.___sbyte_5;
		if ((((int32_t)L_344) == ((int32_t)L_347)))
		{
			G_B150_0 = (&V_20);
			goto IL_07e3;
		}
		G_B149_0 = (&V_20);
	}
	{
		G_B151_0 = 0;
		G_B151_1 = G_B149_0;
		goto IL_07e8;
	}

IL_07e3:
	{
		int8_t L_348;
		L_348 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B151_0 = ((int32_t)(L_348));
		G_B151_1 = G_B150_0;
	}

IL_07e8:
	{
		G_B151_1->___sbyte_5 = (int8_t)G_B151_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_349 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_350 = L_349.___register;
		int8_t L_351 = L_350.___sbyte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_352 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_353 = L_352.___register;
		int8_t L_354 = L_353.___sbyte_6;
		if ((((int32_t)L_351) == ((int32_t)L_354)))
		{
			G_B153_0 = (&V_20);
			goto IL_080a;
		}
		G_B152_0 = (&V_20);
	}
	{
		G_B154_0 = 0;
		G_B154_1 = G_B152_0;
		goto IL_080f;
	}

IL_080a:
	{
		int8_t L_355;
		L_355 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B154_0 = ((int32_t)(L_355));
		G_B154_1 = G_B153_0;
	}

IL_080f:
	{
		G_B154_1->___sbyte_6 = (int8_t)G_B154_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_356 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_357 = L_356.___register;
		int8_t L_358 = L_357.___sbyte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_359 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_360 = L_359.___register;
		int8_t L_361 = L_360.___sbyte_7;
		if ((((int32_t)L_358) == ((int32_t)L_361)))
		{
			G_B156_0 = (&V_20);
			goto IL_0831;
		}
		G_B155_0 = (&V_20);
	}
	{
		G_B157_0 = 0;
		G_B157_1 = G_B155_0;
		goto IL_0836;
	}

IL_0831:
	{
		int8_t L_362;
		L_362 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B157_0 = ((int32_t)(L_362));
		G_B157_1 = G_B156_0;
	}

IL_0836:
	{
		G_B157_1->___sbyte_7 = (int8_t)G_B157_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_363 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_364 = L_363.___register;
		int8_t L_365 = L_364.___sbyte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_366 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_367 = L_366.___register;
		int8_t L_368 = L_367.___sbyte_8;
		if ((((int32_t)L_365) == ((int32_t)L_368)))
		{
			G_B159_0 = (&V_20);
			goto IL_0858;
		}
		G_B158_0 = (&V_20);
	}
	{
		G_B160_0 = 0;
		G_B160_1 = G_B158_0;
		goto IL_085d;
	}

IL_0858:
	{
		int8_t L_369;
		L_369 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B160_0 = ((int32_t)(L_369));
		G_B160_1 = G_B159_0;
	}

IL_085d:
	{
		G_B160_1->___sbyte_8 = (int8_t)G_B160_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_370 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_371 = L_370.___register;
		int8_t L_372 = L_371.___sbyte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_373 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_374 = L_373.___register;
		int8_t L_375 = L_374.___sbyte_9;
		if ((((int32_t)L_372) == ((int32_t)L_375)))
		{
			G_B162_0 = (&V_20);
			goto IL_087f;
		}
		G_B161_0 = (&V_20);
	}
	{
		G_B163_0 = 0;
		G_B163_1 = G_B161_0;
		goto IL_0884;
	}

IL_087f:
	{
		int8_t L_376;
		L_376 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B163_0 = ((int32_t)(L_376));
		G_B163_1 = G_B162_0;
	}

IL_0884:
	{
		G_B163_1->___sbyte_9 = (int8_t)G_B163_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_377 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_378 = L_377.___register;
		int8_t L_379 = L_378.___sbyte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_380 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_381 = L_380.___register;
		int8_t L_382 = L_381.___sbyte_10;
		if ((((int32_t)L_379) == ((int32_t)L_382)))
		{
			G_B165_0 = (&V_20);
			goto IL_08a6;
		}
		G_B164_0 = (&V_20);
	}
	{
		G_B166_0 = 0;
		G_B166_1 = G_B164_0;
		goto IL_08ab;
	}

IL_08a6:
	{
		int8_t L_383;
		L_383 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B166_0 = ((int32_t)(L_383));
		G_B166_1 = G_B165_0;
	}

IL_08ab:
	{
		G_B166_1->___sbyte_10 = (int8_t)G_B166_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_384 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_385 = L_384.___register;
		int8_t L_386 = L_385.___sbyte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_387 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_388 = L_387.___register;
		int8_t L_389 = L_388.___sbyte_11;
		if ((((int32_t)L_386) == ((int32_t)L_389)))
		{
			G_B168_0 = (&V_20);
			goto IL_08cd;
		}
		G_B167_0 = (&V_20);
	}
	{
		G_B169_0 = 0;
		G_B169_1 = G_B167_0;
		goto IL_08d2;
	}

IL_08cd:
	{
		int8_t L_390;
		L_390 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B169_0 = ((int32_t)(L_390));
		G_B169_1 = G_B168_0;
	}

IL_08d2:
	{
		G_B169_1->___sbyte_11 = (int8_t)G_B169_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_391 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_392 = L_391.___register;
		int8_t L_393 = L_392.___sbyte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_394 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_395 = L_394.___register;
		int8_t L_396 = L_395.___sbyte_12;
		if ((((int32_t)L_393) == ((int32_t)L_396)))
		{
			G_B171_0 = (&V_20);
			goto IL_08f4;
		}
		G_B170_0 = (&V_20);
	}
	{
		G_B172_0 = 0;
		G_B172_1 = G_B170_0;
		goto IL_08f9;
	}

IL_08f4:
	{
		int8_t L_397;
		L_397 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B172_0 = ((int32_t)(L_397));
		G_B172_1 = G_B171_0;
	}

IL_08f9:
	{
		G_B172_1->___sbyte_12 = (int8_t)G_B172_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_398 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_399 = L_398.___register;
		int8_t L_400 = L_399.___sbyte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_401 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_402 = L_401.___register;
		int8_t L_403 = L_402.___sbyte_13;
		if ((((int32_t)L_400) == ((int32_t)L_403)))
		{
			G_B174_0 = (&V_20);
			goto IL_091b;
		}
		G_B173_0 = (&V_20);
	}
	{
		G_B175_0 = 0;
		G_B175_1 = G_B173_0;
		goto IL_0920;
	}

IL_091b:
	{
		int8_t L_404;
		L_404 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B175_0 = ((int32_t)(L_404));
		G_B175_1 = G_B174_0;
	}

IL_0920:
	{
		G_B175_1->___sbyte_13 = (int8_t)G_B175_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_405 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_406 = L_405.___register;
		int8_t L_407 = L_406.___sbyte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_408 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_409 = L_408.___register;
		int8_t L_410 = L_409.___sbyte_14;
		if ((((int32_t)L_407) == ((int32_t)L_410)))
		{
			G_B177_0 = (&V_20);
			goto IL_0942;
		}
		G_B176_0 = (&V_20);
	}
	{
		G_B178_0 = 0;
		G_B178_1 = G_B176_0;
		goto IL_0947;
	}

IL_0942:
	{
		int8_t L_411;
		L_411 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B178_0 = ((int32_t)(L_411));
		G_B178_1 = G_B177_0;
	}

IL_0947:
	{
		G_B178_1->___sbyte_14 = (int8_t)G_B178_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_412 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_413 = L_412.___register;
		int8_t L_414 = L_413.___sbyte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_415 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_416 = L_415.___register;
		int8_t L_417 = L_416.___sbyte_15;
		if ((((int32_t)L_414) == ((int32_t)L_417)))
		{
			G_B180_0 = (&V_20);
			goto IL_0969;
		}
		G_B179_0 = (&V_20);
	}
	{
		G_B181_0 = 0;
		G_B181_1 = G_B179_0;
		goto IL_096e;
	}

IL_0969:
	{
		int8_t L_418;
		L_418 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B181_0 = ((int32_t)(L_418));
		G_B181_1 = G_B180_0;
	}

IL_096e:
	{
		G_B181_1->___sbyte_15 = (int8_t)G_B181_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_419;
		memset((&L_419), 0, sizeof(L_419));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_419), (&V_20), NULL);
		return L_419;
	}

IL_097b:
	{
		bool L_420 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_420)
		{
			goto IL_0ad9;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_421 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_422 = L_421.___register;
		uint16_t L_423 = L_422.___uint16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_424 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_425 = L_424.___register;
		uint16_t L_426 = L_425.___uint16_0;
		if ((((int32_t)L_423) == ((int32_t)L_426)))
		{
			G_B185_0 = (&V_20);
			goto IL_09b6;
		}
		G_B184_0 = (&V_20);
	}
	{
		G_B186_0 = 0;
		G_B186_1 = G_B184_0;
		goto IL_09bb;
	}

IL_09b6:
	{
		uint16_t L_427;
		L_427 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B186_0 = ((int32_t)(L_427));
		G_B186_1 = G_B185_0;
	}

IL_09bb:
	{
		G_B186_1->___uint16_0 = (uint16_t)G_B186_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_428 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_429 = L_428.___register;
		uint16_t L_430 = L_429.___uint16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_431 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_432 = L_431.___register;
		uint16_t L_433 = L_432.___uint16_1;
		if ((((int32_t)L_430) == ((int32_t)L_433)))
		{
			G_B188_0 = (&V_20);
			goto IL_09dd;
		}
		G_B187_0 = (&V_20);
	}
	{
		G_B189_0 = 0;
		G_B189_1 = G_B187_0;
		goto IL_09e2;
	}

IL_09dd:
	{
		uint16_t L_434;
		L_434 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B189_0 = ((int32_t)(L_434));
		G_B189_1 = G_B188_0;
	}

IL_09e2:
	{
		G_B189_1->___uint16_1 = (uint16_t)G_B189_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_435 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_436 = L_435.___register;
		uint16_t L_437 = L_436.___uint16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_438 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_439 = L_438.___register;
		uint16_t L_440 = L_439.___uint16_2;
		if ((((int32_t)L_437) == ((int32_t)L_440)))
		{
			G_B191_0 = (&V_20);
			goto IL_0a04;
		}
		G_B190_0 = (&V_20);
	}
	{
		G_B192_0 = 0;
		G_B192_1 = G_B190_0;
		goto IL_0a09;
	}

IL_0a04:
	{
		uint16_t L_441;
		L_441 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B192_0 = ((int32_t)(L_441));
		G_B192_1 = G_B191_0;
	}

IL_0a09:
	{
		G_B192_1->___uint16_2 = (uint16_t)G_B192_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_442 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_443 = L_442.___register;
		uint16_t L_444 = L_443.___uint16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_445 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_446 = L_445.___register;
		uint16_t L_447 = L_446.___uint16_3;
		if ((((int32_t)L_444) == ((int32_t)L_447)))
		{
			G_B194_0 = (&V_20);
			goto IL_0a2b;
		}
		G_B193_0 = (&V_20);
	}
	{
		G_B195_0 = 0;
		G_B195_1 = G_B193_0;
		goto IL_0a30;
	}

IL_0a2b:
	{
		uint16_t L_448;
		L_448 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B195_0 = ((int32_t)(L_448));
		G_B195_1 = G_B194_0;
	}

IL_0a30:
	{
		G_B195_1->___uint16_3 = (uint16_t)G_B195_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_449 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_450 = L_449.___register;
		uint16_t L_451 = L_450.___uint16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_452 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_453 = L_452.___register;
		uint16_t L_454 = L_453.___uint16_4;
		if ((((int32_t)L_451) == ((int32_t)L_454)))
		{
			G_B197_0 = (&V_20);
			goto IL_0a52;
		}
		G_B196_0 = (&V_20);
	}
	{
		G_B198_0 = 0;
		G_B198_1 = G_B196_0;
		goto IL_0a57;
	}

IL_0a52:
	{
		uint16_t L_455;
		L_455 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B198_0 = ((int32_t)(L_455));
		G_B198_1 = G_B197_0;
	}

IL_0a57:
	{
		G_B198_1->___uint16_4 = (uint16_t)G_B198_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_456 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_457 = L_456.___register;
		uint16_t L_458 = L_457.___uint16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_459 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_460 = L_459.___register;
		uint16_t L_461 = L_460.___uint16_5;
		if ((((int32_t)L_458) == ((int32_t)L_461)))
		{
			G_B200_0 = (&V_20);
			goto IL_0a79;
		}
		G_B199_0 = (&V_20);
	}
	{
		G_B201_0 = 0;
		G_B201_1 = G_B199_0;
		goto IL_0a7e;
	}

IL_0a79:
	{
		uint16_t L_462;
		L_462 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B201_0 = ((int32_t)(L_462));
		G_B201_1 = G_B200_0;
	}

IL_0a7e:
	{
		G_B201_1->___uint16_5 = (uint16_t)G_B201_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_463 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_464 = L_463.___register;
		uint16_t L_465 = L_464.___uint16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_466 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_467 = L_466.___register;
		uint16_t L_468 = L_467.___uint16_6;
		if ((((int32_t)L_465) == ((int32_t)L_468)))
		{
			G_B203_0 = (&V_20);
			goto IL_0aa0;
		}
		G_B202_0 = (&V_20);
	}
	{
		G_B204_0 = 0;
		G_B204_1 = G_B202_0;
		goto IL_0aa5;
	}

IL_0aa0:
	{
		uint16_t L_469;
		L_469 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B204_0 = ((int32_t)(L_469));
		G_B204_1 = G_B203_0;
	}

IL_0aa5:
	{
		G_B204_1->___uint16_6 = (uint16_t)G_B204_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_470 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_471 = L_470.___register;
		uint16_t L_472 = L_471.___uint16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_473 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_474 = L_473.___register;
		uint16_t L_475 = L_474.___uint16_7;
		if ((((int32_t)L_472) == ((int32_t)L_475)))
		{
			G_B206_0 = (&V_20);
			goto IL_0ac7;
		}
		G_B205_0 = (&V_20);
	}
	{
		G_B207_0 = 0;
		G_B207_1 = G_B205_0;
		goto IL_0acc;
	}

IL_0ac7:
	{
		uint16_t L_476;
		L_476 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B207_0 = ((int32_t)(L_476));
		G_B207_1 = G_B206_0;
	}

IL_0acc:
	{
		G_B207_1->___uint16_7 = (uint16_t)G_B207_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_477;
		memset((&L_477), 0, sizeof(L_477));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_477), (&V_20), NULL);
		return L_477;
	}

IL_0ad9:
	{
		bool L_478 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_478)
		{
			goto IL_0c37;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_479 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_480 = L_479.___register;
		int16_t L_481 = L_480.___int16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_482 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_483 = L_482.___register;
		int16_t L_484 = L_483.___int16_0;
		if ((((int32_t)L_481) == ((int32_t)L_484)))
		{
			G_B211_0 = (&V_20);
			goto IL_0b14;
		}
		G_B210_0 = (&V_20);
	}
	{
		G_B212_0 = 0;
		G_B212_1 = G_B210_0;
		goto IL_0b19;
	}

IL_0b14:
	{
		int16_t L_485;
		L_485 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B212_0 = ((int32_t)(L_485));
		G_B212_1 = G_B211_0;
	}

IL_0b19:
	{
		G_B212_1->___int16_0 = (int16_t)G_B212_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_486 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_487 = L_486.___register;
		int16_t L_488 = L_487.___int16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_489 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_490 = L_489.___register;
		int16_t L_491 = L_490.___int16_1;
		if ((((int32_t)L_488) == ((int32_t)L_491)))
		{
			G_B214_0 = (&V_20);
			goto IL_0b3b;
		}
		G_B213_0 = (&V_20);
	}
	{
		G_B215_0 = 0;
		G_B215_1 = G_B213_0;
		goto IL_0b40;
	}

IL_0b3b:
	{
		int16_t L_492;
		L_492 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B215_0 = ((int32_t)(L_492));
		G_B215_1 = G_B214_0;
	}

IL_0b40:
	{
		G_B215_1->___int16_1 = (int16_t)G_B215_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_493 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_494 = L_493.___register;
		int16_t L_495 = L_494.___int16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_496 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_497 = L_496.___register;
		int16_t L_498 = L_497.___int16_2;
		if ((((int32_t)L_495) == ((int32_t)L_498)))
		{
			G_B217_0 = (&V_20);
			goto IL_0b62;
		}
		G_B216_0 = (&V_20);
	}
	{
		G_B218_0 = 0;
		G_B218_1 = G_B216_0;
		goto IL_0b67;
	}

IL_0b62:
	{
		int16_t L_499;
		L_499 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B218_0 = ((int32_t)(L_499));
		G_B218_1 = G_B217_0;
	}

IL_0b67:
	{
		G_B218_1->___int16_2 = (int16_t)G_B218_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_500 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_501 = L_500.___register;
		int16_t L_502 = L_501.___int16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_503 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_504 = L_503.___register;
		int16_t L_505 = L_504.___int16_3;
		if ((((int32_t)L_502) == ((int32_t)L_505)))
		{
			G_B220_0 = (&V_20);
			goto IL_0b89;
		}
		G_B219_0 = (&V_20);
	}
	{
		G_B221_0 = 0;
		G_B221_1 = G_B219_0;
		goto IL_0b8e;
	}

IL_0b89:
	{
		int16_t L_506;
		L_506 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B221_0 = ((int32_t)(L_506));
		G_B221_1 = G_B220_0;
	}

IL_0b8e:
	{
		G_B221_1->___int16_3 = (int16_t)G_B221_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_507 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_508 = L_507.___register;
		int16_t L_509 = L_508.___int16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_510 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_511 = L_510.___register;
		int16_t L_512 = L_511.___int16_4;
		if ((((int32_t)L_509) == ((int32_t)L_512)))
		{
			G_B223_0 = (&V_20);
			goto IL_0bb0;
		}
		G_B222_0 = (&V_20);
	}
	{
		G_B224_0 = 0;
		G_B224_1 = G_B222_0;
		goto IL_0bb5;
	}

IL_0bb0:
	{
		int16_t L_513;
		L_513 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B224_0 = ((int32_t)(L_513));
		G_B224_1 = G_B223_0;
	}

IL_0bb5:
	{
		G_B224_1->___int16_4 = (int16_t)G_B224_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_514 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_515 = L_514.___register;
		int16_t L_516 = L_515.___int16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_517 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_518 = L_517.___register;
		int16_t L_519 = L_518.___int16_5;
		if ((((int32_t)L_516) == ((int32_t)L_519)))
		{
			G_B226_0 = (&V_20);
			goto IL_0bd7;
		}
		G_B225_0 = (&V_20);
	}
	{
		G_B227_0 = 0;
		G_B227_1 = G_B225_0;
		goto IL_0bdc;
	}

IL_0bd7:
	{
		int16_t L_520;
		L_520 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B227_0 = ((int32_t)(L_520));
		G_B227_1 = G_B226_0;
	}

IL_0bdc:
	{
		G_B227_1->___int16_5 = (int16_t)G_B227_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_521 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_522 = L_521.___register;
		int16_t L_523 = L_522.___int16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_524 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_525 = L_524.___register;
		int16_t L_526 = L_525.___int16_6;
		if ((((int32_t)L_523) == ((int32_t)L_526)))
		{
			G_B229_0 = (&V_20);
			goto IL_0bfe;
		}
		G_B228_0 = (&V_20);
	}
	{
		G_B230_0 = 0;
		G_B230_1 = G_B228_0;
		goto IL_0c03;
	}

IL_0bfe:
	{
		int16_t L_527;
		L_527 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B230_0 = ((int32_t)(L_527));
		G_B230_1 = G_B229_0;
	}

IL_0c03:
	{
		G_B230_1->___int16_6 = (int16_t)G_B230_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_528 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_529 = L_528.___register;
		int16_t L_530 = L_529.___int16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_531 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_532 = L_531.___register;
		int16_t L_533 = L_532.___int16_7;
		if ((((int32_t)L_530) == ((int32_t)L_533)))
		{
			G_B232_0 = (&V_20);
			goto IL_0c25;
		}
		G_B231_0 = (&V_20);
	}
	{
		G_B233_0 = 0;
		G_B233_1 = G_B231_0;
		goto IL_0c2a;
	}

IL_0c25:
	{
		int16_t L_534;
		L_534 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B233_0 = ((int32_t)(L_534));
		G_B233_1 = G_B232_0;
	}

IL_0c2a:
	{
		G_B233_1->___int16_7 = (int16_t)G_B233_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_535;
		memset((&L_535), 0, sizeof(L_535));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_535), (&V_20), NULL);
		return L_535;
	}

IL_0c37:
	{
		bool L_536 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_536)
		{
			goto IL_0cf9;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_537 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_538 = L_537.___register;
		uint32_t L_539 = L_538.___uint32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_540 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_541 = L_540.___register;
		uint32_t L_542 = L_541.___uint32_0;
		if ((((int32_t)L_539) == ((int32_t)L_542)))
		{
			G_B237_0 = (&V_20);
			goto IL_0c72;
		}
		G_B236_0 = (&V_20);
	}
	{
		G_B238_0 = ((uint32_t)(0));
		G_B238_1 = G_B236_0;
		goto IL_0c77;
	}

IL_0c72:
	{
		uint32_t L_543;
		L_543 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B238_0 = L_543;
		G_B238_1 = G_B237_0;
	}

IL_0c77:
	{
		G_B238_1->___uint32_0 = G_B238_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_544 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_545 = L_544.___register;
		uint32_t L_546 = L_545.___uint32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_547 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_548 = L_547.___register;
		uint32_t L_549 = L_548.___uint32_1;
		if ((((int32_t)L_546) == ((int32_t)L_549)))
		{
			G_B240_0 = (&V_20);
			goto IL_0c99;
		}
		G_B239_0 = (&V_20);
	}
	{
		G_B241_0 = ((uint32_t)(0));
		G_B241_1 = G_B239_0;
		goto IL_0c9e;
	}

IL_0c99:
	{
		uint32_t L_550;
		L_550 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B241_0 = L_550;
		G_B241_1 = G_B240_0;
	}

IL_0c9e:
	{
		G_B241_1->___uint32_1 = G_B241_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_551 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_552 = L_551.___register;
		uint32_t L_553 = L_552.___uint32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_554 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_555 = L_554.___register;
		uint32_t L_556 = L_555.___uint32_2;
		if ((((int32_t)L_553) == ((int32_t)L_556)))
		{
			G_B243_0 = (&V_20);
			goto IL_0cc0;
		}
		G_B242_0 = (&V_20);
	}
	{
		G_B244_0 = ((uint32_t)(0));
		G_B244_1 = G_B242_0;
		goto IL_0cc5;
	}

IL_0cc0:
	{
		uint32_t L_557;
		L_557 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B244_0 = L_557;
		G_B244_1 = G_B243_0;
	}

IL_0cc5:
	{
		G_B244_1->___uint32_2 = G_B244_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_558 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_559 = L_558.___register;
		uint32_t L_560 = L_559.___uint32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_561 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_562 = L_561.___register;
		uint32_t L_563 = L_562.___uint32_3;
		if ((((int32_t)L_560) == ((int32_t)L_563)))
		{
			G_B246_0 = (&V_20);
			goto IL_0ce7;
		}
		G_B245_0 = (&V_20);
	}
	{
		G_B247_0 = ((uint32_t)(0));
		G_B247_1 = G_B245_0;
		goto IL_0cec;
	}

IL_0ce7:
	{
		uint32_t L_564;
		L_564 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B247_0 = L_564;
		G_B247_1 = G_B246_0;
	}

IL_0cec:
	{
		G_B247_1->___uint32_3 = G_B247_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_565;
		memset((&L_565), 0, sizeof(L_565));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_565), (&V_20), NULL);
		return L_565;
	}

IL_0cf9:
	{
		bool L_566 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_566)
		{
			goto IL_0dbb;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_567 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_568 = L_567.___register;
		int32_t L_569 = L_568.___int32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_570 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_571 = L_570.___register;
		int32_t L_572 = L_571.___int32_0;
		if ((((int32_t)L_569) == ((int32_t)L_572)))
		{
			G_B251_0 = (&V_20);
			goto IL_0d34;
		}
		G_B250_0 = (&V_20);
	}
	{
		G_B252_0 = 0;
		G_B252_1 = G_B250_0;
		goto IL_0d39;
	}

IL_0d34:
	{
		int32_t L_573;
		L_573 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B252_0 = L_573;
		G_B252_1 = G_B251_0;
	}

IL_0d39:
	{
		G_B252_1->___int32_0 = G_B252_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_574 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_575 = L_574.___register;
		int32_t L_576 = L_575.___int32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_577 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_578 = L_577.___register;
		int32_t L_579 = L_578.___int32_1;
		if ((((int32_t)L_576) == ((int32_t)L_579)))
		{
			G_B254_0 = (&V_20);
			goto IL_0d5b;
		}
		G_B253_0 = (&V_20);
	}
	{
		G_B255_0 = 0;
		G_B255_1 = G_B253_0;
		goto IL_0d60;
	}

IL_0d5b:
	{
		int32_t L_580;
		L_580 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B255_0 = L_580;
		G_B255_1 = G_B254_0;
	}

IL_0d60:
	{
		G_B255_1->___int32_1 = G_B255_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_581 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_582 = L_581.___register;
		int32_t L_583 = L_582.___int32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_584 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_585 = L_584.___register;
		int32_t L_586 = L_585.___int32_2;
		if ((((int32_t)L_583) == ((int32_t)L_586)))
		{
			G_B257_0 = (&V_20);
			goto IL_0d82;
		}
		G_B256_0 = (&V_20);
	}
	{
		G_B258_0 = 0;
		G_B258_1 = G_B256_0;
		goto IL_0d87;
	}

IL_0d82:
	{
		int32_t L_587;
		L_587 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B258_0 = L_587;
		G_B258_1 = G_B257_0;
	}

IL_0d87:
	{
		G_B258_1->___int32_2 = G_B258_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_588 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_589 = L_588.___register;
		int32_t L_590 = L_589.___int32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_591 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_592 = L_591.___register;
		int32_t L_593 = L_592.___int32_3;
		if ((((int32_t)L_590) == ((int32_t)L_593)))
		{
			G_B260_0 = (&V_20);
			goto IL_0da9;
		}
		G_B259_0 = (&V_20);
	}
	{
		G_B261_0 = 0;
		G_B261_1 = G_B259_0;
		goto IL_0dae;
	}

IL_0da9:
	{
		int32_t L_594;
		L_594 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B261_0 = L_594;
		G_B261_1 = G_B260_0;
	}

IL_0dae:
	{
		G_B261_1->___int32_3 = G_B261_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_595;
		memset((&L_595), 0, sizeof(L_595));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_595), (&V_20), NULL);
		return L_595;
	}

IL_0dbb:
	{
		bool L_596 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_596)
		{
			goto IL_0e2e;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_597 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_598 = L_597.___register;
		uint64_t L_599 = L_598.___uint64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_600 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_601 = L_600.___register;
		uint64_t L_602 = L_601.___uint64_0;
		if ((((int64_t)L_599) == ((int64_t)L_602)))
		{
			G_B265_0 = (&V_20);
			goto IL_0df4;
		}
		G_B264_0 = (&V_20);
	}
	{
		int64_t L_603 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B266_0 = ((uint64_t)(L_603));
		G_B266_1 = G_B264_0;
		goto IL_0df9;
	}

IL_0df4:
	{
		uint64_t L_604;
		L_604 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B266_0 = L_604;
		G_B266_1 = G_B265_0;
	}

IL_0df9:
	{
		G_B266_1->___uint64_0 = G_B266_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_605 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_606 = L_605.___register;
		uint64_t L_607 = L_606.___uint64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_608 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_609 = L_608.___register;
		uint64_t L_610 = L_609.___uint64_1;
		if ((((int64_t)L_607) == ((int64_t)L_610)))
		{
			G_B268_0 = (&V_20);
			goto IL_0e1c;
		}
		G_B267_0 = (&V_20);
	}
	{
		int64_t L_611 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B269_0 = ((uint64_t)(L_611));
		G_B269_1 = G_B267_0;
		goto IL_0e21;
	}

IL_0e1c:
	{
		uint64_t L_612;
		L_612 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B269_0 = L_612;
		G_B269_1 = G_B268_0;
	}

IL_0e21:
	{
		G_B269_1->___uint64_1 = G_B269_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_613;
		memset((&L_613), 0, sizeof(L_613));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_613), (&V_20), NULL);
		return L_613;
	}

IL_0e2e:
	{
		bool L_614 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_614)
		{
			goto IL_0ea1;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_615 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_616 = L_615.___register;
		int64_t L_617 = L_616.___int64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_618 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_619 = L_618.___register;
		int64_t L_620 = L_619.___int64_0;
		if ((((int64_t)L_617) == ((int64_t)L_620)))
		{
			G_B273_0 = (&V_20);
			goto IL_0e67;
		}
		G_B272_0 = (&V_20);
	}
	{
		int64_t L_621 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B274_0 = L_621;
		G_B274_1 = G_B272_0;
		goto IL_0e6c;
	}

IL_0e67:
	{
		int64_t L_622;
		L_622 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		G_B274_0 = L_622;
		G_B274_1 = G_B273_0;
	}

IL_0e6c:
	{
		G_B274_1->___int64_0 = G_B274_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_623 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_624 = L_623.___register;
		int64_t L_625 = L_624.___int64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_626 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_627 = L_626.___register;
		int64_t L_628 = L_627.___int64_1;
		if ((((int64_t)L_625) == ((int64_t)L_628)))
		{
			G_B276_0 = (&V_20);
			goto IL_0e8f;
		}
		G_B275_0 = (&V_20);
	}
	{
		int64_t L_629 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B277_0 = L_629;
		G_B277_1 = G_B275_0;
		goto IL_0e94;
	}

IL_0e8f:
	{
		int64_t L_630;
		L_630 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		G_B277_0 = L_630;
		G_B277_1 = G_B276_0;
	}

IL_0e94:
	{
		G_B277_1->___int64_1 = G_B277_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_631;
		memset((&L_631), 0, sizeof(L_631));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_631), (&V_20), NULL);
		return L_631;
	}

IL_0ea1:
	{
		bool L_632 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_632)
		{
			goto IL_0f73;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_633 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_634 = L_633.___register;
		float L_635 = L_634.___single_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_636 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_637 = L_636.___register;
		float L_638 = L_637.___single_0;
		if ((((float)L_635) == ((float)L_638)))
		{
			G_B281_0 = (&V_20);
			goto IL_0ee0;
		}
		G_B280_0 = (&V_20);
	}
	{
		G_B282_0 = (0.0f);
		G_B282_1 = G_B280_0;
		goto IL_0ee5;
	}

IL_0ee0:
	{
		float L_639;
		L_639 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B282_0 = L_639;
		G_B282_1 = G_B281_0;
	}

IL_0ee5:
	{
		G_B282_1->___single_0 = G_B282_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_640 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_641 = L_640.___register;
		float L_642 = L_641.___single_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_643 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_644 = L_643.___register;
		float L_645 = L_644.___single_1;
		if ((((float)L_642) == ((float)L_645)))
		{
			G_B284_0 = (&V_20);
			goto IL_0f0b;
		}
		G_B283_0 = (&V_20);
	}
	{
		G_B285_0 = (0.0f);
		G_B285_1 = G_B283_0;
		goto IL_0f10;
	}

IL_0f0b:
	{
		float L_646;
		L_646 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B285_0 = L_646;
		G_B285_1 = G_B284_0;
	}

IL_0f10:
	{
		G_B285_1->___single_1 = G_B285_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_647 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_648 = L_647.___register;
		float L_649 = L_648.___single_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_650 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_651 = L_650.___register;
		float L_652 = L_651.___single_2;
		if ((((float)L_649) == ((float)L_652)))
		{
			G_B287_0 = (&V_20);
			goto IL_0f36;
		}
		G_B286_0 = (&V_20);
	}
	{
		G_B288_0 = (0.0f);
		G_B288_1 = G_B286_0;
		goto IL_0f3b;
	}

IL_0f36:
	{
		float L_653;
		L_653 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B288_0 = L_653;
		G_B288_1 = G_B287_0;
	}

IL_0f3b:
	{
		G_B288_1->___single_2 = G_B288_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_654 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_655 = L_654.___register;
		float L_656 = L_655.___single_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_657 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_658 = L_657.___register;
		float L_659 = L_658.___single_3;
		if ((((float)L_656) == ((float)L_659)))
		{
			G_B290_0 = (&V_20);
			goto IL_0f61;
		}
		G_B289_0 = (&V_20);
	}
	{
		G_B291_0 = (0.0f);
		G_B291_1 = G_B289_0;
		goto IL_0f66;
	}

IL_0f61:
	{
		float L_660;
		L_660 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B291_0 = L_660;
		G_B291_1 = G_B290_0;
	}

IL_0f66:
	{
		G_B291_1->___single_3 = G_B291_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_661;
		memset((&L_661), 0, sizeof(L_661));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_661), (&V_20), NULL);
		return L_661;
	}

IL_0f73:
	{
		bool L_662 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_662)
		{
			goto IL_0ff4;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_663 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_664 = L_663.___register;
		double L_665 = L_664.___double_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_666 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_667 = L_666.___register;
		double L_668 = L_667.___double_0;
		if ((((double)L_665) == ((double)L_668)))
		{
			G_B295_0 = (&V_20);
			goto IL_0fb3;
		}
		G_B294_0 = (&V_20);
	}
	{
		G_B296_0 = (0.0);
		G_B296_1 = G_B294_0;
		goto IL_0fb8;
	}

IL_0fb3:
	{
		double L_669;
		L_669 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		G_B296_0 = L_669;
		G_B296_1 = G_B295_0;
	}

IL_0fb8:
	{
		G_B296_1->___double_0 = G_B296_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_670 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_671 = L_670.___register;
		double L_672 = L_671.___double_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_673 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_674 = L_673.___register;
		double L_675 = L_674.___double_1;
		if ((((double)L_672) == ((double)L_675)))
		{
			G_B298_0 = (&V_20);
			goto IL_0fe2;
		}
		G_B297_0 = (&V_20);
	}
	{
		G_B299_0 = (0.0);
		G_B299_1 = G_B297_0;
		goto IL_0fe7;
	}

IL_0fe2:
	{
		double L_676;
		L_676 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		G_B299_0 = L_676;
		G_B299_1 = G_B298_0;
	}

IL_0fe7:
	{
		G_B299_1->___double_1 = G_B299_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_677;
		memset((&L_677), 0, sizeof(L_677));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_677), (&V_20), NULL);
		return L_677;
	}

IL_0ff4:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_678 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_678, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_678, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_mD34044F5519631ED7AA89E35525ABFFA300D7895_fshared (Il2CppFullySharedGenericStruct ___0_left, Il2CppFullySharedGenericStruct ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_6 = L_1;
	const Il2CppFullySharedGenericStruct L_11 = L_1;
	const Il2CppFullySharedGenericStruct L_16 = L_1;
	const Il2CppFullySharedGenericStruct L_21 = L_1;
	const Il2CppFullySharedGenericStruct L_26 = L_1;
	const Il2CppFullySharedGenericStruct L_31 = L_1;
	const Il2CppFullySharedGenericStruct L_36 = L_1;
	const Il2CppFullySharedGenericStruct L_41 = L_1;
	const Il2CppFullySharedGenericStruct L_46 = L_1;
	const Il2CppFullySharedGenericStruct L_3 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_8 = L_3;
	const Il2CppFullySharedGenericStruct L_13 = L_3;
	const Il2CppFullySharedGenericStruct L_18 = L_3;
	const Il2CppFullySharedGenericStruct L_23 = L_3;
	const Il2CppFullySharedGenericStruct L_28 = L_3;
	const Il2CppFullySharedGenericStruct L_33 = L_3;
	const Il2CppFullySharedGenericStruct L_38 = L_3;
	const Il2CppFullySharedGenericStruct L_43 = L_3;
	const Il2CppFullySharedGenericStruct L_48 = L_3;
	{
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_0034;
		}
	}
	{
		il2cpp_codegen_memcpy(L_1, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_2;
		il2cpp_codegen_box_unbox(L_1, (&L_2), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_3, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_4;
		il2cpp_codegen_box_unbox(L_3, (&L_4), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_2) == ((int32_t)L_4))? 1 : 0);
	}

IL_0034:
	{
		bool L_5 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_5)
		{
			goto IL_0068;
		}
	}
	{
		il2cpp_codegen_memcpy(L_6, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_7;
		il2cpp_codegen_box_unbox(L_6, (&L_7), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_8, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_9;
		il2cpp_codegen_box_unbox(L_8, (&L_9), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_7) == ((int32_t)L_9))? 1 : 0);
	}

IL_0068:
	{
		bool L_10 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_10)
		{
			goto IL_009c;
		}
	}
	{
		il2cpp_codegen_memcpy(L_11, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_12;
		il2cpp_codegen_box_unbox(L_11, (&L_12), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_13, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_14;
		il2cpp_codegen_box_unbox(L_13, (&L_14), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_12) == ((int32_t)L_14))? 1 : 0);
	}

IL_009c:
	{
		bool L_15 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_15)
		{
			goto IL_00d0;
		}
	}
	{
		il2cpp_codegen_memcpy(L_16, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_17;
		il2cpp_codegen_box_unbox(L_16, (&L_17), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_18, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_19;
		il2cpp_codegen_box_unbox(L_18, (&L_19), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_17) == ((int32_t)L_19))? 1 : 0);
	}

IL_00d0:
	{
		bool L_20 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_20)
		{
			goto IL_0104;
		}
	}
	{
		il2cpp_codegen_memcpy(L_21, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_22;
		il2cpp_codegen_box_unbox(L_21, (&L_22), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_23, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_24;
		il2cpp_codegen_box_unbox(L_23, (&L_24), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_22) == ((int32_t)L_24))? 1 : 0);
	}

IL_0104:
	{
		bool L_25 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_25)
		{
			goto IL_0138;
		}
	}
	{
		il2cpp_codegen_memcpy(L_26, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_27;
		il2cpp_codegen_box_unbox(L_26, (&L_27), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_28, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_29;
		il2cpp_codegen_box_unbox(L_28, (&L_29), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_27) == ((int32_t)L_29))? 1 : 0);
	}

IL_0138:
	{
		bool L_30 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_30)
		{
			goto IL_016c;
		}
	}
	{
		il2cpp_codegen_memcpy(L_31, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_32;
		il2cpp_codegen_box_unbox(L_31, (&L_32), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_33, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_34;
		il2cpp_codegen_box_unbox(L_33, (&L_34), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		return (bool)((((int64_t)L_32) == ((int64_t)L_34))? 1 : 0);
	}

IL_016c:
	{
		bool L_35 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_35)
		{
			goto IL_01a0;
		}
	}
	{
		il2cpp_codegen_memcpy(L_36, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_37;
		il2cpp_codegen_box_unbox(L_36, (&L_37), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_38, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_39;
		il2cpp_codegen_box_unbox(L_38, (&L_39), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		return (bool)((((int64_t)L_37) == ((int64_t)L_39))? 1 : 0);
	}

IL_01a0:
	{
		bool L_40 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_40)
		{
			goto IL_01d4;
		}
	}
	{
		il2cpp_codegen_memcpy(L_41, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_42;
		il2cpp_codegen_box_unbox(L_41, (&L_42), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_43, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_44;
		il2cpp_codegen_box_unbox(L_43, (&L_44), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		return (bool)((((float)L_42) == ((float)L_44))? 1 : 0);
	}

IL_01d4:
	{
		bool L_45 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_45)
		{
			goto IL_0208;
		}
	}
	{
		il2cpp_codegen_memcpy(L_46, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_47;
		il2cpp_codegen_box_unbox(L_46, (&L_47), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_48, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_49;
		il2cpp_codegen_box_unbox(L_48, (&L_49), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		return (bool)((((double)L_47) == ((double)L_49))? 1 : 0);
	}

IL_0208:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_50 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_50, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_50, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1_GetOneValue_mE737616FA904E2C6558D22FEA78098714972060A_fshared (Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_5 = L_2;
	const Il2CppFullySharedGenericStruct L_8 = L_2;
	const Il2CppFullySharedGenericStruct L_11 = L_2;
	const Il2CppFullySharedGenericStruct L_14 = L_2;
	const Il2CppFullySharedGenericStruct L_17 = L_2;
	const Il2CppFullySharedGenericStruct L_21 = L_2;
	const Il2CppFullySharedGenericStruct L_25 = L_2;
	const Il2CppFullySharedGenericStruct L_28 = L_2;
	const Il2CppFullySharedGenericStruct L_31 = L_2;
	{
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_0027;
		}
	}
	{
		uint8_t L_1 = 1;
		il2cpp_codegen_box_unbox((&L_1), L_2, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0027:
	{
		bool L_3 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_3)
		{
			goto IL_004e;
		}
	}
	{
		int8_t L_4 = 1;
		il2cpp_codegen_box_unbox((&L_4), L_5, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_5, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_004e:
	{
		bool L_6 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_6)
		{
			goto IL_0075;
		}
	}
	{
		uint16_t L_7 = 1;
		il2cpp_codegen_box_unbox((&L_7), L_8, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_8, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0075:
	{
		bool L_9 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_9)
		{
			goto IL_009c;
		}
	}
	{
		int16_t L_10 = 1;
		il2cpp_codegen_box_unbox((&L_10), L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_009c:
	{
		bool L_12 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			goto IL_00c3;
		}
	}
	{
		uint32_t L_13 = 1;
		il2cpp_codegen_box_unbox((&L_13), L_14, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_14, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00c3:
	{
		bool L_15 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_15)
		{
			goto IL_00ea;
		}
	}
	{
		int32_t L_16 = 1;
		il2cpp_codegen_box_unbox((&L_16), L_17, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_17, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00ea:
	{
		bool L_18 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_18)
		{
			goto IL_0112;
		}
	}
	{
		int64_t L_19 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		uint64_t L_20 = L_19;
		il2cpp_codegen_box_unbox((&L_20), L_21, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_21, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0112:
	{
		bool L_22 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_22)
		{
			goto IL_013a;
		}
	}
	{
		int64_t L_23 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_24 = L_23;
		il2cpp_codegen_box_unbox((&L_24), L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_013a:
	{
		bool L_26 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_26)
		{
			goto IL_0165;
		}
	}
	{
		float L_27 = (1.0f);
		il2cpp_codegen_box_unbox((&L_27), L_28, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_28, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0165:
	{
		bool L_29 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_29)
		{
			goto IL_0194;
		}
	}
	{
		double L_30 = (1.0);
		il2cpp_codegen_box_unbox((&L_30), L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0194:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_32 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_32, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_32, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1_GetAllBitsSetValue_mB4736B3DE9ED10228E2F1991D497A98C9FE3E67B_fshared (Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_3 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_7 = L_3;
	const Il2CppFullySharedGenericStruct L_11 = L_3;
	const Il2CppFullySharedGenericStruct L_15 = L_3;
	const Il2CppFullySharedGenericStruct L_19 = L_3;
	const Il2CppFullySharedGenericStruct L_23 = L_3;
	const Il2CppFullySharedGenericStruct L_27 = L_3;
	const Il2CppFullySharedGenericStruct L_31 = L_3;
	const Il2CppFullySharedGenericStruct L_35 = L_3;
	const Il2CppFullySharedGenericStruct L_39 = L_3;
	{
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_002b;
		}
	}
	{
		uint8_t L_1;
		L_1 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		uint8_t L_2 = L_1;
		il2cpp_codegen_box_unbox((&L_2), L_3, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_3, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_002b:
	{
		bool L_4 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_4)
		{
			goto IL_0056;
		}
	}
	{
		int8_t L_5;
		L_5 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		int8_t L_6 = L_5;
		il2cpp_codegen_box_unbox((&L_6), L_7, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_7, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0056:
	{
		bool L_8 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_8)
		{
			goto IL_0081;
		}
	}
	{
		uint16_t L_9;
		L_9 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		uint16_t L_10 = L_9;
		il2cpp_codegen_box_unbox((&L_10), L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0081:
	{
		bool L_12 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			goto IL_00ac;
		}
	}
	{
		int16_t L_13;
		L_13 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		int16_t L_14 = L_13;
		il2cpp_codegen_box_unbox((&L_14), L_15, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_15, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00ac:
	{
		bool L_16 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_16)
		{
			goto IL_00d7;
		}
	}
	{
		uint32_t L_17;
		L_17 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		uint32_t L_18 = L_17;
		il2cpp_codegen_box_unbox((&L_18), L_19, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_19, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00d7:
	{
		bool L_20 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_20)
		{
			goto IL_0102;
		}
	}
	{
		int32_t L_21;
		L_21 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		int32_t L_22 = L_21;
		il2cpp_codegen_box_unbox((&L_22), L_23, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_23, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0102:
	{
		bool L_24 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_24)
		{
			goto IL_012d;
		}
	}
	{
		uint64_t L_25;
		L_25 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		uint64_t L_26 = L_25;
		il2cpp_codegen_box_unbox((&L_26), L_27, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_27, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_012d:
	{
		bool L_28 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_28)
		{
			goto IL_0158;
		}
	}
	{
		int64_t L_29;
		L_29 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		int64_t L_30 = L_29;
		il2cpp_codegen_box_unbox((&L_30), L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0158:
	{
		bool L_32 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_32)
		{
			goto IL_0183;
		}
	}
	{
		float L_33;
		L_33 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		float L_34 = L_33;
		il2cpp_codegen_box_unbox((&L_34), L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0183:
	{
		bool L_36 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_36)
		{
			goto IL_01ae;
		}
	}
	{
		double L_37;
		L_37 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		double L_38 = L_37;
		il2cpp_codegen_box_unbox((&L_38), L_39, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_39, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_01ae:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_40 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_40, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_40, method);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__cctor_m5C2E6DBA5BAABD495E2C5E516B928C78DB2A7615_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_5 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 12)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 12));
		((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count = L_0;
		il2cpp_codegen_initobj((&((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero), sizeof(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2));
		InvokerActionInvoker1< Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13), NULL, (Il2CppFullySharedGenericStruct*)L_1);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_3;
		memset((&L_3), 0, sizeof(L_3));
		Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2((&L_3), il2cpp_codegen_memcpy(L_2, L_1, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_one = L_3;
		InvokerActionInvoker1< Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 15)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 15), NULL, (Il2CppFullySharedGenericStruct*)L_4);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_6;
		memset((&L_6), 0, sizeof(L_6));
		Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2((&L_6), il2cpp_codegen_memcpy(L_5, L_4, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_allOnes = L_6;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline (NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___numberGroupSeparator;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline (const RuntimeMethod* method) 
{
	uint64_t V_0 = 0;
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		V_0 = L_0;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		il2cpp_codegen_stind<int64_t>((int64_t*)L_1, (int64_t)L_2);
		uint64_t L_3 = V_0;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline (double* __this, const RuntimeMethod* method) 
{
	int64_t V_0 = 0;
	{
		double L_0 = il2cpp_codegen_ldind<double, double>(__this);
		int64_t L_1;
		L_1 = BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline(L_0, NULL);
		V_0 = L_1;
		int64_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		if ((((int64_t)((int64_t)(((int64_t)il2cpp_codegen_subtract(L_2, L_3))&((int64_t)(std::numeric_limits<int64_t>::max)())))) < ((int64_t)((int64_t)9218868437227405312LL))))
		{
			goto IL_002d;
		}
	}
	{
		int64_t L_4 = V_0;
		V_0 = ((int64_t)(L_4&((int64_t)9218868437227405312LL)));
	}

IL_002d:
	{
		int64_t L_5 = V_0;
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_5,NULL));
		int64_t L_7 = V_0;
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)(L_7>>((int32_t)32))),NULL));
		return ((int32_t)(L_6^L_8));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline (const RuntimeMethod* method) 
{
	uint8_t V_0 = 0x0;
	{
		V_0 = (uint8_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int8_t>((int8_t*)L_0, (int8_t)((int32_t)255));
		uint8_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline (const RuntimeMethod* method) 
{
	int8_t V_0 = 0x0;
	{
		V_0 = (int8_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int8_t>((int8_t*)L_0, (int8_t)(-1));
		int8_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) 
{
	uint16_t V_0 = 0;
	{
		V_0 = (uint16_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int16_t>((int16_t*)L_0, (int16_t)((int32_t)65535));
		uint16_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline (const RuntimeMethod* method) 
{
	int16_t V_0 = 0;
	{
		V_0 = (int16_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int16_t>((int16_t*)L_0, (int16_t)(-1));
		int16_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline (const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	{
		V_0 = 0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int32_t>((int32_t*)L_0, (int32_t)(-1));
		uint32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline (const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = 0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int32_t>((int32_t*)L_0, (int32_t)(-1));
		int32_t L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline (const RuntimeMethod* method) 
{
	int64_t V_0 = 0;
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		V_0 = L_0;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		il2cpp_codegen_stind<int64_t>((int64_t*)L_1, (int64_t)L_2);
		int64_t L_3 = V_0;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline (const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	{
		V_0 = (0.0f);
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>((&V_0),NULL));
		il2cpp_codegen_stind<int32_t>((int32_t*)L_0, (int32_t)(-1));
		float L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline (const RuntimeMethod* method) 
{
	double V_0 = 0.0;
	{
		V_0 = (0.0);
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		il2cpp_codegen_stind<int64_t>((int64_t*)L_0, (int64_t)L_1);
		double L_2 = V_0;
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_mC75C8C6E913E7FF8A3D10467D6DADE41711EF3CC_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_mE275DCDE4DC3B6FB30AB80ACEAC8363207BA9BEC_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27(__this, ((*(Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m73081D1B852400C74618D0A814BBED2FE272175D_inline (uint64_t ___0_left, uint64_t ___1_right, const RuntimeMethod* method) 
{
	{
		goto IL_0034;
	}

IL_0034:
	{
		goto IL_0068;
	}

IL_0068:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00d0;
	}

IL_00d0:
	{
		goto IL_0104;
	}

IL_0104:
	{
		goto IL_0138;
	}

IL_0138:
	{
	}
	{
		uint64_t L_0 = ___0_left;
		uint64_t L_1 = ___1_right;
		return (bool)((((int64_t)L_0) == ((int64_t)L_1))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD4D4AE7733CACE50CA2FCFFFB0A16818EEC01293_inline (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___0_left, Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = Vector_1_Equals_mAE01D42B31EB54893DC4DB1BE8A99216AF784C27((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetOneValue_mE2DE5D8CFC8D7A4990743C160CD1C4ED71CDA288_inline (const RuntimeMethod* method) 
{
	{
		goto IL_0027;
	}

IL_0027:
	{
		goto IL_004e;
	}

IL_004e:
	{
		goto IL_0075;
	}

IL_0075:
	{
		goto IL_009c;
	}

IL_009c:
	{
		goto IL_00c3;
	}

IL_00c3:
	{
		goto IL_00ea;
	}

IL_00ea:
	{
	}
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t Vector_1_GetAllBitsSetValue_m99E582A6A7DA5089B26FE42E5F8FDE26A6005ED0_inline (const RuntimeMethod* method) 
{
	{
		goto IL_002b;
	}

IL_002b:
	{
		goto IL_0056;
	}

IL_0056:
	{
		goto IL_0081;
	}

IL_0081:
	{
		goto IL_00ac;
	}

IL_00ac:
	{
		goto IL_00d7;
	}

IL_00d7:
	{
		goto IL_0102;
	}

IL_0102:
	{
	}
	{
		uint64_t L_0;
		L_0 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared_inline (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))(__this, ((*(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline (double ___0_value, const RuntimeMethod* method) 
{
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>((&___0_value),NULL));
		int64_t L_1 = il2cpp_codegen_ldind<int64_t, int64_t>(((int64_t*)L_0));
		return L_1;
	}
}
