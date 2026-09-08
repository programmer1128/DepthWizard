#include "pch-cpp.hpp"





template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3* p3)
	{
		void* params[3] = { p1, &p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, params[2]);
	}
};

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct BatchDrawCommand_t9DAB9B739DA9EBC6B1BB0D2DD51AF65B12F66BF0;
struct BatchDrawCommandIndirect_t06F3B5DC4AF7D4B115CEECDB0A1E4E92065BC705;
struct BatchDrawCommandProcedural_t5780BD7745B5772AA54BA6E6021292F6A6553B86;
struct BatchDrawCommandProceduralIndirect_t8417CDF3495237CD8C9204B3DADC6BA4A1488B50;
struct BatchDrawRange_t736D745E918A629658B80A0F7D2D17DAFBA6172F;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C;
struct IntPtr_t;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C;
struct String_t;
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF;
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C;
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2;
struct UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral4EBC86E0EACFCA522AEB82874860D0E248D782A5;
IL2CPP_EXTERN_C const RuntimeMethod* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct UnsafeUtilityInternal_t5FEF1714A0FC54C68B384571076C8DF48E831240  : public RuntimeObject
{
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
struct Vector_t246EF05F1CA5F494FB8B48AB2724DFCD2C2C5A9A  : public RuntimeObject
{
};
struct Volatile_tC26FEDFD254742AD25E4B908FA81293FBBF4ECB0  : public RuntimeObject
{
};
struct xxHash3_t1B0090718977D51798C540A03964F9CB74D52462  : public RuntimeObject
{
};
struct MarshalledUnityObject_tA225A4A0AE6E49830C3C0142B2984549E0786A28  : public RuntimeObject
{
};
struct AlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D 
{
	uint8_t ___dummy;
	uint8_t ___data;
};
struct AlignOfHelper_1_t2B1B6F8C95D259E66B253A1C059AE8D3365B528E 
{
	uint8_t ___dummy;
	int16_t ___data;
};
struct AlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE 
{
	uint8_t ___dummy;
	int32_t ___data;
};
struct AlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4 
{
	uint8_t ___dummy;
	float ___data;
};
struct AlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9 
{
	uint8_t ___dummy;
	uint16_t ___data;
};
struct AlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3 
{
	uint8_t ___dummy;
	uint32_t ___data;
};
struct AlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E 
{
	uint8_t ___dummy;
	uint64_t ___data;
};
struct ArraySlice_1_t62CE85979628F3D63985E52623CBDB8E8CEDF91C 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D 
{
	BatchDrawCommand_t9DAB9B739DA9EBC6B1BB0D2DD51AF65B12F66BF0* ___drawCommands;
	BatchDrawCommandIndirect_t06F3B5DC4AF7D4B115CEECDB0A1E4E92065BC705* ___indirectDrawCommands;
	BatchDrawCommandProcedural_t5780BD7745B5772AA54BA6E6021292F6A6553B86* ___proceduralDrawCommands;
	BatchDrawCommandProceduralIndirect_t8417CDF3495237CD8C9204B3DADC6BA4A1488B50* ___proceduralIndirectDrawCommands;
	int32_t* ___visibleInstances;
	BatchDrawRange_t736D745E918A629658B80A0F7D2D17DAFBA6172F* ___drawRanges;
	float* ___instanceSortingPositions;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8* ___drawCommandPickingEntityIds;
	int32_t ___drawCommandCount;
	int32_t ___indirectDrawCommandCount;
	int32_t ___proceduralDrawCommandCount;
	int32_t ___proceduralIndirectDrawCommandCount;
	int32_t ___visibleInstanceCount;
	int32_t ___drawRangeCount;
	int32_t ___instanceSortingPositionFloatCount;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
};
struct EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 
{
	union
	{
		struct
		{
			uint64_t ___m_rawData;
		};
		uint8_t EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8__padding[8];
	};
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
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
struct InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D 
{
	uint8_t ___m_Data;
};
struct InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 
{
	int32_t ___forceLod;
	float ___lodSelectionBias;
};
struct InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF 
{
	uint32_t ___m_RenderingLayerMask;
	uint16_t ___m_Data;
	uint8_t ___m_ObjectLayer;
};
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct LinearColor_t60964F15C567D7FE5442C29298DCF20ABD8816C7 
{
	float ___m_red;
	float ___m_green;
	float ___m_blue;
	float ___m_intensity;
};
struct Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 
{
	int64_t ___f0;
	int64_t ___f1;
	int64_t ___f2;
	int64_t ___f3;
	int64_t ___f4;
	int64_t ___f5;
	int64_t ___f6;
	int64_t ___f7;
};
struct Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 
{
	float ___m00;
	float ___m10;
	float ___m20;
	float ___m30;
	float ___m01;
	float ___m11;
	float ___m21;
	float ___m31;
	float ___m02;
	float ___m12;
	float ___m22;
	float ___m32;
	float ___m03;
	float ___m13;
	float ___m23;
	float ___m33;
};
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
};
struct RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268 
{
	int32_t ___start;
	int32_t ___length;
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
struct UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t* ___values;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t* ___values_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keys_OffsetPadding[8];
			uint8_t* ___keys;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keys_OffsetPadding_forAlignmentOnly[8];
			uint8_t* ___keys_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___next_OffsetPadding[16];
			uint8_t* ___next;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___next_OffsetPadding_forAlignmentOnly[16];
			uint8_t* ___next_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___buckets_OffsetPadding[24];
			uint8_t* ___buckets;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___buckets_OffsetPadding_forAlignmentOnly[24];
			uint8_t* ___buckets_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___keyCapacity_OffsetPadding[32];
			int32_t ___keyCapacity;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___keyCapacity_OffsetPadding_forAlignmentOnly[32];
			int32_t ___keyCapacity_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding[36];
			int32_t ___bucketCapacityMask;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___bucketCapacityMask_OffsetPadding_forAlignmentOnly[36];
			int32_t ___bucketCapacityMask_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding[40];
			int32_t ___allocatedIndexLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___allocatedIndexLength_OffsetPadding_forAlignmentOnly[40];
			int32_t ___allocatedIndexLength_forAlignmentOnly;
		};
	};
};
struct UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C 
{
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___m_NextBlock;
	int32_t ___m_NumItems;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
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
struct double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 
{
	double ___x;
	double ___y;
};
struct float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 
{
	float ___x;
	float ___y;
};
struct float3_t7600B73F092B37F484B12910A5269F30C778D31E 
{
	float ___x;
	float ___y;
	float ___z;
};
struct float4_t545A994996126766890C1F28B43EA823F2410190 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
};
struct int2_tB123E869131C6102341F8F9AA01726E0E7C2768D 
{
	int32_t ___x;
	int32_t ___y;
};
struct int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 
{
	int32_t ___x;
	int32_t ___y;
	int32_t ___z;
};
struct int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90 
{
	int32_t ___x;
	int32_t ___y;
	int32_t ___z;
	int32_t ___w;
};
struct uint2_tB27E0548FBAD8AFF74840E32AA4362409E48E082 
{
	uint32_t ___x;
	uint32_t ___y;
};
struct uint4_tB6BF4BE7E92EFB510DFCB18F2E217DAD1CD8FC1E 
{
	uint32_t ___x;
	uint32_t ___y;
	uint32_t ___z;
	uint32_t ___w;
};
struct AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 
{
	uint16_t ___Index;
	uint16_t ___Version;
};
struct U3Cm_FadeTransitionWidthsU3Ee__FixedBuffer_tC44EA0D00BAF5D4021A10861FE9C59C8804B21E4 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3Cm_FadeTransitionWidthsU3Ee__FixedBuffer_tC44EA0D00BAF5D4021A10861FE9C59C8804B21E4__padding[16];
	};
};
struct U3Cm_RendererCountsU3Ee__FixedBuffer_t877AF3B14647FADCA74D2F1A1BBB59648DC5AE67 
{
	union
	{
		struct
		{
			uint8_t ___FixedElementField;
		};
		uint8_t U3Cm_RendererCountsU3Ee__FixedBuffer_t877AF3B14647FADCA74D2F1A1BBB59648DC5AE67__padding[8];
	};
};
struct U3Cm_ScreenRelativeTransitionHeightsU3Ee__FixedBuffer_t2C41FA0F591BD145EEED3C0E09D6F04CD521B804 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3Cm_ScreenRelativeTransitionHeightsU3Ee__FixedBuffer_t2C41FA0F591BD145EEED3C0E09D6F04CD521B804__padding[16];
	};
};
struct Array_t1E323B687FA2B776FFD4500566C5078C058371A7 
{
	union
	{
		struct
		{
		};
		uint8_t Array_t1E323B687FA2B776FFD4500566C5078C058371A7__padding[1];
	};
};
struct Unmanaged_t06043455F062B5BBF755BE852B0A7AB1876E3310 
{
	union
	{
		struct
		{
		};
		uint8_t Unmanaged_t06043455F062B5BBF755BE852B0A7AB1876E3310__padding[1];
	};
};
struct LodSelectionCurve_t5E3F99BC782C22E828074538B8B43051FF859713 
{
	float ___m_LodSlope;
	float ___m_LodBias;
};
struct Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 
{
	int64_t ___m_long;
};
struct U3CbucketOffsetsU3Ee__FixedBuffer_t02430A98A7BDAED51F45AADE83044D404F68DB64 
{
	union
	{
		struct
		{
			uint32_t ___FixedElementField;
		};
		uint8_t U3CbucketOffsetsU3Ee__FixedBuffer_t02430A98A7BDAED51F45AADE83044D404F68DB64__padding[64];
	};
};
struct U3CbucketSizesU3Ee__FixedBuffer_t6E55B56B1212BEF70964F4027D41AAE340D5F91B 
{
	union
	{
		struct
		{
			uint8_t ___FixedElementField;
		};
		uint8_t U3CbucketSizesU3Ee__FixedBuffer_t6E55B56B1212BEF70964F4027D41AAE340D5F91B__padding[16];
	};
};
struct U3CdecodeTableU3Ee__FixedBuffer_t258FFC7B1E65D42A1149FE37642F704C0EC14C10 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3CdecodeTableU3Ee__FixedBuffer_t258FFC7B1E65D42A1149FE37642F704C0EC14C10__padding[128];
	};
};
struct U3CencodeTableU3Ee__FixedBuffer_tE77A05CDD75344674029C3FA7C3BEF244EE1A840 
{
	union
	{
		struct
		{
			uint16_t ___FixedElementField;
		};
		uint8_t U3CencodeTableU3Ee__FixedBuffer_tE77A05CDD75344674029C3FA7C3BEF244EE1A840__padding[32];
	};
};
struct Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6 
{
	uint8_t* ___Ptr;
	int32_t ___Size;
	int32_t ___Offset;
};
struct U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116 
{
	union
	{
		struct
		{
			uint8_t ___FixedElementField;
		};
		uint8_t U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116__padding[1];
	};
};
struct U3CjointsU3Ee__FixedBuffer_t247A255BAD6230E79187CCF28093D98E575CAF88 
{
	union
	{
		struct
		{
			uint32_t ___FixedElementField;
		};
		uint8_t U3CjointsU3Ee__FixedBuffer_t247A255BAD6230E79187CCF28093D98E575CAF88__padding[16];
	};
};
struct U3CweightsU3Ee__FixedBuffer_t38977884B7556D7D2264A4364FA615B5744932BC 
{
	union
	{
		struct
		{
			float ___FixedElementField;
		};
		uint8_t U3CweightsU3Ee__FixedBuffer_t38977884B7556D7D2264A4364FA615B5744932BC__padding[16];
	};
};
struct VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99 
{
	RuntimeObject* ___Value;
};
struct VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99_marshaled_pinvoke
{
	RuntimeObject* ___Value;
};
struct VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99_marshaled_com
{
	RuntimeObject* ___Value;
};
struct LongDoubleUnion_t17011746129284B81F310F56E20D549A6F6710D0 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___longValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___longValue_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___doubleValue;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___doubleValue_forAlignmentOnly;
		};
	};
};
struct Array_t3B8F006A80A48C83471DE3516556F1AFE6873381 
{
	union
	{
		struct
		{
		};
		uint8_t Array_t3B8F006A80A48C83471DE3516556F1AFE6873381__padding[1];
	};
};
struct StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___Acc;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___Acc_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Buffer_OffsetPadding[64];
			uint8_t ___Buffer;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Buffer_OffsetPadding_forAlignmentOnly[64];
			uint8_t ___Buffer_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___IsHash64_OffsetPadding[320];
			int32_t ___IsHash64;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___IsHash64_OffsetPadding_forAlignmentOnly[320];
			int32_t ___IsHash64_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___BufferedSize_OffsetPadding[324];
			int32_t ___BufferedSize;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___BufferedSize_OffsetPadding_forAlignmentOnly[324];
			int32_t ___BufferedSize_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___NbStripesSoFar_OffsetPadding[328];
			int32_t ___NbStripesSoFar;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___NbStripesSoFar_OffsetPadding_forAlignmentOnly[328];
			int32_t ___NbStripesSoFar_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___TotalLength_OffsetPadding[336];
			int64_t ___TotalLength;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___TotalLength_OffsetPadding_forAlignmentOnly[336];
			int64_t ___TotalLength_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___Seed_OffsetPadding[344];
			uint64_t ___Seed;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___Seed_OffsetPadding_forAlignmentOnly[344];
			uint64_t ___Seed_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___SecretKey_OffsetPadding[352];
			uint8_t ___SecretKey;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___SecretKey_OffsetPadding_forAlignmentOnly[352];
			uint8_t ___SecretKey_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ____PadEnd_OffsetPadding[540];
			uint8_t ____PadEnd;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ____PadEnd_OffsetPadding_forAlignmentOnly[540];
			uint8_t ____PadEnd_forAlignmentOnly;
		};
	};
};
struct AlignOfHelper_1_tBEA2F557D94117D6B5CA3D54DEA10F7A2F5AF996 
{
	uint8_t ___dummy;
	BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D ___data;
};
struct AlignOfHelper_1_tCD4B08DBB915013B12E50DA43CE11B02B0D135DD 
{
	uint8_t ___dummy;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___data;
};
struct AlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752 
{
	uint8_t ___dummy;
	intptr_t ___data;
};
struct AlignOfHelper_1_tCFC8A208D36EA414B14215D004A770AEC0DB8BA2 
{
	uint8_t ___dummy;
	InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D ___data;
};
struct AlignOfHelper_1_t1A20691B0774E0EFBEAD966FB0B480A553DCF42E 
{
	uint8_t ___dummy;
	InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 ___data;
};
struct AlignOfHelper_1_t6F2F300ADF773C90F661FF403B84D167EB793773 
{
	uint8_t ___dummy;
	InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF ___data;
};
struct AlignOfHelper_1_t7880A587D589BDB26652DC16C427FE26F3D1053C 
{
	uint8_t ___dummy;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___data;
};
struct AlignOfHelper_1_t6C24EA77B111E6877D279F01810C1D4E13534301 
{
	uint8_t ___dummy;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___data;
};
struct AlignOfHelper_1_tE6A7C0BC2AB9B74FA79F8449B8FA1BC94A474BC4 
{
	uint8_t ___dummy;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___data;
};
struct AlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5 
{
	uint8_t ___dummy;
	RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268 ___data;
};
struct AlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9 
{
	uint8_t ___dummy;
	UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926 ___data;
};
struct AlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA 
{
	uint8_t ___dummy;
	UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C ___data;
};
struct AlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A 
{
	uint8_t ___dummy;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___data;
};
struct AlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773 
{
	uint8_t ___dummy;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___data;
};
struct AlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4 
{
	uint8_t ___dummy;
	double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 ___data;
};
struct AlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460 
{
	uint8_t ___dummy;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___data;
};
struct AlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE 
{
	uint8_t ___dummy;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___data;
};
struct AlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7 
{
	uint8_t ___dummy;
	float4_t545A994996126766890C1F28B43EA823F2410190 ___data;
};
struct AlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C 
{
	uint8_t ___dummy;
	int2_tB123E869131C6102341F8F9AA01726E0E7C2768D ___data;
};
struct AlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396 
{
	uint8_t ___dummy;
	int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 ___data;
};
struct AlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3 
{
	uint8_t ___dummy;
	int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90 ___data;
};
struct HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B 
{
	uint8_t* ___Ptr;
	int32_t* ___Keys;
	int32_t* ___Next;
	int32_t* ___Buckets;
	int32_t ___Count;
	int32_t ___Capacity;
	int32_t ___Log2MinGrowth;
	int32_t ___BucketCapacity;
	int32_t ___AllocatedIndex;
	int32_t ___FirstFreeIdx;
	int32_t ___SizeOfTValue;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D 
{
	uint8_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 
{
	int32_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 
{
	intptr_t* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258 
{
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___m_Buffer;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___m_AllocatorLabel;
};
struct UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6 
{
	int32_t* ___Ptr;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___m_Capacity;
	int32_t ___m_Filled;
	int32_t ___m_Write;
	int32_t ___m_Read;
};
struct Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Center;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Extents;
};
struct CollisionPairHeaderFlags_tBA40F470BC1564B84C3093CEA5761804FA0650C3 
{
	uint16_t ___value__;
};
struct CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___sphereCenter;
	float ___sphereRadius;
	int32_t ___cullingPlaneOffset;
	int32_t ___cullingPlaneCount;
	float ___cascadeBlendCullingFactor;
	float ___nearPlane;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___cullingMatrix;
};
struct EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B 
{
	U3Cm_ScreenRelativeTransitionHeightsU3Ee__FixedBuffer_t2C41FA0F591BD145EEED3C0E09D6F04CD521B804 ___m_ScreenRelativeTransitionHeights;
	U3Cm_FadeTransitionWidthsU3Ee__FixedBuffer_tC44EA0D00BAF5D4021A10861FE9C59C8804B21E4 ___m_FadeTransitionWidths;
	U3Cm_RendererCountsU3Ee__FixedBuffer_t877AF3B14647FADCA74D2F1A1BBB59648DC5AE67 ___m_RendererCounts;
	uint8_t ___m_Length;
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
struct FalloffType_tE9BECCB411DA63109760103AF7476F422A01376D 
{
	uint8_t ___value__;
};
struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle;
};
struct GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32 
{
	int32_t ___subMeshCount;
	int32_t ___meshLodCount;
	LodSelectionCurve_t5E3F99BC782C22E828074538B8B43051FF859713 ___meshLodSelectionCurve;
};
struct LightMode_t058E4E7AAE5689BCFF46BB8E0259D90D227E7FF9 
{
	uint8_t ___value__;
};
struct LightType_t97C5050F2F742FBF050FEB8FC5131A9A8DB50D26 
{
	uint8_t ___value__;
};
struct Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D 
{
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f0;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f1;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f2;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f3;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f4;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f5;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f6;
	Long8_t47945FFD68CACB5C8CE8E03AECE69B817A6A9659 ___f7;
};
struct MeshTopology_t815FF5CF04D62195A23E2DF8A5C0A071F11FBCBF 
{
	int32_t ___value__;
};
struct ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960 
{
	intptr_t ___actor;
	intptr_t ___otherActor;
	intptr_t ___shape;
	intptr_t ___otherShape;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___rotation;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___position;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___otherRotation;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___otherPosition;
	int32_t ___numContacts;
	intptr_t ___contacts;
};
struct NativeArrayOptions_t3E979EEF4B4840228A7692A97DA07553C6465F1D 
{
	int32_t ___value__;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Normal;
	float ___m_Distance;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct StreamCompressionModel_t7F9FB7DB2D88DA832A4DD61C1E6587A4C530697D 
{
	uint8_t ___m_Initialized;
	U3CencodeTableU3Ee__FixedBuffer_tE77A05CDD75344674029C3FA7C3BEF244EE1A840 ___encodeTable;
	U3CdecodeTableU3Ee__FixedBuffer_t258FFC7B1E65D42A1149FE37642F704C0EC14C10 ___decodeTable;
	U3CbucketSizesU3Ee__FixedBuffer_t6E55B56B1212BEF70964F4027D41AAE340D5F91B ___bucketSizes;
	U3CbucketOffsetsU3Ee__FixedBuffer_t02430A98A7BDAED51F45AADE83044D404F68DB64 ___bucketOffsets;
};
struct UCircle_t867F766ACBC8203697A5637D6046595BBCA3A156 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___center;
	float ___radius;
};
struct UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___a;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___b;
	int32_t ___index;
};
struct UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___a;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___b;
	int32_t ___idx;
	int32_t ___type;
};
struct UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___a;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___b;
	int32_t ___idx;
	ArraySlice_1_t62CE85979628F3D63985E52623CBDB8E8CEDF91C ___ilarray;
	int32_t ___ilcount;
	ArraySlice_1_t62CE85979628F3D63985E52623CBDB8E8CEDF91C ___iuarray;
	int32_t ___iucount;
};
struct UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D 
{
	ArraySlice_1_t62CE85979628F3D63985E52623CBDB8E8CEDF91C ___points;
	int32_t ___pointCount;
};
struct UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 
{
	uint64_t* ___Ptr;
	int32_t ___Length;
	int32_t ___Capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2 
{
	intptr_t ___m_FirstBlock;
	intptr_t ___m_LastBlock;
	int32_t ___m_MaxItems;
	int32_t ___m_CurrentRead;
	uint8_t* ___m_CurrentWriteBlockTLS;
};
struct UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C 
{
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___Next;
	U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116 ___Data;
};
struct UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 
{
	void* ___Ptr;
	int32_t ___m_length;
	int32_t ___m_capacity;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
	int32_t ___padding;
};
struct VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF 
{
	U3CweightsU3Ee__FixedBuffer_t38977884B7556D7D2264A4364FA615B5744932BC ___weights;
	U3CjointsU3Ee__FixedBuffer_t247A255BAD6230E79187CCF28093D98E575CAF88 ___joints;
};
struct VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___position;
};
struct VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD 
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___position;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___normal;
};
struct VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___position;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___normal;
	float4_t545A994996126766890C1F28B43EA823F2410190 ___tangent;
};
struct VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
};
struct VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
};
struct VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv2;
};
struct VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv2;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv3;
};
struct VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv2;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv3;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv4;
};
struct VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv2;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv3;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv4;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv5;
};
struct VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv2;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv3;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv4;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv5;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv6;
};
struct VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv0;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv1;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv2;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv3;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv4;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv5;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv6;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___uv7;
};
struct quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA 
{
	float4_t545A994996126766890C1F28B43EA823F2410190 ___value;
};
struct Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC 
{
	intptr_t ___Pointer;
	int32_t ___Items;
	AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___Allocator;
};
struct TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE 
{
	intptr_t ___function;
	intptr_t ___state;
};
struct StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020 
{
	StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A ___State;
};
struct AlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50 
{
	uint8_t ___dummy;
	HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B ___data;
};
struct AlignOfHelper_1_t1E8E61551DF980F24CBCDC154CDF9D613283AEE8 
{
	uint8_t ___dummy;
	UnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D ___data;
};
struct AlignOfHelper_1_t79FB2646CB5124B22898AECE2C1787E0B0EA4C93 
{
	uint8_t ___dummy;
	UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718 ___data;
};
struct AlignOfHelper_1_tF8D2C4925153DD905077B2DDBFFA1665C36A62BC 
{
	uint8_t ___dummy;
	UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613 ___data;
};
struct AlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163 
{
	uint8_t ___dummy;
	UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258 ___data;
};
struct AlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693 
{
	uint8_t ___dummy;
	UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6 ___data;
};
struct AlignOfHelper_1_t34CCC6CF432525FDD94891D4DAFB9DB74F9AF3E9 
{
	uint8_t ___dummy;
	Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 ___data;
};
struct AlignOfHelper_1_tF6B6CAC1AFD67E6448C9B177EA1734D57E3BCDA2 
{
	uint8_t ___dummy;
	CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 ___data;
};
struct AlignOfHelper_1_tFC537E4E3FE3F7962CBC5F219276522C16824ACF 
{
	uint8_t ___dummy;
	EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B ___data;
};
struct AlignOfHelper_1_t398568B8BA5FC2BA68E01C861AA1BEDC4750E61D 
{
	uint8_t ___dummy;
	GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32 ___data;
};
struct AlignOfHelper_1_tF3D321A7435452B0B749AF58D2CF8AB1865BC52C 
{
	uint8_t ___dummy;
	ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960 ___data;
};
struct AlignOfHelper_1_t4257D6924487B14B176AB4C639F1251F2E4ED1C6 
{
	uint8_t ___dummy;
	Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C ___data;
};
struct AlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D 
{
	uint8_t ___dummy;
	UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1 ___data;
};
struct AlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37 
{
	uint8_t ___dummy;
	UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC ___data;
};
struct AlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056 
{
	uint8_t ___dummy;
	UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851 ___data;
};
struct AlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5 
{
	uint8_t ___dummy;
	UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D ___data;
};
struct AlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981 
{
	uint8_t ___dummy;
	UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4 ___data;
};
struct AlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3 
{
	uint8_t ___dummy;
	UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2 ___data;
};
struct AlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B 
{
	uint8_t ___dummy;
	VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF ___data;
};
struct AlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A 
{
	uint8_t ___dummy;
	VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 ___data;
};
struct AlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8 
{
	uint8_t ___dummy;
	VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD ___data;
};
struct AlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED 
{
	uint8_t ___dummy;
	VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 ___data;
};
struct AlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7 
{
	uint8_t ___dummy;
	VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9 ___data;
};
struct AlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233 
{
	uint8_t ___dummy;
	VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F ___data;
};
struct AlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF 
{
	uint8_t ___dummy;
	VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99 ___data;
};
struct AlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6 
{
	uint8_t ___dummy;
	VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580 ___data;
};
struct AlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28 
{
	uint8_t ___dummy;
	VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD ___data;
};
struct AlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150 
{
	uint8_t ___dummy;
	VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC ___data;
};
struct AlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF 
{
	uint8_t ___dummy;
	VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2 ___data;
};
struct AlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1 
{
	uint8_t ___dummy;
	VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D ___data;
};
struct AlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C 
{
	uint8_t ___dummy;
	quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA ___data;
};
struct Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F 
{
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f0;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f1;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f2;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f3;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f4;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f5;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f6;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f7;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f8;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f9;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f10;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f11;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f12;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f13;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f14;
	TableEntry_t5E44AFA7857A41AC654D7F248FD36B15D7835FFE ___f15;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_BodyID;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___m_OtherBodyID;
	intptr_t ___m_StartPtr;
	uint32_t ___m_NbPairs;
	uint16_t ___m_Flags;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_ThisBodyLinearVelocity;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_ThisBodyAngularVelocity;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_OtherBodyLinearVelocity;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_OtherBodyAngularVelocity;
};
struct GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B 
{
	int32_t ___topology;
	uint32_t ___baseVertex;
	uint32_t ___indexStart;
	uint32_t ___indexCount;
};
struct LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21 
{
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___entityId;
	EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___cookieTextureEntityId;
	float ___cookieScale;
	LinearColor_t60964F15C567D7FE5442C29298DCF20ABD8816C7 ___color;
	LinearColor_t60964F15C567D7FE5442C29298DCF20ABD8816C7 ___indirectColor;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___orientation;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___position;
	float ___range;
	float ___coneAngle;
	float ___innerConeAngle;
	float ___shape0;
	float ___shape1;
	uint8_t ___type;
	uint8_t ___mode;
	uint8_t ___shadow;
	uint8_t ___falloff;
	float ___indirectMultiplier;
	int32_t ____padding;
};
struct Long512_t2D339FF6672EB3709A6C638EABA7D13C7FEC1878 
{
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f0;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f1;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f2;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f3;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f4;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f5;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f6;
	Long64_t9C8641A91D7FEF90D4B55FDC6B5823A59670156D ___f7;
};
struct MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 
{
	union
	{
		struct
		{
			intptr_t ___pointer;
			int32_t ___allocator;
		};
		uint8_t MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2__padding[16];
	};
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F 
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___va;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___vb;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___vc;
	UCircle_t867F766ACBC8203697A5637D6046595BBCA3A156 ___c;
	float ___area;
	int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 ___indices;
};
struct UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67 
{
	UntypedUnsafeList_tB7A46F76589C71832F1147292E5123FB99E199B2 ___m_UntypedListData;
};
struct Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 
{
	Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC ___Range;
	int32_t ___BytesPerItem;
	int32_t ___AllocatedItems;
	uint8_t ___Log2Alignment;
	uint8_t ___Padding0;
	uint16_t ___Padding1;
	uint32_t ___Padding2;
};
struct AlignOfHelper_1_t08A14D9ACB4D26ACA71BCA57DAB866764B883825 
{
	uint8_t ___dummy;
	ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B ___data;
};
struct AlignOfHelper_1_t9B8325E941D53AE21ECA21E2996411A52D0F8663 
{
	uint8_t ___dummy;
	GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B ___data;
};
struct AlignOfHelper_1_tF9C3457088E3B293794AA641A2261DD4B6D5B57A 
{
	uint8_t ___dummy;
	LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21 ___data;
};
struct AlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669 
{
	uint8_t ___dummy;
	UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F ___data;
};
struct AlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E 
{
	uint8_t ___dummy;
	UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67 ___data;
};
struct Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 
{
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f0;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f1;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f2;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f3;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f4;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f5;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f6;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f7;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f8;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f9;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f10;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f11;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f12;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f13;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f14;
	Array16_1_tD7DC1805EB67B07DF30FB4A25D3C1D0D5C0F9A9F ___f15;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct Long1024_tEE887C506947419DC829213E6C7483D80AF5659F 
{
	Long512_t2D339FF6672EB3709A6C638EABA7D13C7FEC1878 ___f0;
	Long512_t2D339FF6672EB3709A6C638EABA7D13C7FEC1878 ___f1;
};
struct MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84 
{
	uint8_t* ___m_pointer;
	int64_t ___m_bytes;
	Union_t651696C44E98CE15C53FE2628FA73E4B102D6C21 ___m_union;
	MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___m_memoryLabel;
};
struct Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458 
{
	Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 ___m_BlockData;
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___m_CurrentBlock;
	uint8_t* ___m_CurrentPtr;
	uint8_t* ___m_CurrentBlockEnd;
	int32_t ___m_RemainingItemCount;
	int32_t ___m_LastBlockSize;
};
struct Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F 
{
	Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 ___m_BlockData;
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___m_CurrentBlock;
	uint8_t* ___m_CurrentPtr;
	uint8_t* ___m_CurrentBlockEnd;
	int32_t ___m_ForeachIndex;
	int32_t ___m_ElementCount;
	UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* ___m_FirstBlock;
	int32_t ___m_FirstOffset;
	int32_t ___m_NumberOfBlocks;
	int32_t ___m_ThreadIndex;
};
struct AlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9 
{
	uint8_t ___dummy;
	MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84 ___data;
};
struct Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 
{
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f0;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f1;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f2;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f3;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f4;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f5;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f6;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f7;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f8;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f9;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f10;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f11;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f12;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f13;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f14;
	Array256_1_t5410033DC9920374048839AA4B80BA4420373D59 ___f15;
};
struct Reader_t84D582FCC8C26F85ACE0F2F31416D31F71FE4AD9 
{
	Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458 ___m_Reader;
};
struct Writer_tFFFC2E32CAA4337A0C5E1FAF6127DCC8BBD9DB8F 
{
	Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F ___m_Writer;
};
struct Array32768_1_tF94DB9E949B98E267CCEE7E61378AA0A89C951D6 
{
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f0;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f1;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f2;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f3;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f4;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f5;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f6;
	Array4096_1_t97465F61B5971FE36BADFE9A629DEB33EF47E8D8 ___f7;
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
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73_StaticFields
{
	InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 ___Default;
};
struct InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF_StaticFields
{
	InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF ___Default;
};
struct Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6_StaticFields
{
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___zeroMatrix;
	Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___identityMatrix;
};
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_StaticFields
{
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___identityQuaternion;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector;
};
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_StaticFields
{
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___zeroVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___oneVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___positiveInfinityVector;
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___negativeInfinityVector;
};
struct double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_StaticFields
{
	double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 ___zero;
};
struct float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_StaticFields
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___zero;
};
struct float4_t545A994996126766890C1F28B43EA823F2410190_StaticFields
{
	float4_t545A994996126766890C1F28B43EA823F2410190 ___zero;
};
struct int2_tB123E869131C6102341F8F9AA01726E0E7C2768D_StaticFields
{
	int2_tB123E869131C6102341F8F9AA01726E0E7C2768D ___zero;
};
struct Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields
{
	int32_t ___s_count;
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___s_zero;
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___s_one;
	Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___s_allOnes;
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
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct StreamCompressionModel_t7F9FB7DB2D88DA832A4DD61C1E6587A4C530697D_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___k_BucketSizes;
	UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___k_BucketOffsets;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___k_FirstBucketCandidate;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___k_DefaultModelData;
};
struct quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_StaticFields
{
	quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA ___identity;
};
struct StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_StaticFields
{
	int32_t ___SECRET_LIMIT;
	int32_t ___NB_STRIPES_PER_BLOCK;
	int32_t ___INTERNAL_BUFFER_SIZE;
	int32_t ___INTERNAL_BUFFER_STRIPES;
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


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5_mC4112DF120EBF605C8F77839E842177AF068D44E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m462940FF70DE74B43CFAFE2670B4A652829BDF3F_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4_m19CE06B2A77B620A1DE800E56AFEE3A5616E99E6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m2379B61902CFDAAAE7E5BE25FDA4BBBBF7E54273_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D_m22F628ADD6E12980B394B9237C61AB0C95E1EC1C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_m78BC20EBEDF9DDD29C261AACF9F19965B5A49C92_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37_m120CCD2A94A7B51A2631C5630A9E505F1DDB1CD7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_mD7804F40606876E9729617E9761E42F9D6056B26_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056_m24D80B10C7527E88ECD7E5C10731C7F1663E2C27_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_mDB23A7351A2DB7A69197EC17A28401C3A9B4DA98_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9_mE690DD75A3C952CEDEB71F13B96E603904A60567_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mB21F3357E1DB01146285E803CB68EE945ADA7149_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3_m936B8B899C03B9C80AA39CD231B892274340136D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_m483305F08D432A8FC41A6E11289383D1E2C3E8AE_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E_m2D3BC72BBF45866A72C7ADF31F40AEFC56BBD498_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mAA2B8333B77A7410376516B6E13FCC02AEE6A5AC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5_m6333413607F97523DA83C70DA244CCE8E0B50D8E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m87DD2D062338C42E1537725895679ED703A237D3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669_m50F19243DCF7F556C625C9C7048E8BA7FDA09C6E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_m0E3277DA666E697D096F659128CBE7238C655CA3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981_m0E4242520596E02B9AAE81652FFB8EE3542259AA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m9B75EBBD9DF8560D30B3C2E1E2C38BF7D85CAF9D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9_m98AA8DA7813F89F461C97A6373493AB6D70B858B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m3C94249F648A50E2D27EDAD82BD9BFD652086097_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA_m05924C78C0CB3BE4A7F3029ACEA5F044E6E559A0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3_mE4962E35BBA3FE3704E13AB652950BF09D05115F_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E_mFD07D65557C1FB04588D27C6A200F7746663E0B0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_mA5DC0B2032262984D97EFF4CF894E776A34A181F_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B_m019BC64A12A26B709A3CD09D40E912FCD97288A0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m5A6BC515442EB0B285497391D72FB18A31516CB2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A_m9D18F31B0150761121CE90F7608804E66D7C3A8E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mC4E70A23733EF555E25391199DFEB2A1FD127B7B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8_m9FEED4A848E422F5FCF3D03117ED631B4F585297_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mB0E98D09340662B90EC173E1CA8A23E15139D4F2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED_m6348B019EEA1591225152EC62349A8080572DEBE_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m2BA8D7C6E9CCBF7FF7426C0D61535B7C666FA642_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7_m8D3DF77211E69FDD188488FFCCC64392102FB872_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mE4848DFE6C4FDC789BE02AFD21E8FE4D0B4E743C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233_m10A168D59EE90DAFFEEF6F7416AA57E0596C2E70_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mD41EF628ACDD0AFCE611B0FF1420F33AEC2B85AF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF_m070F102DB9A8BCBD8CFC09CC7D9D3D6D3BE8EBA1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mE4561796E61AEFB55AA7AFBE1C9FD48F7AB887D3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6_mE75EA22DD22C5D163B9332C164A64653D05277D8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_mFEF7DABDBCC29D7CB4F903941FE66B61C0717CEF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28_m9C3C44466009BED76EBD7B1BDE919205705F2C97_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mA32DB809A91F2DC32E2319D41D9A5F00EB29A60E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150_mEFAE743E1DB26C808D99EBC8ADAAA960EF14E898_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mE9990F4132E7E548E1327B5AFDA595393DC8AB70_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF_m14EA35185C8F445B80BE36972B0E55FFE828CE69_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mE420CEFAC83BFD18111C33ED0C1DF46FE76A64B9_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1_m2786A7365CB5CE12DB402F330EC19DD42E7F56D9_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mB068DEDD3DC301EDA8B26358237AAC852800E5AD_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A_m034AE7678181AD29323E752CCA82EDCFE2E3CAA0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m297C8507511B4B7C587AF49B53D880021418C5CC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773_mAA11ED5EDA264AB3B48690198F615B38D00FE294_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m567C299D0E9EA26E8A3ADC4158D175D9F101BC1E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4_m29E0C0863AA5A2364C1F00FAEAD6CCEC94DA70FF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m96D588AB3F164F56BB1DE77BC435342E9F1BD745_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460_mDA796E09ECCAD2EAEF6F0A2C1773617A9FBA6E6E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mE64EA17FB7FE71E52F389B33C2AE7F4894B63B16_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE_m275DDCFF618B41FD8D55D227B523EE4375524AE0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m0F16771B993937271160B6B8203D4AF6E89B3E20_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7_m3B08AAF0A9461124EEB149509CB15BD615CAFA2D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mC0D8F1150C7D0AB1BF48EAE3FF8A9E7EADCFC89E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C_mAA91F87ABC1C69B33E87DD76C50A480D237F8B9A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_mB216CE24697733053C38D23575F516F72C0E7F06_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396_mB59C152F5426670D374DC720745E2F06FAADE0CA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_m8C0D64D09B9A2F8238A614656203048B06759A6B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3_m35ABFDD366C53EC12FEB57C526087B620B8844C2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mA8C62CC9E230AC8C9856724F0AD3DB92EBABE192_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C_mB6F9FC86B4C97B91F2ED87738287527A39EC3E12_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_mB36574769AB412B4AA1DD70033B37BEED9F5BD92_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9_m0307FE22A5AF62C62045020268823FBD9652FA71_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m64096CFB58B4B0A976A42BC41901B89806B85F69_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1ADEAC45E92C10A0C3D9686063C582FDD76F5937_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_op_Explicit_mEFC640DAE334AF4ED540F354F6FCDF25F74E95A2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 Vector_1_Equals_m6F913845CB1E8A1A753B3C187A8EB840C36F5ADF_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72 (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276 (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m68DAEAFD02AE0CA6A976BF0B8B0CAE855D168F32 (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___3_label, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0 (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F (intptr_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t* Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81 (uint64_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784 (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4 (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21 (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3 (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t MarshalledUnityObject_MarshalNotNull_TisIl2CppSharedGenericObject_mCE897EC9A79983B4B1E6E2C8342452256309044A_gshared_inline (Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* UnsafeUtility_As_TisIntPtr_t_TisGCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC_mD94F597CB91662C823496DA9FA9A7CF908734A78_inline (intptr_t* ___0_from, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mECC3B0123B8C95AF837F45785072BE5466D989C9_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m5DB7C8854924D1E1D01E14FB83112EBF8905533C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mD30E57AEFF1E2218A4DCE4EA77B9AE170B7A6BB3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mB76E5D04768F570DF3F45ABEB65D6BAFDFFF638A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mC44B74F48735FA62BAE3FBA763123E932B9EF822_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisIntPtr_t_m7FF5CB3788B437CA624174389D25EE9BCB2B212E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m29B7D9DA9527706BBA1F73ECEA934CCD0B2D99E3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mA359E62F880352C70AB4DC921D67E178E6DACB15_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mD2E2A270320B9190D3ECE518E4055D43CFF0C7EC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m73AE74F3CDDD5919B822BA2521D23FF3D3C930E6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m3CE37249D5247521F44E2D498FDBC3714462A3E3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m78688762B313B8CD8725C345D0D2446E999924E4_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m844535A4D039E811CA8C8A80A30A2499268FF979_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* UnsafeUtilityInternal_As_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mE1CA751887466B801BE69083C2B0EA3EDE41FF9B_fshared_inline (Il2CppFullySharedGenericAny* ___0_from, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50_m7E4E66C593913FCDFC8C03C06EFC4FFDC9A96BCF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m0E37BE54FFDD9D93D5ADCA4464466720A0534F51_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163_m4D97EFDBFE98987E636ECEAD022BD99CAB158A50_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mB7E3DB3D712EE116DD131EEFE9548C1E0FA09AF9_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693_m28A0205203C49D5369496BB8258836A6E90B4275_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m6C73B80F6290ED267404794EB2AC27F5EEDB4EF3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D_m8CB43E8118CC0E65E6E8130381DEB11701F21848_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m485E79FA6794AD30B29C6414A85A867DF156E5E1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752_m6197C4317CE4E01732509D53E08172FEA65ED04E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisIntPtr_t_mF9218FE174B91F132731D032A744AFC048AFB932_inline (const RuntimeMethod* method) ;

IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5_mC4112DF120EBF605C8F77839E842177AF068D44E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m462940FF70DE74B43CFAFE2670B4A652829BDF3F_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4_m19CE06B2A77B620A1DE800E56AFEE3A5616E99E6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m2379B61902CFDAAAE7E5BE25FDA4BBBBF7E54273_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D_m22F628ADD6E12980B394B9237C61AB0C95E1EC1C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_m78BC20EBEDF9DDD29C261AACF9F19965B5A49C92_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37_m120CCD2A94A7B51A2631C5630A9E505F1DDB1CD7_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_mD7804F40606876E9729617E9761E42F9D6056B26_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056_m24D80B10C7527E88ECD7E5C10731C7F1663E2C27_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_mDB23A7351A2DB7A69197EC17A28401C3A9B4DA98_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9_mE690DD75A3C952CEDEB71F13B96E603904A60567_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mB21F3357E1DB01146285E803CB68EE945ADA7149_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3_m936B8B899C03B9C80AA39CD231B892274340136D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_m483305F08D432A8FC41A6E11289383D1E2C3E8AE_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E_m2D3BC72BBF45866A72C7ADF31F40AEFC56BBD498_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mAA2B8333B77A7410376516B6E13FCC02AEE6A5AC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5_m6333413607F97523DA83C70DA244CCE8E0B50D8E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m87DD2D062338C42E1537725895679ED703A237D3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669_m50F19243DCF7F556C625C9C7048E8BA7FDA09C6E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_m0E3277DA666E697D096F659128CBE7238C655CA3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981_m0E4242520596E02B9AAE81652FFB8EE3542259AA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m9B75EBBD9DF8560D30B3C2E1E2C38BF7D85CAF9D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9_m98AA8DA7813F89F461C97A6373493AB6D70B858B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m3C94249F648A50E2D27EDAD82BD9BFD652086097_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA_m05924C78C0CB3BE4A7F3029ACEA5F044E6E559A0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3_mE4962E35BBA3FE3704E13AB652950BF09D05115F_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E_mFD07D65557C1FB04588D27C6A200F7746663E0B0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_mA5DC0B2032262984D97EFF4CF894E776A34A181F_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B_m019BC64A12A26B709A3CD09D40E912FCD97288A0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m5A6BC515442EB0B285497391D72FB18A31516CB2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A_m9D18F31B0150761121CE90F7608804E66D7C3A8E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mC4E70A23733EF555E25391199DFEB2A1FD127B7B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8_m9FEED4A848E422F5FCF3D03117ED631B4F585297_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mB0E98D09340662B90EC173E1CA8A23E15139D4F2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED_m6348B019EEA1591225152EC62349A8080572DEBE_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m2BA8D7C6E9CCBF7FF7426C0D61535B7C666FA642_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7_m8D3DF77211E69FDD188488FFCCC64392102FB872_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mE4848DFE6C4FDC789BE02AFD21E8FE4D0B4E743C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233_m10A168D59EE90DAFFEEF6F7416AA57E0596C2E70_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mD41EF628ACDD0AFCE611B0FF1420F33AEC2B85AF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF_m070F102DB9A8BCBD8CFC09CC7D9D3D6D3BE8EBA1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mE4561796E61AEFB55AA7AFBE1C9FD48F7AB887D3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6_mE75EA22DD22C5D163B9332C164A64653D05277D8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_mFEF7DABDBCC29D7CB4F903941FE66B61C0717CEF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28_m9C3C44466009BED76EBD7B1BDE919205705F2C97_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mA32DB809A91F2DC32E2319D41D9A5F00EB29A60E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150_mEFAE743E1DB26C808D99EBC8ADAAA960EF14E898_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mE9990F4132E7E548E1327B5AFDA595393DC8AB70_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF_m14EA35185C8F445B80BE36972B0E55FFE828CE69_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mE420CEFAC83BFD18111C33ED0C1DF46FE76A64B9_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1_m2786A7365CB5CE12DB402F330EC19DD42E7F56D9_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mB068DEDD3DC301EDA8B26358237AAC852800E5AD_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A_m034AE7678181AD29323E752CCA82EDCFE2E3CAA0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m297C8507511B4B7C587AF49B53D880021418C5CC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773_mAA11ED5EDA264AB3B48690198F615B38D00FE294_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m567C299D0E9EA26E8A3ADC4158D175D9F101BC1E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4_m29E0C0863AA5A2364C1F00FAEAD6CCEC94DA70FF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m96D588AB3F164F56BB1DE77BC435342E9F1BD745_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460_mDA796E09ECCAD2EAEF6F0A2C1773617A9FBA6E6E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mE64EA17FB7FE71E52F389B33C2AE7F4894B63B16_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE_m275DDCFF618B41FD8D55D227B523EE4375524AE0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m0F16771B993937271160B6B8203D4AF6E89B3E20_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7_m3B08AAF0A9461124EEB149509CB15BD615CAFA2D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mC0D8F1150C7D0AB1BF48EAE3FF8A9E7EADCFC89E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C_mAA91F87ABC1C69B33E87DD76C50A480D237F8B9A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_mB216CE24697733053C38D23575F516F72C0E7F06_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396_mB59C152F5426670D374DC720745E2F06FAADE0CA_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_m8C0D64D09B9A2F8238A614656203048B06759A6B_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3_m35ABFDD366C53EC12FEB57C526087B620B8844C2_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mA8C62CC9E230AC8C9856724F0AD3DB92EBABE192_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C_mB6F9FC86B4C97B91F2ED87738287527A39EC3E12_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_mB36574769AB412B4AA1DD70033B37BEED9F5BD92_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9_m0307FE22A5AF62C62045020268823FBD9652FA71_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m64096CFB58B4B0A976A42BC41901B89806B85F69_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1ADEAC45E92C10A0C3D9686063C582FDD76F5937_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) ;
inline Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_op_Explicit_m5E44D3923BF92F437AEC34CDE0CBD6130883B0B7 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_value, const RuntimeMethod* method)
{
	return ((  Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A (*) (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489, const RuntimeMethod*))Vector_1_op_Explicit_mEFC640DAE334AF4ED540F354F6FCDF25F74E95A2_fshared)(___0_value, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 Vector_1_Equals_m6F913845CB1E8A1A753B3C187A8EB840C36F5ADF_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint4_tB6BF4BE7E92EFB510DFCB18F2E217DAD1CD8FC1E xxHash3_Hash128_m6C799BBDD04BD7A1B9E8044B84B54C0F1A80D440 (void* ___0_input, int64_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint2_tB27E0548FBAD8AFF74840E32AA4362409E48E082 xxHash3_Hash64_m5BDF0741A0FB998E325592F811A387368043803C (void* ___0_input, int64_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_tzcnt_m25573278D92DAE1280EBFACAAB6BB50CFF4172CD_inline (int32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Block_set_Alignment_m4E74D90E827C5F58B3EBE91B2F5B097388E0500F (Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AllocatorHandle_Try_m4E8677E100693A0F015076408244AF2BA827CBC9 (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148* __this, Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3* ___0_block, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemClear_m6C4377117084A11A667A567BC2F5E606A632A7C1 (void* ___0_destination, int64_t ___1_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177 (void* ___0_destination, void* ___1_source, int64_t ___2_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72 (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276 (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m68DAEAFD02AE0CA6A976BF0B8B0CAE855D168F32 (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___3_label, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0 (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F (intptr_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t* Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81 (uint64_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784 (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4 (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21 (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3 (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Reader_ReadUnsafePtr_m6B71AAF3513F6A2D6AA072F03A5E9E7020F46906 (Reader_t84D582FCC8C26F85ACE0F2F31416D31F71FE4AD9* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Writer_Allocate_m647D78C16BD8AE24E717888CC1568DF31D573311 (Writer_tFFFC2E32CAA4337A0C5E1FAF6127DCC8BBD9DB8F* __this, int32_t ___0_size, const RuntimeMethod* method) ;
inline intptr_t MarshalledUnityObject_MarshalNotNull_TisIl2CppSharedGenericObject_mCE897EC9A79983B4B1E6E2C8342452256309044A_inline (Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method)
{
	return ((  intptr_t (*) (Il2CppSharedGenericObject*, const RuntimeMethod*))MarshalledUnityObject_MarshalNotNull_TisIl2CppSharedGenericObject_mCE897EC9A79983B4B1E6E2C8342452256309044A_gshared_inline)(___0_obj, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC MarshalledUnityObject_FromIntPtrUnsafe_m1C5AE0FB7CD1978A8387B0081DB909BAAC2324C3_inline (intptr_t ___0_gcHandle, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9 (uint64_t ___0_offset, int32_t ___1_alignmentPowerOfTwo, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Reader_ReadNext_m7C9150A60E622C8581A3E80C8DD1AD71D043BF6A (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t ___0_structSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Reader_ReadUnsafePtr_m6CDEF727114990BC4C2DF321BE752F229104A888 (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Writer_Allocate_m85F9D4FF8746C0A59DC23A9003398A6D9D42526D (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, int32_t ___0_size, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5 (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, void* ___0_input, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380 (void* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, int64_t ___4_size, int32_t ___5_align, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Array_Resize_mA60C117B1C01C122EB2D509DD4EADE4FB44C2150 (void* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___3_label, int64_t ___4_size, int32_t ___5_align, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_tzcnt_m9318C63D3F5FC4DE0F7ACB372307134237D52DA9_inline (uint32_t ___0_x, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* UnsafeUtility_As_TisIntPtr_t_TisGCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC_mD94F597CB91662C823496DA9FA9A7CF908734A78_inline (intptr_t* ___0_from, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetTarget_mE0AF851834410E2AEA6285B2497751570236C794 (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
inline void Vector_1__ctor_m48CD7847B9597F3193C9C0BA97ED64E276F4340A (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mECC3B0123B8C95AF837F45785072BE5466D989C9_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m5DB7C8854924D1E1D01E14FB83112EBF8905533C_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mD30E57AEFF1E2218A4DCE4EA77B9AE170B7A6BB3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mB76E5D04768F570DF3F45ABEB65D6BAFDFFF638A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mC44B74F48735FA62BAE3FBA763123E932B9EF822_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisIntPtr_t_m7FF5CB3788B437CA624174389D25EE9BCB2B212E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m29B7D9DA9527706BBA1F73ECEA934CCD0B2D99E3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mA359E62F880352C70AB4DC921D67E178E6DACB15_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mD2E2A270320B9190D3ECE518E4055D43CFF0C7EC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m73AE74F3CDDD5919B822BA2521D23FF3D3C930E6_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m3CE37249D5247521F44E2D498FDBC3714462A3E3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m78688762B313B8CD8725C345D0D2446E999924E4_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m844535A4D039E811CA8C8A80A30A2499268FF979_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF (intptr_t ___0_value, const RuntimeMethod* method) ;
inline GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* UnsafeUtilityInternal_As_TisIntPtr_t_TisGCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC_mD43127D5F7AA6EB4B52E5C30BA53F29843E9E9A2_inline (intptr_t* ___0_from, const RuntimeMethod* method)
{
	return ((  GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* (*) (intptr_t*, const RuntimeMethod*))UnsafeUtilityInternal_As_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mE1CA751887466B801BE69083C2B0EA3EDE41FF9B_fshared_inline)(___0_from, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50_m7E4E66C593913FCDFC8C03C06EFC4FFDC9A96BCF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m0E37BE54FFDD9D93D5ADCA4464466720A0534F51_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163_m4D97EFDBFE98987E636ECEAD022BD99CAB158A50_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mB7E3DB3D712EE116DD131EEFE9548C1E0FA09AF9_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693_m28A0205203C49D5369496BB8258836A6E90B4275_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m6C73B80F6290ED267404794EB2AC27F5EEDB4EF3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D_m8CB43E8118CC0E65E6E8130381DEB11701F21848_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m485E79FA6794AD30B29C6414A85A867DF156E5E1_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752_m6197C4317CE4E01732509D53E08172FEA65ED04E_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisIntPtr_t_mF9218FE174B91F132731D032A744AFC048AFB932_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m36853F8E5ABD4C14B492DED38BA104203DA9FADC (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5_mC4112DF120EBF605C8F77839E842177AF068D44E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m462940FF70DE74B43CFAFE2670B4A652829BDF3F_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m9B9607330865C0A5ABFB515754C1C1C96D19F344 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4_m19CE06B2A77B620A1DE800E56AFEE3A5616E99E6_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m2379B61902CFDAAAE7E5BE25FDA4BBBBF7E54273_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_mC80D3B528E9C492E0BAE5124788711053E5BA8AE (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D_m22F628ADD6E12980B394B9237C61AB0C95E1EC1C_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_m78BC20EBEDF9DDD29C261AACF9F19965B5A49C92_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_m2EAF1749DEC30DF8BAE54F2E152E33EEBF06D2E7 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37_m120CCD2A94A7B51A2631C5630A9E505F1DDB1CD7_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_mD7804F40606876E9729617E9761E42F9D6056B26_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_m9DF201FCDB9B057604B20987096858076D21CFAB (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056_m24D80B10C7527E88ECD7E5C10731C7F1663E2C27_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_mDB23A7351A2DB7A69197EC17A28401C3A9B4DA98_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m5CC670602FE83644EBD988EBBA04AB4D7D731FD7 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9_mE690DD75A3C952CEDEB71F13B96E603904A60567_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mB21F3357E1DB01146285E803CB68EE945ADA7149_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mF228544B123C545DB4D43DDE0E23492B7A731A7F (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3_m936B8B899C03B9C80AA39CD231B892274340136D_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_m483305F08D432A8FC41A6E11289383D1E2C3E8AE_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m29B7D9DA9527706BBA1F73ECEA934CCD0B2D99E3 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E_m2D3BC72BBF45866A72C7ADF31F40AEFC56BBD498_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mAA2B8333B77A7410376516B6E13FCC02AEE6A5AC_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m120C8454AB3B92B9FDB39562A6C50C333B6D7BD3 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5_m6333413607F97523DA83C70DA244CCE8E0B50D8E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m87DD2D062338C42E1537725895679ED703A237D3_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_mC3E4D8B9B275315C3369194023ADC219C9BFA56B (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669_m50F19243DCF7F556C625C9C7048E8BA7FDA09C6E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_m0E3277DA666E697D096F659128CBE7238C655CA3_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mA359E62F880352C70AB4DC921D67E178E6DACB15 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981_m0E4242520596E02B9AAE81652FFB8EE3542259AA_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m9B75EBBD9DF8560D30B3C2E1E2C38BF7D85CAF9D_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mD2E2A270320B9190D3ECE518E4055D43CFF0C7EC (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9_m98AA8DA7813F89F461C97A6373493AB6D70B858B_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m3C94249F648A50E2D27EDAD82BD9BFD652086097_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m73AE74F3CDDD5919B822BA2521D23FF3D3C930E6 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA_m05924C78C0CB3BE4A7F3029ACEA5F044E6E559A0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m3CE37249D5247521F44E2D498FDBC3714462A3E3 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3_mE4962E35BBA3FE3704E13AB652950BF09D05115F_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m78688762B313B8CD8725C345D0D2446E999924E4 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E_mFD07D65557C1FB04588D27C6A200F7746663E0B0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_mA5DC0B2032262984D97EFF4CF894E776A34A181F_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m32F628FAD732F47EC7CEDB37071D4639E661ABB6 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B_m019BC64A12A26B709A3CD09D40E912FCD97288A0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m5A6BC515442EB0B285497391D72FB18A31516CB2_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_m95CAE2BAA7571B168792961B6A721551A499126A (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A_m9D18F31B0150761121CE90F7608804E66D7C3A8E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mC4E70A23733EF555E25391199DFEB2A1FD127B7B_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m95DE51195AF1ADA1B15D23BDE4DBB5053F00EE22 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8_m9FEED4A848E422F5FCF3D03117ED631B4F585297_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mB0E98D09340662B90EC173E1CA8A23E15139D4F2_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m75A25DE096711F22DA683BA2E8AC44EC777A4F56 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED_m6348B019EEA1591225152EC62349A8080572DEBE_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m2BA8D7C6E9CCBF7FF7426C0D61535B7C666FA642_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_m26CA58A5033C2AF2AD3336BBDC3423E97BD8405E (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7_m8D3DF77211E69FDD188488FFCCC64392102FB872_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mE4848DFE6C4FDC789BE02AFD21E8FE4D0B4E743C_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mBFA0CF3BF84B2F905E0F91346C70C35F29C81648 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233_m10A168D59EE90DAFFEEF6F7416AA57E0596C2E70_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mD41EF628ACDD0AFCE611B0FF1420F33AEC2B85AF_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mB38743798FE7CE71DE15FA437C22246D2CFBC931 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF_m070F102DB9A8BCBD8CFC09CC7D9D3D6D3BE8EBA1_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mE4561796E61AEFB55AA7AFBE1C9FD48F7AB887D3_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m86631A14E09F4E5877BFFC8D94DEE2D94C3FE178 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6_mE75EA22DD22C5D163B9332C164A64653D05277D8_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_mFEF7DABDBCC29D7CB4F903941FE66B61C0717CEF_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_m258B4BE9CF4EFE61A9DE6A4C243ECE3B665ABE88 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28_m9C3C44466009BED76EBD7B1BDE919205705F2C97_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mA32DB809A91F2DC32E2319D41D9A5F00EB29A60E_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mE58B3BC39B650A9926C99821E9DFC16E6CBC09B6 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150_mEFAE743E1DB26C808D99EBC8ADAAA960EF14E898_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mE9990F4132E7E548E1327B5AFDA595393DC8AB70_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_m00F58516EA2B8C981DF1EE814244B0109FDE04ED (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF_m14EA35185C8F445B80BE36972B0E55FFE828CE69_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mE420CEFAC83BFD18111C33ED0C1DF46FE76A64B9_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mDDA47836D0386A0C63E13B719C79300F4E4ACDE3 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1_m2786A7365CB5CE12DB402F330EC19DD42E7F56D9_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mB068DEDD3DC301EDA8B26358237AAC852800E5AD_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m5A04043858F190DDD4C4AB8C2C707306514BCA45 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A_m034AE7678181AD29323E752CCA82EDCFE2E3CAA0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m297C8507511B4B7C587AF49B53D880021418C5CC_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mA208BE87A87C101AE5CCF93D07CE98EF4B72BB9D (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773_mAA11ED5EDA264AB3B48690198F615B38D00FE294_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m567C299D0E9EA26E8A3ADC4158D175D9F101BC1E_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisIl2CppFullySharedGenericStruct_m530059660A1E31984686E17CC9E1E8EC5BADDADF_fshared (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(il2cpp_rgctx_method(method->rgctx_data, 0));
		int32_t L_1;
		L_1 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m8D474CAB34FA5FB18D61421063147CE9793F0B05 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4_m29E0C0863AA5A2364C1F00FAEAD6CCEC94DA70FF_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m96D588AB3F164F56BB1DE77BC435342E9F1BD745_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mF5574E385BD8BFE25E8CE39CF6C0587EEB03EA32 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460_mDA796E09ECCAD2EAEF6F0A2C1773617A9FBA6E6E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mE64EA17FB7FE71E52F389B33C2AE7F4894B63B16_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m65D7BAAAA8022AA9B94420A96D4C457FF5569B5F (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE_m275DDCFF618B41FD8D55D227B523EE4375524AE0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m0F16771B993937271160B6B8203D4AF6E89B3E20_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_m57E0E337595766FD03823C81059B5D86BAB8FEEF (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7_m3B08AAF0A9461124EEB149509CB15BD615CAFA2D_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mC0D8F1150C7D0AB1BF48EAE3FF8A9E7EADCFC89E_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_m26EBC94AD0C3507224F27777BDABDC7B666D0880 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C_mAA91F87ABC1C69B33E87DD76C50A480D237F8B9A_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_mB216CE24697733053C38D23575F516F72C0E7F06_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_mBF5C30CFD8345346842446C6C9505350076D4166 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396_mB59C152F5426670D374DC720745E2F06FAADE0CA_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_m8C0D64D09B9A2F8238A614656203048B06759A6B_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mE9667172DCCAA2CC0371D40CBC26AD69CA73BE00 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3_m35ABFDD366C53EC12FEB57C526087B620B8844C2_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mA8C62CC9E230AC8C9856724F0AD3DB92EBABE192_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_m91C4A0D0A806E7177DA4B51414E5D6BB3BC61B2E (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C_mB6F9FC86B4C97B91F2ED87738287527A39EC3E12_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_mB36574769AB412B4AA1DD70033B37BEED9F5BD92_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m844535A4D039E811CA8C8A80A30A2499268FF979 (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9_m0307FE22A5AF62C62045020268823FBD9652FA71_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m64096CFB58B4B0A976A42BC41901B89806B85F69_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* UnsafeUtilityInternal_ArrayElementAsRef_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mEA5953BE348C2ADF6E742F4D841ADD96E78F2A97 (void* ___0_ptr, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint8_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		return (uint8_t*)(((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* UnsafeUtilityInternal_ArrayElementAsRef_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m4EB31308E947CE0FCF90BDEF2FC07157D0DB4678 (void* ___0_ptr, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		return (int32_t*)(((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* UnsafeUtilityInternal_ArrayElementAsRef_TisIl2CppFullySharedGenericStruct_m15B3F40D2AAAD385E615370BDEEAF11C94C43831_fshared (void* ___0_ptr, int32_t ___1_index, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t6008FADC86896702BBF0B0D1C9FBB34D7C0BDB09 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	{
		void* L_0 = ___0_ptr;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = SizeOf_T_t6008FADC86896702BBF0B0D1C9FBB34D7C0BDB09;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		return (Il2CppFullySharedGenericStruct*)(((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* UnsafeUtilityInternal_As_TisIl2CppSharedGenericObject_mF938497D672DB9C14D0738F1F43F1F449466EB67_gshared (RuntimeObject* ___0_from, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_from;
		return (Il2CppSharedGenericObject*)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* UnsafeUtilityInternal_As_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mE1CA751887466B801BE69083C2B0EA3EDE41FF9B_fshared (Il2CppFullySharedGenericAny* ___0_from, const RuntimeMethod* method) 
{
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_from;
		return (Il2CppFullySharedGenericAny*)(L_0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* UnsafeUtilityInternal_AsRef_TisIl2CppFullySharedGenericStruct_m4AE204964F54C3F7626BE47CADE4A52CF2797B6B_fshared (void* ___0_ptr, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		return (Il2CppFullySharedGenericStruct*)(L_0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mECC3B0123B8C95AF837F45785072BE5466D989C9 (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		int32_t* L_1 = ___1_output;
		UnsafeUtilityInternal_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1ADEAC45E92C10A0C3D9686063C582FDD76F5937_inline(L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyPtrToStructure_TisIl2CppFullySharedGenericStruct_m497ECA325F03B8C0201958D2EDD9088FFB44BBDD_fshared (void* ___0_ptr, Il2CppFullySharedGenericStruct* ___1_output, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		void* L_0 = ___0_ptr;
		Il2CppFullySharedGenericStruct* L_1 = ___1_output;
		((  void (*) (void*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6C6F7ABC33BDF25A69E8A2E8DE137DB2ACB77FDC (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_input;
		void* L_1 = ___1_ptr;
		UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline(L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyStructureToPtr_TisIl2CppFullySharedGenericStruct_m323E735FDEFDBCFEBB7D6566658A860C97410FFB_fshared (Il2CppFullySharedGenericStruct* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_input;
		void* L_1 = ___1_ptr;
		((  void (*) (Il2CppFullySharedGenericStruct*, void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1ADEAC45E92C10A0C3D9686063C582FDD76F5937 (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___1_output;
		void* L_1 = ___0_ptr;
		int32_t L_2 = (*(int32_t*)L_1);
		*(int32_t*)L_0 = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyPtrToStructure_TisIl2CppFullySharedGenericStruct_m06FA487F742A380443BFC89A98F97C63718E2BAA_fshared (void* ___0_ptr, Il2CppFullySharedGenericStruct* ___1_output, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t096D5B9D40ED0F73F21EBAE175F1DEC3156E3C81 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t096D5B9D40ED0F73F21EBAE175F1DEC3156E3C81);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___1_output;
		void* L_1 = ___0_ptr;
		il2cpp_codegen_memcpy(L_2, L_1, SizeOf_T_t096D5B9D40ED0F73F21EBAE175F1DEC3156E3C81);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_0, L_2, SizeOf_T_t096D5B9D40ED0F73F21EBAE175F1DEC3156E3C81);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericStruct*)L_0, (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127 (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___1_ptr;
		int32_t* L_1 = ___0_input;
		int32_t L_2 = (*(int32_t*)L_1);
		*(int32_t*)L_0 = L_2;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisIl2CppFullySharedGenericStruct_mECFA8273692D57001184F23BE06202A197831B12_fshared (Il2CppFullySharedGenericStruct* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t46FA681AF7AD470383D494C79EA6EE5D768C6E88 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t46FA681AF7AD470383D494C79EA6EE5D768C6E88);
	{
		void* L_0 = ___1_ptr;
		Il2CppFullySharedGenericStruct* L_1 = ___0_input;
		il2cpp_codegen_memcpy(L_2, L_1, SizeOf_T_t46FA681AF7AD470383D494C79EA6EE5D768C6E88);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_0, L_2, SizeOf_T_t46FA681AF7AD470383D494C79EA6EE5D768C6E88);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericStruct*)L_0, (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D UnsafeUtilityInternal_ReadArrayElement_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_mDBEEA432305DC45F859549C5C3C2BC1AB641161C (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_6 = (*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 UnsafeUtilityInternal_ReadArrayElement_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_mFF2A9A45B70E41FC9F6A40A69B2C8E3BAF76360A (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 L_6 = (*(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t UnsafeUtilityInternal_ReadArrayElement_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m215470D8CCA83493150D2E40676D8A40FCF722B0 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint8_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint8_t L_6 = (*(uint8_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B UnsafeUtilityInternal_ReadArrayElement_TisContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B_mE64830E3E69DCC7AFC8FF6B0965DCA99D7390356 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B L_6 = (*(ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 UnsafeUtilityInternal_ReadArrayElement_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m3DD623F7581DFB21C61537373F0F32050E5D8CFE (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_6 = (*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double UnsafeUtilityInternal_ReadArrayElement_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_m3153A5430B46A926C90C99ECC737289006BAB570 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(double);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		double L_6 = (*(double*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B UnsafeUtilityInternal_ReadArrayElement_TisEmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B_mAAB0A3B6158D3A53128F92076405F23C82C562CA (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B L_6 = (*(EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 UnsafeUtilityInternal_ReadArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mDC8A7125EE74C940B9F940440D412BA4B3A42575 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_6 = (*(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32 UnsafeUtilityInternal_ReadArrayElement_TisGPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32_m3AC186183B40DD72F475DEA5ABBA39D050266613 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32 L_6 = (*(GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B UnsafeUtilityInternal_ReadArrayElement_TisGPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B_mBF012366896A35F47863D2A27520F935DBDFADE0 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B L_6 = (*(GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int16_t UnsafeUtilityInternal_ReadArrayElement_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_mE907DE0EDCAAEB74B259B5022D1AC07C3FA77763 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int16_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int16_t L_6 = (*(int16_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int32_t L_6 = (*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t UnsafeUtilityInternal_ReadArrayElement_TisIntPtr_t_mC53DA66CA829ADB467A34898F82725DDA86091D6 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(intptr_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		intptr_t L_6 = (*(intptr_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D UnsafeUtilityInternal_ReadArrayElement_TisInternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D_m9B17FB9991C066865590CE397EC91A2056D1089A (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D L_6 = (*(InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 UnsafeUtilityInternal_ReadArrayElement_TisInternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73_mE43484F89D326B2CFC50C120174997AB2082FBE0 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 L_6 = (*(InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF UnsafeUtilityInternal_ReadArrayElement_TisInternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF_m0FD7B9D7ECD3AD5A4D20DA6E6A0CF95AB3D75C46 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF L_6 = (*(InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 UnsafeUtilityInternal_ReadArrayElement_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m1662D1EBAE1BC88EA11BD8D8D073D6DA787405D7 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_6 = (*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21 UnsafeUtilityInternal_ReadArrayElement_TisLightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21_m2B823F0822F76CA45530AD04A3D3DB110EC8259B (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21 L_6 = (*(LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 UnsafeUtilityInternal_ReadArrayElement_TisMatrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6_mDC2BC421E66DB6186E7ADB438406EB88CF637011 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 L_6 = (*(Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960 UnsafeUtilityInternal_ReadArrayElement_TisModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960_m1967F25DC74B6E081724F2C2A8158CE6999A3F63 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960 L_6 = (*(ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C UnsafeUtilityInternal_ReadArrayElement_TisPlane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C_mD0A53DDAFDC425AE7EEA283E95C48E3A414A87FD (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C L_6 = (*(Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 UnsafeUtilityInternal_ReadArrayElement_TisQuaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_m02B55D9C2BC9B83FDE111ACC6AC6826964D5E3D4 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6 = (*(Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268 UnsafeUtilityInternal_ReadArrayElement_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_mA0E6724F3B2E9E09250FBC5091626A5CF5A6FF93 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268 L_6 = (*(RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float UnsafeUtilityInternal_ReadArrayElement_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_mC8BDFAFE242DB675D668D2942EFD7CE36006251C (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float L_6 = (*(float*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1 UnsafeUtilityInternal_ReadArrayElement_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_m8F5A17DAD42997B6D75E949B0FF9379B2D066CE2 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1 L_6 = (*(UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC UnsafeUtilityInternal_ReadArrayElement_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_mEE88732C7CB1E07F024B69DB93E5131352E8A1E7 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC L_6 = (*(UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851 UnsafeUtilityInternal_ReadArrayElement_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_m8EB87859A6B1CDD9DD1729BB8913CB8985295847 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851 L_6 = (*(UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t UnsafeUtilityInternal_ReadArrayElement_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m67997A9A0642E52B1CB9AD52C90FD98038221C0F (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint16_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint16_t L_6 = (*(uint16_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t UnsafeUtilityInternal_ReadArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_mAA4A4AC11C7C0784A0566FAE86EFBAD08CF4126D (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint32_t L_6 = (*(uint32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t UnsafeUtilityInternal_ReadArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mA5895D44428BCE7F38A3E30CA324F5E0E599364F (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint64_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint64_t L_6 = (*(uint64_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D UnsafeUtilityInternal_ReadArrayElement_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m11B8FD36241682A117B1BD6EC4B1F4ED78B49B47 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D L_6 = (*(UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F UnsafeUtilityInternal_ReadArrayElement_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_mD9BEE07F15A62EDC899159691530AC27B6ABDAE2 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F L_6 = (*(UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF UnsafeUtilityInternal_ReadArrayElement_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m428197529023725620AD98901F36805C7F44946A (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF L_6 = (*(VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 UnsafeUtilityInternal_ReadArrayElement_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mBB1009A0B754FAAEB780D5AA2FB6C78EB196DBBA (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VPos_t60F9F86213E6426227874FBBA41EF5551B920A72);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 L_6 = (*(VPos_t60F9F86213E6426227874FBBA41EF5551B920A72*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD UnsafeUtilityInternal_ReadArrayElement_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mA3B0044C25A46E6F19051E9AB6956356C08F9C60 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD L_6 = (*(VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 UnsafeUtilityInternal_ReadArrayElement_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_mDD5FD2940C1729753C094962066A8565ED384457 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 L_6 = (*(VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9 UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mF3C6E6152A5ADE015EB9B2C9699CBC787C1688E9 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9 L_6 = (*(VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_m715DB71B0848B0FDEE63DF3050579F0B565DACCF (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F L_6 = (*(VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99 UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mDD1DABAD39E572E391456720F4DBDCA985C34FB5 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99 L_6 = (*(VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580 UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_mC1C97A1DAE36BB96BEA4A4F2F51B5C97814FE3F9 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580 L_6 = (*(VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_m8505B224F70969748DB0CEC64B87E7D1C284BCDC (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD L_6 = (*(VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_m377838C1C3DABC90CC462CA71594CD93CA822144 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC L_6 = (*(VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2 UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_m52EEC487FDA53B8ADB005EC2859B0C5845A74555 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2 L_6 = (*(VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D UnsafeUtilityInternal_ReadArrayElement_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_m61005BA63CBEA8D622D67764E5F3B60E89400C11 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D L_6 = (*(VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 UnsafeUtilityInternal_ReadArrayElement_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m726E59AE606BDAEEA7E8DD67B5F69FD00875153F (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = (*(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 UnsafeUtilityInternal_ReadArrayElement_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m4E48372E1097232C60446DED043FEC5C7A61C4B0 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_6 = (*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_ReadArrayElement_TisIl2CppFullySharedGenericAny_mC729F1975F0494EB9B61C929EAF0F798DCF68563_fshared (void* ___0_source, int32_t ___1_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t0AA6189E765AD6394317DDCA688595C885DC47B5 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t0AA6189E765AD6394317DDCA688595C885DC47B5);
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = SizeOf_T_t0AA6189E765AD6394317DDCA688595C885DC47B5;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		il2cpp_codegen_memcpy(L_6, ((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)), SizeOf_T_t0AA6189E765AD6394317DDCA688595C885DC47B5);
		il2cpp_codegen_memcpy(il2cppRetVal, L_6, SizeOf_T_t0AA6189E765AD6394317DDCA688595C885DC47B5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 UnsafeUtilityInternal_ReadArrayElement_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m40CEC3B3B74322BA7691BA450694C03DC4A1D452 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 L_6 = (*(double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 UnsafeUtilityInternal_ReadArrayElement_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mAA646CC2B25329E898077679928AB15DE9BC865E (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 L_6 = (*(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float3_t7600B73F092B37F484B12910A5269F30C778D31E UnsafeUtilityInternal_ReadArrayElement_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m1DB9C74A2931EC40BC55F536EAF48A42F71DF8B7 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float3_t7600B73F092B37F484B12910A5269F30C778D31E);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_6 = (*(float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float4_t545A994996126766890C1F28B43EA823F2410190 UnsafeUtilityInternal_ReadArrayElement_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_m4345334F80FD4FB761347999B8A9004C958D64DA (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float4_t545A994996126766890C1F28B43EA823F2410190);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float4_t545A994996126766890C1F28B43EA823F2410190 L_6 = (*(float4_t545A994996126766890C1F28B43EA823F2410190*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int2_tB123E869131C6102341F8F9AA01726E0E7C2768D UnsafeUtilityInternal_ReadArrayElement_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_m331A9772A1384E1911C59CDE98F9366F81EED2C7 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int2_tB123E869131C6102341F8F9AA01726E0E7C2768D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int2_tB123E869131C6102341F8F9AA01726E0E7C2768D L_6 = (*(int2_tB123E869131C6102341F8F9AA01726E0E7C2768D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 UnsafeUtilityInternal_ReadArrayElement_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_mBD52AD6E8736CB48656CFA0961D93E411266B81E (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 L_6 = (*(int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90 UnsafeUtilityInternal_ReadArrayElement_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_m776429375A9EF46AD949435543FDD0C5676070AC (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90 L_6 = (*(int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA UnsafeUtilityInternal_ReadArrayElement_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_mF5BE0A7677821E3A031B12EFE228B0D48C53A720 (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA L_6 = (*(quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t UnsafeUtilityInternal_ReadArrayElementWithStride_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5B0836CD7E15D2A86DB39068965A12E98670A649 (void* ___0_source, int32_t ___1_index, int32_t ___2_stride, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint8_t L_6 = (*(uint8_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElementWithStride_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m142239EC03EF551AAC70809189D5B14C59260A72 (void* ___0_source, int32_t ___1_index, int32_t ___2_stride, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int32_t L_6 = (*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 UnsafeUtilityInternal_ReadArrayElementWithStride_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mB3B0153D579BC9CB1ACD30A3769DEFE1916794DE (void* ___0_source, int32_t ___1_index, int32_t ___2_stride, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_6 = (*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_ReadArrayElementWithStride_TisIl2CppFullySharedGenericAny_mD8DC640103D38E555B272D6E61CA4B06A15E46ED_fshared (void* ___0_source, int32_t ___1_index, int32_t ___2_stride, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tA43FF1096C0DCB01EA2F665B1AE872CB6AB31798 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_tA43FF1096C0DCB01EA2F665B1AE872CB6AB31798);
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		il2cpp_codegen_memcpy(L_6, ((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)), SizeOf_T_tA43FF1096C0DCB01EA2F665B1AE872CB6AB31798);
		il2cpp_codegen_memcpy(il2cppRetVal, L_6, SizeOf_T_tA43FF1096C0DCB01EA2F665B1AE872CB6AB31798);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float4_t545A994996126766890C1F28B43EA823F2410190 UnsafeUtilityInternal_ReadArrayElementWithStride_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mB499A7B32DD2E6F7B46821F888F49AC0E7781A11 (void* ___0_source, int32_t ___1_index, int32_t ___2_stride, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float4_t545A994996126766890C1F28B43EA823F2410190 L_6 = (*(float4_t545A994996126766890C1F28B43EA823F2410190*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50_m7E4E66C593913FCDFC8C03C06EFC4FFDC9A96BCF (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1E8E61551DF980F24CBCDC154CDF9D613283AEE8_mB08B79DA9B4B36E5F91C1C905AB72CE425BBE00B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t1E8E61551DF980F24CBCDC154CDF9D613283AEE8);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t79FB2646CB5124B22898AECE2C1787E0B0EA4C93_m1E0DD44C4227A6BC53E61B5313522C65B9573BD8 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t79FB2646CB5124B22898AECE2C1787E0B0EA4C93);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF8D2C4925153DD905077B2DDBFFA1665C36A62BC_mF08A3C25AB3DEA08A2FF1BF469849DBF57980F3C (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF8D2C4925153DD905077B2DDBFFA1665C36A62BC);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163_m4D97EFDBFE98987E636ECEAD022BD99CAB158A50 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693_m28A0205203C49D5369496BB8258836A6E90B4275 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tBEA2F557D94117D6B5CA3D54DEA10F7A2F5AF996_mC0091F1B9C9C5F6FE2EF40A40286F792951D680B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tBEA2F557D94117D6B5CA3D54DEA10F7A2F5AF996);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t34CCC6CF432525FDD94891D4DAFB9DB74F9AF3E9_m8E01215ECE32A86C1F6BEBD206783D5863BE3102 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t34CCC6CF432525FDD94891D4DAFB9DB74F9AF3E9);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D_m8CB43E8118CC0E65E6E8130381DEB11701F21848 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t08A14D9ACB4D26ACA71BCA57DAB866764B883825_m234350549A466D387273283CD034377BA980C785 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t08A14D9ACB4D26ACA71BCA57DAB866764B883825);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF6B6CAC1AFD67E6448C9B177EA1734D57E3BCDA2_mF17960322FD73F94C5B1EA66A15A812107E8E26C (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF6B6CAC1AFD67E6448C9B177EA1734D57E3BCDA2);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFC537E4E3FE3F7962CBC5F219276522C16824ACF_m6ED1AB2C11E9DEA8670BFFABDB8A999E66D4460D (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tFC537E4E3FE3F7962CBC5F219276522C16824ACF);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tCD4B08DBB915013B12E50DA43CE11B02B0D135DD_m5CB9D53CC2151EBA31EE911F86BF64236024C41B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tCD4B08DBB915013B12E50DA43CE11B02B0D135DD);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t398568B8BA5FC2BA68E01C861AA1BEDC4750E61D_m5F14358FA8512CD3007A89FBBF226B14ECA4C00B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t398568B8BA5FC2BA68E01C861AA1BEDC4750E61D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9B8325E941D53AE21ECA21E2996411A52D0F8663_m70AC25EBFF484644D693343C24F146A8528614C8 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t9B8325E941D53AE21ECA21E2996411A52D0F8663);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t2B1B6F8C95D259E66B253A1C059AE8D3365B528E_m9653BC5706AAE6334C692185FFA0519BD7824CB3 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t2B1B6F8C95D259E66B253A1C059AE8D3365B528E);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752_m6197C4317CE4E01732509D53E08172FEA65ED04E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tCFC8A208D36EA414B14215D004A770AEC0DB8BA2_m88DBA349C0FF85634217C1CB08E8DB162E461E71 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tCFC8A208D36EA414B14215D004A770AEC0DB8BA2);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1A20691B0774E0EFBEAD966FB0B480A553DCF42E_m2B08131E6C67851405962CD6DF12CF465931B858 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t1A20691B0774E0EFBEAD966FB0B480A553DCF42E);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6F2F300ADF773C90F661FF403B84D167EB793773_m69F6C16E7F867D1C227B7289CE495CC095EC7AD0 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t6F2F300ADF773C90F661FF403B84D167EB793773);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t7880A587D589BDB26652DC16C427FE26F3D1053C_m1B9D4F13A41CCA89EE044338ABEFF47C7E72CD5B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t7880A587D589BDB26652DC16C427FE26F3D1053C);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF9C3457088E3B293794AA641A2261DD4B6D5B57A_m58FF4964D2CAEB4EFC416B1E0FDFD6E9705F3143 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF9C3457088E3B293794AA641A2261DD4B6D5B57A);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6C24EA77B111E6877D279F01810C1D4E13534301_m65D985DC623EBE012CF7CAE94EF2DFEF1B8A3243 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t6C24EA77B111E6877D279F01810C1D4E13534301);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF3D321A7435452B0B749AF58D2CF8AB1865BC52C_m1CAC82495552B9A4A605EEA04EA097B8AF87C8C2 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF3D321A7435452B0B749AF58D2CF8AB1865BC52C);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t4257D6924487B14B176AB4C639F1251F2E4ED1C6_mDDF1DABCBD0F4009518CE893AD84E6078D170199 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t4257D6924487B14B176AB4C639F1251F2E4ED1C6);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE6A7C0BC2AB9B74FA79F8449B8FA1BC94A474BC4_m19212FA6DC039BBDFD64B28E598F6264D54DB691 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE6A7C0BC2AB9B74FA79F8449B8FA1BC94A474BC4);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5_mC4112DF120EBF605C8F77839E842177AF068D44E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4_m19CE06B2A77B620A1DE800E56AFEE3A5616E99E6 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D_m22F628ADD6E12980B394B9237C61AB0C95E1EC1C (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37_m120CCD2A94A7B51A2631C5630A9E505F1DDB1CD7 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056_m24D80B10C7527E88ECD7E5C10731C7F1663E2C27 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9_mE690DD75A3C952CEDEB71F13B96E603904A60567 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3_m936B8B899C03B9C80AA39CD231B892274340136D (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E_m2D3BC72BBF45866A72C7ADF31F40AEFC56BBD498 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5_m6333413607F97523DA83C70DA244CCE8E0B50D8E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669_m50F19243DCF7F556C625C9C7048E8BA7FDA09C6E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981_m0E4242520596E02B9AAE81652FFB8EE3542259AA (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9_m98AA8DA7813F89F461C97A6373493AB6D70B858B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA_m05924C78C0CB3BE4A7F3029ACEA5F044E6E559A0 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3_mE4962E35BBA3FE3704E13AB652950BF09D05115F (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E_mFD07D65557C1FB04588D27C6A200F7746663E0B0 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B_m019BC64A12A26B709A3CD09D40E912FCD97288A0 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A_m9D18F31B0150761121CE90F7608804E66D7C3A8E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8_m9FEED4A848E422F5FCF3D03117ED631B4F585297 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED_m6348B019EEA1591225152EC62349A8080572DEBE (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7_m8D3DF77211E69FDD188488FFCCC64392102FB872 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233_m10A168D59EE90DAFFEEF6F7416AA57E0596C2E70 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF_m070F102DB9A8BCBD8CFC09CC7D9D3D6D3BE8EBA1 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6_mE75EA22DD22C5D163B9332C164A64653D05277D8 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28_m9C3C44466009BED76EBD7B1BDE919205705F2C97 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150_mEFAE743E1DB26C808D99EBC8ADAAA960EF14E898 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF_m14EA35185C8F445B80BE36972B0E55FFE828CE69 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1_m2786A7365CB5CE12DB402F330EC19DD42E7F56D9 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A_m034AE7678181AD29323E752CCA82EDCFE2E3CAA0 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773_mAA11ED5EDA264AB3B48690198F615B38D00FE294 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4_m29E0C0863AA5A2364C1F00FAEAD6CCEC94DA70FF (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460_mDA796E09ECCAD2EAEF6F0A2C1773617A9FBA6E6E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE_m275DDCFF618B41FD8D55D227B523EE4375524AE0 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7_m3B08AAF0A9461124EEB149509CB15BD615CAFA2D (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C_mAA91F87ABC1C69B33E87DD76C50A480D237F8B9A (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396_mB59C152F5426670D374DC720745E2F06FAADE0CA (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3_m35ABFDD366C53EC12FEB57C526087B620B8844C2 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C_mB6F9FC86B4C97B91F2ED87738287527A39EC3E12 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9_m0307FE22A5AF62C62045020268823FBD9652FA71 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisArray32768_1_tF94DB9E949B98E267CCEE7E61378AA0A89C951D6_m2D622DB508425A61059ECE0559FF2A1DAB9A6C08 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Array32768_1_tF94DB9E949B98E267CCEE7E61378AA0A89C951D6);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m0E37BE54FFDD9D93D5ADCA4464466720A0534F51 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D_m985082069E9AFCDB431F1FAEA8C86A270FC1CC09 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeList_1_t5C65DCA6782B7C9860C859C2F0C07A2C497E822D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718_m3252E9A232963C9F11F0525E7D34301A8EB8F303 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeList_1_t6C5E84D303190B625F3759C244502E1735453718);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613_m8DD238B8C39AF9036ECA11CB1F1EC7ED85903F62 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeList_1_t7F37B06177929AC50704A82689AED5BBFE830613);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mB7E3DB3D712EE116DD131EEFE9548C1E0FA09AF9 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m6C73B80F6290ED267404794EB2AC27F5EEDB4EF3 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m439E4115054F2F7F3DFE86DEAEF565B37F9DA51F (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m1B3257CEE82ED08641AFCA4D9B2ACBC96222B922 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m485E79FA6794AD30B29C6414A85A867DF156E5E1 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint8_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B_m409346A2C7D4615BB703F2802A6B9E12650CDB39 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m445C79CB5CEFFE71D2530C3CACDBC4B8D3A9D0A9 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisEmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B_mA1468D24A7B620A10E023979868C9D1EE2D5DE69 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_mD1B0EBD0B43B19830ED5B0A121221D27AA0B963E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisGPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32_mAC88D9A89F4AD39D5BDA8F3FF5419977CDCCC3E3 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisGPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B_m90E80C680B80CD82EB5839F5DDE33F22BFBF18D1 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m8EC54AD1BB1FFE52E59D872A1F83666DD9D381AA (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int16_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int32_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisIntPtr_t_mF9218FE174B91F132731D032A744AFC048AFB932 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(intptr_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D_m7042BFD95CFAA71CA1DD3DB939DB030B0656C6D2 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73_m00E1BE18CB920FCCCBFE7C2C4A1BF8BA0A7EFECF (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF_mFB035E1C19B4E54280B4B9D660EDA3A8A086CAF6 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m683E74E957EA7C85232727A0935BFE355EAC0732 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21_mF4E7699562D0DD8909029C23414C07C41E83166C (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisLong1024_tEE887C506947419DC829213E6C7483D80AF5659F_m09A4EDA10EB189B6A3BB08B453C99F93E6E9DD8A (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Long1024_tEE887C506947419DC829213E6C7483D80AF5659F);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisMatrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6_m310E3F9A8E091DFAB070D735691100178B15463B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960_m4FA6D33FFCEC8031D4883ABCA5ED229D28E44D80 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisPlane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C_m289C662F3DEC8A9CACB14474D55B65B1E5E1AE84 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisQuaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_mA10F583A957D150C530045E8E0C54DD2A4D96489 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m462940FF70DE74B43CFAFE2670B4A652829BDF3F (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m2379B61902CFDAAAE7E5BE25FDA4BBBBF7E54273 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisStreamCompressionModel_t7F9FB7DB2D88DA832A4DD61C1E6587A4C530697D_m9AF3854E29412DF4741CAAEE2BF182642A7248D2 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(StreamCompressionModel_t7F9FB7DB2D88DA832A4DD61C1E6587A4C530697D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_m78BC20EBEDF9DDD29C261AACF9F19965B5A49C92 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_mD7804F40606876E9729617E9761E42F9D6056B26 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_mDB23A7351A2DB7A69197EC17A28401C3A9B4DA98 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mB21F3357E1DB01146285E803CB68EE945ADA7149 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint16_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_m483305F08D432A8FC41A6E11289383D1E2C3E8AE (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint32_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mAA2B8333B77A7410376516B6E13FCC02AEE6A5AC (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint64_t);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m87DD2D062338C42E1537725895679ED703A237D3 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_m0E3277DA666E697D096F659128CBE7238C655CA3 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m9B75EBBD9DF8560D30B3C2E1E2C38BF7D85CAF9D (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m3C94249F648A50E2D27EDAD82BD9BFD652086097 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_mA5DC0B2032262984D97EFF4CF894E776A34A181F (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m5A6BC515442EB0B285497391D72FB18A31516CB2 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mC4E70A23733EF555E25391199DFEB2A1FD127B7B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VPos_t60F9F86213E6426227874FBBA41EF5551B920A72);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mB0E98D09340662B90EC173E1CA8A23E15139D4F2 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m2BA8D7C6E9CCBF7FF7426C0D61535B7C666FA642 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mE4848DFE6C4FDC789BE02AFD21E8FE4D0B4E743C (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mD41EF628ACDD0AFCE611B0FF1420F33AEC2B85AF (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mE4561796E61AEFB55AA7AFBE1C9FD48F7AB887D3 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_mFEF7DABDBCC29D7CB4F903941FE66B61C0717CEF (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mA32DB809A91F2DC32E2319D41D9A5F00EB29A60E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mE9990F4132E7E548E1327B5AFDA595393DC8AB70 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mE420CEFAC83BFD18111C33ED0C1DF46FE76A64B9 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mB068DEDD3DC301EDA8B26358237AAC852800E5AD (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m297C8507511B4B7C587AF49B53D880021418C5CC (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m567C299D0E9EA26E8A3ADC4158D175D9F101BC1E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisIl2CppFullySharedGenericStruct_m9FC95A845D303A9C72ED4044691DD435A70F994A_fshared (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t8EBE725B2740B3ECE9C2D5E9EBEB0B97172D5E18 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	{
		uint32_t L_0 = SizeOf_T_t8EBE725B2740B3ECE9C2D5E9EBEB0B97172D5E18;
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m96D588AB3F164F56BB1DE77BC435342E9F1BD745 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mE64EA17FB7FE71E52F389B33C2AE7F4894B63B16 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m0F16771B993937271160B6B8203D4AF6E89B3E20 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float3_t7600B73F092B37F484B12910A5269F30C778D31E);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mC0D8F1150C7D0AB1BF48EAE3FF8A9E7EADCFC89E (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float4_t545A994996126766890C1F28B43EA823F2410190);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_mB216CE24697733053C38D23575F516F72C0E7F06 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int2_tB123E869131C6102341F8F9AA01726E0E7C2768D);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_m8C0D64D09B9A2F8238A614656203048B06759A6B (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mA8C62CC9E230AC8C9856724F0AD3DB92EBABE192 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_mB36574769AB412B4AA1DD70033B37BEED9F5BD92 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m64096CFB58B4B0A976A42BC41901B89806B85F69 (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisStreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A_m6182D8E9A1FF63851810F09B7AB03D8F49749A9F (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(StreamingStateData_tB4ECCAB2ECCD0555A32604F161D9B80D9FA42B3A);
		return (int32_t)L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisBatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D_m8F2F55BA88BD7D9AE44C0AEDE2832F7B5D1F35B6 (void* ___0_destination, int32_t ___1_index, BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D L_6 = ___2_value;
		*(BatchCullingOutputDrawCommands_t61DD68A8D702A9468AF6D5DDF4529CE7BD5A636D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisBounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3_m2A0F09E085DD77128506415E87841F78B28A6C54 (void* ___0_destination, int32_t ___1_index, Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 L_6 = ___2_value;
		*(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m5BCA8D074309F3B46CEC7FD68ED40110FC26ADB7 (void* ___0_destination, int32_t ___1_index, uint8_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint8_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint8_t L_6 = ___2_value;
		*(uint8_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B_mE39132565475093BAD090E92CA932991E46BC595 (void* ___0_destination, int32_t ___1_index, ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B L_6 = ___2_value;
		*(ContactPairHeader_tA8C64AAEEF017149E77A6600B10A10F1A1C5648B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisCullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0_m384FBBC6F8F5110A48E4143C7F675776EA47445F (void* ___0_destination, int32_t ___1_index, CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0 L_6 = ___2_value;
		*(CullingSplit_tA645AE6542408220387BA7188513D7FEDBC1CAC0*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisDouble_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_mC2A7BB5CE0978BC539FB52E5326DA5A704553463 (void* ___0_destination, int32_t ___1_index, double ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(double);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		double L_6 = ___2_value;
		*(double*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisEmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B_m51B6E5CA111B53732375EAEACEAAA619F6649872 (void* ___0_destination, int32_t ___1_index, EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B L_6 = ___2_value;
		*(EmbeddedLODBuffer_t6D75CECAC228D0710132158E77ACB46D0C43027B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisEntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8_m9C0FADCA718C9341E229CEE17C8FE4855AC72880 (void* ___0_destination, int32_t ___1_index, EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8 L_6 = ___2_value;
		*(EntityId_t982FBD037EAC5CA077B1602A7EA40E3523AA0FC8*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisGPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32_m8D30843628A1D5617028C57F54F533476754764A (void* ___0_destination, int32_t ___1_index, GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32 L_6 = ___2_value;
		*(GPUDrivenMeshData_t0D53E18AECCB1ED48149AFD77C12CF1624340C32*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisGPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B_mD11C11FD5E761DB5DFA854AE4BAD7EC7255AE737 (void* ___0_destination, int32_t ___1_index, GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B L_6 = ___2_value;
		*(GPUDrivenSubMesh_t2D3B77E083A07816281294E54907E064B2A2A22B*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisInt16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_m98F5668334FA5D7DC5943C2EF4820057B8FA3AC8 (void* ___0_destination, int32_t ___1_index, int16_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int16_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int16_t L_6 = ___2_value;
		*(int16_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m6CE8AF6F42FA98657985C680DB85747DAC856E2F (void* ___0_destination, int32_t ___1_index, int32_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int32_t L_6 = ___2_value;
		*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisIntPtr_t_mD032891DCCD5A38294F51BAEEA8BFAA62B8557FB (void* ___0_destination, int32_t ___1_index, intptr_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(intptr_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		intptr_t L_6 = ___2_value;
		*(intptr_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisInternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D_m8A735DF8D46F26149043C87F203926540BC1E6B8 (void* ___0_destination, int32_t ___1_index, InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D L_6 = ___2_value;
		*(InternalLODGroupSettings_t9F08C56422FEBE035004C6D96DE664DB1961F38D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisInternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73_mD92C129429E118347DCE3E80F61ABED812BB3713 (void* ___0_destination, int32_t ___1_index, InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73 L_6 = ___2_value;
		*(InternalMeshLodRendererSettings_t2B499712F80597BFB45A4813CC139D1BEEDEBB73*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisInternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF_m7A4D40E228244C59345E45676D4CC8348B83617A (void* ___0_destination, int32_t ___1_index, InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF L_6 = ___2_value;
		*(InternalMeshRendererSettings_tFA0423524032AD2C34E24C53548BE032F67FC6AF*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mD1BBDE4AA26071C075B55ABB5CAC4980F449B46F (void* ___0_destination, int32_t ___1_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_6 = ___2_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisLightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21_m214EFE079E3D95383C08945E8BAFA5E3C3FAA190 (void* ___0_destination, int32_t ___1_index, LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21 L_6 = ___2_value;
		*(LightDataGI_t47D2197E863C0DDA40C2182FBF0A21367E468E21*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisMatrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6_mA93DE94079CF55B4D3FB32AE0780DF796C3CCA47 (void* ___0_destination, int32_t ___1_index, Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6 L_6 = ___2_value;
		*(Matrix4x4_tDB70CF134A14BA38190C59AA700BCE10E2AED3E6*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960_m6B028924EA3CC36810A213B16F58DE31DE31687E (void* ___0_destination, int32_t ___1_index, ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960 L_6 = ___2_value;
		*(ModifiableContactPair_t8D3CA3E20AF1718A5421A6098D633DDA67399960*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisPlane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C_mBE119E8ABAF3D83B9A393B7004C208DF31E4901C (void* ___0_destination, int32_t ___1_index, Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C L_6 = ___2_value;
		*(Plane_tB7D8CC6F7AACF5F3AA483AF005C1102A8577BC0C*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisQuaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_m9F92E74FB0AAD0FC40CC4DE76AF4BBA2C47C88D6 (void* ___0_destination, int32_t ___1_index, Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6 = ___2_value;
		*(Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m8A51075F082D2E4A1FB053EA92EB0FC37CAE35EA (void* ___0_destination, int32_t ___1_index, RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268 L_6 = ___2_value;
		*(RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m7871DE4308B379F2F32315380DA04C05F11DA13F (void* ___0_destination, int32_t ___1_index, float ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float L_6 = ___2_value;
		*(float*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_mE2BF625B742B08C6B1C2B768BD2C6B56E8FCF9FA (void* ___0_destination, int32_t ___1_index, UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1 L_6 = ___2_value;
		*(UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_m2FBE2FA3BBCE3FB77BD4AE0019762C8453B4C17B (void* ___0_destination, int32_t ___1_index, UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC L_6 = ___2_value;
		*(UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_m80FE70456505C6177FDF18C114A5896234C5A46A (void* ___0_destination, int32_t ___1_index, UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851 L_6 = ___2_value;
		*(UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m8096FCC44AAECDAC8F7011A27B6D4B6745A539CE (void* ___0_destination, int32_t ___1_index, uint16_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint16_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint16_t L_6 = ___2_value;
		*(uint16_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_m2A3A6B90150B69BBDEE5319C3CE02AF8B872B64B (void* ___0_destination, int32_t ___1_index, uint32_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint32_t L_6 = ___2_value;
		*(uint32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mC71868C665A692778D508E69E8AF1A631E0CD348 (void* ___0_destination, int32_t ___1_index, uint64_t ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(uint64_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint64_t L_6 = ___2_value;
		*(uint64_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m5EA80C1639D238E594564D9B622DF4CCE1141D4B (void* ___0_destination, int32_t ___1_index, UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D L_6 = ___2_value;
		*(UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_m6A69EFB7BEE099EB16798F6EA62AC3C8612E49D0 (void* ___0_destination, int32_t ___1_index, UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F L_6 = ___2_value;
		*(UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m20FDEA9ED991EA01160F0AE1E7AEFE8530CAAB4C (void* ___0_destination, int32_t ___1_index, VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF L_6 = ___2_value;
		*(VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_m36FFBBDF0611989274E616A874492853F59E4FD8 (void* ___0_destination, int32_t ___1_index, VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VPos_t60F9F86213E6426227874FBBA41EF5551B920A72);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 L_6 = ___2_value;
		*(VPos_t60F9F86213E6426227874FBBA41EF5551B920A72*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mDD2F0F124A03EC23919FFA542870013A6F2FD001 (void* ___0_destination, int32_t ___1_index, VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD L_6 = ___2_value;
		*(VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m4DDCDF023EDA4BDD354FF1ADF489ED9850562A2D (void* ___0_destination, int32_t ___1_index, VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 L_6 = ___2_value;
		*(VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_m6CB5EAB0C179428B6E74A8B442A5754B9320AC35 (void* ___0_destination, int32_t ___1_index, VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9 L_6 = ___2_value;
		*(VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_m44D2EE8015BFFDD7D5F4017F74C77423B35DA7AB (void* ___0_destination, int32_t ___1_index, VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F L_6 = ___2_value;
		*(VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_m8B0600E33EBE59134550CA81852D1B43F2A7F3D1 (void* ___0_destination, int32_t ___1_index, VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99 L_6 = ___2_value;
		*(VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m6D6319719C2A3C2D4BCA50C5623DDE389FEEA11F (void* ___0_destination, int32_t ___1_index, VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580 L_6 = ___2_value;
		*(VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_m5C1F9AFA9098CDE3849D8535CC27EDFBA5E74DF5 (void* ___0_destination, int32_t ___1_index, VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD L_6 = ___2_value;
		*(VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_m5D4A846892529AC50A22886E0DB07B4FFBF7DAED (void* ___0_destination, int32_t ___1_index, VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC L_6 = ___2_value;
		*(VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_m911C12F819AF33CBCF7997D84DADABD2FDC110AC (void* ___0_destination, int32_t ___1_index, VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2 L_6 = ___2_value;
		*(VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_m153403B9F3DD79383D12F8E6D82A7228F2E95F7A (void* ___0_destination, int32_t ___1_index, VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D L_6 = ___2_value;
		*(VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m4DC28ACC65CD91D06E733BEA0BC919D23DF3D7E4 (void* ___0_destination, int32_t ___1_index, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___2_value;
		*(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_mA724E762E40FA0C9F59E22D26CD7760418780D94 (void* ___0_destination, int32_t ___1_index, Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 L_6 = ___2_value;
		*(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_TisIl2CppFullySharedGenericAny_mDF23616AEE03407D05BE4CE63658C326ACA1ADC0_fshared (void* ___0_destination, int32_t ___1_index, Il2CppFullySharedGenericAny ___2_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t07C3F1A12A8E95862F1A2E3DD5ED60C8EC56F580 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t07C3F1A12A8E95862F1A2E3DD5ED60C8EC56F580);
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = SizeOf_T_t07C3F1A12A8E95862F1A2E3DD5ED60C8EC56F580;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___2_value : &___2_value), SizeOf_T_t07C3F1A12A8E95862F1A2E3DD5ED60C8EC56F580);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericAny*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)), L_6, SizeOf_T_t07C3F1A12A8E95862F1A2E3DD5ED60C8EC56F580);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericAny*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)), (void*)L_6);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_mF7835C7C0CCCC6506483D47D9F965AE133A2580A (void* ___0_destination, int32_t ___1_index, double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83 L_6 = ___2_value;
		*(double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_m394E812F3E02FCD362EB8DCBF0A7D112DBBE9DA3 (void* ___0_destination, int32_t ___1_index, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 L_6 = ___2_value;
		*(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_mCCB7378A1654D6858AC01354F23A9B160E4FA9A4 (void* ___0_destination, int32_t ___1_index, float3_t7600B73F092B37F484B12910A5269F30C778D31E ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float3_t7600B73F092B37F484B12910A5269F30C778D31E);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float3_t7600B73F092B37F484B12910A5269F30C778D31E L_6 = ___2_value;
		*(float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mFB3C5BA7935279F597DF44F272FAD304A9F6438D (void* ___0_destination, int32_t ___1_index, float4_t545A994996126766890C1F28B43EA823F2410190 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(float4_t545A994996126766890C1F28B43EA823F2410190);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float4_t545A994996126766890C1F28B43EA823F2410190 L_6 = ___2_value;
		*(float4_t545A994996126766890C1F28B43EA823F2410190*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_mE5E734E01AED08F1ED47485C1721B5B1331B0A58 (void* ___0_destination, int32_t ___1_index, int2_tB123E869131C6102341F8F9AA01726E0E7C2768D ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int2_tB123E869131C6102341F8F9AA01726E0E7C2768D);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int2_tB123E869131C6102341F8F9AA01726E0E7C2768D L_6 = ___2_value;
		*(int2_tB123E869131C6102341F8F9AA01726E0E7C2768D*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_m3A3B9DFD873633E9078206152E40D232B1B0F8D2 (void* ___0_destination, int32_t ___1_index, int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5 L_6 = ___2_value;
		*(int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mBFAF687EB944C031EFE295967D340706BA7A8F57 (void* ___0_destination, int32_t ___1_index, int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90 ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90 L_6 = ___2_value;
		*(int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElement_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_m137346D63C02B24B13FE945057F1D13B8A3FE53A (void* ___0_destination, int32_t ___1_index, quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA ___2_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA L_6 = ___2_value;
		*(quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElementWithStride_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mA5285ACD5E02F45B998BB8D461AA957EE449EE76 (void* ___0_destination, int32_t ___1_index, int32_t ___2_stride, uint8_t ___3_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		uint8_t L_6 = ___3_value;
		*(uint8_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElementWithStride_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m46E20F2BBF8564E1BC4A202FE67CCEC245A13E11 (void* ___0_destination, int32_t ___1_index, int32_t ___2_stride, int32_t ___3_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int32_t L_6 = ___3_value;
		*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElementWithStride_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m9538473830FB22B02FF843693C586B0F0CDFC5A3 (void* ___0_destination, int32_t ___1_index, int32_t ___2_stride, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_6 = ___3_value;
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElementWithStride_TisIl2CppFullySharedGenericAny_m43737F191942C3B66CAD8213014C3E89AB211631_fshared (void* ___0_destination, int32_t ___1_index, int32_t ___2_stride, Il2CppFullySharedGenericAny ___3_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t9E3CA3FDC66F405C1818D76720E23E0FECDA7AEF = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t9E3CA3FDC66F405C1818D76720E23E0FECDA7AEF);
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		il2cpp_codegen_memcpy(L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(method->rgctx_data, 0)) ? ___3_value : &___3_value), SizeOf_T_t9E3CA3FDC66F405C1818D76720E23E0FECDA7AEF);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericAny*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)), L_6, SizeOf_T_t9E3CA3FDC66F405C1818D76720E23E0FECDA7AEF);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericAny*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)), (void*)L_6);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_WriteArrayElementWithStride_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mE6F610F3BD0E2C0AD56B86CA623144900F598A29 (void* ___0_destination, int32_t ___1_index, int32_t ___2_stride, float4_t545A994996126766890C1F28B43EA823F2410190 ___3_value, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_destination;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		int32_t L_3 = ___2_stride;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		float4_t545A994996126766890C1F28B43EA823F2410190 L_6 = ___3_value;
		*(float4_t545A994996126766890C1F28B43EA823F2410190*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)) = L_6;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_AsVectorUInt64_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m0D538510931D731CE9075661C07B0DECAAC84B82 (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(Vector_1_t5ABB92D0A8A9F5B15E1C6E405ADBABA59736E56F_StaticInit);
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_0 = ___0_value;
		CHECKED_LOCAL_INIT(Vector_1_t5ABB92D0A8A9F5B15E1C6E405ADBABA59736E56F_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_1;
		L_1 = Vector_1_op_Explicit_m5E44D3923BF92F437AEC34CDE0CBD6130883B0B7(L_0, NULL);
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_AsVectorUInt64_TisIl2CppFullySharedGenericStruct_mD3B6243B6DD2F19C7DA294F642D66F699D797811_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(Vector_1_t5ABB92D0A8A9F5B15E1C6E405ADBABA59736E56F_StaticInit);
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ___0_value;
		CHECKED_LOCAL_INIT(Vector_1_t5ABB92D0A8A9F5B15E1C6E405ADBABA59736E56F_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_1;
		L_1 = ((  Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, NULL);
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 Vector_Equals_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_m1E49423160D9D2F662A38FDEE88842FC26B67EBC (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(Vector_1_t6B5A9226C7EC33CCA1D9ED26AD7E3FB392A69961_StaticInit);
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_0 = ___0_left;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t6B5A9226C7EC33CCA1D9ED26AD7E3FB392A69961_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_2;
		L_2 = Vector_1_Equals_m6F913845CB1E8A1A753B3C187A8EB840C36F5ADF_inline(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 Vector_Equals_TisIl2CppFullySharedGenericStruct_m589C7C54FDBBA8A38CC7672C2E2734EB16BDFD24_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(Vector_1_t6B5A9226C7EC33CCA1D9ED26AD7E3FB392A69961_StaticInit);
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ___0_left;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t6B5A9226C7EC33CCA1D9ED26AD7E3FB392A69961_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 1)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_2;
		L_2 = ((  Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, L_1, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Volatile_Read_TisIl2CppSharedGenericObject_m80AA45DB17514248EE3F1C51892F22E546B63BC9_gshared (Il2CppSharedGenericObject** ___0_location, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject** L_0 = ___0_location;
		VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99* L_1;
		L_1 = il2cpp_unsafe_as_ref<VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99>(L_0);
		RuntimeObject* L_2 = L_1->___Value;
		il2cpp_codegen_memory_barrier();
		Il2CppSharedGenericObject* L_3;
		L_3 = il2cpp_unsafe_as<Il2CppSharedGenericObject*>(L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Volatile_Write_TisIl2CppSharedGenericObject_m5283DEB09B854082CE5EFC9E4C1B19F4D8E1A5CA_gshared (Il2CppSharedGenericObject** ___0_location, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject** L_0 = ___0_location;
		VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99* L_1;
		L_1 = il2cpp_unsafe_as_ref<VolatileObject_tEA3ACFAAFB9D2EFA5162F693BAAB342EA7737B99>(L_0);
		Il2CppSharedGenericObject* L_2 = ___1_value;
		il2cpp_codegen_memory_barrier();
		L_1->___Value = (RuntimeObject*)L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___Value), (void*)(RuntimeObject*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint4_tB6BF4BE7E92EFB510DFCB18F2E217DAD1CD8FC1E xxHash3_Hash128_TisIl2CppFullySharedGenericStruct_mF840EB31CA16166C9809095238C704E98BE4C8BE_fshared (Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tA165AD8A197D950C46AD3C23F745A63FE161B6FC = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_input;
		void* L_1;
		L_1 = ((  void* (*) (Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 0));
		uint32_t L_2 = SizeOf_T_tA165AD8A197D950C46AD3C23F745A63FE161B6FC;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		uint4_tB6BF4BE7E92EFB510DFCB18F2E217DAD1CD8FC1E L_4;
		L_4 = xxHash3_Hash128_m6C799BBDD04BD7A1B9E8044B84B54C0F1A80D440(L_1, L_3, NULL);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint2_tB27E0548FBAD8AFF74840E32AA4362409E48E082 xxHash3_Hash64_TisIl2CppFullySharedGenericStruct_m3B27E6971156BEF59AFC23904113D23D9CB0C153_fshared (Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tD611D3B5B1ACD7BF81005B4B15839E4870306CCA = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_input;
		void* L_1;
		L_1 = ((  void* (*) (Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 0));
		uint32_t L_2 = SizeOf_T_tD611D3B5B1ACD7BF81005B4B15839E4870306CCA;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		uint2_tB27E0548FBAD8AFF74840E32AA4362409E48E082 L_4;
		L_4 = xxHash3_Hash64_m5BDF0741A0FB998E325592F811A387368043803C(L_1, L_3, NULL);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 AllocatorHandle_AllocateBlock_TisIl2CppFullySharedGenericStruct_mC112EEF2D397B738A58A313DBEDAC6A3C0884C21_fshared (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148* __this, int32_t ___0_items, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_items;
		int32_t L_1;
		L_1 = ((  int32_t (*) (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148*, Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(__this, (&V_0), L_0, il2cpp_rgctx_method(method->rgctx_data, 0));
		Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t AllocatorHandle_TryAllocateBlock_TisIl2CppFullySharedGenericStruct_m60B17BC434ABCADEE353507AE370842FE51C0D24_fshared (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148* __this, Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3* ___0_block, int32_t ___1_items, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t348255223DEAEC4C1C5AAE0D9DDF1B3C4008F582 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3* L_0 = ___0_block;
		il2cpp_codegen_initobj((&V_0), sizeof(Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3));
		il2cpp_codegen_initobj((&V_1), sizeof(Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC));
		int32_t L_1 = ___1_items;
		(&V_1)->___Items = L_1;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_2 = (*(AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148*)__this);
		(&V_1)->___Allocator = L_2;
		Range_tB5BAD1274CA0989FC97B0093B4149EF3CD5F21AC L_3 = V_1;
		(&V_0)->___Range = L_3;
		uint32_t L_4 = SizeOf_T_t348255223DEAEC4C1C5AAE0D9DDF1B3C4008F582;
		(&V_0)->___BytesPerItem = (int32_t)L_4;
		uint32_t L_5 = SizeOf_T_t348255223DEAEC4C1C5AAE0D9DDF1B3C4008F582;
		int32_t L_6;
		L_6 = math_tzcnt_m25573278D92DAE1280EBFACAAB6BB50CFF4172CD_inline((int32_t)L_5, NULL);
		int32_t L_7;
		L_7 = math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline(3, L_6, NULL);
		Block_set_Alignment_m4E74D90E827C5F58B3EBE91B2F5B097388E0500F((&V_0), ((int32_t)(1<<((int32_t)(L_7&((int32_t)31))))), NULL);
		Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3 L_8 = V_0;
		*(Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3*)L_0 = L_8;
		Block_tCCF620817FE305B5BF7B0FB7705B4571F976C4E3* L_9 = ___0_block;
		int32_t L_10;
		L_10 = AllocatorHandle_Try_m4E8677E100693A0F015076408244AF2BA827CBC9(__this, L_9, NULL);
		return L_10;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_TisIl2CppFullySharedGenericStruct_mD730785C3E9637938098A9F0A235B89FEE3AE7CA_fshared (Il2CppFullySharedGenericStruct* ___0_pointer, int64_t ___1_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t7E6A82CD805595CF7C6B952586DEF0592CEB5BE8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int64_t V_0 = 0;
	{
		int64_t L_0 = ___1_count;
		uint32_t L_1 = SizeOf_T_t7E6A82CD805595CF7C6B952586DEF0592CEB5BE8;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_1,NULL));
		V_0 = ((int64_t)il2cpp_codegen_multiply(L_0, L_2));
		Il2CppFullySharedGenericStruct* L_3 = ___0_pointer;
		int64_t L_4 = V_0;
		UnsafeUtility_MemClear_m6C4377117084A11A667A567BC2F5E606A632A7C1((void*)L_3, L_4, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_TisIl2CppFullySharedGenericStruct_m663B37B7863FEFA92383BB1F3457755E0FCF9C76_fshared (Il2CppFullySharedGenericStruct* ___0_dest, Il2CppFullySharedGenericStruct* ___1_src, int64_t ___2_count, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tBF4BAAB61C2B50FA098E305FEA3F21FCA51171DF = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int64_t V_0 = 0;
	{
		int64_t L_0 = ___2_count;
		uint32_t L_1 = SizeOf_T_tBF4BAAB61C2B50FA098E305FEA3F21FCA51171DF;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_1,NULL));
		V_0 = ((int64_t)il2cpp_codegen_multiply(L_0, L_2));
		Il2CppFullySharedGenericStruct* L_3 = ___0_dest;
		Il2CppFullySharedGenericStruct* L_4 = ___1_src;
		int64_t L_5 = V_0;
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_3, (void*)L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Set_TisIl2CppFullySharedGenericStruct_mE1A1DAD75AFF2C9365C8CDA0E40CBC5831526483_fshared (Il2CppFullySharedGenericStruct* ___0_pointer, int64_t ___1_count, Il2CppFullySharedGenericStruct ___2_t, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tC2AD72A0897436B221D24DCD3322E21010B1E4AC = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_tC2AD72A0897436B221D24DCD3322E21010B1E4AC);
	int32_t V_0 = 0;
	{
		V_0 = 0;
		goto IL_0019;
	}

IL_0004:
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		int32_t L_1 = V_0;
		intptr_t L_2 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = SizeOf_T_tC2AD72A0897436B221D24DCD3322E21010B1E4AC;
		il2cpp_codegen_memcpy(L_4, ___2_t, SizeOf_T_tC2AD72A0897436B221D24DCD3322E21010B1E4AC);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3)))), L_4, SizeOf_T_tC2AD72A0897436B221D24DCD3322E21010B1E4AC);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 0), (void**)(Il2CppFullySharedGenericStruct*)((Il2CppFullySharedGenericStruct*)il2cpp_codegen_add((intptr_t)L_0, ((intptr_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3)))), (void*)L_4);
		int32_t L_5 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0019:
	{
		int32_t L_6 = V_0;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_6,NULL));
		int64_t L_8 = ___1_count;
		if ((((int64_t)L_7) < ((int64_t)L_8)))
		{
			goto IL_0004;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Unmanaged_Allocate_TisIl2CppFullySharedGenericStruct_m489B7BAF35FECA60495B14643710C36E2A903DDC_fshared (MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___0_label, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_3 = ___0_label;
		Il2CppFullySharedGenericStruct* L_4;
		L_4 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((Il2CppFullySharedGenericStruct*)L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Unmanaged_Allocate_TisIl2CppFullySharedGenericStruct_m057D0CA6874E6719E10B462BACECFDC4352FE9AE_fshared (AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___0_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___0_allocator;
		Il2CppFullySharedGenericStruct* L_4;
		L_4 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((Il2CppFullySharedGenericStruct*)L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m805FE99DED95E176759F6DBEF0B7B3120EB67B47 (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_6;
		L_6 = Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m2DE439768C1ED8207B310B087BA22C4E1344C151 (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_6;
		L_6 = Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m1EEF7F2F65542F10C73B042CE442EB5F8FA73473 (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_6;
		L_6 = Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB842487F6E39F1309C51145BFD8100F50F607D67 (uint8_t* ___0_pointer, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___1_label, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		uint8_t* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_5 = ___1_label;
		uint8_t* L_6;
		L_6 = Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m68DAEAFD02AE0CA6A976BF0B8B0CAE855D168F32(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1C432B8FDFC847D68ECC57BF4C911BA784284271 (uint8_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		uint8_t* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		uint8_t* L_6;
		L_6 = Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBDAC644D78CB577E5C3CEF18A59DB392CB645A4C (int32_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		int32_t* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		int32_t* L_6;
		L_6 = Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisIntPtr_t_mBB8D3065E5D6C54BBD56EF509EA39BF1BF139F54 (intptr_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		intptr_t* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		intptr_t* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		intptr_t* L_6;
		L_6 = Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mEE0CCF17012BE1CA95605693A9DC3BC6AACCFB64 (uint64_t* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		uint64_t* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		uint64_t* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		uint64_t* L_6;
		L_6 = Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mE3F6373EC4A8E7ED5EA452E3A5738529668CD99E (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_6;
		L_6 = Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m22827025CA779A0BDA69EEF4AB67F77D1070C655 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_6;
		L_6 = Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m096E2AEE0566600497706AAD1E2B8CF599A2EFDB (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_6;
		L_6 = Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m2B126798068B361AB653416A8345288E9A242B22 (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_6;
		L_6 = Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m43022B9CFB1F8C5AB5994140793058FD355CCF84 (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_6;
		L_6 = Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisIl2CppFullySharedGenericStruct_mDA239BE5AFDF8B439292D696E2F1F609E61E5E77_fshared (Il2CppFullySharedGenericStruct* ___0_pointer, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___1_label, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		Il2CppFullySharedGenericStruct* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_5 = ___1_label;
		Il2CppFullySharedGenericStruct* L_6;
		L_6 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisIl2CppFullySharedGenericStruct_mC5E4D92A647D08D8B3B7CCF667B40D0ECD8ACB83_fshared (Il2CppFullySharedGenericStruct* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		Il2CppFullySharedGenericStruct* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		Il2CppFullySharedGenericStruct* L_6;
		L_6 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Unmanaged_Free_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m7B99D1F06742355AC760F246D818C9979FADF666 (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_pointer, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_2 = ___0_pointer;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___1_allocator;
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_6;
		L_6 = Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3(L_2, L_3, L_4, L_5, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Peek_TisIl2CppFullySharedGenericStruct_m2858A9931F3736225D223F6D7A66EB3B740CFB3E_fshared (Reader_t84D582FCC8C26F85ACE0F2F31416D31F71FE4AD9* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* L_0 = (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458*)(&__this->___m_Reader);
		Il2CppFullySharedGenericStruct* L_1;
		L_1 = ((  Il2CppFullySharedGenericStruct* (*) (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Read_TisIl2CppFullySharedGenericStruct_m72E44AFFE62AB8341A8BF0975D02F88F85B58819_fshared (Reader_t84D582FCC8C26F85ACE0F2F31416D31F71FE4AD9* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tEA8AB95C30D4228D83981D7139BD4CF1E13E0FA8 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int32_t V_0 = 0;
	{
		uint32_t L_0 = SizeOf_T_tEA8AB95C30D4228D83981D7139BD4CF1E13E0FA8;
		V_0 = (int32_t)L_0;
		int32_t L_1 = V_0;
		uint8_t* L_2;
		L_2 = Reader_ReadUnsafePtr_m6B71AAF3513F6A2D6AA072F03A5E9E7020F46906(__this, L_1, NULL);
		Il2CppFullySharedGenericStruct* L_3;
		L_3 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Writer_Allocate_TisIl2CppFullySharedGenericStruct_m152D2779B7277D522B694AF0698A887AEDD0B866_fshared (Writer_tFFFC2E32CAA4337A0C5E1FAF6127DCC8BBD9DB8F* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t509902FD265E7DED0EEB59220BA2B883E22CDA1F = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int32_t V_0 = 0;
	{
		uint32_t L_0 = SizeOf_T_t509902FD265E7DED0EEB59220BA2B883E22CDA1F;
		V_0 = (int32_t)L_0;
		int32_t L_1 = V_0;
		uint8_t* L_2;
		L_2 = Writer_Allocate_m647D78C16BD8AE24E717888CC1568DF31D573311(__this, L_1, NULL);
		Il2CppFullySharedGenericStruct* L_3;
		L_3 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Writer_Write_TisIl2CppFullySharedGenericStruct_m4B52108B68A52441FB126D64ECBC48059BFFE7CB_fshared (Writer_tFFFC2E32CAA4337A0C5E1FAF6127DCC8BBD9DB8F* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t4D147616122922D2FA67851EB5ADEC781EBCE735 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_T_t4D147616122922D2FA67851EB5ADEC781EBCE735);
	{
		Il2CppFullySharedGenericStruct* L_0;
		L_0 = ((  Il2CppFullySharedGenericStruct* (*) (Writer_tFFFC2E32CAA4337A0C5E1FAF6127DCC8BBD9DB8F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(__this, il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_memcpy(L_1, ___0_value, SizeOf_T_t4D147616122922D2FA67851EB5ADEC781EBCE735);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_0, L_1, SizeOf_T_t4D147616122922D2FA67851EB5ADEC781EBCE735);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 1), (void**)(Il2CppFullySharedGenericStruct*)L_0, (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t MarshalledUnityObject_Marshal_TisIl2CppSharedGenericObject_m35CB06885EF5600EDBB840B54EDAF3A806896DBB_gshared (Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = ___0_obj;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		return 0;
	}

IL_000e:
	{
		Il2CppSharedGenericObject* L_1 = ___0_obj;
		intptr_t L_2;
		L_2 = MarshalledUnityObject_MarshalNotNull_TisIl2CppSharedGenericObject_mCE897EC9A79983B4B1E6E2C8342452256309044A_inline(L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t MarshalledUnityObject_MarshalNotNull_TisIl2CppSharedGenericObject_mCE897EC9A79983B4B1E6E2C8342452256309044A_gshared (Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = ___0_obj;
		intptr_t L_1 = ((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_0)->___m_CachedPtr;
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* MarshalledUnityObject_Unmarshal_TisIl2CppSharedGenericObject_mDFF812844C3A315BA334E9FD102E4EE28E2847B1_gshared (intptr_t ___0_gcHandlePtr, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC V_0;
	memset((&V_0), 0, sizeof(V_0));
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		intptr_t L_0 = ___0_gcHandlePtr;
		bool L_1;
		L_1 = IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271_inline(L_0, 0, NULL);
		if (!L_1)
		{
			goto IL_0017;
		}
	}
	{
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_2 = V_1;
		return L_2;
	}

IL_0017:
	{
		intptr_t L_3 = ___0_gcHandlePtr;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_4;
		L_4 = MarshalledUnityObject_FromIntPtrUnsafe_m1C5AE0FB7CD1978A8387B0081DB909BAAC2324C3_inline(L_3, NULL);
		V_0 = L_4;
		RuntimeObject* L_5;
		L_5 = GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline((&V_0), NULL);
		return ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_5, il2cpp_rgctx_data(method->rgctx_data, 0)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	void* V_2 = NULL;
	{
		uint32_t L_0 = sizeof(int32_t);
		V_0 = (int32_t)L_0;
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_2 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		void* L_3 = V_2;
		uint64_t L_4 = (il2cpp_codegen_conv<uint64_t,void*,intptr_t,false,false>(L_3,NULL));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline(NULL);
		bool L_6;
		L_6 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_4, L_5, NULL);
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		void* L_7 = V_2;
		int32_t L_8;
		L_8 = UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline(L_7, 0, NULL);
		V_1 = L_8;
		goto IL_0038;
	}

IL_002d:
	{
		uintptr_t L_9 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>((&V_1),NULL));
		void* L_10 = V_2;
		int32_t L_11 = V_0;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_11,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_9, L_10, L_12, NULL);
	}

IL_0038:
	{
		int32_t L_13 = __this->___Offset;
		int32_t L_14 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_13, L_14));
		int32_t L_15 = V_1;
		return L_15;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m4BEED82D6907F7A1B30916AD15A551B4477AB2C2_fshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	const Il2CppFullySharedGenericStruct L_15 = L_8;
	int32_t V_0 = 0;
	Il2CppFullySharedGenericStruct V_1 = alloca(SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	memset(V_1, 0, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
	void* V_2 = NULL;
	{
		uint32_t L_0 = SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49;
		V_0 = (int32_t)L_0;
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_2 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		void* L_3 = V_2;
		uint64_t L_4 = (il2cpp_codegen_conv<uint64_t,void*,intptr_t,false,false>(L_3,NULL));
		int32_t L_5;
		L_5 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		bool L_6;
		L_6 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_4, L_5, NULL);
		if (!L_6)
		{
			goto IL_002d;
		}
	}
	{
		void* L_7 = V_2;
		InvokerActionInvoker3< void*, int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)), il2cpp_rgctx_method(method->rgctx_data, 2), NULL, L_7, 0, (Il2CppFullySharedGenericStruct*)L_8);
		il2cpp_codegen_memcpy(V_1, L_8, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		goto IL_0038;
	}

IL_002d:
	{
		uintptr_t L_9 = (il2cpp_codegen_conv<uintptr_t,Il2CppFullySharedGenericStruct*,intptr_t,false,false>((Il2CppFullySharedGenericStruct*)V_1,NULL));
		void* L_10 = V_2;
		int32_t L_11 = V_0;
		int64_t L_12 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_11,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177((void*)L_9, L_10, L_12, NULL);
	}

IL_0038:
	{
		int32_t L_13 = __this->___Offset;
		int32_t L_14 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_13, L_14));
		il2cpp_codegen_memcpy(L_15, V_1, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		il2cpp_codegen_memcpy(il2cppRetVal, L_15, SizeOf_T_t23EFE765355235E0552FEAA74620709E7D407C49);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m17201F199E61247BB0595C13E633DDC1D94569F9 (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	void* V_1 = NULL;
	void* V_2 = NULL;
	int32_t* V_3 = NULL;
	{
		uint32_t L_0 = sizeof(int32_t);
		V_0 = (int32_t)L_0;
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_1 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		void* L_3 = V_1;
		uint64_t L_4 = (il2cpp_codegen_conv<uint64_t,void*,intptr_t,false,false>(L_3,NULL));
		int32_t L_5;
		L_5 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline(NULL);
		bool L_6;
		L_6 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_4, L_5, NULL);
		if (!L_6)
		{
			goto IL_002c;
		}
	}
	{
		void* L_7 = V_1;
		int32_t* L_8 = ___0_value;
		UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_inline(L_7, L_8, NULL);
		goto IL_003d;
	}

IL_002c:
	{
		int32_t* L_9 = ___0_value;
		V_3 = L_9;
		int32_t* L_10 = V_3;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_10,NULL));
		V_2 = (void*)L_11;
		void* L_12 = V_2;
		void* L_13 = V_1;
		int32_t L_14 = V_0;
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_14,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_12, L_13, L_15, NULL);
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_3 = (int32_t*)L_16;
	}

IL_003d:
	{
		int32_t L_17 = __this->___Offset;
		int32_t L_18 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_17, L_18));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_mD61521649968D72362C4D143C6798CF697284C59_fshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, Il2CppFullySharedGenericStruct* ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t989833F3B8437253060D8003F814134F2C820AF6 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int32_t V_0 = 0;
	void* V_1 = NULL;
	void* V_2 = NULL;
	Il2CppFullySharedGenericStruct* V_3 = NULL;
	{
		uint32_t L_0 = SizeOf_T_t989833F3B8437253060D8003F814134F2C820AF6;
		V_0 = (int32_t)L_0;
		uint8_t* L_1 = __this->___Ptr;
		int32_t L_2 = __this->___Offset;
		V_1 = (void*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_1, L_2));
		void* L_3 = V_1;
		uint64_t L_4 = (il2cpp_codegen_conv<uint64_t,void*,intptr_t,false,false>(L_3,NULL));
		int32_t L_5;
		L_5 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		bool L_6;
		L_6 = CollectionHelper_IsAligned_m4761669B9084B892256349C0FF27DBF494DA9AE9(L_4, L_5, NULL);
		if (!L_6)
		{
			goto IL_002c;
		}
	}
	{
		void* L_7 = V_1;
		Il2CppFullySharedGenericStruct* L_8 = ___0_value;
		((  void (*) (void*, Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_7, L_8, il2cpp_rgctx_method(method->rgctx_data, 2));
		goto IL_003d;
	}

IL_002c:
	{
		Il2CppFullySharedGenericStruct* L_9 = ___0_value;
		V_3 = L_9;
		Il2CppFullySharedGenericStruct* L_10 = V_3;
		uintptr_t L_11 = (il2cpp_codegen_conv<uintptr_t,Il2CppFullySharedGenericStruct*,intptr_t,false,false>(L_10,NULL));
		V_2 = (void*)L_11;
		void* L_12 = V_2;
		void* L_13 = V_1;
		int32_t L_14 = V_0;
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_14,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_12, L_13, L_15, NULL);
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_3 = (Il2CppFullySharedGenericStruct*)L_16;
	}

IL_003d:
	{
		int32_t L_17 = __this->___Offset;
		int32_t L_18 = V_0;
		__this->___Offset = ((int32_t)il2cpp_codegen_add(L_17, L_18));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Reader_ReadNext_TisIl2CppFullySharedGenericStruct_m08EA2C685C92045455508A2CEA28AF34C49BF372_fshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* ___0_value, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t3582FAB8EED36663C15B18083F3C38CC8CB2089F = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	void* V_2 = NULL;
	{
		int32_t L_0;
		L_0 = Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774(__this, NULL);
		V_0 = L_0;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_1 = ___0_value;
		int32_t L_2 = V_0;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___1_allocator;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_4;
		L_4 = ((  NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 (*) (int32_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_2, L_3, 0, il2cpp_rgctx_method(method->rgctx_data, 0));
		*(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)L_1 = L_4;
		int32_t L_5 = V_0;
		uint32_t L_6 = SizeOf_T_t3582FAB8EED36663C15B18083F3C38CC8CB2089F;
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_5, (int32_t)L_6));
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_003d;
		}
	}
	{
		int32_t L_8 = V_1;
		void* L_9;
		L_9 = Reader_ReadNext_m7C9150A60E622C8581A3E80C8DD1AD71D043BF6A(__this, L_8, NULL);
		V_2 = L_9;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_10 = ___0_value;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_11 = (*(NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)L_10);
		void* L_12;
		L_12 = ((  void* (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 2)))(L_11, NULL);
		void* L_13 = V_2;
		int32_t L_14 = V_1;
		int64_t L_15 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_14,NULL));
		UnsafeUtility_MemCpy_m5CEA91ACDADC522E584AE3A2AB2B0B74393A9177(L_12, L_13, L_15, NULL);
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* Reader_ReadNextArray_TisIl2CppFullySharedGenericStruct_mE1C3BA7C6F410106344DD729D6EBF3FB62CB67CC_fshared (Reader_t409B401DB3A9E3F5C637DF66E5FAB1F63C291CB6* __this, int32_t* ___0_length, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t6E0E95C00360B98AD1C3846ED50206DFDE012AFF = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	{
		int32_t* L_0 = ___0_length;
		int32_t L_1;
		L_1 = Reader_ReadNext_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m008862EE68B89223188A3A1C95A528DC5CD56774(__this, NULL);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_0, (int32_t)L_1);
		int32_t* L_2 = ___0_length;
		int32_t L_3 = il2cpp_codegen_ldind<int32_t, int32_t>(L_2);
		if (!L_3)
		{
			goto IL_001c;
		}
	}
	{
		int32_t* L_4 = ___0_length;
		int32_t L_5 = il2cpp_codegen_ldind<int32_t, int32_t>(L_4);
		uint32_t L_6 = SizeOf_T_t6E0E95C00360B98AD1C3846ED50206DFDE012AFF;
		void* L_7;
		L_7 = Reader_ReadNext_m7C9150A60E622C8581A3E80C8DD1AD71D043BF6A(__this, ((int32_t)il2cpp_codegen_multiply(L_5, (int32_t)L_6)), NULL);
		return L_7;
	}

IL_001c:
	{
		uintptr_t L_8 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (void*)(L_8);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Peek_TisIl2CppFullySharedGenericStruct_m9282B5560EB03FCC4C6F0F8AC634AE5A13B555D6_fshared (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t78876001400B6CD8FBC8DB6052800D0B07D5996E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int32_t V_0 = 0;
	uint8_t* V_1 = NULL;
	{
		uint32_t L_0 = SizeOf_T_t78876001400B6CD8FBC8DB6052800D0B07D5996E;
		V_0 = (int32_t)L_0;
		uint8_t* L_1 = __this->___m_CurrentPtr;
		V_1 = L_1;
		uint8_t* L_2 = V_1;
		int32_t L_3 = V_0;
		uint8_t* L_4 = __this->___m_CurrentBlockEnd;
		if ((!(((uintptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_2, L_3))) > ((uintptr_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* L_5 = __this->___m_CurrentBlock;
		UnsafeStreamBlock_t0DE96C782B2CBF67BE34978C364781E170B3A86C* L_6 = L_5->___Next;
		U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116* L_7 = (U3CDataU3Ee__FixedBuffer_t60155FEDF2B8430C4B466CB3CDD85327C03F1116*)(&L_6->___Data);
		uint8_t* L_8 = (uint8_t*)(&L_7->___FixedElementField);
		uintptr_t L_9 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_8,NULL));
		V_1 = (uint8_t*)L_9;
	}

IL_0030:
	{
		uint8_t* L_10 = V_1;
		Il2CppFullySharedGenericStruct* L_11;
		L_11 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_10, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_11;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Reader_Read_TisIl2CppFullySharedGenericStruct_mBBF673BF9BED0383144F187B6541B532F2B6A633_fshared (Reader_tE85B398678D2471A73C94A5DCAECD9AA2CAA4458* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_tB637578F0BD33C09FC40FC64F02C0A2D558139E3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int32_t V_0 = 0;
	{
		uint32_t L_0 = SizeOf_T_tB637578F0BD33C09FC40FC64F02C0A2D558139E3;
		V_0 = (int32_t)L_0;
		int32_t L_1 = V_0;
		uint8_t* L_2;
		L_2 = Reader_ReadUnsafePtr_m6CDEF727114990BC4C2DF321BE752F229104A888(__this, L_1, NULL);
		Il2CppFullySharedGenericStruct* L_3;
		L_3 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Writer_Allocate_TisIl2CppFullySharedGenericStruct_m4503233E7BE788F93FD1C91B7BE65AC121483DB7_fshared (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t116435D0785AA26BF8114803668B5077681E8C02 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	int32_t V_0 = 0;
	{
		uint32_t L_0 = SizeOf_T_t116435D0785AA26BF8114803668B5077681E8C02;
		V_0 = (int32_t)L_0;
		int32_t L_1 = V_0;
		uint8_t* L_2;
		L_2 = Writer_Allocate_m85F9D4FF8746C0A59DC23A9003398A6D9D42526D(__this, L_1, NULL);
		Il2CppFullySharedGenericStruct* L_3;
		L_3 = ((  Il2CppFullySharedGenericStruct* (*) (void*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))((void*)L_2, il2cpp_rgctx_method(method->rgctx_data, 1));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Writer_Write_TisIl2CppFullySharedGenericStruct_m3255C6DE3AD541593524A784715AE50082831917_fshared (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7);
	{
		Il2CppFullySharedGenericStruct* L_0;
		L_0 = ((  Il2CppFullySharedGenericStruct* (*) (Writer_t16BC5D7104F5959779BA8C578EC794067872FB0F*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(__this, il2cpp_rgctx_method(method->rgctx_data, 0));
		il2cpp_codegen_memcpy(L_1, ___0_value, SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7);
		il2cpp_codegen_memcpy((Il2CppFullySharedGenericStruct*)L_0, L_1, SizeOf_T_t4D7283DBD6CD71348652C5C25061A381CAB760A7);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(method->rgctx_data, 1), (void**)(Il2CppFullySharedGenericStruct*)L_0, (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StreamingState_Update_TisIl2CppFullySharedGenericStruct_m301FBB6A80BBA46BB5AC2B0DF206CAB72593DE1D_fshared (StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020* __this, Il2CppFullySharedGenericStruct* ___0_input, const RuntimeMethod* method) 
{
	if (!il2cpp_rgctx_is_initialized(method))
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var);
		il2cpp_rgctx_method_init(method);
	}
	const uint32_t SizeOf_T_t0FAE9973A0C60B49E231E1F7F01F959BFBB59552 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 1));
	CHECKED_LOCAL(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_StaticInit);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_input;
		void* L_1;
		L_1 = ((  void* (*) (Il2CppFullySharedGenericStruct*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_0, il2cpp_rgctx_method(method->rgctx_data, 0));
		uint32_t L_2 = SizeOf_T_t0FAE9973A0C60B49E231E1F7F01F959BFBB59552;
		CHECKED_LOCAL_INIT(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_StaticInit,(StreamingState_t407BC6BBA6752E76D2075153BF945841B2D06020_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		StreamingState_Update_mD0C172FBC9AB99BC72DF8CC3665ABB61658AB9E5(__this, L_1, (int32_t)L_2, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Allocate_TisIl2CppFullySharedGenericStruct_m040B30CAEA05884CC6EF77610B3FABB3B53AB4AD_fshared (int64_t ___0_count, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___1_label, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_2 = ___0_count;
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_3 = ___1_label;
		Il2CppFullySharedGenericStruct* L_4;
		L_4 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((Il2CppFullySharedGenericStruct*)L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Allocate_TisIl2CppFullySharedGenericStruct_m472C3AE183E3C768741B28481DD1F012013B13A6_fshared (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_2 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___1_allocator;
		Il2CppFullySharedGenericStruct* L_4;
		L_4 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))((Il2CppFullySharedGenericStruct*)L_0, L_1, L_2, L_3, il2cpp_rgctx_method(method->rgctx_data, 0));
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Allocate_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_mCDBD1381CA662F016D4B6003D9BA89FE592EB6D8 (int64_t ___0_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___1_allocator, const RuntimeMethod* method) 
{
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		int64_t L_2 = ___0_count;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___1_allocator;
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_4;
		L_4 = Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3((MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)L_0, L_1, L_2, L_3, NULL);
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Free_TisIl2CppFullySharedGenericStruct_mA04A0C63F38A5DB9CAC0294B7DC90B9D35EACC14_fshared (Il2CppFullySharedGenericStruct* ___0_pointer, int64_t ___1_count, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___2_label, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		Il2CppFullySharedGenericStruct* L_2 = ___0_pointer;
		int64_t L_3 = ___1_count;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_5 = ___2_label;
		Il2CppFullySharedGenericStruct* L_6;
		L_6 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Free_TisIl2CppFullySharedGenericStruct_m6AA7597FA98F8020ABEFACEA0A1D00A384716627_fshared (Il2CppFullySharedGenericStruct* ___0_pointer, int64_t ___1_count, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___2_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_pointer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		if ((!(((uintptr_t)L_0) == ((uintptr_t)L_1))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}

IL_0006:
	{
		Il2CppFullySharedGenericStruct* L_2 = ___0_pointer;
		int64_t L_3 = ___1_count;
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_5 = ___2_allocator;
		Il2CppFullySharedGenericStruct* L_6;
		L_6 = ((  Il2CppFullySharedGenericStruct* (*) (Il2CppFullySharedGenericStruct*, int64_t, int64_t, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 0)))(L_2, L_3, L_4, L_5, il2cpp_rgctx_method(method->rgctx_data, 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* Array_Resize_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m3411CCE45309DF743A524C406531532C4FC8CD72 (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* Array_Resize_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m87C047C9A0252B77CBF08B5DDEF1D493A14DD276 (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* Array_Resize_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mCA2193874571CACB1B8D75FBD095B8AD29C6403A (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m68DAEAFD02AE0CA6A976BF0B8B0CAE855D168F32 (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___3_label, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_3 = ___3_label;
		uint32_t L_4 = sizeof(uint8_t);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mA60C117B1C01C122EB2D509DD4EADE4FB44C2150((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (uint8_t*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m1767423622567D1059537F40EF99A5522126FBD0 (uint8_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(uint8_t);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (uint8_t*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t* Array_Resize_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mEE512F558B8B16B19497E4DF8445518F289534BE (int32_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(int32_t);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (int32_t*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t* Array_Resize_TisIntPtr_t_mE1CA5D0262B2B8D4C9453D51DF34A94A0CF3556F (intptr_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		intptr_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(intptr_t);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (intptr_t*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t* Array_Resize_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mD3BD6186C5C7D5B3952897C2602B7C5BEA1A7E81 (uint64_t* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		uint64_t* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(uint64_t);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (uint64_t*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* Array_Resize_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m61718F1D9CCF897E5BE50BB484C8D816C988DF6F (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* Array_Resize_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m1576AD06CC03F6E9D06FC13A0F280519B1666726 (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* Array_Resize_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_mF6857EF793C9156A611EAA1E63A02352EFE46784 (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* Array_Resize_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m1082D56F32F50ECA3CFFDB87DB3512F2CE7544F4 (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* Array_Resize_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m520F16927035702AB0DF9C30EE88686BDC346F21 (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Resize_TisIl2CppFullySharedGenericStruct_mDAEE7836D30B1E69218DA92D10DEFB59679D311A_fshared (Il2CppFullySharedGenericStruct* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 ___3_label, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t463F46A118A7AA284DE9A95CCBE473111EF5DF8B = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		MemoryLabel_t29CE7AB312D2ED888B444BBE5D452F7132EC9DB2 L_3 = ___3_label;
		uint32_t L_4 = SizeOf_T_t463F46A118A7AA284DE9A95CCBE473111EF5DF8B;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		void* L_7;
		L_7 = Array_Resize_mA60C117B1C01C122EB2D509DD4EADE4FB44C2150((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (Il2CppFullySharedGenericStruct*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppFullySharedGenericStruct* Array_Resize_TisIl2CppFullySharedGenericStruct_m07039200651D43DBB7FBC0CB244761DA34C164FD_fshared (Il2CppFullySharedGenericStruct* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	const uint32_t SizeOf_T_t4439E68F64AF98A1F1E70993ACB3E0626E7A7954 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(method->rgctx_data, 0));
	{
		Il2CppFullySharedGenericStruct* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = SizeOf_T_t4439E68F64AF98A1F1E70993ACB3E0626E7A7954;
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(method->rgctx_data, 1)))(il2cpp_rgctx_method(method->rgctx_data, 1));
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (Il2CppFullySharedGenericStruct*)(L_7);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* Array_Resize_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m66D39A0700C852DFD578157D9E4862A8230233F3 (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* ___0_oldPointer, int64_t ___1_oldCount, int64_t ___2_newCount, AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 ___3_allocator, const RuntimeMethod* method) 
{
	{
		MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84* L_0 = ___0_oldPointer;
		int64_t L_1 = ___1_oldCount;
		int64_t L_2 = ___2_newCount;
		AllocatorHandle_t3CA09720B1F89F91A8DDBA95E74C28A1EC3E3148 L_3 = ___3_allocator;
		uint32_t L_4 = sizeof(MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84);
		int64_t L_5 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_4,NULL));
		int32_t L_6;
		L_6 = UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_inline(NULL);
		void* L_7;
		L_7 = Array_Resize_mC7BE2965DE3FCF4014D43B606D94951480A65380((void*)L_0, L_1, L_2, L_3, L_5, L_6, NULL);
		return (MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84*)(L_7);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_tzcnt_m25573278D92DAE1280EBFACAAB6BB50CFF4172CD_inline (int32_t ___0_x, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_x;
		int32_t L_1;
		L_1 = math_tzcnt_m9318C63D3F5FC4DE0F7ACB372307134237D52DA9_inline(L_0, NULL);
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_min_m0D183243301588F5000801E35B451374CD10DFC1_inline (int32_t ___0_x, int32_t ___1_y, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_x;
		int32_t L_1 = ___1_y;
		if ((((int32_t)L_0) < ((int32_t)L_1)))
		{
			goto IL_0006;
		}
	}
	{
		int32_t L_2 = ___1_y;
		return L_2;
	}

IL_0006:
	{
		int32_t L_3 = ___0_x;
		return L_3;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Equality_m7D9CDCDE9DC2A0C2C614633F4921E90187FAB271_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = ___0_value1;
		intptr_t L_1 = ___1_value2;
		return (bool)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC MarshalledUnityObject_FromIntPtrUnsafe_m1C5AE0FB7CD1978A8387B0081DB909BAAC2324C3_inline (intptr_t ___0_gcHandle, const RuntimeMethod* method) 
{
	{
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_0;
		L_0 = UnsafeUtility_As_TisIntPtr_t_TisGCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC_mD94F597CB91662C823496DA9FA9A7CF908734A78_inline((&___0_gcHandle), NULL);
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_1 = (*(GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)L_0);
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) 
{
	{
		bool L_0;
		L_0 = GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline(__this, NULL);
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_1 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral4EBC86E0EACFCA522AEB82874860D0E248D782A5)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_RuntimeMethod_var)));
	}

IL_0013:
	{
		intptr_t L_2 = __this->___handle;
		bool L_3;
		L_3 = GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline(L_2, NULL);
		if (!L_3)
		{
			goto IL_002c;
		}
	}
	{
		intptr_t L_4 = __this->___handle;
		RuntimeObject* L_5;
		L_5 = GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline(L_4, NULL);
		return L_5;
	}

IL_002c:
	{
		intptr_t L_6 = __this->___handle;
		RuntimeObject* L_7;
		L_7 = GCHandle_GetTarget_mE0AF851834410E2AEA6285B2497751570236C794(L_6, NULL);
		return L_7;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5_mC4112DF120EBF605C8F77839E842177AF068D44E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t151A1BD8ECCDCBCF3185238615804E396C3B07A5);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisRangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268_m462940FF70DE74B43CFAFE2670B4A652829BDF3F_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(RangeInt_tDFBE4FD13857C11F21F7C3DA6B60D05341B67268);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4_m19CE06B2A77B620A1DE800E56AFEE3A5616E99E6_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t25880EEE885729199077AC19774C8BE13323D4B4);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisSingle_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_m2379B61902CFDAAAE7E5BE25FDA4BBBBF7E54273_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D_m22F628ADD6E12980B394B9237C61AB0C95E1EC1C_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3FE2545879EC19D84F399DE73EA83AAEDEA14C9D);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1_m78BC20EBEDF9DDD29C261AACF9F19965B5A49C92_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UEncroachingSegment_t3AE1B0B8E50020697D3FA3FFF0C86E406ABFA3C1);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37_m120CCD2A94A7B51A2631C5630A9E505F1DDB1CD7_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t054F2568D7C1097239A28CF25D80D8353E29BB37);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC_mD7804F40606876E9729617E9761E42F9D6056B26_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UEvent_t81CE84F34955D2A2DE962ADE28CDE659605FB2AC);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056_m24D80B10C7527E88ECD7E5C10731C7F1663E2C27_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t0280929E6B4134EE85E97F8BFC283CFB4C7BC056);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851_mDB23A7351A2DB7A69197EC17A28401C3A9B4DA98_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UHull_tBA3DC6A41F928298B0D924EDFE00150F307BA851);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9_mE690DD75A3C952CEDEB71F13B96E603904A60567_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t70E1FB13BE93757804A731D115FA219AE664F9B9);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_mB21F3357E1DB01146285E803CB68EE945ADA7149_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint16_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3_m936B8B899C03B9C80AA39CD231B892274340136D_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF3C6E1F1F032602FD9777BBE4466632711C12DC3);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_m483305F08D432A8FC41A6E11289383D1E2C3E8AE_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint32_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E_m2D3BC72BBF45866A72C7ADF31F40AEFC56BBD498_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mAA2B8333B77A7410376516B6E13FCC02AEE6A5AC_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint64_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5_m6333413607F97523DA83C70DA244CCE8E0B50D8E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t9E9A73E6B25DCBB1356ABAF5D5F64CEB912639E5);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D_m87DD2D062338C42E1537725895679ED703A237D3_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UStar_tF8CA0D7A7A3197E68176CA173B07251554C7465D);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669_m50F19243DCF7F556C625C9C7048E8BA7FDA09C6E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE0DC7EEADD8DE994397C46E4B7F6E4EC9FE4F669);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F_m0E3277DA666E697D096F659128CBE7238C655CA3_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UTriangle_t6D4513C8A4054BEEC30F937F14BBE005BC4A141F);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981_m0E4242520596E02B9AAE81652FFB8EE3542259AA_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m9B75EBBD9DF8560D30B3C2E1E2C38BF7D85CAF9D_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9_m98AA8DA7813F89F461C97A6373493AB6D70B858B_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m3C94249F648A50E2D27EDAD82BD9BFD652086097_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA_m05924C78C0CB3BE4A7F3029ACEA5F044E6E559A0_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3_mE4962E35BBA3FE3704E13AB652950BF09D05115F_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E_mFD07D65557C1FB04588D27C6A200F7746663E0B0_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_mA5DC0B2032262984D97EFF4CF894E776A34A181F_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B_m019BC64A12A26B709A3CD09D40E912FCD97288A0_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t6D1FF4DA66C5CD05448BC8E466557A009CD56C1B);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF_m5A6BC515442EB0B285497391D72FB18A31516CB2_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VBones_t97D4AD59DF3FC7F8528C16AE839B525F19B2D7AF);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A_m9D18F31B0150761121CE90F7608804E66D7C3A8E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5787732685E90796D7F6E3DC189E956C20950F1A);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mC4E70A23733EF555E25391199DFEB2A1FD127B7B_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VPos_t60F9F86213E6426227874FBBA41EF5551B920A72);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8_m9FEED4A848E422F5FCF3D03117ED631B4F585297_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t53FADBF8042978698F567574543B2E8DC005C7F8);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mB0E98D09340662B90EC173E1CA8A23E15139D4F2_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED_m6348B019EEA1591225152EC62349A8080572DEBE_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5D5E9E80CB62E864F8B8C657186E23B2646B9CED);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m2BA8D7C6E9CCBF7FF7426C0D61535B7C666FA642_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7_m8D3DF77211E69FDD188488FFCCC64392102FB872_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t9D35938BEFD8DB4D61969D40C546B4C54CD104C7);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mE4848DFE6C4FDC789BE02AFD21E8FE4D0B4E743C_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233_m10A168D59EE90DAFFEEF6F7416AA57E0596C2E70_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tFC175CA99A87CC173A3622A4DCF5C4F7933AA233);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mD41EF628ACDD0AFCE611B0FF1420F33AEC2B85AF_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF_m070F102DB9A8BCBD8CFC09CC7D9D3D6D3BE8EBA1_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3C56757B8B5D40EE02B63692D1CD6C8481D89DCF);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_mE4561796E61AEFB55AA7AFBE1C9FD48F7AB887D3_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6_mE75EA22DD22C5D163B9332C164A64653D05277D8_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3A81268A2315AB9ECAA1C77BDADAA486EAF7F5F6);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_mFEF7DABDBCC29D7CB4F903941FE66B61C0717CEF_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28_m9C3C44466009BED76EBD7B1BDE919205705F2C97_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t92506EAFDBF20161594E3FA14BDB70327C877C28);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mA32DB809A91F2DC32E2319D41D9A5F00EB29A60E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150_mEFAE743E1DB26C808D99EBC8ADAAA960EF14E898_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t986CC8A8C9BF39E54F9340567EBCA386C3F14150);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mE9990F4132E7E548E1327B5AFDA595393DC8AB70_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF_m14EA35185C8F445B80BE36972B0E55FFE828CE69_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tA87CE99031DF63C9AC8573FC83F04CA430BDD1AF);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mE420CEFAC83BFD18111C33ED0C1DF46FE76A64B9_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1_m2786A7365CB5CE12DB402F330EC19DD42E7F56D9_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t628E567BC7D5CA27D1091359E103212C5F59EBB1);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mB068DEDD3DC301EDA8B26358237AAC852800E5AD_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(VTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A_m034AE7678181AD29323E752CCA82EDCFE2E3CAA0_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tA7BAD341B87833F98272549F84315FE63B02CC5A);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_m297C8507511B4B7C587AF49B53D880021418C5CC_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773_mAA11ED5EDA264AB3B48690198F615B38D00FE294_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t26C526A4040EF3870B74BFD09D3768388C3BD773);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisVector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_m567C299D0E9EA26E8A3ADC4158D175D9F101BC1E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4_m29E0C0863AA5A2364C1F00FAEAD6CCEC94DA70FF_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tF31F09BEF44353E98923E6193CEADA52B8ED43D4);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisdouble2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83_m96D588AB3F164F56BB1DE77BC435342E9F1BD745_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(double2_t2124FB15A5BDCC0BD48B80116D4B24DC9DCA9D83);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460_mDA796E09ECCAD2EAEF6F0A2C1773617A9FBA6E6E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t0C97FDE41871CAD34CA643C258038DE7C30AA460);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_mE64EA17FB7FE71E52F389B33C2AE7F4894B63B16_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE_m275DDCFF618B41FD8D55D227B523EE4375524AE0_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t087E7B0F666EF0EF8294A6D4D2DD66B992A818BE);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat3_t7600B73F092B37F484B12910A5269F30C778D31E_m0F16771B993937271160B6B8203D4AF6E89B3E20_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float3_t7600B73F092B37F484B12910A5269F30C778D31E);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7_m3B08AAF0A9461124EEB149509CB15BD615CAFA2D_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5A52B0BFA9E5F093980EA7DB7A00D19E58C018D7);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisfloat4_t545A994996126766890C1F28B43EA823F2410190_mC0D8F1150C7D0AB1BF48EAE3FF8A9E7EADCFC89E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(float4_t545A994996126766890C1F28B43EA823F2410190);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C_mAA91F87ABC1C69B33E87DD76C50A480D237F8B9A_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t6ADF810505F028EA6EBCA5B664B68A8372696F9C);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint2_tB123E869131C6102341F8F9AA01726E0E7C2768D_mB216CE24697733053C38D23575F516F72C0E7F06_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int2_tB123E869131C6102341F8F9AA01726E0E7C2768D);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396_mB59C152F5426670D374DC720745E2F06FAADE0CA_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t5DC854A29E0F5E52BA538EDE0BFDED0CC3F2B396);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint3_t18873F121F1EF24ECE875EAB01170B69E1B498C5_m8C0D64D09B9A2F8238A614656203048B06759A6B_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int3_t18873F121F1EF24ECE875EAB01170B69E1B498C5);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3_m35ABFDD366C53EC12FEB57C526087B620B8844C2_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3815CFB9721539E18DAC181E8DB449C4D3C731E3);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisint4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90_mA8C62CC9E230AC8C9856724F0AD3DB92EBABE192_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int4_t6DC3FEACC0DD1EAE4D5B897188E8D669BC4DAB90);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C_mB6F9FC86B4C97B91F2ED87738287527A39EC3E12_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t055CB1840CB7012C011A59A9E40EDF311DBD505C);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_Tisquaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA_mB36574769AB412B4AA1DD70033B37BEED9F5BD92_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(quaternion_t9C8C2916B7359C174B215BBB41F290ABCBEA8AEA);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9_m0307FE22A5AF62C62045020268823FBD9652FA71_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m64096CFB58B4B0A976A42BC41901B89806B85F69_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(MemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1ADEAC45E92C10A0C3D9686063C582FDD76F5937_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___1_output;
		void* L_1 = ___0_ptr;
		int32_t L_2 = (*(int32_t*)L_1);
		*(int32_t*)L_0 = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_InternalCopyStructureToPtr_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mBEE053A98420A095CBB4B7034433ECB95ACFB127_inline (int32_t* ___0_input, void* ___1_ptr, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___1_ptr;
		int32_t* L_1 = ___0_input;
		int32_t L_2 = (*(int32_t*)L_1);
		*(int32_t*)L_0 = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 Vector_1_Equals_m6F913845CB1E8A1A753B3C187A8EB840C36F5ADF_inline (Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___0_left, Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 ___1_right, const RuntimeMethod* method) 
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
	uint16_t* G_B21_0 = NULL;
	uint16_t* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	uint16_t* G_B22_1 = NULL;
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
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_2 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_1,NULL));
		if ((uintptr_t)L_2 * (uintptr_t)2 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_3 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_2, 2));
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
		V_4 = (uint16_t*)L_4;
		V_5 = 0;
		goto IL_0122;
	}

IL_00f2:
	{
		uint16_t* L_5 = V_4;
		int32_t L_6 = V_5;
		intptr_t L_7 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_6,NULL));
		int32_t L_8 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		uint16_t L_9;
		L_9 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27((&___0_left), L_8, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		int32_t L_10 = V_5;
		uint16_t L_11;
		L_11 = Vector_1_get_Item_m248FFF521980A3A43D237B8C5CA2ABD5C62D4D27((&___1_right), L_10, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
		bool L_12;
		L_12 = Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline(L_9, L_11, NULL);
		if (L_12)
		{
			G_B21_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 2))));
			goto IL_0116;
		}
		G_B20_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_5, ((intptr_t)il2cpp_codegen_multiply(L_7, 2))));
	}
	{
		G_B22_0 = 0;
		G_B22_1 = G_B20_0;
		goto IL_011b;
	}

IL_0116:
	{
		uint16_t L_13;
		L_13 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B22_0 = ((int32_t)(L_13));
		G_B22_1 = G_B21_0;
	}

IL_011b:
	{
		il2cpp_codegen_stind<int16_t>((int16_t*)G_B22_1, (int16_t)G_B22_0);
		int32_t L_14 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0122:
	{
		int32_t L_15 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_16;
		L_16 = Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_00f2;
		}
	}
	{
		uint16_t* L_17 = V_4;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_18;
		memset((&L_18), 0, sizeof(L_18));
		Vector_1__ctor_m46ADEA122EFBA7AEF487716891A8ADD284FD12E3((&L_18), (void*)L_17, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_18;
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
	}
	{
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_19 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_20 = L_19.___register;
		uint16_t L_21 = L_20.___uint16_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_22 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_23 = L_22.___register;
		uint16_t L_24 = L_23.___uint16_0;
		if ((((int32_t)L_21) == ((int32_t)L_24)))
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
		uint16_t L_25;
		L_25 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B186_0 = ((int32_t)(L_25));
		G_B186_1 = G_B185_0;
	}

IL_09bb:
	{
		G_B186_1->___uint16_0 = (uint16_t)G_B186_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_26 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_27 = L_26.___register;
		uint16_t L_28 = L_27.___uint16_1;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_29 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_30 = L_29.___register;
		uint16_t L_31 = L_30.___uint16_1;
		if ((((int32_t)L_28) == ((int32_t)L_31)))
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
		uint16_t L_32;
		L_32 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B189_0 = ((int32_t)(L_32));
		G_B189_1 = G_B188_0;
	}

IL_09e2:
	{
		G_B189_1->___uint16_1 = (uint16_t)G_B189_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_33 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_34 = L_33.___register;
		uint16_t L_35 = L_34.___uint16_2;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_36 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_37 = L_36.___register;
		uint16_t L_38 = L_37.___uint16_2;
		if ((((int32_t)L_35) == ((int32_t)L_38)))
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
		uint16_t L_39;
		L_39 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B192_0 = ((int32_t)(L_39));
		G_B192_1 = G_B191_0;
	}

IL_0a09:
	{
		G_B192_1->___uint16_2 = (uint16_t)G_B192_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_40 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_41 = L_40.___register;
		uint16_t L_42 = L_41.___uint16_3;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_43 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_44 = L_43.___register;
		uint16_t L_45 = L_44.___uint16_3;
		if ((((int32_t)L_42) == ((int32_t)L_45)))
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
		uint16_t L_46;
		L_46 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B195_0 = ((int32_t)(L_46));
		G_B195_1 = G_B194_0;
	}

IL_0a30:
	{
		G_B195_1->___uint16_3 = (uint16_t)G_B195_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_47 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_48 = L_47.___register;
		uint16_t L_49 = L_48.___uint16_4;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_50 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_51 = L_50.___register;
		uint16_t L_52 = L_51.___uint16_4;
		if ((((int32_t)L_49) == ((int32_t)L_52)))
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
		uint16_t L_53;
		L_53 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B198_0 = ((int32_t)(L_53));
		G_B198_1 = G_B197_0;
	}

IL_0a57:
	{
		G_B198_1->___uint16_4 = (uint16_t)G_B198_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_54 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_55 = L_54.___register;
		uint16_t L_56 = L_55.___uint16_5;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_57 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_58 = L_57.___register;
		uint16_t L_59 = L_58.___uint16_5;
		if ((((int32_t)L_56) == ((int32_t)L_59)))
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
		uint16_t L_60;
		L_60 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B201_0 = ((int32_t)(L_60));
		G_B201_1 = G_B200_0;
	}

IL_0a7e:
	{
		G_B201_1->___uint16_5 = (uint16_t)G_B201_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_61 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_62 = L_61.___register;
		uint16_t L_63 = L_62.___uint16_6;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_64 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_65 = L_64.___register;
		uint16_t L_66 = L_65.___uint16_6;
		if ((((int32_t)L_63) == ((int32_t)L_66)))
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
		uint16_t L_67;
		L_67 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B204_0 = ((int32_t)(L_67));
		G_B204_1 = G_B203_0;
	}

IL_0aa5:
	{
		G_B204_1->___uint16_6 = (uint16_t)G_B204_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_68 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_69 = L_68.___register;
		uint16_t L_70 = L_69.___uint16_7;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_71 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_72 = L_71.___register;
		uint16_t L_73 = L_72.___uint16_7;
		if ((((int32_t)L_70) == ((int32_t)L_73)))
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
		uint16_t L_74;
		L_74 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B207_0 = ((int32_t)(L_74));
		G_B207_1 = G_B206_0;
	}

IL_0acc:
	{
		G_B207_1->___uint16_7 = (uint16_t)G_B207_0;
		Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489 L_75;
		memset((&L_75), 0, sizeof(L_75));
		Vector_1__ctor_m48CD7847B9597F3193C9C0BA97ED64E276F4340A((&L_75), (&V_20), NULL);
		return L_75;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t MarshalledUnityObject_MarshalNotNull_TisIl2CppSharedGenericObject_mCE897EC9A79983B4B1E6E2C8342452256309044A_gshared_inline (Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = ___0_obj;
		intptr_t L_1 = ((Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)L_0)->___m_CachedPtr;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m274F833CD001C63E56A22D8F42C76CE8C6CC39DF_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mFBA66C06ECEB0A2BC1AAE634B6E6BB436F957084_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int32_t L_2;
		L_2 = UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline(L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtility_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mD9A1240B1BCA4029B93CBDCE0196491FEC192E38_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		int32_t* L_1 = ___1_output;
		UnsafeUtilityInternal_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mECC3B0123B8C95AF837F45785072BE5466D989C9_inline(L_0, L_1, NULL);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m9D33FAB445EBAAEAB91BED2D158B3290B610D47E_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m5DB7C8854924D1E1D01E14FB83112EBF8905533C_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_m796E3C1D5F3A55A9EFFD1AA98C09AB788198C7A1_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mD30E57AEFF1E2218A4DCE4EA77B9AE170B7A6BB3_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m219DC3BB1EF8E9E18A66470555A9974E2C7D9EC6_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mB76E5D04768F570DF3F45ABEB65D6BAFDFFF638A_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mB152D3C658FB48DEDB6E662EEB0C91018E7F2857_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mC44B74F48735FA62BAE3FBA763123E932B9EF822_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisIntPtr_t_mB17C6C168D8CA088879EDD0D5B9923F70F5269B8_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisIntPtr_t_m7FF5CB3788B437CA624174389D25EE9BCB2B212E_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m8127223B00E08567EC09EF1D992F89C74F248AB0_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m29B7D9DA9527706BBA1F73ECEA934CCD0B2D99E3_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m56B5B812224539B0C633BABE891ADDE1973580F6_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mA359E62F880352C70AB4DC921D67E178E6DACB15_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mC1EBD5161294EF95B8AC378DDF616869D287DC36_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mD2E2A270320B9190D3ECE518E4055D43CFF0C7EC_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m3DF404928C7038CCD5C05BBBA41C4B2FD35A4253_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m73AE74F3CDDD5919B822BA2521D23FF3D3C930E6_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_mD84C2AFFB4ED036B913CEAD2FBF8A60E9C3A017D_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m3CE37249D5247521F44E2D498FDBC3714462A3E3_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m5892DF1B875736B0E3612716E560A4E4AD5F6591_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m78688762B313B8CD8725C345D0D2446E999924E4_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtility_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m6AD8B4EF31CDD94CA734378B1443806DAFE68A05_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m844535A4D039E811CA8C8A80A30A2499268FF979_inline(NULL);
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t math_tzcnt_m9318C63D3F5FC4DE0F7ACB372307134237D52DA9_inline (uint32_t ___0_x, const RuntimeMethod* method) 
{
	LongDoubleUnion_t17011746129284B81F310F56E20D549A6F6710D0 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		uint32_t L_0 = ___0_x;
		if (L_0)
		{
			goto IL_0006;
		}
	}
	{
		return ((int32_t)32);
	}

IL_0006:
	{
		uint32_t L_1 = ___0_x;
		uint32_t L_2 = ___0_x;
		uint64_t L_3 = (il2cpp_codegen_conv<uint64_t,uint32_t,int32_t,false,false>(L_2,NULL));
		uint32_t L_4 = (il2cpp_codegen_conv<uint32_t,int64_t,int64_t,false,false>(((-((int64_t)L_3))),NULL));
		___0_x = ((int32_t)((int32_t)L_1&(int32_t)L_4));
		(&V_0)->___doubleValue = (0.0);
		uint32_t L_5 = ___0_x;
		uint64_t L_6 = (il2cpp_codegen_conv<uint64_t,uint32_t,int32_t,false,false>(L_5,NULL));
		(&V_0)->___longValue = ((int64_t)il2cpp_codegen_add(((int64_t)4841369599423283200LL), (int64_t)L_6));
		double* L_7 = (double*)(&(&V_0)->___doubleValue);
		double* L_8 = L_7;
		double L_9 = il2cpp_codegen_ldind<double, double>(L_8);
		il2cpp_codegen_stind<double>((double*)L_8, (double)((double)il2cpp_codegen_subtract(L_9, (4503599627370496.0))));
		LongDoubleUnion_t17011746129284B81F310F56E20D549A6F6710D0 L_10 = V_0;
		int64_t L_11 = L_10.___longValue;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)(L_11>>((int32_t)52))),NULL));
		return ((int32_t)il2cpp_codegen_subtract(L_12, ((int32_t)1023)));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = __this->___handle;
		bool L_1;
		L_1 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline(L_0, 0, NULL);
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline (intptr_t ___0_handle, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = ___0_handle;
		intptr_t L_1 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(1,NULL));
		intptr_t L_2 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((intptr_t)((intptr_t)(L_0&L_1))) == ((intptr_t)L_2))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline (intptr_t ___0_handle, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = ___0_handle;
		void* L_1;
		L_1 = IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF(L_0, NULL);
		RuntimeObject** L_2;
		L_2 = il2cpp_unsafe_as_ref<RuntimeObject*>((intptr_t*)L_1);
		RuntimeObject* L_3 = il2cpp_codegen_ldind<RuntimeObject*, RuntimeObject*>(L_2);
		return L_3;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* UnsafeUtility_As_TisIntPtr_t_TisGCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC_mD94F597CB91662C823496DA9FA9A7CF908734A78_inline (intptr_t* ___0_from, const RuntimeMethod* method) 
{
	{
		intptr_t* L_0 = ___0_from;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_1;
		L_1 = UnsafeUtilityInternal_As_TisIntPtr_t_TisGCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC_mD43127D5F7AA6EB4B52E5C30BA53F29843E9E9A2_inline(L_0, NULL);
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m6DF09E4443FC90521D33C892BE69D32B04D85A15_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_tACF5C606E327928B31CCD8E09C9224DCA7065489_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_m4E13E30219B0D2AADB58AD6E5CB2B54B9FCBFAAE_inline (uint16_t ___0_left, uint16_t ___1_right, const RuntimeMethod* method) 
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
	}
	{
		uint16_t L_0 = ___0_left;
		uint16_t L_1 = ___1_right;
		return (bool)((((int32_t)L_0) == ((int32_t)L_1))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mB5611745B3ED473868EF6B61479E2860BBB2223C_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_ReadArrayElement_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m0B7B877C8F00DCC1C95D7124B3B0D83C6D492345_inline (void* ___0_source, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_source;
		int32_t L_1 = ___1_index;
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(L_1,NULL));
		uint32_t L_3 = sizeof(int32_t);
		int64_t L_4 = (il2cpp_codegen_conv<int64_t,uint32_t,int32_t,false,false>(L_3,NULL));
		intptr_t L_5 = (il2cpp_codegen_conv<intptr_t,int64_t,int64_t,false,false>(((int64_t)il2cpp_codegen_multiply(L_2, L_4)),NULL));
		int32_t L_6 = (*(int32_t*)((void*)il2cpp_codegen_add((intptr_t)L_0, L_5)));
		return L_6;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnsafeUtilityInternal_CopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mECC3B0123B8C95AF837F45785072BE5466D989C9_inline (void* ___0_ptr, int32_t* ___1_output, const RuntimeMethod* method) 
{
	{
		void* L_0 = ___0_ptr;
		int32_t* L_1 = ___1_output;
		UnsafeUtilityInternal_InternalCopyPtrToStructure_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_m1ADEAC45E92C10A0C3D9686063C582FDD76F5937_inline(L_0, L_1, NULL);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m5DB7C8854924D1E1D01E14FB83112EBF8905533C_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50_m7E4E66C593913FCDFC8C03C06EFC4FFDC9A96BCF_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m0E37BE54FFDD9D93D5ADCA4464466720A0534F51_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mD30E57AEFF1E2218A4DCE4EA77B9AE170B7A6BB3_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163_m4D97EFDBFE98987E636ECEAD022BD99CAB158A50_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mB7E3DB3D712EE116DD131EEFE9548C1E0FA09AF9_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_mB76E5D04768F570DF3F45ABEB65D6BAFDFFF638A_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693_m28A0205203C49D5369496BB8258836A6E90B4275_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m6C73B80F6290ED267404794EB2AC27F5EEDB4EF3_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_mC44B74F48735FA62BAE3FBA763123E932B9EF822_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D_m8CB43E8118CC0E65E6E8130381DEB11701F21848_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m485E79FA6794AD30B29C6414A85A867DF156E5E1_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisIntPtr_t_m7FF5CB3788B437CA624174389D25EE9BCB2B212E_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752_m6197C4317CE4E01732509D53E08172FEA65ED04E_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisIntPtr_t_mF9218FE174B91F132731D032A744AFC048AFB932_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_m29B7D9DA9527706BBA1F73ECEA934CCD0B2D99E3_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE21040F72E90527C319FF9B07B398E23DF95BE2E_m2D3BC72BBF45866A72C7ADF31F40AEFC56BBD498_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_mAA2B8333B77A7410376516B6E13FCC02AEE6A5AC_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_mA359E62F880352C70AB4DC921D67E178E6DACB15_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tDBD984B5788DF4AA3E90F8C09B5859ED6CB5D981_m0E4242520596E02B9AAE81652FFB8EE3542259AA_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeBitArray_t74DFECCCA980372B6F29B9AA508ACC77A3D6B8D4_m9B75EBBD9DF8560D30B3C2E1E2C38BF7D85CAF9D_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_mD2E2A270320B9190D3ECE518E4055D43CFF0C7EC_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tB6C5A6C6C3F87E6E89F1D273846EEC6B31DFCDA9_m98AA8DA7813F89F461C97A6373493AB6D70B858B_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeParallelHashMapData_t43CAB3170FBB624A9CCB6F30C0EC1BB820D57926_m3C94249F648A50E2D27EDAD82BD9BFD652086097_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m73AE74F3CDDD5919B822BA2521D23FF3D3C930E6_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t71DBCA88B2EAABDA2DD3387E09C204E5E9B12EEA_m05924C78C0CB3BE4A7F3029ACEA5F044E6E559A0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueueBlockHeader_t93BDD5BE3C4A0486BE2A07B68862CFF1F5870D9C_m4443406CB5E8C38BA71CE11444CF35BD26797053_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m3CE37249D5247521F44E2D498FDBC3714462A3E3_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tE427A888F6FDAAB27509B03069802920EC4AA0A3_mE4962E35BBA3FE3704E13AB652950BF09D05115F_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeQueueData_t43073ABB3262F6905C43F9180FCBB71E301597C2_m9D71081BBF4C1B8CCA23832463B32C5362F17249_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_m78688762B313B8CD8725C345D0D2446E999924E4_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t89E0918ECFFC8A376F89EAE40DA2D8C58E85432E_mFD07D65557C1FB04588D27C6A200F7746663E0B0_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisUnsafeText_t93F5D82C1FF7AB12B0E621B9D0EC9855D005FF67_mA5DC0B2032262984D97EFF4CF894E776A34A181F_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_AlignOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m844535A4D039E811CA8C8A80A30A2499268FF979_inline (const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t3AC3A908E2A7B1D4167756986BD005C60ACF4BC9_m0307FE22A5AF62C62045020268823FBD9652FA71_inline(NULL);
		int32_t L_1;
		L_1 = UnsafeUtilityInternal_SizeOf_TisMemoryBlock_t83C4AD217E04686899AC67FBD8D14A7C9AAC6E84_m64096CFB58B4B0A976A42BC41901B89806B85F69_inline(NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_0, L_1));
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = ___0_value1;
		intptr_t L_1 = ___1_value2;
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppFullySharedGenericAny* UnsafeUtilityInternal_As_TisIl2CppFullySharedGenericAny_TisIl2CppFullySharedGenericAny_mE1CA751887466B801BE69083C2B0EA3EDE41FF9B_fshared_inline (Il2CppFullySharedGenericAny* ___0_from, const RuntimeMethod* method) 
{
	{
		Il2CppFullySharedGenericAny* L_0 = ___0_from;
		return (Il2CppFullySharedGenericAny*)(L_0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE_mB243DC326B2D814D1A62FDABCC2F2AA541A8C895_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t676424B8757032427D7761BC732079DC7512D8AE);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisInt32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_mA24CDBA02971DC06DEDE40B17E72F8C262B6B131_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(int32_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50_m7E4E66C593913FCDFC8C03C06EFC4FFDC9A96BCF_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t245EB4127E14738DE7A1928AA9BD796398AB3E50);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisHashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B_m0E37BE54FFDD9D93D5ADCA4464466720A0534F51_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(HashMapHelper_1_t51F726D16732CD16EFBBB3DE324B481A05388D2B);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163_m4D97EFDBFE98987E636ECEAD022BD99CAB158A50_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t7423A7512EC617A3595A4C8B8D8B41727DCB2163);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258_mB7E3DB3D712EE116DD131EEFE9548C1E0FA09AF9_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeQueue_1_t0323897433D8F18174111DB978F6D9EB951CB258);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693_m28A0205203C49D5369496BB8258836A6E90B4275_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tC0471DA3EB3B5C4A559BBA96E11DC778D51C2693);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisUnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6_m6C73B80F6290ED267404794EB2AC27F5EEDB4EF3_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(UnsafeRingQueue_1_tAF3191C06795E5D904223D7CA3372A4D56B5B5B6);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D_m8CB43E8118CC0E65E6E8130381DEB11701F21848_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_tAF795AF837E3C37401B92C7483D74A4E5145DB4D);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m485E79FA6794AD30B29C6414A85A867DF156E5E1_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(uint8_t);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisAlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752_m6197C4317CE4E01732509D53E08172FEA65ED04E_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(AlignOfHelper_1_t1C2506D8F2F53BF0A585917F05CD8BC880EBB752);
		return (int32_t)L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t UnsafeUtilityInternal_SizeOf_TisIntPtr_t_mF9218FE174B91F132731D032A744AFC048AFB932_inline (const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = sizeof(intptr_t);
		return (int32_t)L_0;
	}
}
