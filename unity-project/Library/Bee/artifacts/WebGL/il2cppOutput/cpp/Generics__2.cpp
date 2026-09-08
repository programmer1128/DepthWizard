#include "pch-cpp.hpp"





template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1Invoker;
template <typename T1>
struct InterfaceActionInvoker1Invoker<T1*>
{
	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1* p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		void* params[1] = { p1 };
		invokeData.method->invoker_method(il2cpp_codegen_get_method_pointer(invokeData.method), invokeData.method, obj, params, params[0]);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*,T1,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,invokeData.method);
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

struct ConcurrentDictionary_2_t6DF554984593E2F9932FAFBF9E1AFD30D1ED0812;
struct ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858;
struct ConditionalWeakTable_2_tDA4DD9BAFAF3114A73F0B4D6AA3049208A3B288B;
struct DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A;
struct Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B;
struct Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A;
struct Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9;
struct Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7;
struct Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B;
struct Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069;
struct Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290;
struct Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588;
struct Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E;
struct EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F;
struct EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB;
struct EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399;
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC;
struct EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35;
struct EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184;
struct EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B;
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081;
struct EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9;
struct IDictionary_2_t2FA61AE137EED621840AB6E61A1C75D249C05100;
struct IDictionary_2_tE849F992474EEBB668D9A9A590CF675D9449C7BE;
struct IDictionary_2_t81C94C2596A809C22FBCE957D38A8B8E80247769;
struct IDictionary_2_tBAB4B4F3D1E9859C43BD27825725B52EFAD07D0C;
struct IDictionary_2_t5316E1B118FCB8FCF8C09297C5DB7AE9CB7533C7;
struct IDictionary_2_t3FA7BF8C08F13A5D15D4CBD0FE3AFA52B7AB7F1C;
struct IDictionary_2_t7D6BA743AEB26515AEF1567BC9A697EB1FB4D34E;
struct IEnumerator_1_t1FC23C4652B02A4E4AE212074D88FC38BE085681;
struct IEnumerator_1_tC0408FCD0D690D95C68E5294CA36C400FFB79781;
struct IEnumerator_1_tD37712EF66C2DACD5DBFA05DB7CE341EF2FBA1EE;
struct IEnumerator_1_t1DE90964025F3E49484DDA43335AF57CECEAFBFF;
struct IEnumerator_1_tB91B38EF7DBADE91EDE695D68977568987137D29;
struct IEnumerator_1_t54D12606D2B2D3845FE9C78F42EF456819DED9F3;
struct IEnumerator_1_tBA3480833B49E482B7738989CE44B50B47418072;
struct IEnumerator_1_tFABD3B897F1296469E9A2DB9BCF6C89439049208;
struct IEqualityComparer_1_t6EEEF539D2CA2C93760158FE927CE8A0B1E6AD2D;
struct IEqualityComparer_1_t49EBDA1133E48B1F11BA86D393C4766FB32F2501;
struct IEqualityComparer_1_t0706C8CEAD5235F761D9A8DB3AC57BA61E96F1C9;
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
struct IEqualityComparer_1_t56DA9BBADF80D06B382719FBEE2A597D94458417;
struct IEqualityComparer_1_tC153F65F278AE0C32BA0CC809B12AA724AF65F85;
struct IEqualityComparer_1_t6F0AB70120D6AE40037B48E056791408CF21AEE2;
struct IEqualityComparer_1_t47CC0B235E693652D181B679FF6D61A469ECC122;
struct KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575;
struct KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C;
struct KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE;
struct KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C;
struct KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7;
struct KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9;
struct KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF;
struct KeyCollection_tB792ACBAE0B99278B0B7B0F7440B4788E98F0D55;
struct Tables_tD895B223685217918C345ED5D52074F7E29E5F95;
struct ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1;
struct ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96;
struct ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32;
struct ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF;
struct ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98;
struct ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9;
struct ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D;
struct ValueCollection_tC492596681BD51AB34FC76FA76C15C9B3FFB7B40;
struct EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3;
struct EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0;
struct EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3;
struct EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E;
struct EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE;
struct EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB;
struct EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392;
struct KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F;
struct KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A;
struct KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856;
struct KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93;
struct KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC;
struct KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38;
struct KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363;
struct KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533;
struct EphemeronU5BU5D_t4F80428A1142C3102C946127F8190063001742E8;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IDictionaryEnumerator_tE129D608FCDB7207E0F0ECE33473CC950A83AD16;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct IFormatterConverter_t726606DAC82C384B08C82471313C340968DDB609;
struct IManagedVFSFileHandler_tB83893582A9A15F195D1895A33EE10FE7AA510BA;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct String_t;
struct Type_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
IL2CPP_EXTERN_C String_t* _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
IL2CPP_EXTERN_C String_t* _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A;
IL2CPP_EXTERN_C String_t* _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1;
IL2CPP_EXTERN_C const RuntimeMethod* ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3;
struct EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0;
struct EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3;
struct EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E;
struct EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE;
struct EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB;
struct EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392;
struct KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F;
struct KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A;
struct KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856;
struct KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93;
struct KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC;
struct KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38;
struct KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363;
struct DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct ConcurrentDictionary_2_t6DF554984593E2F9932FAFBF9E1AFD30D1ED0812  : public RuntimeObject
{
	Tables_tD895B223685217918C345ED5D52074F7E29E5F95* ____tables;
	RuntimeObject* ____comparer;
	bool ____growLockArray;
	int32_t ____budget;
	KeyValuePair_2U5BU5D_t885F2E060B0261B18E97D336746D53BA61338F57* ____serializationArray;
	int32_t ____serializationConcurrencyLevel;
	int32_t ____serializationCapacity;
};
struct ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858  : public RuntimeObject
{
	EphemeronU5BU5D_t4F80428A1142C3102C946127F8190063001742E8* ___data;
	RuntimeObject* ____lock;
	int32_t ___size;
};
struct DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A  : public RuntimeObject
{
	RuntimeObject* ____enumerator;
};
struct DictionaryKeyCollectionDebugView_2_tA967A5CC2E1F95032AE886F39B1005E56173D9D2  : public RuntimeObject
{
};
struct DictionaryValueCollectionDebugView_2_tE2C8C453C326A08B63223B59D5D010EFFE30BEF3  : public RuntimeObject
{
};
struct Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575* ____keys;
	ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C* ____keys;
	ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE* ____keys;
	ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C* ____keys;
	ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7* ____keys;
	ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9* ____keys;
	ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9* ____values;
	RuntimeObject* ____syncRoot;
};
struct Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF* ____keys;
	ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D* ____values;
	RuntimeObject* ____syncRoot;
};
struct EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F  : public RuntimeObject
{
};
struct EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB  : public RuntimeObject
{
};
struct EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399  : public RuntimeObject
{
};
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC  : public RuntimeObject
{
};
struct EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35  : public RuntimeObject
{
};
struct EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184  : public RuntimeObject
{
};
struct EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B  : public RuntimeObject
{
};
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081  : public RuntimeObject
{
};
struct EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9  : public RuntimeObject
{
};
struct KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575  : public RuntimeObject
{
	Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ____dictionary;
};
struct KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C  : public RuntimeObject
{
	Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ____dictionary;
};
struct KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE  : public RuntimeObject
{
	Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ____dictionary;
};
struct KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C  : public RuntimeObject
{
	Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ____dictionary;
};
struct KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7  : public RuntimeObject
{
	Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ____dictionary;
};
struct KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9  : public RuntimeObject
{
	Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ____dictionary;
};
struct KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF  : public RuntimeObject
{
	Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ____dictionary;
};
struct ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1  : public RuntimeObject
{
	Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ____dictionary;
};
struct ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96  : public RuntimeObject
{
	Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ____dictionary;
};
struct ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32  : public RuntimeObject
{
	Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ____dictionary;
};
struct ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF  : public RuntimeObject
{
	Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ____dictionary;
};
struct ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98  : public RuntimeObject
{
	Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ____dictionary;
};
struct ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9  : public RuntimeObject
{
	Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ____dictionary;
};
struct ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D  : public RuntimeObject
{
	Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ____dictionary;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37  : public RuntimeObject
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_members;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___m_data;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___m_types;
	Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588* ___m_nameToIndex;
	int32_t ___m_currMember;
	RuntimeObject* ___m_converter;
	String_t* ___m_fullTypeName;
	String_t* ___m_assemName;
	Type_t* ___objectType;
	bool ___isFullTypeNameSetExplicit;
	bool ___isAssemblyNameSetExplicit;
	bool ___requireSameTokenInPartialTrust;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
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
struct Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286 
{
	int32_t ___hashCode;
	int32_t ___next;
	int32_t ___key;
	Il2CppSharedGenericObject* ___value;
};
struct KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 
{
	int32_t ___key;
	Il2CppSharedGenericObject* ___value;
};
typedef Il2CppFullySharedGenericStruct KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669;
struct ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A 
{
	Il2CppSharedGenericObject* ___Item1;
	Il2CppSharedGenericObject* ___Item2;
};
struct ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A 
{
	Il2CppSharedGenericObject* ___Item1;
	int32_t ___Item2;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB 
{
	RuntimeObject* ____key;
	RuntimeObject* ____value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_marshaled_pinvoke
{
	Il2CppIUnknown* ____key;
	Il2CppIUnknown* ____value;
};
struct DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_marshaled_com
{
	Il2CppIUnknown* ____key;
	Il2CppIUnknown* ____value;
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
struct Guid_t 
{
	int32_t ____a;
	int16_t ____b;
	int16_t ____c;
	uint8_t ____d;
	uint8_t ____e;
	uint8_t ____f;
	uint8_t ____g;
	uint8_t ____h;
	uint8_t ____i;
	uint8_t ____j;
	uint8_t ____k;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 
{
	int32_t ___handle;
};
struct LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D 
{
	Type_t* ____scopeType;
	RuntimeObject* ____context;
};
struct LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D_marshaled_pinvoke
{
	Type_t* ____scopeType;
	Il2CppIUnknown* ____context;
};
struct LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D_marshaled_com
{
	Type_t* ____scopeType;
	Il2CppIUnknown* ____context;
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
struct Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 
{
	RuntimeObject* ___handler;
	int32_t ___handle;
};
struct Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8_marshaled_pinvoke
{
	RuntimeObject* ___handler;
	int32_t ___handle;
};
struct Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8_marshaled_com
{
	RuntimeObject* ___handler;
	int32_t ___handle;
};
struct Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14 
{
	int32_t ___hashCode;
	int32_t ___next;
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___key;
	Il2CppSharedGenericObject* ___value;
};
struct Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254 
{
	int32_t ___hashCode;
	int32_t ___next;
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___key;
	Il2CppSharedGenericObject* ___value;
};
struct Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28 
{
	int32_t ___hashCode;
	int32_t ___next;
	Guid_t ___key;
	Il2CppSharedGenericObject* ___value;
};
struct Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB 
{
	int32_t ___hashCode;
	int32_t ___next;
	InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___key;
	Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___value;
};
struct Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E 
{
	int32_t ___hashCode;
	int32_t ___next;
	LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___key;
	Il2CppSharedGenericObject* ___value;
};
struct Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 
{
	Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ____current;
	int32_t ____getEnumeratorRetType;
};
struct KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 
{
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___key;
	Il2CppSharedGenericObject* ___value;
};
struct KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 
{
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___key;
	Il2CppSharedGenericObject* ___value;
};
struct KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B 
{
	Guid_t ___key;
	Il2CppSharedGenericObject* ___value;
};
struct KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE 
{
	InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___key;
	Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___value;
};
struct KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C 
{
	LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___key;
	Il2CppSharedGenericObject* ___value;
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
struct ExceptionArgument_t60E7F8D9DE5362CBE9365893983C30302D83B778 
{
	int32_t ___value__;
};
struct ExceptionResource_t609A85E253A4E615583553D91D839E2E79FDFBD9 
{
	int32_t ___value__;
};
struct FilterMode_t4AD57F1A3FE272D650E0E688BA044AE872BD2A34 
{
	int32_t ___value__;
};
struct InsertionBehavior_tAD0393881947C559238D7041A36917BEE6E2C7B1 
{
	uint8_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct StreamingContextStates_t5EE358E619B251608A9327618C7BFE8638FC33C1 
{
	int32_t ___value__;
};
struct TextureWrapMode_tF9851343029052ED45668D1C99BAE09B2CCC13AD 
{
	int32_t ___value__;
};
struct Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF 
{
	Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 ____current;
	int32_t ____getEnumeratorRetType;
};
struct Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF 
{
	Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 ____current;
	int32_t ____getEnumeratorRetType;
};
struct Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A 
{
	Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B ____current;
	int32_t ____getEnumeratorRetType;
};
struct Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 
{
	Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE ____current;
	int32_t ____getEnumeratorRetType;
};
struct Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 
{
	Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C ____current;
	int32_t ____getEnumeratorRetType;
};
struct SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 
{
	int32_t ___m_FilterMode;
	int32_t ___m_WrapModeU;
	int32_t ___m_WrapModeV;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 
{
	RuntimeObject* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_pinvoke
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct StreamingContext_t56760522A751890146EE45F82F866B55B7E33677_marshaled_com
{
	Il2CppIUnknown* ___m_additionalContext;
	int32_t ___m_state;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134 
{
	int32_t ___hashCode;
	int32_t ___next;
	SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___key;
	Il2CppSharedGenericObject* ___value;
};
struct KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 
{
	SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___key;
	Il2CppSharedGenericObject* ___value;
};
struct ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A 
{
	Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 ____current;
	int32_t ____getEnumeratorRetType;
};
struct ConcurrentDictionary_2_t6DF554984593E2F9932FAFBF9E1AFD30D1ED0812_StaticFields
{
	bool ___s_isValueWriteAtomic;
};
struct EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F_StaticFields
{
	EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* ___defaultComparer;
};
struct EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB_StaticFields
{
	EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* ___defaultComparer;
};
struct EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399_StaticFields
{
	EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* ___defaultComparer;
};
struct EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields
{
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* ___defaultComparer;
};
struct EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35_StaticFields
{
	EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* ___defaultComparer;
};
struct EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184_StaticFields
{
	EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* ___defaultComparer;
};
struct EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B_StaticFields
{
	EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* ___defaultComparer;
};
struct EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields
{
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* ___defaultComparer;
};
struct EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9_StaticFields
{
	EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* ___defaultComparer;
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
struct Guid_t_StaticFields
{
	Guid_t ___Empty;
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
struct EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14 m_Items[1];

	inline Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item2), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item2), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 m_Items[1];

	inline KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item2), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item2), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533  : public RuntimeArray
{
	ALIGN_FIELD (8) DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB m_Items[1];

	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____value), (void*)NULL);
		#endif
	}
	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____key), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->____value), (void*)NULL);
		#endif
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254 m_Items[1];

	inline Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 m_Items[1];

	inline KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28 m_Items[1];

	inline Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B m_Items[1];

	inline KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};
struct EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286 m_Items[1];

	inline Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 m_Items[1];

	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};
struct EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB m_Items[1];

	inline Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___handler), (void*)NULL);
	}
	inline Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___handler), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE m_Items[1];

	inline KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___handler), (void*)NULL);
	}
	inline KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___value))->___handler), (void*)NULL);
	}
};
struct EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E m_Items[1];

	inline Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____scopeType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____context), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____scopeType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____context), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C m_Items[1];

	inline KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____scopeType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____context), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
	inline KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____scopeType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&((m_Items + index)->___key))->____context), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
		#endif
	}
};
struct EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392  : public RuntimeArray
{
	ALIGN_FIELD (8) Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134 m_Items[1];

	inline Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};
struct KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363  : public RuntimeArray
{
	ALIGN_FIELD (8) KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 m_Items[1];

	inline KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
	inline KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___value), (void*)NULL);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE4B120CEAC8B3FB8164A6B8421DB9482654758F3_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_gshared_inline (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_gshared_inline (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared (KeyCollection_tB792ACBAE0B99278B0B7B0F7440B4788E98F0D55* __this, Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* ___0_dictionary, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared (ValueCollection_tC492596681BD51AB34FC76FA76C15C9B3FFB7B40* __this, Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* ___0_dictionary, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m38590317DE74DBE8D92F2CBEF07EB2166FD77F8A_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared (Dictionary_2_t5C32AF17A5801FB3109E5B0E622BA8402A04E08E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_m0D4121FAC5AC308F9F11677446270359EE7F187F_gshared (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E_gshared (Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF* __this, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7_gshared (ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mECA349A5C568918987B1E5F01CF437B826B24473_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ConditionalWeakTable_2_TryGetValue_m90CA5ADAC109E3D265A2A6AD8B5165727D9605D2_gshared (ConditionalWeakTable_2_tDA4DD9BAFAF3114A73F0B4D6AA3049208A3B288B* __this, Il2CppSharedGenericObject* ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ConditionalWeakTable_2_Remove_m035485E631710955A475F95DE3800BBD2EBD20B5_gshared (ConditionalWeakTable_2_tDA4DD9BAFAF3114A73F0B4D6AA3049208A3B288B* __this, Il2CppSharedGenericObject* ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m89E3D5532F34F27BEB5DF28BB40F3558ECDF3728_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054_gshared (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_mB372B26FF800DAB8A056AC36CEF56999C6B8C0B2_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mAD75EF58F66B595F8D3901C3452232FC94062088_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_gshared_inline (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_gshared_inline (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m86A5B73912916A5825210A61600309B0CEBE7022_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mD0CA78640E4E9AEDF3F7B13285742812AD9D3F93_gshared (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8_gshared (Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF* __this, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404_gshared (ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m2B49E5B27DE63B7B42984CEC07EAE9D3119B80F7_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m7D9EC0F043E0B9FAB07F7AE3EA84667BFA73B967_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m50080FF99F5F609F7C6D4A916D1A4264AB88BCC5_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mFE8D024D7FA568AAB39FCF6DAF344F43EE1F4A43_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Guid_t KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_gshared_inline (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_gshared_inline (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m2BD0E6825D66721033A14ABB6F727A8D1C8E0628_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mAADB86C56A6064707D6B414C20886941E280A8C8_gshared (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D_gshared (Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A* __this, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m4B80FC5F8BA8BAE74E0EAB023D785DFDA03A7F6A_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mADA0004999558ADFD7386840DF35CAA07E676568_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m93D471C69BDF1EE119D28B69BFACB3B4C6E1B9C5_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m0DFAF670559B0FE516624A501EA61CB9B14B7B67_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_gshared_inline (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_gshared_inline (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m07FA12992B3DAD86BD9CD3797525EBC22BE69E15_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mB203F4B742D836457DDC26B3493454EC84369344_gshared (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65_gshared (Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1* __this, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mFFD5EEA58232DF8B073F38D35C39D8CDCB6AD30D_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m82DAF2EEBEF35C89774A8E71F51F1BD13378620F_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m2BB6CF3A683DE145DB22935870F3C63F3E8E3027_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5A86DD7196BAD4E82E1612063D35AA69A41AC127 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m37E8831114C391DE86E5265088822C77C8902039 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* EqualityComparer_1_get_Default_m2B4F62EDB23031C609551EC3F4671100D30E9CEA_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m242481DE2BE6F14286AAC901883DDBDCFF8A3FB0 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mC7D1153B9AF14948CABDF03CB0B9F2738E9D73A2 (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mB32AE83D0B9758EC2EF27CE221A21821D81D1C66 (Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5* __this, Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m7E43D940B96D7285E9B06A4995E5DC3E4F75D750 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mB1AA1911C550F562B65DE6DDC6F4936FADF503F4 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mFE661A28565100336E2E0AC668DE8FBEE997B873 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisBinding_t4902D3C6D27680D096CC41D83FFD0872785E57F8_mA18D5105179EC292D090491E378CBED448E54927 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m2C8B19C423C5ADE5459015BE8B0361D2DA4D2AE2 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE3BF918A0795EB846853FF14EFAA7B94BDE3804F_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_gshared_inline (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_gshared_inline (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m9B8C23C73DCE5610BAD4E4506C7260A603E3BD82_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mDCDE0152C265A2053B88ED33A9DF26DCF2F78F1F_gshared (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036_gshared (Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6* __this, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m6C1A1056F7B16BC3FB46419013821F6D2E8BC6DF_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mB8FC12542175B64C09AC8D93BFFCA68DDF3860D1_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m6121DA29D4E26687E594BFA4AF8F974D3E0E2230_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m830173718C916AE82B9646A3C6AEC86D5AB69774_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_gshared_inline (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_gshared_inline (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m875E41231D476577C9A3B051A475870CE8A41118_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_m62040016A6CE2E5FDD9B8A2BF034F1319CA0379D_gshared (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6_gshared (Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A* __this, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m923041BDE6BE4962A302162C644214A773DD97C0_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m9A7E6DE44A18A45A6E783210B518C26336A648BC_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m03B251192DEED90E69DEE07C8E616FEB8AE6F720_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* EqualityComparer_1_CreateComparer_mDDE2C10C48FE5C71172724020C00DA2C431DBF21_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* EqualityComparer_1_CreateComparer_mB0408C395999134DEDD71AB568D127159ACF5141_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* EqualityComparer_1_CreateComparer_mD3D60BAB4A1E7DF8FDC8779F5A1A3104CAD5202A (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* EqualityComparer_1_CreateComparer_m538EEAA8DA010A259CC57D5123DA0B894EFC04BE (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* EqualityComparer_1_CreateComparer_m596C801639AA4AC5BAEF2ADC1E5651C7F99C400F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* EqualityComparer_1_CreateComparer_m05DA1830F41332AD085B970EE82FB91C62301E40 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* EqualityComparer_1_CreateComparer_mB189012E616E6286F0B1D722223BEDF80F3610A5 (const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, int32_t, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97 (int32_t ___0_argument, const RuntimeMethod* method) ;
inline int32_t Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, int32_t, const RuntimeMethod*))Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256_gshared)(__this, ___0_capacity, method);
}
inline EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_gshared_inline)(method);
}
inline void Dictionary_2__ctor_mE4B120CEAC8B3FB8164A6B8421DB9482654758F3 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_mE4B120CEAC8B3FB8164A6B8421DB9482654758F3_gshared)(__this, ___0_dictionary, ___1_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC (int32_t ___0_argument, const RuntimeMethod* method) ;
inline void Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940_gshared)(__this, ___0_key, ___1_value, method);
}
inline ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, const RuntimeMethod* method)
{
	return ((  ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A (*) (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295*, const RuntimeMethod*))KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_gshared_inline)(__this, method);
}
inline Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_inline (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295*, const RuntimeMethod*))KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_gshared_inline)(__this, method);
}
inline void KeyCollection__ctor_m28B3CAD60EA6848BE8C46114BD6E0C8FF936E72A (KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575* __this, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575*, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_mD531F2816B35D4869E5EB9CCD56794AD15649388 (ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1* __this, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1*, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
inline int32_t Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, const RuntimeMethod*))Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6_gshared)(__this, ___0_key, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7 (RuntimeObject* ___0_key, const RuntimeMethod* method) ;
inline bool Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, Il2CppSharedGenericObject*, uint8_t, const RuntimeMethod*))Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865_gshared)(__this, ___0_key, ___1_value, ___2_behavior, method);
}
inline EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline)(method);
}
inline bool Dictionary_2_Remove_m38590317DE74DBE8D92F2CBEF07EB2166FD77F8A (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, const RuntimeMethod*))Dictionary_2_Remove_m38590317DE74DBE8D92F2CBEF07EB2166FD77F8A_gshared)(__this, ___0_key, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F (const RuntimeMethod* method) ;
inline int32_t Dictionary_2_get_Count_mE694E1EB3DC6921BA682AB491035440877A5024C (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA (int32_t ___0_resource, const RuntimeMethod* method) ;
inline void KeyValuePair_2__ctor_m0D4121FAC5AC308F9F11677446270359EE7F187F (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, Il2CppSharedGenericObject*, const RuntimeMethod*))KeyValuePair_2__ctor_m0D4121FAC5AC308F9F11677446270359EE7F187F_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E (Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF* __this, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF*, Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, int32_t, const RuntimeMethod*))Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E_gshared)(__this, ___0_dictionary, ___1_getEnumeratorRetType, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, int32_t ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, RuntimeObject* ___1_value, Type_t* ___2_type, const RuntimeMethod* method) ;
inline void Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* ___0_array, int32_t ___1_index, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F*, int32_t, const RuntimeMethod*))Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA_gshared)(__this, ___0_array, ___1_index, method);
}
inline int32_t ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7 (ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*, const RuntimeMethod*))ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472 (int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5 (RuntimeObject* ___0_key, const RuntimeMethod* method) ;
inline void Dictionary_2_Resize_mECA349A5C568918987B1E5F01CF437B826B24473 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, const RuntimeMethod*))Dictionary_2_Resize_mECA349A5C568918987B1E5F01CF437B826B24473_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F (const RuntimeMethod* method) ;
inline bool ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F (ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* __this, RuntimeObject* ___0_key, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858*, RuntimeObject*, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37**, const RuntimeMethod*))ConditionalWeakTable_2_TryGetValue_m90CA5ADAC109E3D265A2A6AD8B5165727D9605D2_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16 (int32_t ___0_resource, const RuntimeMethod* method) ;
inline bool ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E (ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* __this, RuntimeObject* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858*, RuntimeObject*, const RuntimeMethod*))ConditionalWeakTable_2_Remove_m035485E631710955A475F95DE3800BBD2EBD20B5_gshared)(__this, ___0_key, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9 (int32_t ___0_oldSize, const RuntimeMethod* method) ;
inline void Dictionary_2_Resize_m89E3D5532F34F27BEB5DF28BB40F3558ECDF3728 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, int32_t, bool, const RuntimeMethod*))Dictionary_2_Resize_m89E3D5532F34F27BEB5DF28BB40F3558ECDF3728_gshared)(__this, ___0_newSize, ___1_forceNewHashCodes, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC (RuntimeArray* __this, int32_t ___0_dimension, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58 (const RuntimeMethod* method) ;
inline void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054_gshared)(___0_value, ___1_argName, method);
}
inline void Dictionary_2_set_Item_mB372B26FF800DAB8A056AC36CEF56999C6B8C0B2 (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_set_Item_mB372B26FF800DAB8A056AC36CEF56999C6B8C0B2_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910 (RuntimeObject* ___0_value, Type_t* ___1_targetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982 (RuntimeObject* ___0_key, Type_t* ___1_targetType, const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, int32_t, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
inline int32_t Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, int32_t, const RuntimeMethod*))Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF_gshared)(__this, ___0_capacity, method);
}
inline EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* (*) (const RuntimeMethod*))EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_gshared_inline)(method);
}
inline void Dictionary_2__ctor_mAD75EF58F66B595F8D3901C3452232FC94062088 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_mAD75EF58F66B595F8D3901C3452232FC94062088_gshared)(__this, ___0_dictionary, ___1_comparer, method);
}
inline void Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164_gshared)(__this, ___0_key, ___1_value, method);
}
inline ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, const RuntimeMethod* method)
{
	return ((  ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A (*) (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2*, const RuntimeMethod*))KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_gshared_inline)(__this, method);
}
inline Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_inline (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2*, const RuntimeMethod*))KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_gshared_inline)(__this, method);
}
inline void KeyCollection__ctor_mD5E79842FA5F42C6B3E458407CA711BDAAB1FE69 (KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C* __this, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C*, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_m7782EC432C8B7591F78A35C56024E8E21C78A345 (ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96* __this, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96*, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
inline int32_t Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, const RuntimeMethod*))Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7_gshared)(__this, ___0_key, method);
}
inline bool Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, Il2CppSharedGenericObject*, uint8_t, const RuntimeMethod*))Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC_gshared)(__this, ___0_key, ___1_value, ___2_behavior, method);
}
inline bool Dictionary_2_Remove_m86A5B73912916A5825210A61600309B0CEBE7022 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, const RuntimeMethod*))Dictionary_2_Remove_m86A5B73912916A5825210A61600309B0CEBE7022_gshared)(__this, ___0_key, method);
}
inline int32_t Dictionary_2_get_Count_m889AEFA656A4A6AB38DC123246E8BEC33647F2BB (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
inline void KeyValuePair_2__ctor_mD0CA78640E4E9AEDF3F7B13285742812AD9D3F93 (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, Il2CppSharedGenericObject*, const RuntimeMethod*))KeyValuePair_2__ctor_mD0CA78640E4E9AEDF3F7B13285742812AD9D3F93_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8 (Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF* __this, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF*, Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, int32_t, const RuntimeMethod*))Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8_gshared)(__this, ___0_dictionary, ___1_getEnumeratorRetType, method);
}
inline void Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* ___0_array, int32_t ___1_index, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A*, int32_t, const RuntimeMethod*))Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66_gshared)(__this, ___0_array, ___1_index, method);
}
inline int32_t ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404 (ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*, const RuntimeMethod*))ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404_gshared)(__this, method);
}
inline void Dictionary_2_Resize_m2B49E5B27DE63B7B42984CEC07EAE9D3119B80F7 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, const RuntimeMethod*))Dictionary_2_Resize_m2B49E5B27DE63B7B42984CEC07EAE9D3119B80F7_gshared)(__this, method);
}
inline void Dictionary_2_Resize_m7D9EC0F043E0B9FAB07F7AE3EA84667BFA73B967 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, int32_t, bool, const RuntimeMethod*))Dictionary_2_Resize_m7D9EC0F043E0B9FAB07F7AE3EA84667BFA73B967_gshared)(__this, ___0_newSize, ___1_forceNewHashCodes, method);
}
inline void Dictionary_2_set_Item_m50080FF99F5F609F7C6D4A916D1A4264AB88BCC5 (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_set_Item_m50080FF99F5F609F7C6D4A916D1A4264AB88BCC5_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, int32_t, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
inline int32_t Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, int32_t, const RuntimeMethod*))Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5_gshared)(__this, ___0_capacity, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline (const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_mFE8D024D7FA568AAB39FCF6DAF344F43EE1F4A43 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_mFE8D024D7FA568AAB39FCF6DAF344F43EE1F4A43_gshared)(__this, ___0_dictionary, ___1_comparer, method);
}
inline void Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, Guid_t, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB_gshared)(__this, ___0_key, ___1_value, method);
}
inline Guid_t KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, const RuntimeMethod* method)
{
	return ((  Guid_t (*) (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B*, const RuntimeMethod*))KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_gshared_inline)(__this, method);
}
inline Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_inline (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B*, const RuntimeMethod*))KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_gshared_inline)(__this, method);
}
inline void KeyCollection__ctor_m1DD9728163AEE8DECB0FD6CC40DDEB6E3B419E04 (KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE* __this, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE*, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_m16305A7173A73FFD4F82FAC103C980A99266B7E2 (ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32* __this, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32*, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
inline int32_t Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, Guid_t, const RuntimeMethod*))Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D_gshared)(__this, ___0_key, method);
}
inline bool Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, Guid_t, Il2CppSharedGenericObject*, uint8_t, const RuntimeMethod*))Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D_gshared)(__this, ___0_key, ___1_value, ___2_behavior, method);
}
inline bool Dictionary_2_Remove_m2BD0E6825D66721033A14ABB6F727A8D1C8E0628 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, Guid_t, const RuntimeMethod*))Dictionary_2_Remove_m2BD0E6825D66721033A14ABB6F727A8D1C8E0628_gshared)(__this, ___0_key, method);
}
inline int32_t Dictionary_2_get_Count_m62CB7B656456CFDD5DC73F6ECAA5BAF24EFBA62C (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
inline void KeyValuePair_2__ctor_mAADB86C56A6064707D6B414C20886941E280A8C8 (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B*, Guid_t, Il2CppSharedGenericObject*, const RuntimeMethod*))KeyValuePair_2__ctor_mAADB86C56A6064707D6B414C20886941E280A8C8_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D (Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A* __this, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A*, Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, int32_t, const RuntimeMethod*))Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D_gshared)(__this, ___0_dictionary, ___1_getEnumeratorRetType, method);
}
inline void Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* ___0_array, int32_t ___1_index, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856*, int32_t, const RuntimeMethod*))Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60_gshared)(__this, ___0_array, ___1_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Guid_GetHashCode_m239B7679BB9ED5A207B3D2F858B5F30FFC455408 (Guid_t* __this, const RuntimeMethod* method) ;
inline void Dictionary_2_Resize_m4B80FC5F8BA8BAE74E0EAB023D785DFDA03A7F6A (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, const RuntimeMethod*))Dictionary_2_Resize_m4B80FC5F8BA8BAE74E0EAB023D785DFDA03A7F6A_gshared)(__this, method);
}
inline void Dictionary_2_Resize_mADA0004999558ADFD7386840DF35CAA07E676568 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, int32_t, bool, const RuntimeMethod*))Dictionary_2_Resize_mADA0004999558ADFD7386840DF35CAA07E676568_gshared)(__this, ___0_newSize, ___1_forceNewHashCodes, method);
}
inline void Dictionary_2_set_Item_m93D471C69BDF1EE119D28B69BFACB3B4C6E1B9C5 (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*, Guid_t, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_set_Item_m93D471C69BDF1EE119D28B69BFACB3B4C6E1B9C5_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
inline int32_t Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, const RuntimeMethod*))Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB_gshared)(__this, ___0_capacity, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_m0DFAF670559B0FE516624A501EA61CB9B14B7B67 (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m0DFAF670559B0FE516624A501EA61CB9B14B7B67_gshared)(__this, ___0_dictionary, ___1_comparer, method);
}
inline void Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B_gshared)(__this, ___0_key, ___1_value, method);
}
inline int32_t KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55*, const RuntimeMethod*))KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_gshared_inline)(__this, method);
}
inline Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_inline (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55*, const RuntimeMethod*))KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_gshared_inline)(__this, method);
}
inline void KeyCollection__ctor_m574C0BEA657118596B91087FCD53CD5206AB8CE1 (KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C* __this, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C*, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_mC5E41CEAC9927A0756C903DA9D06C533F76D1913 (ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF* __this, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF*, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
inline int32_t Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698 (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, const RuntimeMethod*))Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698_gshared)(__this, ___0_key, method);
}
inline bool Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, Il2CppSharedGenericObject*, uint8_t, const RuntimeMethod*))Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F_gshared)(__this, ___0_key, ___1_value, ___2_behavior, method);
}
inline bool Dictionary_2_Remove_m07FA12992B3DAD86BD9CD3797525EBC22BE69E15 (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, const RuntimeMethod*))Dictionary_2_Remove_m07FA12992B3DAD86BD9CD3797525EBC22BE69E15_gshared)(__this, ___0_key, method);
}
inline int32_t Dictionary_2_get_Count_mCE5BB990E0EB80EB89D6FDF8DB85AF06C991991B (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
inline void KeyValuePair_2__ctor_mB203F4B742D836457DDC26B3493454EC84369344 (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))KeyValuePair_2__ctor_mB203F4B742D836457DDC26B3493454EC84369344_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65 (Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1* __this, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1*, Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, const RuntimeMethod*))Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65_gshared)(__this, ___0_dictionary, ___1_getEnumeratorRetType, method);
}
inline void Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* ___0_array, int32_t ___1_index, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*, int32_t, const RuntimeMethod*))Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB_gshared)(__this, ___0_array, ___1_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295 (int32_t* __this, const RuntimeMethod* method) ;
inline void Dictionary_2_Resize_mFFD5EEA58232DF8B073F38D35C39D8CDCB6AD30D (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, const RuntimeMethod*))Dictionary_2_Resize_mFFD5EEA58232DF8B073F38D35C39D8CDCB6AD30D_gshared)(__this, method);
}
inline void Dictionary_2_Resize_m82DAF2EEBEF35C89774A8E71F51F1BD13378620F (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, bool, const RuntimeMethod*))Dictionary_2_Resize_m82DAF2EEBEF35C89774A8E71F51F1BD13378620F_gshared)(__this, ___0_newSize, ___1_forceNewHashCodes, method);
}
inline void Dictionary_2_set_Item_m2BB6CF3A683DE145DB22935870F3C63F3E8E3027 (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_set_Item_m2BB6CF3A683DE145DB22935870F3C63F3E8E3027_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5A86DD7196BAD4E82E1612063D35AA69A41AC127 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, const RuntimeMethod* method) ;
inline void KeyCollection__ctor_m02A1D71902F956CF8E4F3EBF6B393B3027059F88 (KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7* __this, Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7*, Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_m9F330FA04A0EDF48F556FA52CDB1C53E10AFC265 (ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98* __this, Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98*, Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m37E8831114C391DE86E5265088822C77C8902039 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* EqualityComparer_1_get_Default_m2B4F62EDB23031C609551EC3F4671100D30E9CEA_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m242481DE2BE6F14286AAC901883DDBDCFF8A3FB0 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) ;
inline int32_t Dictionary_2_get_Count_mB2AF075C1A6CDDDB77A2F1AD3F7951AF2C655046 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void KeyValuePair_2__ctor_mC7D1153B9AF14948CABDF03CB0B9F2738E9D73A2 (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mB32AE83D0B9758EC2EF27CE221A21821D81D1C66 (Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5* __this, Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m7E43D940B96D7285E9B06A4995E5DC3E4F75D750 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline (InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mB1AA1911C550F562B65DE6DDC6F4936FADF503F4 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mFE661A28565100336E2E0AC668DE8FBEE997B873 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisBinding_t4902D3C6D27680D096CC41D83FFD0872785E57F8_mA18D5105179EC292D090491E378CBED448E54927 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m2C8B19C423C5ADE5459015BE8B0361D2DA4D2AE2 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, int32_t, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
inline int32_t Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, int32_t, const RuntimeMethod*))Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0_gshared)(__this, ___0_capacity, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline (const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_mE3BF918A0795EB846853FF14EFAA7B94BDE3804F (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_mE3BF918A0795EB846853FF14EFAA7B94BDE3804F_gshared)(__this, ___0_dictionary, ___1_comparer, method);
}
inline void Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D_gshared)(__this, ___0_key, ___1_value, method);
}
inline LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, const RuntimeMethod* method)
{
	return ((  LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D (*) (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C*, const RuntimeMethod*))KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_gshared_inline)(__this, method);
}
inline Il2CppSharedGenericObject* KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_inline (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C*, const RuntimeMethod*))KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_gshared_inline)(__this, method);
}
inline void KeyCollection__ctor_mCB4E7E205EC342EAB10B0702E3B66409B6A9B200 (KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9* __this, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9*, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_m1BD339959757C06FE8E0334B098E945E9FA88D87 (ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9* __this, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9*, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
inline int32_t Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, const RuntimeMethod*))Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040_gshared)(__this, ___0_key, method);
}
inline bool Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, Il2CppSharedGenericObject*, uint8_t, const RuntimeMethod*))Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0_gshared)(__this, ___0_key, ___1_value, ___2_behavior, method);
}
inline bool Dictionary_2_Remove_m9B8C23C73DCE5610BAD4E4506C7260A603E3BD82 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, const RuntimeMethod*))Dictionary_2_Remove_m9B8C23C73DCE5610BAD4E4506C7260A603E3BD82_gshared)(__this, ___0_key, method);
}
inline int32_t Dictionary_2_get_Count_m0FEE8044BE7041E9FEDEA39C11EAD8AF0D8101C8 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
inline void KeyValuePair_2__ctor_mDCDE0152C265A2053B88ED33A9DF26DCF2F78F1F (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C*, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, Il2CppSharedGenericObject*, const RuntimeMethod*))KeyValuePair_2__ctor_mDCDE0152C265A2053B88ED33A9DF26DCF2F78F1F_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036 (Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6* __this, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6*, Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, int32_t, const RuntimeMethod*))Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036_gshared)(__this, ___0_dictionary, ___1_getEnumeratorRetType, method);
}
inline void Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* ___0_array, int32_t ___1_index, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38*, int32_t, const RuntimeMethod*))Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635_gshared)(__this, ___0_array, ___1_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t LifecycleScopeKey_GetHashCode_mFF0E00A6E201E85BAE8E7D68D9F28FF33314BF73 (LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D* __this, const RuntimeMethod* method) ;
inline void Dictionary_2_Resize_m6C1A1056F7B16BC3FB46419013821F6D2E8BC6DF (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, const RuntimeMethod*))Dictionary_2_Resize_m6C1A1056F7B16BC3FB46419013821F6D2E8BC6DF_gshared)(__this, method);
}
inline void Dictionary_2_Resize_mB8FC12542175B64C09AC8D93BFFCA68DDF3860D1 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, int32_t, bool, const RuntimeMethod*))Dictionary_2_Resize_mB8FC12542175B64C09AC8D93BFFCA68DDF3860D1_gshared)(__this, ___0_newSize, ___1_forceNewHashCodes, method);
}
inline void Dictionary_2_set_Item_m6121DA29D4E26687E594BFA4AF8F974D3E0E2230 (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_set_Item_m6121DA29D4E26687E594BFA4AF8F974D3E0E2230_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, int32_t, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94_gshared)(__this, ___0_capacity, ___1_comparer, method);
}
inline int32_t Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, int32_t, const RuntimeMethod*))Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B_gshared)(__this, ___0_capacity, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline (const RuntimeMethod* method) ;
inline void Dictionary_2__ctor_m830173718C916AE82B9646A3C6AEC86D5AB69774 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, RuntimeObject*, RuntimeObject*, const RuntimeMethod*))Dictionary_2__ctor_m830173718C916AE82B9646A3C6AEC86D5AB69774_gshared)(__this, ___0_dictionary, ___1_comparer, method);
}
inline void Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680_gshared)(__this, ___0_key, ___1_value, method);
}
inline SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, const RuntimeMethod* method)
{
	return ((  SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 (*) (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2*, const RuntimeMethod*))KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_gshared_inline)(__this, method);
}
inline Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_inline (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2*, const RuntimeMethod*))KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_gshared_inline)(__this, method);
}
inline void KeyCollection__ctor_m7E2470EE4EC9FB62B159CCCAD65C4D28BF62ADA4 (KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF* __this, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF*, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, const RuntimeMethod*))KeyCollection__ctor_m7AF8E4ED6C5228B083FFB423B7DC792CA7C5DD1F_fshared)(__this, ___0_dictionary, method);
}
inline void ValueCollection__ctor_mCA65F91E6386BB7AFEDB097F1EE273D3C97B3E5F (ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D* __this, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ___0_dictionary, const RuntimeMethod* method)
{
	((  void (*) (ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D*, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, const RuntimeMethod*))ValueCollection__ctor_m382CBA779E83FEFFA62EDF7BF82EB0101BD7858E_fshared)(__this, ___0_dictionary, method);
}
inline int32_t Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, const RuntimeMethod*))Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81_gshared)(__this, ___0_key, method);
}
inline bool Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, Il2CppSharedGenericObject*, uint8_t, const RuntimeMethod*))Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10_gshared)(__this, ___0_key, ___1_value, ___2_behavior, method);
}
inline bool Dictionary_2_Remove_m875E41231D476577C9A3B051A475870CE8A41118 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, const RuntimeMethod*))Dictionary_2_Remove_m875E41231D476577C9A3B051A475870CE8A41118_gshared)(__this, ___0_key, method);
}
inline int32_t Dictionary_2_get_Count_mCD0ED4AC38DA3D2F05E2129818FC98C046B09A36 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, const RuntimeMethod*))Dictionary_2_get_Count_mBB454C6743410D3E06D44D494D4D6FF4CBBBDB1E_fshared)(__this, method);
}
inline void KeyValuePair_2__ctor_m62040016A6CE2E5FDD9B8A2BF034F1319CA0379D (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2*, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, Il2CppSharedGenericObject*, const RuntimeMethod*))KeyValuePair_2__ctor_m62040016A6CE2E5FDD9B8A2BF034F1319CA0379D_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6 (Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A* __this, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* ___0_dictionary, int32_t ___1_getEnumeratorRetType, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A*, Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, int32_t, const RuntimeMethod*))Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6_gshared)(__this, ___0_dictionary, ___1_getEnumeratorRetType, method);
}
inline void Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* ___0_array, int32_t ___1_index, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363*, int32_t, const RuntimeMethod*))Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96_gshared)(__this, ___0_array, ___1_index, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SamplerKey_GetHashCode_m65CFF629294833D2638E8331CCD322205A3F58E6 (SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724* __this, const RuntimeMethod* method) ;
inline void Dictionary_2_Resize_m923041BDE6BE4962A302162C644214A773DD97C0 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, const RuntimeMethod*))Dictionary_2_Resize_m923041BDE6BE4962A302162C644214A773DD97C0_gshared)(__this, method);
}
inline void Dictionary_2_Resize_m9A7E6DE44A18A45A6E783210B518C26336A648BC (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, int32_t, bool, const RuntimeMethod*))Dictionary_2_Resize_m9A7E6DE44A18A45A6E783210B518C26336A648BC_gshared)(__this, ___0_newSize, ___1_forceNewHashCodes, method);
}
inline void Dictionary_2_set_Item_m03B251192DEED90E69DEE07C8E616FEB8AE6F720 (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, Il2CppSharedGenericObject*, const RuntimeMethod*))Dictionary_2_set_Item_m03B251192DEED90E69DEE07C8E616FEB8AE6F720_gshared)(__this, ___0_key, ___1_value, method);
}
inline EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* EqualityComparer_1_CreateComparer_mDDE2C10C48FE5C71172724020C00DA2C431DBF21 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mDDE2C10C48FE5C71172724020C00DA2C431DBF21_gshared)(method);
}
inline EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530_gshared)(method);
}
inline EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* EqualityComparer_1_CreateComparer_mB0408C395999134DEDD71AB568D127159ACF5141 (const RuntimeMethod* method)
{
	return ((  EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* (*) (const RuntimeMethod*))EqualityComparer_1_CreateComparer_mB0408C395999134DEDD71AB568D127159ACF5141_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* EqualityComparer_1_CreateComparer_mD3D60BAB4A1E7DF8FDC8779F5A1A3104CAD5202A (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* EqualityComparer_1_CreateComparer_m538EEAA8DA010A259CC57D5123DA0B894EFC04BE (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* EqualityComparer_1_CreateComparer_m596C801639AA4AC5BAEF2ADC1E5651C7F99C400F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* EqualityComparer_1_CreateComparer_m05DA1830F41332AD085B970EE82FB91C62301E40 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* EqualityComparer_1_CreateComparer_mB189012E616E6286F0B1D722223BEDF80F3610A5 (const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DictionaryEnumerator__ctor_mE63FC46E53E46535C7DD59172E65E42BD570D5F3_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, ConcurrentDictionary_2_t6DF554984593E2F9932FAFBF9E1AFD30D1ED0812* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		ConcurrentDictionary_2_t6DF554984593E2F9932FAFBF9E1AFD30D1ED0812* L_0 = ___0_dictionary;
		RuntimeObject* L_1;
		L_1 = ((  RuntimeObject* (*) (ConcurrentDictionary_2_t6DF554984593E2F9932FAFBF9E1AFD30D1ED0812*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->____enumerator = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____enumerator), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB DictionaryEnumerator_get_Entry_m6EB9062A7B59C89B18B6B61214B707BE4AA44086_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3));
	const uint32_t SizeOf_TKey_t41C513A174F5F1C2B7E599C2ECFAF69540C6C9C7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_TKey_t41C513A174F5F1C2B7E599C2ECFAF69540C6C9C7);
	const uint32_t SizeOf_TValue_t9F4D688327705ABBE7AC2FE14F9F923B56192632 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TValue_t9F4D688327705ABBE7AC2FE14F9F923B56192632);
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_1 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_5 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 V_0 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	memset(V_0, 0, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	{
		RuntimeObject* L_0 = __this->____enumerator;
		InterfaceActionInvoker1Invoker< KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 1), L_0, (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_0, (Il2CppFullySharedGenericAny*)L_2);
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5), L_2);
		RuntimeObject* L_4 = __this->____enumerator;
		InterfaceActionInvoker1Invoker< KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 1), L_4, (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_5);
		il2cpp_codegen_memcpy(V_0, L_5, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_0, (Il2CppFullySharedGenericAny*)L_6);
		RuntimeObject* L_7 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7), L_6);
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_8;
		memset((&L_8), 0, sizeof(L_8));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_8), L_3, L_7, NULL);
		return L_8;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* DictionaryEnumerator_get_Key_m0990C99F94EA95C5392CA5485B4BFD344BAED6FE_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3));
	const uint32_t SizeOf_TKey_t41C513A174F5F1C2B7E599C2ECFAF69540C6C9C7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_TKey_t41C513A174F5F1C2B7E599C2ECFAF69540C6C9C7);
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_1 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 V_0 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	memset(V_0, 0, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	{
		RuntimeObject* L_0 = __this->____enumerator;
		InterfaceActionInvoker1Invoker< KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 1), L_0, (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_0, (Il2CppFullySharedGenericAny*)L_2);
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5), L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* DictionaryEnumerator_get_Value_mD790494FF5E50257030CC045B516A70513EE98A8_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 3));
	const uint32_t SizeOf_TValue_t9F4D688327705ABBE7AC2FE14F9F923B56192632 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_TValue_t9F4D688327705ABBE7AC2FE14F9F923B56192632);
	const KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 L_1 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669 V_0 = alloca(SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	memset(V_0, 0, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
	{
		RuntimeObject* L_0 = __this->____enumerator;
		InterfaceActionInvoker1Invoker< KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 1), L_0, (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)L_1);
		il2cpp_codegen_memcpy(V_0, L_1, SizeOf_KeyValuePair_2_t7B799B8ED9C86E8E9BC5354DE4FDABD0184FF6B7);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6), (KeyValuePair_2_t28EF90BF7804CE5D7F99A364266351E7DC652669*)V_0, (Il2CppFullySharedGenericAny*)L_2);
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7), L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* DictionaryEnumerator_get_Current_m84A050320869FF83584304FF56D3BA05368095F2_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_0;
		L_0 = ((  DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB (*) (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_1 = L_0;
		RuntimeObject* L_2 = Box(DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB_il2cpp_TypeInfo_var, &L_1);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool DictionaryEnumerator_MoveNext_mCD670B5AE8886409051790844BF74853977F5846_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____enumerator;
		bool L_1;
		L_1 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_0);
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DictionaryEnumerator_Reset_mBAC7702D03B6B7A6496AA713EC06CE6162127B2C_fshared (DictionaryEnumerator_t50968DBECB732082714E6294722DC51777C8A22A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->____enumerator;
		InterfaceActionInvoker0::Invoke(2, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_0);
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
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mDAE28766991DA90CA0182FEB3630C356F0D3A58A_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m7D07BFF09CD0A13D048507C8478F869D9B7DA954_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE29A61FA622B0B4CC65A83F2ABAF19B40D6D9539_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_5;
		L_5 = EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m55E1072B6FFDBB2DA0795FB824559888AADB831D_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_mE4B120CEAC8B3FB8164A6B8421DB9482654758F3(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE4B120CEAC8B3FB8164A6B8421DB9482654758F3_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* G_B2_0 = NULL;
	Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), (RuntimeObject*)L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_m86B8B16DB9C92FF405CB902F82146B9D136E9984(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* L_9 = ((Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_15 = V_1;
		int32_t L_16 = V_2;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_18 = V_1;
		int32_t L_19 = V_2;
		Il2CppSharedGenericObject* L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), (RuntimeObject*)L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_30;
				L_30 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline((&V_4), NULL);
				Il2CppSharedGenericObject* L_31;
				L_31 = KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_inline((&V_4), NULL);
				Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575* Dictionary_2_get_Keys_m59EDFF48264F283729CF504D7ED40484240331EC_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575* L_1 = (KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_m28B3CAD60EA6848BE8C46114BD6E0C8FF936E72A(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_tF3843FC39D5C3B0CEA3C2A09563C6BE9D7327575* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1* Dictionary_2_get_Values_mDEA6A43564B7A3B2B74ADB07370392714267B447_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1* L_1 = (ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_mD531F2816B35D4869E5EB9CCD56794AD15649388(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_tE676A0B8EBB18ACFBE7F3E153BEC60CA0E3BE2D1* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Dictionary_2_get_Item_m23A5A07AE8C61F7DBA9F66FD4082B5647D271F61_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_6 = ___0_key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_mB372B26FF800DAB8A056AC36CEF56999C6B8C0B2_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m36A1726D1A64DBFB0EB4E109963BC1C38DA7C2DA_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0;
		L_0 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline((&___0_keyValuePair), NULL);
		Il2CppSharedGenericObject* L_1;
		L_1 = KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_mCDA4ABDA01342BBEBFBF15C806D85D07A0FEE307_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0;
		L_0 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_mEB4DBA68128DB3538B6D92415D213E3836A0DB00_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0;
		L_0 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_9;
		L_9 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m38590317DE74DBE8D92F2CBEF07EB2166FD77F8A(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m3D9BEEAC0D4BEFD3F54006312EC7895EA1BD7A63_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_m08A93A4677DE0106AF8187A341C674A783136F9E_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppSharedGenericObject* V_2 = NULL;
	int32_t V_3 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_0 = __this->____entries;
		V_0 = L_0;
		Il2CppSharedGenericObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_0049;
		}
	}
	{
		V_1 = 0;
		goto IL_003b;
	}

IL_0013:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_2 = V_0;
		int32_t L_3 = V_1;
		int32_t L_4 = ((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_5 = V_0;
		int32_t L_6 = V_1;
		Il2CppSharedGenericObject* L_7 = ((L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		if (L_7)
		{
			goto IL_0037;
		}
	}
	{
		return (bool)1;
	}

IL_0037:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_003b:
	{
		int32_t L_9 = V_1;
		int32_t L_10 = __this->____count;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0013;
		}
	}
	{
		goto IL_00db;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_11 = V_2;
		if (!L_11)
		{
			goto IL_0096;
		}
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_12 = V_0;
		int32_t L_13 = V_3;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_15;
		L_15 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_16 = V_0;
		int32_t L_17 = V_3;
		Il2CppSharedGenericObject* L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		Il2CppSharedGenericObject* L_19 = ___0_value;
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_21 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_008b:
	{
		int32_t L_22 = V_3;
		int32_t L_23 = __this->____count;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_0096:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_24;
		L_24 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		V_4 = L_24;
		V_5 = 0;
		goto IL_00d1;
	}

IL_00a2:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_25 = V_0;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		if ((((int32_t)L_27) < ((int32_t)0)))
		{
			goto IL_00cb;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_28 = V_4;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_29 = V_0;
		int32_t L_30 = V_5;
		Il2CppSharedGenericObject* L_31 = ((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___value;
		Il2CppSharedGenericObject* L_32 = ___0_value;
		bool L_33;
		L_33 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_28, L_31, L_32);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		return (bool)1;
	}

IL_00cb:
	{
		int32_t L_34 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00d1:
	{
		int32_t L_35 = V_5;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_00a2;
		}
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_mE694E1EB3DC6921BA682AB491035440877A5024C(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_16 = V_1;
		int32_t L_17 = V_2;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_19 = V_1;
		int32_t L_20 = V_2;
		Il2CppSharedGenericObject* L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_m0D4121FAC5AC308F9F11677446270359EE7F187F((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF Dictionary_2_GetEnumerator_mE94C147615A97349C2423579A3A5D9B9CC3BD37A_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_mCCB91D0539BEA0FD63F7A0E7B337FAEBFB9825E1_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E((&L_0), __this, 2, NULL);
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_m6A625FAB57C6DB605126EBCAF4F286C86EEA05CE_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_6;
		L_6 = EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, (RuntimeObject*)G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_mE694E1EB3DC6921BA682AB491035440877A5024C(__this, NULL);
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_15 = (KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F*)(KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_16 = V_0;
		Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A V_6;
	memset((&V_6), 0, sizeof(V_6));
	EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_21;
		L_21 = EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_22 = V_2;
		int32_t L_23 = V_0;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_51 = V_2;
		int32_t L_52 = V_0;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_5 = (EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3*)(EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* V_10 = NULL;
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A V_11;
	memset((&V_11), 0, sizeof(V_11));
	EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_26;
		L_26 = EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_27 = V_0;
		int32_t L_28 = V_5;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_33 = V_0;
		int32_t L_34 = V_5;
		Il2CppSharedGenericObject* L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value), (void*)L_35);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_37 = ___0_key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_55 = V_0;
		int32_t L_56 = V_5;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_61 = V_0;
		int32_t L_62 = V_5;
		Il2CppSharedGenericObject* L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)(&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value), (void*)L_63);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_65 = ___0_key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_mECA349A5C568918987B1E5F01CF437B826B24473(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_101 = V_10;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_102 = ___0_key;
		L_101->___key = L_102;
		Il2CppCodeGenWriteBarrier((void**)&(((&L_101->___key))->___Item1), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&L_101->___key))->___Item2), (void*)NULL);
		#endif
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_103 = V_10;
		Il2CppSharedGenericObject* L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)(&L_103->___value), (void*)L_104);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_mCBBB6C49A72A1E855D48008CB4ECB7FBC97D70D6_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, (RuntimeObject*)__this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_19 = V_3;
		int32_t L_20 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_21;
		L_21 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_22 = V_3;
		int32_t L_23 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_24;
		L_24 = KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_25 = V_3;
		int32_t L_26 = V_4;
		Il2CppSharedGenericObject* L_27;
		L_27 = KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_m76898227E21B42ADA9F5DB5A6366CE107CE1E940(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, (RuntimeObject*)__this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mECA349A5C568918987B1E5F01CF437B826B24473_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_m89E3D5532F34F27BEB5DF28BB40F3558ECDF3728(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m89E3D5532F34F27BEB5DF28BB40F3558ECDF3728_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_1 = NULL;
	int32_t V_2 = 0;
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_3 = (EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3*)(EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_5 = __this->____entries;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A));
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_15 = V_1;
		int32_t L_16 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* L_17 = (ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7(L_17, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m38590317DE74DBE8D92F2CBEF07EB2166FD77F8A_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_21;
		L_21 = EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_22 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_23 = L_22->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_26 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_27 = L_26->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
	}
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_42 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* L_43 = (ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*)(&L_42->___key);
		il2cpp_codegen_initobj(L_43, sizeof(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A));
	}

IL_00ff:
	{
	}
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_44 = V_4;
		Il2CppSharedGenericObject** L_45 = (Il2CppSharedGenericObject**)(&L_44->___value);
		il2cpp_codegen_initobj(L_45, sizeof(Il2CppSharedGenericObject*));
	}

IL_0113:
	{
		int32_t L_46 = V_3;
		__this->____freeList = L_46;
		int32_t L_47 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_47, 1));
		int32_t L_48 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_48, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_49 = V_3;
		V_2 = L_49;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_50 = V_4;
		int32_t L_51 = L_50->___next;
		V_3 = L_51;
	}

IL_0142:
	{
		int32_t L_52 = V_3;
		if ((((int32_t)L_52) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m2F8BE2685E916E74DF6889F2CFC623C4091315BD_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = ValueTuple_2_GetHashCode_m99568F302DE6AD3E15E0EA2EC480BD67D049F1D7((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_21;
		L_21 = EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_22 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_23 = L_22->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_26 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_27 = L_26->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Il2CppSharedGenericObject** L_39 = ___1_value;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_40 = V_4;
		Il2CppSharedGenericObject* L_41 = L_40->___value;
		*(Il2CppSharedGenericObject**)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_39, (void*)L_41);
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
	}
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_45 = V_4;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A* L_46 = (ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*)(&L_45->___key);
		il2cpp_codegen_initobj(L_46, sizeof(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A));
	}

IL_010c:
	{
	}
	{
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_47 = V_4;
		Il2CppSharedGenericObject** L_48 = (Il2CppSharedGenericObject**)(&L_47->___value);
		il2cpp_codegen_initobj(L_48, sizeof(Il2CppSharedGenericObject*));
	}

IL_0120:
	{
		int32_t L_49 = V_3;
		__this->____freeList = L_49;
		int32_t L_50 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_50, 1));
		int32_t L_51 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_51, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_52 = V_3;
		V_2 = L_52;
		Entry_tE1E58729B91F813087891EA78F6ED04BC6F84B14* L_53 = V_4;
		int32_t L_54 = L_53->___next;
		V_3 = L_54;
	}

IL_014f:
	{
		int32_t L_55 = V_3;
		if ((((int32_t)L_55) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Il2CppSharedGenericObject** L_56 = ___1_value;
		il2cpp_codegen_initobj(L_56, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m544B10FFDD54BB3DB13B9CEEFEF9C9A89B85A4DB_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m5EE6BB86A74B61BA4F43F7FCD7A19396DDA1DEB6(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Il2CppSharedGenericObject** L_3 = ___1_value;
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Il2CppSharedGenericObject**)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)L_6);
		return (bool)1;
	}

IL_0025:
	{
		Il2CppSharedGenericObject** L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_m31A536EBEE4B544593F612F05A5CE8D8A9F8BBBF_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m80FCA7D16C6C7009BA59F2ABAA24CF6394A0F865(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_mC110421C30B569259BF43D5F07B7BA084EB04D18_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_m3331B0EDDA7E98A34425B81A329F50D136FFC044_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_mE694E1EB3DC6921BA682AB491035440877A5024C(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_t4208D2E1B4635D7EA4C927172F54BAD9776A760F* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_mF0207C12B681D9CD010A20E3C7FEBDCE5EEC46EA(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_25 = V_2;
		int32_t L_26 = V_3;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_30 = V_2;
		int32_t L_31 = V_3;
		Il2CppSharedGenericObject* L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_33;
		memset((&L_33), 0, sizeof(L_33));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_33), L_29, (RuntimeObject*)L_32, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_33);
	}

IL_00b5:
	{
		int32_t L_34 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b9:
	{
		int32_t L_35 = V_3;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_37 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_37, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = V_4;
		if (L_38)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_39 = __this->____count;
			V_5 = L_39;
			EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_40 = __this->____entries;
			V_6 = L_40;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_41 = V_6;
			int32_t L_42 = V_7;
			int32_t L_43 = ((L_41)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_42)))->___hashCode;
			if ((((int32_t)L_43) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_44 = V_4;
			int32_t L_45 = ___1_index;
			int32_t L_46 = L_45;
			___1_index = ((int32_t)il2cpp_codegen_add(L_46, 1));
			EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_47 = V_6;
			int32_t L_48 = V_7;
			ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_49 = ((L_47)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_48)))->___key;
			EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_50 = V_6;
			int32_t L_51 = V_7;
			Il2CppSharedGenericObject* L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___value;
			KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 L_53;
			memset((&L_53), 0, sizeof(L_53));
			KeyValuePair_2__ctor_m0D4121FAC5AC308F9F11677446270359EE7F187F((&L_53), L_49, L_52, NULL);
			KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295 L_54 = L_53;
			RuntimeObject* L_55 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_54);
			ArrayElementTypeCheck (L_44, L_55);
			(L_44)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_46), (RuntimeObject*)L_55);
		}

IL_012a_1:
		{
			int32_t L_56 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_56, 1));
		}

IL_0130_1:
		{
			int32_t L_57 = V_7;
			int32_t L_58 = V_5;
			if ((((int32_t)L_57) < ((int32_t)L_58)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_59 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m0E09940D27D94EDDCFF470810EC0D0A114E226D1_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E((&L_0), __this, 2, NULL);
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_m6CC01D6F08A4B3391BCE3715088D08CB44B7FC0F_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_t2CF41CF5E2621F7EFD1220745F530C0B5DC797C3* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_m9694FF4B4E2C144DCEF2FCE1F3082855262A7256(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_m89E3D5532F34F27BEB5DF28BB40F3558ECDF3728(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_m610E6007B2B296B398434104EAEB9F9F153AF5DB_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A V_0;
	memset((&V_0), 0, sizeof(V_0));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_mB372B26FF800DAB8A056AC36CEF56999C6B8C0B2(__this, L_3, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_mC6F17349CADE66B7F72E1242F3A1ADA2CFBA6021_gshared (Dictionary_2_t6EE05E1DBF257B416E0A3B6FE8BF1C1F55C8C13B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m61E3631AF88B2F19F5C1DD6448CB0F8E7DD2118E((&L_0), __this, 1, NULL);
		Enumerator_t2192A20535292BE4B74B395AB95FBE0E90FF51DF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5C96FD77BE99497A7E54C6230E41959030E607A4_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m1AF2FE90D9DD9D693B99B74CDC4935CA972ECD7C_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mAE587446CB22990BE3D88C5276B4D8C4AB38E6C3_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_5;
		L_5 = EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m0BBACC79A6257D56E9A512758BDAB39209B1352B_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_mAD75EF58F66B595F8D3901C3452232FC94062088(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mAD75EF58F66B595F8D3901C3452232FC94062088_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* G_B2_0 = NULL;
	Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), (RuntimeObject*)L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_m18A30ACAED5ED63080749BA1C8B6DDAC6B36C3EE(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* L_9 = ((Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_15 = V_1;
		int32_t L_16 = V_2;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_18 = V_1;
		int32_t L_19 = V_2;
		Il2CppSharedGenericObject* L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), (RuntimeObject*)L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_30;
				L_30 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline((&V_4), NULL);
				Il2CppSharedGenericObject* L_31;
				L_31 = KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_inline((&V_4), NULL);
				Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C* Dictionary_2_get_Keys_mB891254A1B6A6791387BC11637DE57B8C898FE7C_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C* L_1 = (KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_mD5E79842FA5F42C6B3E458407CA711BDAAB1FE69(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_tFB65BE5C0E6B6C8D1CB0CCA25F056AA72F66D37C* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96* Dictionary_2_get_Values_m357BBB623B919A08A8CADA535288272258A9BEC4_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96* L_1 = (ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_m7782EC432C8B7591F78A35C56024E8E21C78A345(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_t850579E5C2FF909D1C3606EC46C87F0FADFEDB96* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Dictionary_2_get_Item_m65968339FBA4115BF0BB1C10D8B6117085315C45_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_6 = ___0_key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m50080FF99F5F609F7C6D4A916D1A4264AB88BCC5_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m30681F352B63FA36D2AE605D5DC58BFF543421BE_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0;
		L_0 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline((&___0_keyValuePair), NULL);
		Il2CppSharedGenericObject* L_1;
		L_1 = KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m78DB65587BADCAB9417C6D8BDC27071931CBED83_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0;
		L_0 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m61AEF7D244D9C0A1F70618EE0F47ADF21CD291B4_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0;
		L_0 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_9;
		L_9 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m86A5B73912916A5825210A61600309B0CEBE7022(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_mF1F5EAAC106826831EF6763729D6C06F730FCC77_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_m2AF961FE749C46EFD7FB3E2C8E75525BA2F4D434_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppSharedGenericObject* V_2 = NULL;
	int32_t V_3 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_0 = __this->____entries;
		V_0 = L_0;
		Il2CppSharedGenericObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_0049;
		}
	}
	{
		V_1 = 0;
		goto IL_003b;
	}

IL_0013:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_2 = V_0;
		int32_t L_3 = V_1;
		int32_t L_4 = ((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_5 = V_0;
		int32_t L_6 = V_1;
		Il2CppSharedGenericObject* L_7 = ((L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		if (L_7)
		{
			goto IL_0037;
		}
	}
	{
		return (bool)1;
	}

IL_0037:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_003b:
	{
		int32_t L_9 = V_1;
		int32_t L_10 = __this->____count;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0013;
		}
	}
	{
		goto IL_00db;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_11 = V_2;
		if (!L_11)
		{
			goto IL_0096;
		}
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_12 = V_0;
		int32_t L_13 = V_3;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_15;
		L_15 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_16 = V_0;
		int32_t L_17 = V_3;
		Il2CppSharedGenericObject* L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		Il2CppSharedGenericObject* L_19 = ___0_value;
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_21 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_008b:
	{
		int32_t L_22 = V_3;
		int32_t L_23 = __this->____count;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_0096:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_24;
		L_24 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		V_4 = L_24;
		V_5 = 0;
		goto IL_00d1;
	}

IL_00a2:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_25 = V_0;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		if ((((int32_t)L_27) < ((int32_t)0)))
		{
			goto IL_00cb;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_28 = V_4;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_29 = V_0;
		int32_t L_30 = V_5;
		Il2CppSharedGenericObject* L_31 = ((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___value;
		Il2CppSharedGenericObject* L_32 = ___0_value;
		bool L_33;
		L_33 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_28, L_31, L_32);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		return (bool)1;
	}

IL_00cb:
	{
		int32_t L_34 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00d1:
	{
		int32_t L_35 = V_5;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_00a2;
		}
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_m889AEFA656A4A6AB38DC123246E8BEC33647F2BB(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_16 = V_1;
		int32_t L_17 = V_2;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_19 = V_1;
		int32_t L_20 = V_2;
		Il2CppSharedGenericObject* L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_mD0CA78640E4E9AEDF3F7B13285742812AD9D3F93((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF Dictionary_2_GetEnumerator_m54D4A1E66302F1BEBCFB8C0B2FC06A5C8813D490_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m438F264A33351AD7D356691BB7136AE09C98CD6F_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8((&L_0), __this, 2, NULL);
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_m8781D518EA932B0B78BD8C9C45C7632FA09FF54F_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_6;
		L_6 = EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, (RuntimeObject*)G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_m889AEFA656A4A6AB38DC123246E8BEC33647F2BB(__this, NULL);
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_15 = (KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A*)(KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_16 = V_0;
		Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A V_6;
	memset((&V_6), 0, sizeof(V_6));
	EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_21;
		L_21 = EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_22 = V_2;
		int32_t L_23 = V_0;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_51 = V_2;
		int32_t L_52 = V_0;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_5 = (EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0*)(EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* V_10 = NULL;
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A V_11;
	memset((&V_11), 0, sizeof(V_11));
	EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_26;
		L_26 = EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_27 = V_0;
		int32_t L_28 = V_5;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_33 = V_0;
		int32_t L_34 = V_5;
		Il2CppSharedGenericObject* L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value), (void*)L_35);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_37 = ___0_key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_55 = V_0;
		int32_t L_56 = V_5;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_61 = V_0;
		int32_t L_62 = V_5;
		Il2CppSharedGenericObject* L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)(&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value), (void*)L_63);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_65 = ___0_key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_m2B49E5B27DE63B7B42984CEC07EAE9D3119B80F7(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_101 = V_10;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_102 = ___0_key;
		L_101->___key = L_102;
		Il2CppCodeGenWriteBarrier((void**)&(((&L_101->___key))->___Item1), (void*)NULL);
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_103 = V_10;
		Il2CppSharedGenericObject* L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)(&L_103->___value), (void*)L_104);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_mA752F2F2B61278E1E74F701743FB807C3966CAB3_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, (RuntimeObject*)__this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_19 = V_3;
		int32_t L_20 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_21;
		L_21 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_22 = V_3;
		int32_t L_23 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_24;
		L_24 = KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_25 = V_3;
		int32_t L_26 = V_4;
		Il2CppSharedGenericObject* L_27;
		L_27 = KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_mB472F849E1EC334185C8660C50A557237F0BE164(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, (RuntimeObject*)__this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m2B49E5B27DE63B7B42984CEC07EAE9D3119B80F7_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_m7D9EC0F043E0B9FAB07F7AE3EA84667BFA73B967(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m7D9EC0F043E0B9FAB07F7AE3EA84667BFA73B967_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_1 = NULL;
	int32_t V_2 = 0;
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_3 = (EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0*)(EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_5 = __this->____entries;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A));
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_15 = V_1;
		int32_t L_16 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* L_17 = (ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404(L_17, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m86A5B73912916A5825210A61600309B0CEBE7022_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_21;
		L_21 = EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_22 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_23 = L_22->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_26 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_27 = L_26->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
	}
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_42 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* L_43 = (ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*)(&L_42->___key);
		il2cpp_codegen_initobj(L_43, sizeof(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A));
	}

IL_00ff:
	{
	}
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_44 = V_4;
		Il2CppSharedGenericObject** L_45 = (Il2CppSharedGenericObject**)(&L_44->___value);
		il2cpp_codegen_initobj(L_45, sizeof(Il2CppSharedGenericObject*));
	}

IL_0113:
	{
		int32_t L_46 = V_3;
		__this->____freeList = L_46;
		int32_t L_47 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_47, 1));
		int32_t L_48 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_48, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_49 = V_3;
		V_2 = L_49;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_50 = V_4;
		int32_t L_51 = L_50->___next;
		V_3 = L_51;
	}

IL_0142:
	{
		int32_t L_52 = V_3;
		if ((((int32_t)L_52) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m2719CA011E1E8F2CBB92D0BE553FCE6970E9E63B_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = ValueTuple_2_GetHashCode_mF359FEBDF1FA01E57B2160C5F106BFC25DAC0404((&___0_key), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_21;
		L_21 = EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_22 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_23 = L_22->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_26 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_27 = L_26->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Il2CppSharedGenericObject** L_39 = ___1_value;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_40 = V_4;
		Il2CppSharedGenericObject* L_41 = L_40->___value;
		*(Il2CppSharedGenericObject**)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_39, (void*)L_41);
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
	}
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_45 = V_4;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A* L_46 = (ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*)(&L_45->___key);
		il2cpp_codegen_initobj(L_46, sizeof(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A));
	}

IL_010c:
	{
	}
	{
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_47 = V_4;
		Il2CppSharedGenericObject** L_48 = (Il2CppSharedGenericObject**)(&L_47->___value);
		il2cpp_codegen_initobj(L_48, sizeof(Il2CppSharedGenericObject*));
	}

IL_0120:
	{
		int32_t L_49 = V_3;
		__this->____freeList = L_49;
		int32_t L_50 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_50, 1));
		int32_t L_51 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_51, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_52 = V_3;
		V_2 = L_52;
		Entry_t833BE0585D8B6A240162BBCD9DE7A05889C81254* L_53 = V_4;
		int32_t L_54 = L_53->___next;
		V_3 = L_54;
	}

IL_014f:
	{
		int32_t L_55 = V_3;
		if ((((int32_t)L_55) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Il2CppSharedGenericObject** L_56 = ___1_value;
		il2cpp_codegen_initobj(L_56, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mDBE5311D34FDF95AF0D6ED8F04E8D7CFE23B6D23_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF40EED5EF900EB145AFD21B959058FC4F3CFD3C7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Il2CppSharedGenericObject** L_3 = ___1_value;
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Il2CppSharedGenericObject**)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)L_6);
		return (bool)1;
	}

IL_0025:
	{
		Il2CppSharedGenericObject** L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_m401A4F54A243ABD0325F58FAC4555131C960419C_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m215840BF1C032E1A9D5056DB815A0F7E761F38FC(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m079F564A61DDEE2C2D4E633C8B7F2D9D51E20606_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_mB8CADFD47399FA30DB86B69EF77618BB9E7206F5_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_m889AEFA656A4A6AB38DC123246E8BEC33647F2BB(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_t9F59B28C21BBB1C41719D5BDFC79702EFA03FC3A* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_mD9B70A6E4EDB4E0CAB6CD3A7C94AB74BEF08CF66(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_25 = V_2;
		int32_t L_26 = V_3;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_30 = V_2;
		int32_t L_31 = V_3;
		Il2CppSharedGenericObject* L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_33;
		memset((&L_33), 0, sizeof(L_33));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_33), L_29, (RuntimeObject*)L_32, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_33);
	}

IL_00b5:
	{
		int32_t L_34 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b9:
	{
		int32_t L_35 = V_3;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_37 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_37, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = V_4;
		if (L_38)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_39 = __this->____count;
			V_5 = L_39;
			EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_40 = __this->____entries;
			V_6 = L_40;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_41 = V_6;
			int32_t L_42 = V_7;
			int32_t L_43 = ((L_41)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_42)))->___hashCode;
			if ((((int32_t)L_43) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_44 = V_4;
			int32_t L_45 = ___1_index;
			int32_t L_46 = L_45;
			___1_index = ((int32_t)il2cpp_codegen_add(L_46, 1));
			EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_47 = V_6;
			int32_t L_48 = V_7;
			ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_49 = ((L_47)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_48)))->___key;
			EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_50 = V_6;
			int32_t L_51 = V_7;
			Il2CppSharedGenericObject* L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___value;
			KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 L_53;
			memset((&L_53), 0, sizeof(L_53));
			KeyValuePair_2__ctor_mD0CA78640E4E9AEDF3F7B13285742812AD9D3F93((&L_53), L_49, L_52, NULL);
			KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2 L_54 = L_53;
			RuntimeObject* L_55 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_54);
			ArrayElementTypeCheck (L_44, L_55);
			(L_44)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_46), (RuntimeObject*)L_55);
		}

IL_012a_1:
		{
			int32_t L_56 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_56, 1));
		}

IL_0130_1:
		{
			int32_t L_57 = V_7;
			int32_t L_58 = V_5;
			if ((((int32_t)L_57) < ((int32_t)L_58)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_59 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m661C31792617A73375B49EF25DFAA3CD1997A3CB_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8((&L_0), __this, 2, NULL);
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_m25588CDDB6FCE4088A12E4FA7A48812B8FA21589_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_tD168B9758081967AE421A2B6D72D8EBDC95FC1E0* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_mD6E490F5E2D02CB8B433925CF5DAE535CBA6F8CF(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_m7D9EC0F043E0B9FAB07F7AE3EA84667BFA73B967(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_m078EF951722EFA64543A568CAEA122EBE0DEE3D7_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A V_0;
	memset((&V_0), 0, sizeof(V_0));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_m50080FF99F5F609F7C6D4A916D1A4264AB88BCC5(__this, L_3, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_m90DAB44691EDFBA25E3E472018B053435DA7FCD0_gshared (Dictionary_2_tAC56BFFAB0D6C547AD119E1707252267F9C0C49A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0EF0E488E739D3719F9EB825293E138DA7DF2CA8((&L_0), __this, 1, NULL);
		Enumerator_t3C7F7AA223D7FD8BC46DAE355A8719EAB17A9EDF L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mAED8CDB89C85F3A8161EF7FEBFA27BBBBC1583C2_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m973EC7603C3FDE98E046A2C6554CA5FAC97BB1FF_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m064A8264F943DBBAC13C529623AB1904DF2B6399_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_5;
		L_5 = EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m4DEA1B8CB215692D40CABFBD55CFBBB1F138FBFE_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_mFE8D024D7FA568AAB39FCF6DAF344F43EE1F4A43(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mFE8D024D7FA568AAB39FCF6DAF344F43EE1F4A43_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* G_B2_0 = NULL;
	Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), (RuntimeObject*)L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_mBE9E061358F2E6A91E9915CEFD2879A13D028050(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* L_9 = ((Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_15 = V_1;
		int32_t L_16 = V_2;
		Guid_t L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_18 = V_1;
		int32_t L_19 = V_2;
		Il2CppSharedGenericObject* L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), (RuntimeObject*)L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				Guid_t L_30;
				L_30 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline((&V_4), NULL);
				Il2CppSharedGenericObject* L_31;
				L_31 = KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_inline((&V_4), NULL);
				Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE* Dictionary_2_get_Keys_mFC9AADC3C1C00FBE73A7B0AC6F8BC262E2469703_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE* L_1 = (KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_m1DD9728163AEE8DECB0FD6CC40DDEB6E3B419E04(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_tABC0767E4C9CAC395DC791123D07816845B5F3FE* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32* Dictionary_2_get_Values_m668F75FF60F59F3624BAB4938DA51B500B81D491_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32* L_1 = (ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_m16305A7173A73FFD4F82FAC103C980A99266B7E2(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_t6E5730979611F4C4C82E15329EA4E3C265DFED32* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Dictionary_2_get_Item_mEA3BFFB2296A12A45164153B3D86B6DB928B7A93_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		Guid_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		Guid_t L_6 = ___0_key;
		Guid_t L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m93D471C69BDF1EE119D28B69BFACB3B4C6E1B9C5_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		Guid_t L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		Guid_t L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m0CBC134BCF5E1C9FB01257E2F3834A91F5F3CAC4_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		Guid_t L_0;
		L_0 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline((&___0_keyValuePair), NULL);
		Il2CppSharedGenericObject* L_1;
		L_1 = KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m4309834032BDE6E1B7ED6C2FB9AE7F13647BD967_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Guid_t L_0;
		L_0 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m7C32F0809AD3AFB57C16582AEC83B382EA3750F0_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Guid_t L_0;
		L_0 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		Guid_t L_9;
		L_9 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m2BD0E6825D66721033A14ABB6F727A8D1C8E0628(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_mAF7D6813B74981E1659BF29AEDEFBEF99CC34A62_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method) 
{
	{
		Guid_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_m551DC69C4B2FFF7E3AE8DC22086AE971FC3FC4B3_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppSharedGenericObject* V_2 = NULL;
	int32_t V_3 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_0 = __this->____entries;
		V_0 = L_0;
		Il2CppSharedGenericObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_0049;
		}
	}
	{
		V_1 = 0;
		goto IL_003b;
	}

IL_0013:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_2 = V_0;
		int32_t L_3 = V_1;
		int32_t L_4 = ((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_5 = V_0;
		int32_t L_6 = V_1;
		Il2CppSharedGenericObject* L_7 = ((L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		if (L_7)
		{
			goto IL_0037;
		}
	}
	{
		return (bool)1;
	}

IL_0037:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_003b:
	{
		int32_t L_9 = V_1;
		int32_t L_10 = __this->____count;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0013;
		}
	}
	{
		goto IL_00db;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_11 = V_2;
		if (!L_11)
		{
			goto IL_0096;
		}
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_12 = V_0;
		int32_t L_13 = V_3;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_15;
		L_15 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_16 = V_0;
		int32_t L_17 = V_3;
		Il2CppSharedGenericObject* L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		Il2CppSharedGenericObject* L_19 = ___0_value;
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_21 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_008b:
	{
		int32_t L_22 = V_3;
		int32_t L_23 = __this->____count;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_0096:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_24;
		L_24 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		V_4 = L_24;
		V_5 = 0;
		goto IL_00d1;
	}

IL_00a2:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_25 = V_0;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		if ((((int32_t)L_27) < ((int32_t)0)))
		{
			goto IL_00cb;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_28 = V_4;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_29 = V_0;
		int32_t L_30 = V_5;
		Il2CppSharedGenericObject* L_31 = ((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___value;
		Il2CppSharedGenericObject* L_32 = ___0_value;
		bool L_33;
		L_33 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_28, L_31, L_32);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		return (bool)1;
	}

IL_00cb:
	{
		int32_t L_34 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00d1:
	{
		int32_t L_35 = V_5;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_00a2;
		}
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_m62CB7B656456CFDD5DC73F6ECAA5BAF24EFBA62C(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_16 = V_1;
		int32_t L_17 = V_2;
		Guid_t L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_19 = V_1;
		int32_t L_20 = V_2;
		Il2CppSharedGenericObject* L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_mAADB86C56A6064707D6B414C20886941E280A8C8((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A Dictionary_2_GetEnumerator_mC56D8EEA1FC332C55A4D6F293A4790AFE1E7ECAB_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m27799B667A88624121FEA2ACDA3E6DCD84385244_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D((&L_0), __this, 2, NULL);
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_mEA944741AD9C0C4D3F8EE5DF611D9B261AC5D003_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_6;
		L_6 = EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_m62CB7B656456CFDD5DC73F6ECAA5BAF24EFBA62C(__this, NULL);
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_15 = (KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856*)(KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_16 = V_0;
		Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	Guid_t V_6;
	memset((&V_6), 0, sizeof(V_6));
	EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = Guid_GetHashCode_m239B7679BB9ED5A207B3D2F858B5F30FFC455408((&___0_key), NULL);
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(Guid_t));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_21;
		L_21 = EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_22 = V_2;
		int32_t L_23 = V_0;
		Guid_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		Guid_t L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		Guid_t L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, Guid_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_51 = V_2;
		int32_t L_52 = V_0;
		Guid_t L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		Guid_t L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_5 = (EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3*)(EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* V_10 = NULL;
	Guid_t V_11;
	memset((&V_11), 0, sizeof(V_11));
	EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		Guid_t L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, Guid_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = Guid_GetHashCode_m239B7679BB9ED5A207B3D2F858B5F30FFC455408((&___0_key), NULL);
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Guid_t));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_26;
		L_26 = EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_27 = V_0;
		int32_t L_28 = V_5;
		Guid_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		Guid_t L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_33 = V_0;
		int32_t L_34 = V_5;
		Il2CppSharedGenericObject* L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value), (void*)L_35);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		Guid_t L_37 = ___0_key;
		Guid_t L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_55 = V_0;
		int32_t L_56 = V_5;
		Guid_t L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		Guid_t L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_61 = V_0;
		int32_t L_62 = V_5;
		Il2CppSharedGenericObject* L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)(&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value), (void*)L_63);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		Guid_t L_65 = ___0_key;
		Guid_t L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_m4B80FC5F8BA8BAE74E0EAB023D785DFDA03A7F6A(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_101 = V_10;
		Guid_t L_102 = ___0_key;
		L_101->___key = L_102;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_103 = V_10;
		Il2CppSharedGenericObject* L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)(&L_103->___value), (void*)L_104);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_m6A54BE936068A38475485E8D84EDC69AC6A008B9_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, (RuntimeObject*)__this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_19 = V_3;
		int32_t L_20 = V_4;
		Guid_t L_21;
		L_21 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_22 = V_3;
		int32_t L_23 = V_4;
		Guid_t L_24;
		L_24 = KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_25 = V_3;
		int32_t L_26 = V_4;
		Il2CppSharedGenericObject* L_27;
		L_27 = KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_m12D2FABDF928772CD0B0C28D389D86E688E4F4CB(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, (RuntimeObject*)__this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m4B80FC5F8BA8BAE74E0EAB023D785DFDA03A7F6A_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_mADA0004999558ADFD7386840DF35CAA07E676568(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mADA0004999558ADFD7386840DF35CAA07E676568_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_1 = NULL;
	int32_t V_2 = 0;
	Guid_t V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_3 = (EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3*)(EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_5 = __this->____entries;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(Guid_t));
		Guid_t L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_15 = V_1;
		int32_t L_16 = V_4;
		Guid_t* L_17 = (Guid_t*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = Guid_GetHashCode_m239B7679BB9ED5A207B3D2F858B5F30FFC455408(L_17, NULL);
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m2BD0E6825D66721033A14ABB6F727A8D1C8E0628_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = Guid_GetHashCode_m239B7679BB9ED5A207B3D2F858B5F30FFC455408((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		Guid_t L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, Guid_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_21;
		L_21 = EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_22 = V_4;
		Guid_t L_23 = L_22->___key;
		Guid_t L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_26 = V_4;
		Guid_t L_27 = L_26->___key;
		Guid_t L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
		goto IL_00ff;
	}

IL_00ff:
	{
	}
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_42 = V_4;
		Il2CppSharedGenericObject** L_43 = (Il2CppSharedGenericObject**)(&L_42->___value);
		il2cpp_codegen_initobj(L_43, sizeof(Il2CppSharedGenericObject*));
	}

IL_0113:
	{
		int32_t L_44 = V_3;
		__this->____freeList = L_44;
		int32_t L_45 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_46, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_47 = V_3;
		V_2 = L_47;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_48 = V_4;
		int32_t L_49 = L_48->___next;
		V_3 = L_49;
	}

IL_0142:
	{
		int32_t L_50 = V_3;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m6CA8C95085FAB19088435E4FB24516A35AB75C3E_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = Guid_GetHashCode_m239B7679BB9ED5A207B3D2F858B5F30FFC455408((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		Guid_t L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, Guid_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_21;
		L_21 = EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_22 = V_4;
		Guid_t L_23 = L_22->___key;
		Guid_t L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_26 = V_4;
		Guid_t L_27 = L_26->___key;
		Guid_t L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, Guid_t, Guid_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Il2CppSharedGenericObject** L_39 = ___1_value;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_40 = V_4;
		Il2CppSharedGenericObject* L_41 = L_40->___value;
		*(Il2CppSharedGenericObject**)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_39, (void*)L_41);
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
		goto IL_010c;
	}

IL_010c:
	{
	}
	{
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_45 = V_4;
		Il2CppSharedGenericObject** L_46 = (Il2CppSharedGenericObject**)(&L_45->___value);
		il2cpp_codegen_initobj(L_46, sizeof(Il2CppSharedGenericObject*));
	}

IL_0120:
	{
		int32_t L_47 = V_3;
		__this->____freeList = L_47;
		int32_t L_48 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_50 = V_3;
		V_2 = L_50;
		Entry_t385D55B7BB5A3AD762B8087CBDA8389D3818AF28* L_51 = V_4;
		int32_t L_52 = L_51->___next;
		V_3 = L_52;
	}

IL_014f:
	{
		int32_t L_53 = V_3;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Il2CppSharedGenericObject** L_54 = ___1_value;
		il2cpp_codegen_initobj(L_54, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m198483A968CEBE45C4EE5A7E372ECF0085087FEA_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Guid_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_m9F77A9A1350FCE78B97CC693F9F5444E8F3E645D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Il2CppSharedGenericObject** L_3 = ___1_value;
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Il2CppSharedGenericObject**)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)L_6);
		return (bool)1;
	}

IL_0025:
	{
		Il2CppSharedGenericObject** L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_mEAF6BFC11AD4EA79E3B5884F495CDD32FB9CF30F_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, Guid_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		Guid_t L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m7AC671B331F6CD67E04ADA8CD9174C90AB75E18D(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m22E850641682AB81F24550AAFBBE396B1B7834F8_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_mD44BA3E3AD85A0C5AC3BF8F778210F7D0D364EEE_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_m62CB7B656456CFDD5DC73F6ECAA5BAF24EFBA62C(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_t9DF131722D7F3B6C04EF603B3CF8C56E1AF7D856* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_m99C002B6D6FCB05E047BE5D0AE65AC2F6E3ACD60(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_25 = V_2;
		int32_t L_26 = V_3;
		Guid_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		Guid_t L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_30 = V_2;
		int32_t L_31 = V_3;
		Il2CppSharedGenericObject* L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_33;
		memset((&L_33), 0, sizeof(L_33));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_33), L_29, (RuntimeObject*)L_32, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_33);
	}

IL_00b5:
	{
		int32_t L_34 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b9:
	{
		int32_t L_35 = V_3;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_37 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_37, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = V_4;
		if (L_38)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_39 = __this->____count;
			V_5 = L_39;
			EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_40 = __this->____entries;
			V_6 = L_40;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_41 = V_6;
			int32_t L_42 = V_7;
			int32_t L_43 = ((L_41)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_42)))->___hashCode;
			if ((((int32_t)L_43) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_44 = V_4;
			int32_t L_45 = ___1_index;
			int32_t L_46 = L_45;
			___1_index = ((int32_t)il2cpp_codegen_add(L_46, 1));
			EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_47 = V_6;
			int32_t L_48 = V_7;
			Guid_t L_49 = ((L_47)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_48)))->___key;
			EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_50 = V_6;
			int32_t L_51 = V_7;
			Il2CppSharedGenericObject* L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___value;
			KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B L_53;
			memset((&L_53), 0, sizeof(L_53));
			KeyValuePair_2__ctor_mAADB86C56A6064707D6B414C20886941E280A8C8((&L_53), L_49, L_52, NULL);
			KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B L_54 = L_53;
			RuntimeObject* L_55 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_54);
			ArrayElementTypeCheck (L_44, L_55);
			(L_44)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_46), (RuntimeObject*)L_55);
		}

IL_012a_1:
		{
			int32_t L_56 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_56, 1));
		}

IL_0130_1:
		{
			int32_t L_57 = V_7;
			int32_t L_58 = V_5;
			if ((((int32_t)L_57) < ((int32_t)L_58)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_59 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m4A4EA3A132E8979F3B81CAAF5F5BD81AA90C288D_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D((&L_0), __this, 2, NULL);
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_m1D1600A35C5D3B2C1DA9E71568B4A447824E8A80_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_tAAF64BD0D9C29E733318312670F238A6137022E3* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_m4B270DD202530A4EA0CB4EA2C5463BDFAC3289C5(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_mADA0004999558ADFD7386840DF35CAA07E676568(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_mFF7478B8510DCF1152CDCD7A043627DE22F70B89_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	Guid_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(Guid_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			Guid_t L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_m93D471C69BDF1EE119D28B69BFACB3B4C6E1B9C5(__this, L_3, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_mB37B2F2185806AEA57718E87FB357234B01C1440_gshared (Dictionary_2_tACC278C341353EB0D3F5219D25804742C5DDC8A9* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4414214982827D5E3EE390F4EC2D5458C617935D((&L_0), __this, 1, NULL);
		Enumerator_t664339BF0446B4E80F1055BB5C01417CFF320E2A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m543A280CD3F7D7BB017BDEE2AAB95327542DD8A2_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m04FAE139B2E6332A3BEBBE73DA3016AB92D593E9_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mF33FE1C0D1635189B57630DF027C7D1453CC71E1_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_5;
		L_5 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m17A3BE1D07064DC39EF36F6AC49334E6C118634F_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_m0DFAF670559B0FE516624A501EA61CB9B14B7B67(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m0DFAF670559B0FE516624A501EA61CB9B14B7B67_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* G_B2_0 = NULL;
	Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), (RuntimeObject*)L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_m49575A3BC27C2DD83D288B3E374AA0B5BA4C6E4A(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* L_9 = ((Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_15 = V_1;
		int32_t L_16 = V_2;
		int32_t L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_18 = V_1;
		int32_t L_19 = V_2;
		Il2CppSharedGenericObject* L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), (RuntimeObject*)L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				int32_t L_30;
				L_30 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline((&V_4), NULL);
				Il2CppSharedGenericObject* L_31;
				L_31 = KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_inline((&V_4), NULL);
				Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C* Dictionary_2_get_Keys_mB1A68E24DD56FC7B3FF43BCA487DCEE79C8916BA_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C* L_1 = (KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_m574C0BEA657118596B91087FCD53CD5206AB8CE1(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_t8A3D2A8A2AEED2DCB735C110440CB590EE84367C* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF* Dictionary_2_get_Values_mE0B10BA7C459A85A1EE51D0C9A9145C5926D35ED_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF* L_1 = (ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_mC5E41CEAC9927A0756C903DA9D06C533F76D1913(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_t20B4A413B40603707CB912BD61898CA43B3C28FF* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Dictionary_2_get_Item_mFC61E83AC43E4FE37E2E32828FC29042E04D1EF6_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		int32_t L_6 = ___0_key;
		int32_t L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m2BB6CF3A683DE145DB22935870F3C63F3E8E3027_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_mCCF5A70EDCB68305B5706C902A58F4BE4C08E3FC_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline((&___0_keyValuePair), NULL);
		Il2CppSharedGenericObject* L_1;
		L_1 = KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m7E1B4E8161E2A838899D6FA7039B84754AE06518_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m67BB7DE87D0BCD87E77A44A9177D952D42996617_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		int32_t L_9;
		L_9 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m07FA12992B3DAD86BD9CD3797525EBC22BE69E15(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m4A4E98C56B428A238653A5D58BD1E9AA00496B6C_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_mB33080F9C7360F65D9F081C33D51BB5EB95E14FA_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppSharedGenericObject* V_2 = NULL;
	int32_t V_3 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_0 = __this->____entries;
		V_0 = L_0;
		Il2CppSharedGenericObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_0049;
		}
	}
	{
		V_1 = 0;
		goto IL_003b;
	}

IL_0013:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_2 = V_0;
		int32_t L_3 = V_1;
		int32_t L_4 = ((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_5 = V_0;
		int32_t L_6 = V_1;
		Il2CppSharedGenericObject* L_7 = ((L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		if (L_7)
		{
			goto IL_0037;
		}
	}
	{
		return (bool)1;
	}

IL_0037:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_003b:
	{
		int32_t L_9 = V_1;
		int32_t L_10 = __this->____count;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0013;
		}
	}
	{
		goto IL_00db;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_11 = V_2;
		if (!L_11)
		{
			goto IL_0096;
		}
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_12 = V_0;
		int32_t L_13 = V_3;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_15;
		L_15 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_16 = V_0;
		int32_t L_17 = V_3;
		Il2CppSharedGenericObject* L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		Il2CppSharedGenericObject* L_19 = ___0_value;
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_21 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_008b:
	{
		int32_t L_22 = V_3;
		int32_t L_23 = __this->____count;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_0096:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_24;
		L_24 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		V_4 = L_24;
		V_5 = 0;
		goto IL_00d1;
	}

IL_00a2:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_25 = V_0;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		if ((((int32_t)L_27) < ((int32_t)0)))
		{
			goto IL_00cb;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_28 = V_4;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_29 = V_0;
		int32_t L_30 = V_5;
		Il2CppSharedGenericObject* L_31 = ((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___value;
		Il2CppSharedGenericObject* L_32 = ___0_value;
		bool L_33;
		L_33 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_28, L_31, L_32);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		return (bool)1;
	}

IL_00cb:
	{
		int32_t L_34 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00d1:
	{
		int32_t L_35 = V_5;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_00a2;
		}
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_mCE5BB990E0EB80EB89D6FDF8DB85AF06C991991B(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_16 = V_1;
		int32_t L_17 = V_2;
		int32_t L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_19 = V_1;
		int32_t L_20 = V_2;
		Il2CppSharedGenericObject* L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_mB203F4B742D836457DDC26B3493454EC84369344((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 Dictionary_2_GetEnumerator_mB7F3FCCB0B22E12D5CD0BF11D4255BC0679E534D_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_mEB1F75D535B6A7265EBEF5D7894847AD80744558_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65((&L_0), __this, 2, NULL);
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_m089CED61A675A0A4D2B5789DA01FE496A65E8793_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_6;
		L_6 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_mCE5BB990E0EB80EB89D6FDF8DB85AF06C991991B(__this, NULL);
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_15 = (KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*)(KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_16 = V_0;
		Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&___0_key), NULL);
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(int32_t));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_21;
		L_21 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_22 = V_2;
		int32_t L_23 = V_0;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		int32_t L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		int32_t L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_51 = V_2;
		int32_t L_52 = V_0;
		int32_t L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		int32_t L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_5 = (EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E*)(EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* V_10 = NULL;
	int32_t V_11 = 0;
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		int32_t L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&___0_key), NULL);
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(int32_t));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_26;
		L_26 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_27 = V_0;
		int32_t L_28 = V_5;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		int32_t L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_33 = V_0;
		int32_t L_34 = V_5;
		Il2CppSharedGenericObject* L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value), (void*)L_35);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		int32_t L_37 = ___0_key;
		int32_t L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_55 = V_0;
		int32_t L_56 = V_5;
		int32_t L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		int32_t L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_61 = V_0;
		int32_t L_62 = V_5;
		Il2CppSharedGenericObject* L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)(&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value), (void*)L_63);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		int32_t L_65 = ___0_key;
		int32_t L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_mFFD5EEA58232DF8B073F38D35C39D8CDCB6AD30D(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_101 = V_10;
		int32_t L_102 = ___0_key;
		L_101->___key = L_102;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_103 = V_10;
		Il2CppSharedGenericObject* L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)(&L_103->___value), (void*)L_104);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_mA756283C4F289957E8300CE81D110A10C00B8E83_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, (RuntimeObject*)__this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_19 = V_3;
		int32_t L_20 = V_4;
		int32_t L_21;
		L_21 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_22 = V_3;
		int32_t L_23 = V_4;
		int32_t L_24;
		L_24 = KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_25 = V_3;
		int32_t L_26 = V_4;
		Il2CppSharedGenericObject* L_27;
		L_27 = KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_mB53657B4F779ED11B472769A9ABB51A093A4FF4B(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, (RuntimeObject*)__this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mFFD5EEA58232DF8B073F38D35C39D8CDCB6AD30D_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_m82DAF2EEBEF35C89774A8E71F51F1BD13378620F(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m82DAF2EEBEF35C89774A8E71F51F1BD13378620F_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_3 = (EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E*)(EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_5 = __this->____entries;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(int32_t));
		int32_t L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_15 = V_1;
		int32_t L_16 = V_4;
		int32_t* L_17 = (int32_t*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_17, NULL);
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m07FA12992B3DAD86BD9CD3797525EBC22BE69E15_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		int32_t L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_21;
		L_21 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_22 = V_4;
		int32_t L_23 = L_22->___key;
		int32_t L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_26 = V_4;
		int32_t L_27 = L_26->___key;
		int32_t L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
		goto IL_00ff;
	}

IL_00ff:
	{
	}
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_42 = V_4;
		Il2CppSharedGenericObject** L_43 = (Il2CppSharedGenericObject**)(&L_42->___value);
		il2cpp_codegen_initobj(L_43, sizeof(Il2CppSharedGenericObject*));
	}

IL_0113:
	{
		int32_t L_44 = V_3;
		__this->____freeList = L_44;
		int32_t L_45 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_46, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_47 = V_3;
		V_2 = L_47;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_48 = V_4;
		int32_t L_49 = L_48->___next;
		V_3 = L_49;
	}

IL_0142:
	{
		int32_t L_50 = V_3;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m2398D9D9E0616477152747DF5B2A65875B7C79C9_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		int32_t L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, int32_t >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_21;
		L_21 = EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_22 = V_4;
		int32_t L_23 = L_22->___key;
		int32_t L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, int32_t, int32_t >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_26 = V_4;
		int32_t L_27 = L_26->___key;
		int32_t L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, int32_t, int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Il2CppSharedGenericObject** L_39 = ___1_value;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_40 = V_4;
		Il2CppSharedGenericObject* L_41 = L_40->___value;
		*(Il2CppSharedGenericObject**)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_39, (void*)L_41);
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
		goto IL_010c;
	}

IL_010c:
	{
	}
	{
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_45 = V_4;
		Il2CppSharedGenericObject** L_46 = (Il2CppSharedGenericObject**)(&L_45->___value);
		il2cpp_codegen_initobj(L_46, sizeof(Il2CppSharedGenericObject*));
	}

IL_0120:
	{
		int32_t L_47 = V_3;
		__this->____freeList = L_47;
		int32_t L_48 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_50 = V_3;
		V_2 = L_50;
		Entry_t4D3FDFE59398F64D5B4FFA1D66084EBA0830B286* L_51 = V_4;
		int32_t L_52 = L_51->___next;
		V_3 = L_52;
	}

IL_014f:
	{
		int32_t L_53 = V_3;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Il2CppSharedGenericObject** L_54 = ___1_value;
		il2cpp_codegen_initobj(L_54, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mE84CAE1C2C3C804992294A454700ECB3273CA55C_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mC1EBE3B129C084E57C8F969D8D71CF9087B8D698(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Il2CppSharedGenericObject** L_3 = ___1_value;
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Il2CppSharedGenericObject**)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)L_6);
		return (bool)1;
	}

IL_0025:
	{
		Il2CppSharedGenericObject** L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_m41A9C66611A558D8FC76DF8A5B6D85DEA64AB025_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m8357524D1C8961A4028BC1DC44FE9AD5A78A092F(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m4A5DBE42437FA7371B76904470CD39F967DD3597_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_m741926593764B7FDC06CE3C25FA7064C90EDC465_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_mCE5BB990E0EB80EB89D6FDF8DB85AF06C991991B(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_t1A5E2DC8C4A28412CFB10C3F45A64B3FE257AA93* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_m6079E76F44CA52BDA46A08AB89BC129EC1AFDACB(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_25 = V_2;
		int32_t L_26 = V_3;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		int32_t L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_30 = V_2;
		int32_t L_31 = V_3;
		Il2CppSharedGenericObject* L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_33;
		memset((&L_33), 0, sizeof(L_33));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_33), L_29, (RuntimeObject*)L_32, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_33);
	}

IL_00b5:
	{
		int32_t L_34 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b9:
	{
		int32_t L_35 = V_3;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_37 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_37, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = V_4;
		if (L_38)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_39 = __this->____count;
			V_5 = L_39;
			EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_40 = __this->____entries;
			V_6 = L_40;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_41 = V_6;
			int32_t L_42 = V_7;
			int32_t L_43 = ((L_41)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_42)))->___hashCode;
			if ((((int32_t)L_43) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_44 = V_4;
			int32_t L_45 = ___1_index;
			int32_t L_46 = L_45;
			___1_index = ((int32_t)il2cpp_codegen_add(L_46, 1));
			EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_47 = V_6;
			int32_t L_48 = V_7;
			int32_t L_49 = ((L_47)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_48)))->___key;
			EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_50 = V_6;
			int32_t L_51 = V_7;
			Il2CppSharedGenericObject* L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___value;
			KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_53;
			memset((&L_53), 0, sizeof(L_53));
			KeyValuePair_2__ctor_mB203F4B742D836457DDC26B3493454EC84369344((&L_53), L_49, L_52, NULL);
			KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55 L_54 = L_53;
			RuntimeObject* L_55 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_54);
			ArrayElementTypeCheck (L_44, L_55);
			(L_44)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_46), (RuntimeObject*)L_55);
		}

IL_012a_1:
		{
			int32_t L_56 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_56, 1));
		}

IL_0130_1:
		{
			int32_t L_57 = V_7;
			int32_t L_58 = V_5;
			if ((((int32_t)L_57) < ((int32_t)L_58)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_59 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_mE77D515B9401431AAC8D1465DF309C52F5E99EBC_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65((&L_0), __this, 2, NULL);
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_m4EF9E59B605525DFBC945C4CE685398110C68A49_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_t6E6179EB5F900C355F0B5608A485AD28297C064E* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_m8F58774799ABFD0AF88167500E453B5252FF5FBB(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_m82DAF2EEBEF35C89774A8E71F51F1BD13378620F(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_mA2465C7565752A3558A1088BD0A915470F4F310A_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	int32_t V_0 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(int32_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			int32_t L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_m2BB6CF3A683DE145DB22935870F3C63F3E8E3027(__this, L_3, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_mB8EF6802830790335FE5CD8CE5E52941B5F22A4B_gshared (Dictionary_2_t36B17C1CDA9BE4EE8C94D25A0DC9A7F4C75D51D7* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m32006CB0E3F8700C09347A914C1881579BCFFC65((&L_0), __this, 1, NULL);
		Enumerator_t81A2148DB17455F54BFD43D8DE4377EB070272D1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m7305647D28844BDDE75B6B471741723FF2E50BE6 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mCB497FA495BCCA1BF4D2D2ED00AC9449C48E41FD (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m6D5E6A9F9FA4E1C873EB24004DF2038B8A2A1D9F (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_5;
		L_5 = EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE0912309537537B778BCC94033DB215F0704069B (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_m5A86DD7196BAD4E82E1612063D35AA69A41AC127(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5A86DD7196BAD4E82E1612063D35AA69A41AC127 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* G_B2_0 = NULL;
	Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_m6818D2210BF5328DBDF7247EB90D4E145D266C9E(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* L_9 = ((Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_15 = V_1;
		int32_t L_16 = V_2;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_18 = V_1;
		int32_t L_19 = V_2;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_30;
				L_30 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline((&V_4), NULL);
				Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_31;
				L_31 = KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline((&V_4), NULL);
				Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7* Dictionary_2_get_Keys_mFF4245F70DA617283AA7B8D03117E1CAA269C5E1 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7* L_1 = (KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_m02A1D71902F956CF8E4F3EBF6B393B3027059F88(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_t302F3368F4549F8C5F276558FB4458F9388EDFA7* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98* Dictionary_2_get_Values_m0727B85637956A9354130DFF0667D7C530729E10 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98* L_1 = (ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_m9F330FA04A0EDF48F556FA52CDB1C53E10AFC265(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_t38496EABE25A048F0ED98E59AEDBB2FF22D81F98* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 Dictionary_2_get_Item_m9513953CE43D70DB671962908AD63D50F6FB3A99 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_6 = ___0_key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8));
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m2C8B19C423C5ADE5459015BE8B0361D2DA4D2AE2 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) 
{
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = ___0_key;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m37E8831114C391DE86E5265088822C77C8902039(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) 
{
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = ___0_key;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m37E8831114C391DE86E5265088822C77C8902039(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_m95E70C66D6CF6AB57EAB7363F78AD154A60727D4 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0;
		L_0 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline((&___0_keyValuePair), NULL);
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_1;
		L_1 = KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m899CD22D57C534C7BAD5DFDF8EA6839D60B8386E (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0;
		L_0 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_3;
		L_3 = EqualityComparer_1_get_Default_m2B4F62EDB23031C609551EC3F4671100D30E9CEA_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_7;
		L_7 = KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_mCDEE07D9FF2E4DBAE84119B1FDDC281923B983CF (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0;
		L_0 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_3;
		L_3 = EqualityComparer_1_get_Default_m2B4F62EDB23031C609551EC3F4671100D30E9CEA_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_7;
		L_7 = KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_9;
		L_9 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m242481DE2BE6F14286AAC901883DDBDCFF8A3FB0(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m9A4F2B1DD00D9C57456C698E315114D97FD48BD7 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) 
{
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_m77113A39B4A6F3D226B48BEAF3518B55AB01A995 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_0 = NULL;
	int32_t V_1 = 0;
	Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 V_2;
	memset((&V_2), 0, sizeof(V_2));
	int32_t V_3 = 0;
	EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_0 = __this->____entries;
		V_0 = L_0;
		goto IL_0049;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8));
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_3 = V_0;
		int32_t L_4 = V_3;
		int32_t L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___hashCode;
		if ((((int32_t)L_5) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_6;
		L_6 = EqualityComparer_1_get_Default_m2B4F62EDB23031C609551EC3F4671100D30E9CEA_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_7 = V_0;
		int32_t L_8 = V_3;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_9 = ((L_7)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_8)))->___value;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_10 = ___0_value;
		bool L_11;
		L_11 = VirtualFuncInvoker2< bool, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 >::Invoke(8, L_6, L_9, L_10);
		if (!L_11)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_12 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_12, 1));
	}

IL_008b:
	{
		int32_t L_13 = V_3;
		int32_t L_14 = __this->____count;
		if ((((int32_t)L_13) < ((int32_t)L_14)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m7E43D940B96D7285E9B06A4995E5DC3E4F75D750 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_mB2AF075C1A6CDDDB77A2F1AD3F7951AF2C655046(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_16 = V_1;
		int32_t L_17 = V_2;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_19 = V_1;
		int32_t L_20 = V_2;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_mC7D1153B9AF14948CABDF03CB0B9F2738E9D73A2((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 Dictionary_2_GetEnumerator_mD97F3876F7E1FBF9338BDC8B2B22692D2009F673 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB32AE83D0B9758EC2EF27CE221A21821D81D1C66((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m10B7076BC22D95FF279F7B347BC491E6EED5F0C9 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB32AE83D0B9758EC2EF27CE221A21821D81D1C66((&L_0), __this, 2, NULL);
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_m89F5BD4B0914CE05B9BFE5F9CEC5D9BBF3BB1443 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_6;
		L_6 = EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_mB2AF075C1A6CDDDB77A2F1AD3F7951AF2C655046(__this, NULL);
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_15 = (KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC*)(KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_16 = V_0;
		Dictionary_2_CopyTo_m7E43D940B96D7285E9B06A4995E5DC3E4F75D750(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 V_6;
	memset((&V_6), 0, sizeof(V_6));
	EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline((&___0_key), NULL);
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_21;
		L_21 = EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_22 = V_2;
		int32_t L_23 = V_0;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_51 = V_2;
		int32_t L_52 = V_0;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_5 = (EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE*)(EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m37E8831114C391DE86E5265088822C77C8902039 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* V_10 = NULL;
	InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 V_11;
	memset((&V_11), 0, sizeof(V_11));
	EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline((&___0_key), NULL);
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_26;
		L_26 = EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_27 = V_0;
		int32_t L_28 = V_5;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_33 = V_0;
		int32_t L_34 = V_5;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value))->___handler), (void*)NULL);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_37 = ___0_key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_55 = V_0;
		int32_t L_56 = V_5;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_61 = V_0;
		int32_t L_62 = V_5;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)&(((&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value))->___handler), (void*)NULL);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_65 = ___0_key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_mB1AA1911C550F562B65DE6DDC6F4936FADF503F4(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_101 = V_10;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_102 = ___0_key;
		L_101->___key = L_102;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_103 = V_10;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)&(((&L_103->___value))->___handler), (void*)NULL);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_mA2CD73716E10E5BF750F7BD1C88A8D5C1B02CD0D (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, __this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_19 = V_3;
		int32_t L_20 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_21;
		L_21 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_22 = V_3;
		int32_t L_23 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_24;
		L_24 = KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_25 = V_3;
		int32_t L_26 = V_4;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_27;
		L_27 = KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_m283F367ACCC4A2031B27BDECBAD5371A37A3E136(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, __this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mB1AA1911C550F562B65DE6DDC6F4936FADF503F4 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_mFE661A28565100336E2E0AC668DE8FBEE997B873(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mFE661A28565100336E2E0AC668DE8FBEE997B873 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_1 = NULL;
	int32_t V_2 = 0;
	InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_3 = (EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE*)(EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_5 = __this->____entries;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391));
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_15 = V_1;
		int32_t L_16 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391* L_17 = (InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline(L_17, NULL);
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m242481DE2BE6F14286AAC901883DDBDCFF8A3FB0 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_21;
		L_21 = EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_22 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_23 = L_22->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_26 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_27 = L_26->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
		goto IL_00ff;
	}

IL_00ff:
	{
	}
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_42 = V_4;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* L_43 = (Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)(&L_42->___value);
		il2cpp_codegen_initobj(L_43, sizeof(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8));
	}

IL_0113:
	{
		int32_t L_44 = V_3;
		__this->____freeList = L_44;
		int32_t L_45 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_46, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_47 = V_3;
		V_2 = L_47;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_48 = V_4;
		int32_t L_49 = L_48->___next;
		V_3 = L_49;
	}

IL_0142:
	{
		int32_t L_50 = V_3;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_mC1D876293F41F54114A00C3DC5D2BE5D67499DA6 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_21;
		L_21 = EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_22 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_23 = L_22->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_26 = V_4;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_27 = L_26->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* L_39 = ___1_value;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_40 = V_4;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_41 = L_40->___value;
		*(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)&(((Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)L_39)->___handler), (void*)NULL);
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
		goto IL_010c;
	}

IL_010c:
	{
	}
	{
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_45 = V_4;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* L_46 = (Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)(&L_45->___value);
		il2cpp_codegen_initobj(L_46, sizeof(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8));
	}

IL_0120:
	{
		int32_t L_47 = V_3;
		__this->____freeList = L_47;
		int32_t L_48 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_50 = V_3;
		V_2 = L_50;
		Entry_tA10AF69FA088B432C53449C37561D0D0CC66FBAB* L_51 = V_4;
		int32_t L_52 = L_51->___next;
		V_3 = L_52;
	}

IL_014f:
	{
		int32_t L_53 = V_3;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* L_54 = ___1_value;
		il2cpp_codegen_initobj(L_54, sizeof(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mE89679F3C636638BA68140F715769F0ABA7145B0 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mF6F7D3ED64E85D31556C2FB7C87162FA40C8B452(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* L_3 = ___1_value;
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)&(((Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)L_3)->___handler), (void*)NULL);
		return (bool)1;
	}

IL_0025:
	{
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8* L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_mBC666C11EBA0B72ADB4131B3515055AAB0F31B32 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 ___0_key, Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 ___1_value, const RuntimeMethod* method) 
{
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = ___0_key;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m37E8831114C391DE86E5265088822C77C8902039(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_mC2B3A5B741EB893C9A77CA7972344F98213D8033 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_m7E43D940B96D7285E9B06A4995E5DC3E4F75D750(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_m651255B0E8C4487FF155379369229E2F3F1A4CD4 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_mB2AF075C1A6CDDDB77A2F1AD3F7951AF2C655046(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_tDF7E4854F3A10BE0D3C2E93F0C148F124F044BDC* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_m7E43D940B96D7285E9B06A4995E5DC3E4F75D750(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_25 = V_2;
		int32_t L_26 = V_3;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_30 = V_2;
		int32_t L_31 = V_3;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_33 = L_32;
		RuntimeObject* L_34 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12), &L_33);
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_35;
		memset((&L_35), 0, sizeof(L_35));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_35), L_29, L_34, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_35);
	}

IL_00b5:
	{
		int32_t L_36 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_00b9:
	{
		int32_t L_37 = V_3;
		int32_t L_38 = __this->____count;
		if ((((int32_t)L_37) < ((int32_t)L_38)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_39 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_39, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_40 = V_4;
		if (L_40)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_41 = __this->____count;
			V_5 = L_41;
			EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_42 = __this->____entries;
			V_6 = L_42;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_43 = V_6;
			int32_t L_44 = V_7;
			int32_t L_45 = ((L_43)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_44)))->___hashCode;
			if ((((int32_t)L_45) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_46 = V_4;
			int32_t L_47 = ___1_index;
			int32_t L_48 = L_47;
			___1_index = ((int32_t)il2cpp_codegen_add(L_48, 1));
			EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_49 = V_6;
			int32_t L_50 = V_7;
			InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_51 = ((L_49)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_50)))->___key;
			EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_52 = V_6;
			int32_t L_53 = V_7;
			Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_54 = ((L_52)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_53)))->___value;
			KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE L_55;
			memset((&L_55), 0, sizeof(L_55));
			KeyValuePair_2__ctor_mC7D1153B9AF14948CABDF03CB0B9F2738E9D73A2((&L_55), L_51, L_54, NULL);
			KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE L_56 = L_55;
			RuntimeObject* L_57 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_56);
			ArrayElementTypeCheck (L_46, L_57);
			(L_46)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_48), (RuntimeObject*)L_57);
		}

IL_012a_1:
		{
			int32_t L_58 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_58, 1));
		}

IL_0130_1:
		{
			int32_t L_59 = V_7;
			int32_t L_60 = V_5;
			if ((((int32_t)L_59) < ((int32_t)L_60)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_61 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m9168706206A4190434407DE049B484FEF55FF115 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB32AE83D0B9758EC2EF27CE221A21821D81D1C66((&L_0), __this, 2, NULL);
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_mAF0EE038EA4679D2761253E6A6AF7FDE0E28DC17 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_tE91170FFC8F35645B02EE83FAE075517459DBDDE* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_m5A7B3A4BD35EE33EF1D23EC63D0BF8C835146F95(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_mFE661A28565100336E2E0AC668DE8FBEE997B873(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_m225967F95362B50CAFAE31593850809443A041A9 (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 V_0;
	memset((&V_0), 0, sizeof(V_0));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisBinding_t4902D3C6D27680D096CC41D83FFD0872785E57F8_mA18D5105179EC292D090491E378CBED448E54927(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_m2C8B19C423C5ADE5459015BE8B0361D2DA4D2AE2(__this, L_3, ((*(Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8*)UnBox(L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_mD6F28B2E38AE35E9B9BF0B79CF58D7AA11CCDC8B (Dictionary_2_tCE9DE62380B9B872A2620BB3F77F67E90B8A118B* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB32AE83D0B9758EC2EF27CE221A21821D81D1C66((&L_0), __this, 1, NULL);
		Enumerator_t3249322F295351E1E39A22F8FF2D22A73275F8D5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m30577DF4F4E31A9DAE58AB53C999989381668AEC_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m290A5B4EB9367B6BE97DC58301A9554D8258D795_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m770C4FA32A14E4478ED55634CA5B6A554A61F843_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_5;
		L_5 = EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m1DA7E8221339F2E395560CE93AF93542D4FC93E5_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_mE3BF918A0795EB846853FF14EFAA7B94BDE3804F(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mE3BF918A0795EB846853FF14EFAA7B94BDE3804F_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* G_B2_0 = NULL;
	Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), (RuntimeObject*)L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_m4CA944FFF41C0427C7753F1999AFEC43C33325A7(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* L_9 = ((Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_15 = V_1;
		int32_t L_16 = V_2;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_18 = V_1;
		int32_t L_19 = V_2;
		Il2CppSharedGenericObject* L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), (RuntimeObject*)L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_30;
				L_30 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline((&V_4), NULL);
				Il2CppSharedGenericObject* L_31;
				L_31 = KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_inline((&V_4), NULL);
				Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9* Dictionary_2_get_Keys_m3EE74149DC6731CDFEE5F22F0CA2058B59A8D2D9_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9* L_1 = (KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_mCB4E7E205EC342EAB10B0702E3B66409B6A9B200(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_t5E448F9EF31B8C6F2D80CA7C7858AB780AB912A9* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9* Dictionary_2_get_Values_mEC10CAC4B24A0C0E57AE9BF73D0378DA6D2C852A_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9* L_1 = (ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_m1BD339959757C06FE8E0334B098E945E9FA88D87(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_t7F798658A969389BB4AAA8E1ECC40A4682EF43A9* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Dictionary_2_get_Item_mC69EB6221BAEBEB7C333891ECE11A43404960F7D_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_6 = ___0_key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m6121DA29D4E26687E594BFA4AF8F974D3E0E2230_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_mA1E0D9B55F37F298173C076794A53DFD841CFF2B_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0;
		L_0 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline((&___0_keyValuePair), NULL);
		Il2CppSharedGenericObject* L_1;
		L_1 = KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_m9A44ED1FF3D62ADE07D8D313660EE76BCB96A7A9_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0;
		L_0 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m178A89DEBDCEAE2D34BC41FF29EA720A79C37C9A_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0;
		L_0 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_9;
		L_9 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m9B8C23C73DCE5610BAD4E4506C7260A603E3BD82(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_m4FE70573C5E0F31040F3B0DE433DF7996E83A5B3_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method) 
{
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_m72BEAD957D538CE7B2EEF72FE7A7FCC5ECC4CC2D_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppSharedGenericObject* V_2 = NULL;
	int32_t V_3 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_0 = __this->____entries;
		V_0 = L_0;
		Il2CppSharedGenericObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_0049;
		}
	}
	{
		V_1 = 0;
		goto IL_003b;
	}

IL_0013:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_2 = V_0;
		int32_t L_3 = V_1;
		int32_t L_4 = ((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_5 = V_0;
		int32_t L_6 = V_1;
		Il2CppSharedGenericObject* L_7 = ((L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		if (L_7)
		{
			goto IL_0037;
		}
	}
	{
		return (bool)1;
	}

IL_0037:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_003b:
	{
		int32_t L_9 = V_1;
		int32_t L_10 = __this->____count;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0013;
		}
	}
	{
		goto IL_00db;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_11 = V_2;
		if (!L_11)
		{
			goto IL_0096;
		}
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_12 = V_0;
		int32_t L_13 = V_3;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_15;
		L_15 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_16 = V_0;
		int32_t L_17 = V_3;
		Il2CppSharedGenericObject* L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		Il2CppSharedGenericObject* L_19 = ___0_value;
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_21 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_008b:
	{
		int32_t L_22 = V_3;
		int32_t L_23 = __this->____count;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_0096:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_24;
		L_24 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		V_4 = L_24;
		V_5 = 0;
		goto IL_00d1;
	}

IL_00a2:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_25 = V_0;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		if ((((int32_t)L_27) < ((int32_t)0)))
		{
			goto IL_00cb;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_28 = V_4;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_29 = V_0;
		int32_t L_30 = V_5;
		Il2CppSharedGenericObject* L_31 = ((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___value;
		Il2CppSharedGenericObject* L_32 = ___0_value;
		bool L_33;
		L_33 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_28, L_31, L_32);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		return (bool)1;
	}

IL_00cb:
	{
		int32_t L_34 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00d1:
	{
		int32_t L_35 = V_5;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_00a2;
		}
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_m0FEE8044BE7041E9FEDEA39C11EAD8AF0D8101C8(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_16 = V_1;
		int32_t L_17 = V_2;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_19 = V_1;
		int32_t L_20 = V_2;
		Il2CppSharedGenericObject* L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_mDCDE0152C265A2053B88ED33A9DF26DCF2F78F1F((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 Dictionary_2_GetEnumerator_m0E3D7CDFC1B7CD2E98D01E3186C7A2A1A4F1A4D7_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m3CC0509A8151CD5655B822B5494171C9FD99FC94_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036((&L_0), __this, 2, NULL);
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_m3B934137319E1285DA6642C6ACE08108F189CE03_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_6;
		L_6 = EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_m0FEE8044BE7041E9FEDEA39C11EAD8AF0D8101C8(__this, NULL);
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_15 = (KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38*)(KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_16 = V_0;
		Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D V_6;
	memset((&V_6), 0, sizeof(V_6));
	EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = LifecycleScopeKey_GetHashCode_mFF0E00A6E201E85BAE8E7D68D9F28FF33314BF73((&___0_key), NULL);
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_21;
		L_21 = EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_22 = V_2;
		int32_t L_23 = V_0;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_51 = V_2;
		int32_t L_52 = V_0;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_5 = (EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB*)(EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* V_10 = NULL;
	LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D V_11;
	memset((&V_11), 0, sizeof(V_11));
	EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = LifecycleScopeKey_GetHashCode_mFF0E00A6E201E85BAE8E7D68D9F28FF33314BF73((&___0_key), NULL);
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_26;
		L_26 = EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_27 = V_0;
		int32_t L_28 = V_5;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_33 = V_0;
		int32_t L_34 = V_5;
		Il2CppSharedGenericObject* L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value), (void*)L_35);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_37 = ___0_key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_55 = V_0;
		int32_t L_56 = V_5;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_61 = V_0;
		int32_t L_62 = V_5;
		Il2CppSharedGenericObject* L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)(&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value), (void*)L_63);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_65 = ___0_key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_m6C1A1056F7B16BC3FB46419013821F6D2E8BC6DF(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_101 = V_10;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_102 = ___0_key;
		L_101->___key = L_102;
		Il2CppCodeGenWriteBarrier((void**)&(((&L_101->___key))->____scopeType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&L_101->___key))->____context), (void*)NULL);
		#endif
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_103 = V_10;
		Il2CppSharedGenericObject* L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)(&L_103->___value), (void*)L_104);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_m0AAF544AF88AC2E2043DC44BD6BFD8E3AE6A69B5_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, (RuntimeObject*)__this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_19 = V_3;
		int32_t L_20 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_21;
		L_21 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_22 = V_3;
		int32_t L_23 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_24;
		L_24 = KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_25 = V_3;
		int32_t L_26 = V_4;
		Il2CppSharedGenericObject* L_27;
		L_27 = KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_m0C37ECCAD4CA418B95EEE2AFCAEDCA430B3D6C6D(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, (RuntimeObject*)__this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m6C1A1056F7B16BC3FB46419013821F6D2E8BC6DF_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_mB8FC12542175B64C09AC8D93BFFCA68DDF3860D1(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_mB8FC12542175B64C09AC8D93BFFCA68DDF3860D1_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_1 = NULL;
	int32_t V_2 = 0;
	LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_3 = (EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB*)(EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_5 = __this->____entries;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D));
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_15 = V_1;
		int32_t L_16 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D* L_17 = (LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = LifecycleScopeKey_GetHashCode_mFF0E00A6E201E85BAE8E7D68D9F28FF33314BF73(L_17, NULL);
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m9B8C23C73DCE5610BAD4E4506C7260A603E3BD82_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = LifecycleScopeKey_GetHashCode_mFF0E00A6E201E85BAE8E7D68D9F28FF33314BF73((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_21;
		L_21 = EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_22 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_23 = L_22->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_26 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_27 = L_26->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
	}
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_42 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D* L_43 = (LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D*)(&L_42->___key);
		il2cpp_codegen_initobj(L_43, sizeof(LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D));
	}

IL_00ff:
	{
	}
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_44 = V_4;
		Il2CppSharedGenericObject** L_45 = (Il2CppSharedGenericObject**)(&L_44->___value);
		il2cpp_codegen_initobj(L_45, sizeof(Il2CppSharedGenericObject*));
	}

IL_0113:
	{
		int32_t L_46 = V_3;
		__this->____freeList = L_46;
		int32_t L_47 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_47, 1));
		int32_t L_48 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_48, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_49 = V_3;
		V_2 = L_49;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_50 = V_4;
		int32_t L_51 = L_50->___next;
		V_3 = L_51;
	}

IL_0142:
	{
		int32_t L_52 = V_3;
		if ((((int32_t)L_52) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m4B50FEB8765F78AA02E8529AE4792D2721F64F30_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = LifecycleScopeKey_GetHashCode_mFF0E00A6E201E85BAE8E7D68D9F28FF33314BF73((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_21;
		L_21 = EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_22 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_23 = L_22->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_26 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_27 = L_26->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Il2CppSharedGenericObject** L_39 = ___1_value;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_40 = V_4;
		Il2CppSharedGenericObject* L_41 = L_40->___value;
		*(Il2CppSharedGenericObject**)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_39, (void*)L_41);
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
	}
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_45 = V_4;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D* L_46 = (LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D*)(&L_45->___key);
		il2cpp_codegen_initobj(L_46, sizeof(LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D));
	}

IL_010c:
	{
	}
	{
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_47 = V_4;
		Il2CppSharedGenericObject** L_48 = (Il2CppSharedGenericObject**)(&L_47->___value);
		il2cpp_codegen_initobj(L_48, sizeof(Il2CppSharedGenericObject*));
	}

IL_0120:
	{
		int32_t L_49 = V_3;
		__this->____freeList = L_49;
		int32_t L_50 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_50, 1));
		int32_t L_51 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_51, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_52 = V_3;
		V_2 = L_52;
		Entry_t5536CC094AFB005C6BD131FC8186E873ED50E19E* L_53 = V_4;
		int32_t L_54 = L_53->___next;
		V_3 = L_54;
	}

IL_014f:
	{
		int32_t L_55 = V_3;
		if ((((int32_t)L_55) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Il2CppSharedGenericObject** L_56 = ___1_value;
		il2cpp_codegen_initobj(L_56, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mA238034AD68BB6D92BDE20B1C8BED7498E6A28A8_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mDC1B3C347E3EAA863E05910C7A9FD79AC467D040(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Il2CppSharedGenericObject** L_3 = ___1_value;
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Il2CppSharedGenericObject**)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)L_6);
		return (bool)1;
	}

IL_0025:
	{
		Il2CppSharedGenericObject** L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_mBF4605B7E3966DDB3EF9DC665530C13BFF62869D_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m32A0DE378180C4A6945DAC90DDF41C89A89CABA0(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_m1236E62DA6801EBDF3AA6C4BB1AFA5CD05ACFD13_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_mF14C0F3E1E52181FAEAE81D140DA32D690B2483B_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_m0FEE8044BE7041E9FEDEA39C11EAD8AF0D8101C8(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_t895D65B384A154629261C578EB3073542AD92C38* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_m88ECA2EC15CF8FB69B498BADF3D789F3F569F635(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_25 = V_2;
		int32_t L_26 = V_3;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_30 = V_2;
		int32_t L_31 = V_3;
		Il2CppSharedGenericObject* L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_33;
		memset((&L_33), 0, sizeof(L_33));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_33), L_29, (RuntimeObject*)L_32, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_33);
	}

IL_00b5:
	{
		int32_t L_34 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b9:
	{
		int32_t L_35 = V_3;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_37 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_37, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = V_4;
		if (L_38)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_39 = __this->____count;
			V_5 = L_39;
			EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_40 = __this->____entries;
			V_6 = L_40;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_41 = V_6;
			int32_t L_42 = V_7;
			int32_t L_43 = ((L_41)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_42)))->___hashCode;
			if ((((int32_t)L_43) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_44 = V_4;
			int32_t L_45 = ___1_index;
			int32_t L_46 = L_45;
			___1_index = ((int32_t)il2cpp_codegen_add(L_46, 1));
			EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_47 = V_6;
			int32_t L_48 = V_7;
			LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_49 = ((L_47)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_48)))->___key;
			EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_50 = V_6;
			int32_t L_51 = V_7;
			Il2CppSharedGenericObject* L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___value;
			KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C L_53;
			memset((&L_53), 0, sizeof(L_53));
			KeyValuePair_2__ctor_mDCDE0152C265A2053B88ED33A9DF26DCF2F78F1F((&L_53), L_49, L_52, NULL);
			KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C L_54 = L_53;
			RuntimeObject* L_55 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_54);
			ArrayElementTypeCheck (L_44, L_55);
			(L_44)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_46), (RuntimeObject*)L_55);
		}

IL_012a_1:
		{
			int32_t L_56 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_56, 1));
		}

IL_0130_1:
		{
			int32_t L_57 = V_7;
			int32_t L_58 = V_5;
			if ((((int32_t)L_57) < ((int32_t)L_58)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_59 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m07EF34275BBE16F9B6CCF1C300E9207824BD3096_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036((&L_0), __this, 2, NULL);
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_mE0A589E24F73AFF34787ACDD7EA43DE0D810A42C_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_tDEF7FBAAC2DACC65EAAC93DB156F3C44A315EDFB* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_m17ADF27810C89F6A35958C0DFC8CEA2409F7FBE0(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_mB8FC12542175B64C09AC8D93BFFCA68DDF3860D1(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_m10D0125428788632202F87918D41E268F2F59F64_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D V_0;
	memset((&V_0), 0, sizeof(V_0));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_m6121DA29D4E26687E594BFA4AF8F974D3E0E2230(__this, L_3, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_m48E3BC0F016EFD565BA57494C602629C5962A6F4_gshared (Dictionary_2_tE7CDB026141A092A986D0DA3CB2DFCE6BB552069* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mFCCA6DDA881FD8E1FD66E725FE8E887D44EB5036((&L_0), __this, 1, NULL);
		Enumerator_t0625E1BCE643CC1E335914123F50FBB9F77580E6 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m48D97F5D750CF576CF80C4321A5CDDFCBC40AA39_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94(__this, 0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m7691D715071769B5C11BD77E381A3BB646164444_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_capacity;
		Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m03BB464C831DD251C4254E4728239D8A4AC78EB3_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_comparer;
		Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0011;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_0011:
	{
		int32_t L_1 = ___0_capacity;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_2 = ___0_capacity;
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B(__this, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_001d:
	{
		RuntimeObject* L_4 = ___1_comparer;
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_5;
		L_5 = EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		if ((((RuntimeObject*)(RuntimeObject*)L_4) == ((RuntimeObject*)(EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B*)L_5)))
		{
			goto IL_002c;
		}
	}
	{
		RuntimeObject* L_6 = ___1_comparer;
		__this->____comparer = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)L_6);
	}

IL_002c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_mFB8D449895E6D2EC37DDFE65B66B2B110659E3AE_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_dictionary, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_dictionary;
		Dictionary_2__ctor_m830173718C916AE82B9646A3C6AEC86D5AB69774(__this, L_0, (RuntimeObject*)NULL, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m830173718C916AE82B9646A3C6AEC86D5AB69774_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_dictionary, RuntimeObject* ___1_comparer, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_1 = NULL;
	int32_t V_2 = 0;
	RuntimeObject* V_3 = NULL;
	KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 V_4;
	memset((&V_4), 0, sizeof(V_4));
	Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* G_B2_0 = NULL;
	Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* G_B3_1 = NULL;
	{
		RuntimeObject* L_0 = ___0_dictionary;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
		G_B1_0 = __this;
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_000d;
	}

IL_0007:
	{
		RuntimeObject* L_1 = ___0_dictionary;
		int32_t L_2;
		L_2 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 4), (RuntimeObject*)L_1);
		G_B3_0 = L_2;
		G_B3_1 = G_B2_0;
	}

IL_000d:
	{
		RuntimeObject* L_3 = ___1_comparer;
		Dictionary_2__ctor_m7DF73264467EB266A6C539A9FFDE84217CD46C94(G_B3_1, G_B3_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_4 = ___0_dictionary;
		if (L_4)
		{
			goto IL_001c;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(1, NULL);
	}

IL_001c:
	{
		RuntimeObject* L_5 = ___0_dictionary;
		void* L_6 = il2cpp_codegen_object_get_class(L_5);
		bool L_7 = (il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)) == (L_6);
		if (!L_7)
		{
			goto IL_0080;
		}
	}
	{
		RuntimeObject* L_8 = ___0_dictionary;
		Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* L_9 = ((Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290*)CastclassClass((RuntimeObject*)L_8, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7)));
		int32_t L_10 = L_9->____count;
		V_0 = L_10;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_11 = L_9->____entries;
		V_1 = L_11;
		V_2 = 0;
		goto IL_007b;
	}

IL_004a:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_12 = V_1;
		int32_t L_13 = V_2;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0077;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_15 = V_1;
		int32_t L_16 = V_2;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_17 = ((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_18 = V_1;
		int32_t L_19 = V_2;
		Il2CppSharedGenericObject* L_20 = ((L_18)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)))->___value;
		Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680(__this, L_17, L_20, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0077:
	{
		int32_t L_21 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_007b:
	{
		int32_t L_22 = V_2;
		int32_t L_23 = V_0;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_004a;
		}
	}
	{
		return;
	}

IL_0080:
	{
		RuntimeObject* L_24 = ___0_dictionary;
		RuntimeObject* L_25;
		L_25 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 15), (RuntimeObject*)L_24);
		V_3 = L_25;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00af:
			{
				{
					RuntimeObject* L_26 = V_3;
					if (!L_26)
					{
						goto IL_00b8;
					}
				}
				{
					RuntimeObject* L_27 = V_3;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_27);
				}

IL_00b8:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00a5_1;
			}

IL_0089_1:
			{
				RuntimeObject* L_28 = V_3;
				KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 L_29;
				L_29 = InterfaceFuncInvoker0< KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 17), L_28);
				V_4 = L_29;
				SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_30;
				L_30 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline((&V_4), NULL);
				Il2CppSharedGenericObject* L_31;
				L_31 = KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_inline((&V_4), NULL);
				Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680(__this, L_30, L_31, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
			}

IL_00a5_1:
			{
				RuntimeObject* L_32 = V_3;
				bool L_33;
				L_33 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_32);
				if (L_33)
				{
					goto IL_0089_1;
				}
			}
			{
				goto IL_00b9;
			}
		}
		catch(Il2CppNativeThreadAbortException&)
		{
			__finallyBlock.SetNativeThreadAbortOccurred();
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b9:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF* Dictionary_2_get_Keys_m76CD5EBDA6D8CB7067F34D195306B816BF628A57_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF* L_0 = __this->____keys;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF* L_1 = (KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 22));
		KeyCollection__ctor_m7E2470EE4EC9FB62B159CCCAD65C4D28BF62ADA4(L_1, __this, NULL);
		__this->____keys = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____keys), (void*)L_1);
	}

IL_0014:
	{
		KeyCollection_t913C4A1E522FD86E692FB27A478655A2F417C8AF* L_2 = __this->____keys;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D* Dictionary_2_get_Values_m541F7F5153A90AE21237AA2095A7CD70FCB8C229_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D* L_0 = __this->____values;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D* L_1 = (ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 24));
		ValueCollection__ctor_mCA65F91E6386BB7AFEDB097F1EE273D3C97B3E5F(L_1, __this, NULL);
		__this->____values = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____values), (void*)L_1);
	}

IL_0014:
	{
		ValueCollection_tCCBDA17C333A6C538174B0B7315DAB738871636D* L_2 = __this->____values;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Dictionary_2_get_Item_m21001AD98820142ED079D6269072303A7379188E_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001e;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_3 = __this->____entries;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)))->___value;
		return L_5;
	}

IL_001e:
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_6 = ___0_key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_7 = L_6;
		RuntimeObject* L_8 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_7);
		ThrowHelper_ThrowKeyNotFoundException_m6A17735FA486AD43F2488DE39B755AC60BC99CE7(L_8, NULL);
		il2cpp_codegen_initobj((&V_1), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_9 = V_1;
		return L_9;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m03B251192DEED90E69DEE07C8E616FEB8AE6F720_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10(__this, L_0, L_1, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10(__this, L_0, L_1, 2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Add_mBD4B8E714AA85A180B7F097652BEB55DC0E88AB3_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 ___0_keyValuePair, const RuntimeMethod* method) 
{
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0;
		L_0 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline((&___0_keyValuePair), NULL);
		Il2CppSharedGenericObject* L_1;
		L_1 = KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_inline((&___0_keyValuePair), NULL);
		Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Contains_mE0FFE7D926BF9EEC9462C8E523DBDBC48F4F37B2_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0;
		L_0 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0038;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0038;
		}
	}
	{
		return (bool)1;
	}

IL_0038:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_Remove_m6546C82D18EF4C4027CDEC9405D113B91C14D417_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 ___0_keyValuePair, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0;
		L_0 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline((&___0_keyValuePair), NULL);
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3;
		L_3 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		Il2CppSharedGenericObject* L_7;
		L_7 = KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_inline((&___0_keyValuePair), NULL);
		bool L_8;
		L_8 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_3, L_6, L_7);
		if (!L_8)
		{
			goto IL_0046;
		}
	}
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_9;
		L_9 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline((&___0_keyValuePair), NULL);
		bool L_10;
		L_10 = Dictionary_2_Remove_m875E41231D476577C9A3B051A475870CE8A41118(__this, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		return (bool)1;
	}

IL_0046:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsKey_mAD60EA9833DADEFDB44AC35B01DDB1DAA91303BB_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method) 
{
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		return (bool)((((int32_t)((((int32_t)L_1) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_ContainsValue_mA002A24574868B2B7E97EDB6BB323130B6289970_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, Il2CppSharedGenericObject* ___0_value, const RuntimeMethod* method) 
{
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_0 = NULL;
	int32_t V_1 = 0;
	Il2CppSharedGenericObject* V_2 = NULL;
	int32_t V_3 = 0;
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_4 = NULL;
	int32_t V_5 = 0;
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_0 = __this->____entries;
		V_0 = L_0;
		Il2CppSharedGenericObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_0049;
		}
	}
	{
		V_1 = 0;
		goto IL_003b;
	}

IL_0013:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_2 = V_0;
		int32_t L_3 = V_1;
		int32_t L_4 = ((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)))->___hashCode;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0037;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_5 = V_0;
		int32_t L_6 = V_1;
		Il2CppSharedGenericObject* L_7 = ((L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_6)))->___value;
		if (L_7)
		{
			goto IL_0037;
		}
	}
	{
		return (bool)1;
	}

IL_0037:
	{
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_003b:
	{
		int32_t L_9 = V_1;
		int32_t L_10 = __this->____count;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0013;
		}
	}
	{
		goto IL_00db;
	}

IL_0049:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_11 = V_2;
		if (!L_11)
		{
			goto IL_0096;
		}
	}
	{
		V_3 = 0;
		goto IL_008b;
	}

IL_005d:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_12 = V_0;
		int32_t L_13 = V_3;
		int32_t L_14 = ((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)))->___hashCode;
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_0087;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_15;
		L_15 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_16 = V_0;
		int32_t L_17 = V_3;
		Il2CppSharedGenericObject* L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___value;
		Il2CppSharedGenericObject* L_19 = ___0_value;
		bool L_20;
		L_20 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_15, L_18, L_19);
		if (!L_20)
		{
			goto IL_0087;
		}
	}
	{
		return (bool)1;
	}

IL_0087:
	{
		int32_t L_21 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_21, 1));
	}

IL_008b:
	{
		int32_t L_22 = V_3;
		int32_t L_23 = __this->____count;
		if ((((int32_t)L_22) < ((int32_t)L_23)))
		{
			goto IL_005d;
		}
	}
	{
		goto IL_00db;
	}

IL_0096:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_24;
		L_24 = EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		V_4 = L_24;
		V_5 = 0;
		goto IL_00d1;
	}

IL_00a2:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_25 = V_0;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		if ((((int32_t)L_27) < ((int32_t)0)))
		{
			goto IL_00cb;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_28 = V_4;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_29 = V_0;
		int32_t L_30 = V_5;
		Il2CppSharedGenericObject* L_31 = ((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___value;
		Il2CppSharedGenericObject* L_32 = ___0_value;
		bool L_33;
		L_33 = VirtualFuncInvoker2< bool, Il2CppSharedGenericObject*, Il2CppSharedGenericObject* >::Invoke(8, L_28, L_31, L_32);
		if (!L_33)
		{
			goto IL_00cb;
		}
	}
	{
		return (bool)1;
	}

IL_00cb:
	{
		int32_t L_34 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00d1:
	{
		int32_t L_35 = V_5;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_00a2;
		}
	}

IL_00db:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_1 = NULL;
	int32_t V_2 = 0;
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_index;
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_2 = ___0_array;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((!(((uint32_t)L_1) > ((uint32_t)L_3))))
		{
			goto IL_0014;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0014:
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_4 = ___0_array;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		int32_t L_6 = ___1_index;
		int32_t L_7;
		L_7 = Dictionary_2_get_Count_mCD0ED4AC38DA3D2F05E2129818FC98C046B09A36(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_5, L_6))) >= ((int32_t)L_7)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_0027:
	{
		int32_t L_8 = __this->____count;
		V_0 = L_8;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_9 = __this->____entries;
		V_1 = L_9;
		V_2 = 0;
		goto IL_0075;
	}

IL_0039:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_10 = V_1;
		int32_t L_11 = V_2;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0071;
		}
	}
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_13 = ___0_array;
		int32_t L_14 = ___1_index;
		int32_t L_15 = L_14;
		___1_index = ((int32_t)il2cpp_codegen_add(L_15, 1));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_16 = V_1;
		int32_t L_17 = V_2;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_18 = ((L_16)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_17)))->___key;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_19 = V_1;
		int32_t L_20 = V_2;
		Il2CppSharedGenericObject* L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___value;
		KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 L_22;
		memset((&L_22), 0, sizeof(L_22));
		KeyValuePair_2__ctor_m62040016A6CE2E5FDD9B8A2BF034F1319CA0379D((&L_22), L_18, L_21, NULL);
		(L_13)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2)L_22);
	}

IL_0071:
	{
		int32_t L_23 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_0075:
	{
		int32_t L_24 = V_2;
		int32_t L_25 = V_0;
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_0039;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A Dictionary_2_GetEnumerator_m873564FA936993860B81458503299ACF127F31AB_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6((&L_0), __this, 2, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_Generic_IEnumerableU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_GetEnumerator_m91850B01370A5976417BD9CB20FA2F5DF4E65664_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6((&L_0), __this, 2, NULL);
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_GetObjectData_m8DF1CFD9338C026450792AD1D1B6BD20B90FD677_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* V_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B4_2 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B3_2 = NULL;
	String_t* G_B6_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B6_1 = NULL;
	String_t* G_B5_0 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B5_1 = NULL;
	int32_t G_B7_0 = 0;
	String_t* G_B7_1 = NULL;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* G_B7_2 = NULL;
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(4, NULL);
	}

IL_0009:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_1 = ___0_info;
		int32_t L_2 = __this->____version;
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(L_1, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, L_2, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = ___0_info;
		RuntimeObject* L_4 = __this->____comparer;
		RuntimeObject* L_5 = L_4;
		if (L_5)
		{
			G_B4_0 = L_5;
			G_B4_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
			G_B4_2 = L_3;
			goto IL_002f;
		}
		G_B3_0 = L_5;
		G_B3_1 = _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9;
		G_B3_2 = L_3;
	}
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_6;
		L_6 = EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		G_B4_0 = ((RuntimeObject*)(L_6));
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_002f:
	{
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(G_B4_2, G_B4_1, G_B4_0, L_8, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		if (!L_10)
		{
			G_B6_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
			G_B6_1 = L_9;
			goto IL_0056;
		}
		G_B5_0 = _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69;
		G_B5_1 = L_9;
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		G_B7_0 = L_12;
		G_B7_1 = G_B5_0;
		G_B7_2 = G_B5_1;
		goto IL_0057;
	}

IL_0056:
	{
		G_B7_0 = 0;
		G_B7_1 = G_B6_0;
		G_B7_2 = G_B6_1;
	}

IL_0057:
	{
		SerializationInfo_AddValue_m9D6ADD10966D1FE8D19050F3A269747C23FE9FC4(G_B7_2, G_B7_1, G_B7_0, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		if (!L_13)
		{
			goto IL_008e;
		}
	}
	{
		int32_t L_14;
		L_14 = Dictionary_2_get_Count_mCD0ED4AC38DA3D2F05E2129818FC98C046B09A36(__this, NULL);
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_15 = (KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363*)(KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36), (uint32_t)L_14);
		V_0 = L_15;
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_16 = V_0;
		Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96(__this, L_16, 0, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_17 = ___0_info;
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		SerializationInfo_AddValue_m1AD59BBF8C3129142943D3F298ADF09FF123C199(L_17, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, (RuntimeObject*)L_18, L_20, NULL);
	}

IL_008e:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_1 = NULL;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_2 = NULL;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 V_6;
	memset((&V_6), 0, sizeof(V_6));
	EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* V_7 = NULL;
	int32_t V_8 = 0;
	{
		goto IL_000e;
	}

IL_000e:
	{
		V_0 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		V_1 = L_1;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_2 = __this->____entries;
		V_2 = L_2;
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = V_1;
		if (!L_3)
		{
			goto IL_0175;
		}
	}
	{
		RuntimeObject* L_4 = __this->____comparer;
		V_4 = L_4;
		RuntimeObject* L_5 = V_4;
		if (L_5)
		{
			goto IL_0110;
		}
	}
	{
		int32_t L_6;
		L_6 = SamplerKey_GetHashCode_m65CFF629294833D2638E8331CCD322205A3F58E6((&___0_key), NULL);
		V_5 = ((int32_t)(L_6&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_1;
		int32_t L_8 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_1;
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		int32_t L_11 = ((int32_t)(L_8%L_10));
		int32_t L_12 = (L_7)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_11));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_12, 1));
		il2cpp_codegen_initobj((&V_6), sizeof(SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724));
	}

IL_0066:
	{
		int32_t L_14 = V_0;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_15 = V_2;
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		if ((!(((uint32_t)L_14) < ((uint32_t)L_16))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_17 = V_2;
		int32_t L_18 = V_0;
		int32_t L_19 = ((L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_18)))->___hashCode;
		int32_t L_20 = V_5;
		if ((!(((uint32_t)L_19) == ((uint32_t)L_20))))
		{
			goto IL_009b;
		}
	}
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_21;
		L_21 = EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_22 = V_2;
		int32_t L_23 = V_0;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_25 = ___0_key;
		bool L_26;
		L_26 = VirtualFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(8, L_21, L_24, L_25);
		if (L_26)
		{
			goto IL_0175;
		}
	}

IL_009b:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_27 = V_2;
		int32_t L_28 = V_0;
		int32_t L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___next;
		V_0 = L_29;
		int32_t L_30 = V_3;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_31 = V_2;
		int32_t L_32 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_31)->max_length),NULL));
		if ((((int32_t)L_30) < ((int32_t)L_32)))
		{
			goto IL_00b3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_00b3:
	{
		int32_t L_33 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_33, 1));
		goto IL_0066;
	}

IL_0110:
	{
		RuntimeObject* L_34 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_35 = ___0_key;
		int32_t L_36;
		L_36 = InterfaceFuncInvoker1< int32_t, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_34, L_35);
		V_8 = ((int32_t)(L_36&((int32_t)2147483647LL)));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_37 = V_1;
		int32_t L_38 = V_8;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_39 = V_1;
		int32_t L_40 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_39)->max_length),NULL));
		int32_t L_41 = ((int32_t)(L_38%L_40));
		int32_t L_42 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_41));
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_42, 1));
	}

IL_012b:
	{
		int32_t L_43 = V_0;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_44 = V_2;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((!(((uint32_t)L_43) < ((uint32_t)L_45))))
		{
			goto IL_0175;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_46 = V_2;
		int32_t L_47 = V_0;
		int32_t L_48 = ((L_46)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_47)))->___hashCode;
		int32_t L_49 = V_8;
		if ((!(((uint32_t)L_48) == ((uint32_t)L_49))))
		{
			goto IL_0157;
		}
	}
	{
		RuntimeObject* L_50 = V_4;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_51 = V_2;
		int32_t L_52 = V_0;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_53 = ((L_51)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_52)))->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_54 = ___0_key;
		bool L_55;
		L_55 = InterfaceFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_50, L_53, L_54);
		if (L_55)
		{
			goto IL_0175;
		}
	}

IL_0157:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_56 = V_2;
		int32_t L_57 = V_0;
		int32_t L_58 = ((L_56)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_57)))->___next;
		V_0 = L_58;
		int32_t L_59 = V_3;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_60 = V_2;
		int32_t L_61 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_60)->max_length),NULL));
		if ((((int32_t)L_59) < ((int32_t)L_61)))
		{
			goto IL_016f;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_016f:
	{
		int32_t L_62 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_62, 1));
		goto IL_012b;
	}

IL_0175:
	{
		int32_t L_63 = V_0;
		return L_63;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_0, NULL);
		V_0 = L_1;
		__this->____freeList = (-1);
		int32_t L_2 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_2);
		__this->____buckets = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_3);
		int32_t L_4 = V_0;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_5 = (EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392*)(EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_4);
		__this->____entries = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_5);
		int32_t L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, uint8_t ___2_behavior, const RuntimeMethod* method) 
{
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	int32_t* V_4 = NULL;
	int32_t V_5 = 0;
	bool V_6 = false;
	bool V_7 = false;
	int32_t V_8 = 0;
	int32_t* V_9 = NULL;
	Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* V_10 = NULL;
	SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 V_11;
	memset((&V_11), 0, sizeof(V_11));
	EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* V_12 = NULL;
	int32_t V_13 = 0;
	int32_t G_B7_0 = 0;
	int32_t* G_B51_0 = NULL;
	{
		goto IL_000e;
	}

IL_000e:
	{
		int32_t L_1 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_1, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2 = __this->____buckets;
		if (L_2)
		{
			goto IL_002c;
		}
	}
	{
		int32_t L_3;
		L_3 = Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B(__this, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
	}

IL_002c:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_4 = __this->____entries;
		V_0 = L_4;
		RuntimeObject* L_5 = __this->____comparer;
		V_1 = L_5;
		RuntimeObject* L_6 = V_1;
		if (!L_6)
		{
			goto IL_0046;
		}
	}
	{
		RuntimeObject* L_7 = V_1;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_8 = ___0_key;
		int32_t L_9;
		L_9 = InterfaceFuncInvoker1< int32_t, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_7, L_8);
		G_B7_0 = L_9;
		goto IL_0053;
	}

IL_0046:
	{
		int32_t L_10;
		L_10 = SamplerKey_GetHashCode_m65CFF629294833D2638E8331CCD322205A3F58E6((&___0_key), NULL);
		G_B7_0 = L_10;
	}

IL_0053:
	{
		V_2 = ((int32_t)(G_B7_0&((int32_t)2147483647LL)));
		V_3 = 0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_11 = __this->____buckets;
		int32_t L_12 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13 = __this->____buckets;
		int32_t L_14 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_13)->max_length),NULL));
		V_4 = ((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_12%L_14)))));
		int32_t* L_15 = V_4;
		int32_t L_16 = il2cpp_codegen_ldind<int32_t, int32_t>(L_15);
		V_5 = ((int32_t)il2cpp_codegen_subtract(L_16, 1));
		RuntimeObject* L_17 = V_1;
		if (L_17)
		{
			goto IL_0187;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724));
	}

IL_0091:
	{
		int32_t L_19 = V_5;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_20 = V_0;
		int32_t L_21 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_20)->max_length),NULL));
		if ((!(((uint32_t)L_19) < ((uint32_t)L_21))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_22 = V_0;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		int32_t L_25 = V_2;
		if ((!(((uint32_t)L_24) == ((uint32_t)L_25))))
		{
			goto IL_00ea;
		}
	}
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_26;
		L_26 = EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_27 = V_0;
		int32_t L_28 = V_5;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_29 = ((L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_28)))->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_30 = ___0_key;
		bool L_31;
		L_31 = VirtualFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(8, L_26, L_29, L_30);
		if (!L_31)
		{
			goto IL_00ea;
		}
	}
	{
		uint8_t L_32 = ___2_behavior;
		if ((!(((uint32_t)L_32) == ((uint32_t)1))))
		{
			goto IL_00d9;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_33 = V_0;
		int32_t L_34 = V_5;
		Il2CppSharedGenericObject* L_35 = ___1_value;
		((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value = L_35;
		Il2CppCodeGenWriteBarrier((void**)(&((L_33)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_34)))->___value), (void*)L_35);
		return (bool)1;
	}

IL_00d9:
	{
		uint8_t L_36 = ___2_behavior;
		if ((!(((uint32_t)L_36) == ((uint32_t)2))))
		{
			goto IL_00e8;
		}
	}
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_37 = ___0_key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_38 = L_37;
		RuntimeObject* L_39 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_38);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_39, NULL);
	}

IL_00e8:
	{
		return (bool)0;
	}

IL_00ea:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_40 = V_0;
		int32_t L_41 = V_5;
		int32_t L_42 = ((L_40)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_41)))->___next;
		V_5 = L_42;
		int32_t L_43 = V_3;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_44 = V_0;
		int32_t L_45 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_44)->max_length),NULL));
		if ((((int32_t)L_43) < ((int32_t)L_45)))
		{
			goto IL_0104;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_0104:
	{
		int32_t L_46 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_46, 1));
		goto IL_0091;
	}

IL_0187:
	{
		int32_t L_47 = V_5;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_48 = V_0;
		int32_t L_49 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_48)->max_length),NULL));
		if ((!(((uint32_t)L_47) < ((uint32_t)L_49))))
		{
			goto IL_01f9;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_50 = V_0;
		int32_t L_51 = V_5;
		int32_t L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___hashCode;
		int32_t L_53 = V_2;
		if ((!(((uint32_t)L_52) == ((uint32_t)L_53))))
		{
			goto IL_01d9;
		}
	}
	{
		RuntimeObject* L_54 = V_1;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_55 = V_0;
		int32_t L_56 = V_5;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_57 = ((L_55)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_56)))->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_58 = ___0_key;
		bool L_59;
		L_59 = InterfaceFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), L_54, L_57, L_58);
		if (!L_59)
		{
			goto IL_01d9;
		}
	}
	{
		uint8_t L_60 = ___2_behavior;
		if ((!(((uint32_t)L_60) == ((uint32_t)1))))
		{
			goto IL_01c8;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_61 = V_0;
		int32_t L_62 = V_5;
		Il2CppSharedGenericObject* L_63 = ___1_value;
		((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value = L_63;
		Il2CppCodeGenWriteBarrier((void**)(&((L_61)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_62)))->___value), (void*)L_63);
		return (bool)1;
	}

IL_01c8:
	{
		uint8_t L_64 = ___2_behavior;
		if ((!(((uint32_t)L_64) == ((uint32_t)2))))
		{
			goto IL_01d7;
		}
	}
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_65 = ___0_key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_66 = L_65;
		RuntimeObject* L_67 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_66);
		ThrowHelper_ThrowAddingDuplicateWithKeyArgumentException_m013C856C16A63018719A6096727CB43E1918CDE5(L_67, NULL);
	}

IL_01d7:
	{
		return (bool)0;
	}

IL_01d9:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_68 = V_0;
		int32_t L_69 = V_5;
		int32_t L_70 = ((L_68)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_69)))->___next;
		V_5 = L_70;
		int32_t L_71 = V_3;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_72 = V_0;
		int32_t L_73 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_72)->max_length),NULL));
		if ((((int32_t)L_71) < ((int32_t)L_73)))
		{
			goto IL_01f3;
		}
	}
	{
		ThrowHelper_ThrowInvalidOperationException_ConcurrentOperationsNotSupported_mF8A8EC1112A0933FDC2D1E9DA49C491F4D8797C0(NULL);
	}

IL_01f3:
	{
		int32_t L_74 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_74, 1));
		goto IL_0187;
	}

IL_01f9:
	{
		V_6 = (bool)0;
		V_7 = (bool)0;
		int32_t L_75 = __this->____freeCount;
		if ((((int32_t)L_75) <= ((int32_t)0)))
		{
			goto IL_0223;
		}
	}
	{
		int32_t L_76 = __this->____freeList;
		V_8 = L_76;
		V_7 = (bool)1;
		int32_t L_77 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_subtract(L_77, 1));
		goto IL_0250;
	}

IL_0223:
	{
		int32_t L_78 = __this->____count;
		V_13 = L_78;
		int32_t L_79 = V_13;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_80 = V_0;
		int32_t L_81 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_80)->max_length),NULL));
		if ((!(((uint32_t)L_79) == ((uint32_t)L_81))))
		{
			goto IL_023b;
		}
	}
	{
		Dictionary_2_Resize_m923041BDE6BE4962A302162C644214A773DD97C0(__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 44));
		V_6 = (bool)1;
	}

IL_023b:
	{
		int32_t L_82 = V_13;
		V_8 = L_82;
		int32_t L_83 = V_13;
		__this->____count = ((int32_t)il2cpp_codegen_add(L_83, 1));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_84 = __this->____entries;
		V_0 = L_84;
	}

IL_0250:
	{
		bool L_85 = V_6;
		if (L_85)
		{
			goto IL_0258;
		}
	}
	{
		int32_t* L_86 = V_4;
		G_B51_0 = L_86;
		goto IL_026d;
	}

IL_0258:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_87 = __this->____buckets;
		int32_t L_88 = V_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_89 = __this->____buckets;
		int32_t L_90 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_89)->max_length),NULL));
		G_B51_0 = ((L_87)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(((int32_t)(L_88%L_90)))));
	}

IL_026d:
	{
		V_9 = G_B51_0;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_91 = V_0;
		int32_t L_92 = V_8;
		V_10 = ((L_91)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_92)));
		bool L_93 = V_7;
		if (!L_93)
		{
			goto IL_028a;
		}
	}
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_94 = V_10;
		int32_t L_95 = L_94->___next;
		__this->____freeList = L_95;
	}

IL_028a:
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_96 = V_10;
		int32_t L_97 = V_2;
		L_96->___hashCode = L_97;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_98 = V_10;
		int32_t* L_99 = V_9;
		int32_t L_100 = il2cpp_codegen_ldind<int32_t, int32_t>(L_99);
		L_98->___next = ((int32_t)il2cpp_codegen_subtract(L_100, 1));
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_101 = V_10;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_102 = ___0_key;
		L_101->___key = L_102;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_103 = V_10;
		Il2CppSharedGenericObject* L_104 = ___1_value;
		L_103->___value = L_104;
		Il2CppCodeGenWriteBarrier((void**)(&L_103->___value), (void*)L_104);
		int32_t* L_105 = V_9;
		int32_t L_106 = V_8;
		il2cpp_codegen_stind<int32_t>((int32_t*)L_105, (int32_t)((int32_t)il2cpp_codegen_add(L_106, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_OnDeserialization_mC1D9C7BADDDDFEA0291E77388DF18C62609B7084_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_sender, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	CHECKED_LOCAL(Type_t_StaticInit);
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* V_3 = NULL;
	int32_t V_4 = 0;
	{
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_0;
		L_0 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_1;
		L_1 = ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F(L_0, (RuntimeObject*)__this, (&V_0), ConditionalWeakTable_2_TryGetValue_m8AB467BA44D1FF9EBDB9735CED88B0D67AC6403F_RuntimeMethod_var);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = V_0;
		if (L_2)
		{
			goto IL_0012;
		}
	}
	{
		return;
	}

IL_0012:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_3 = V_0;
		int32_t L_4;
		L_4 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_3, _stringLiteralE200AC1425952F4F5CEAAA9C773B6D17B90E47C1, NULL);
		V_1 = L_4;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_5 = V_0;
		int32_t L_6;
		L_6 = SerializationInfo_GetInt32_m7731402825C7FC8D0673F7610D555615F95E4FB5(L_5, _stringLiteral1275D52763CF050C5A4C759818D60119CC35BD69, NULL);
		V_2 = L_6;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_7 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_8 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 34)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_9;
		L_9 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_8, NULL);
		RuntimeObject* L_10;
		L_10 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_7, _stringLiteralC5F173ABE7214E8ED04EE91D0D5626EEDF0007E9, L_9, NULL);
		__this->____comparer = ((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35)));
		Il2CppCodeGenWriteBarrier((void**)(&__this->____comparer), (void*)((RuntimeObject*)Castclass((RuntimeObject*)L_10, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 35))));
		int32_t L_11 = V_2;
		if (!L_11)
		{
			goto IL_00c9;
		}
	}
	{
		int32_t L_12 = V_2;
		int32_t L_13;
		L_13 = Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B(__this, L_12, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 38)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		RuntimeObject* L_17;
		L_17 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_14, _stringLiteralCECF2650D3F261EAEF98CF86BF0563F906B4EB7A, L_16, NULL);
		V_3 = ((KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363*)CastclassSealed((RuntimeObject*)L_17, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_18 = V_3;
		if (L_18)
		{
			goto IL_007a;
		}
	}
	{
		ThrowHelper_ThrowSerializationException_m03BE2B48CD3617C32FBCEE16030F7C5563E04E16(((int32_t)16), NULL);
	}

IL_007a:
	{
		V_4 = 0;
		goto IL_00c0;
	}

IL_007f:
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_19 = V_3;
		int32_t L_20 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_21;
		L_21 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline(((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20))), NULL);
		goto IL_009a;
	}

IL_009a:
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_22 = V_3;
		int32_t L_23 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_24;
		L_24 = KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_inline(((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23))), NULL);
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_25 = V_3;
		int32_t L_26 = V_4;
		Il2CppSharedGenericObject* L_27;
		L_27 = KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_inline(((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26))), NULL);
		Dictionary_2_Add_mBAF54F5E97F92D0686B0446F5200E9AE8248D680(__this, L_24, L_27, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_28 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00c0:
	{
		int32_t L_29 = V_4;
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_30 = V_3;
		int32_t L_31 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_30)->max_length),NULL));
		if ((((int32_t)L_29) < ((int32_t)L_31)))
		{
			goto IL_007f;
		}
	}
	{
		goto IL_00d0;
	}

IL_00c9:
	{
		__this->____buckets = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)NULL);
	}

IL_00d0:
	{
		int32_t L_32 = V_1;
		__this->____version = L_32;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		ConditionalWeakTable_2_t381B9D0186C0FCC3F83C0696C28C5001468A7858* L_33;
		L_33 = HashHelpers_get_SerializationInfoTable_m8C17D5483B39B68897AEFFD14A9E139AF858222F(NULL);
		bool L_34;
		L_34 = ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E(L_33, (RuntimeObject*)__this, ConditionalWeakTable_2_Remove_mEA61545EA43662F3718895F4E435A1F3EFB9756E_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m923041BDE6BE4962A302162C644214A773DD97C0_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	{
		int32_t L_0 = __this->____count;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = HashHelpers_ExpandPrime_m9A35EC171AA0EA16F7C9F71EE6FAD5A82565ADB9(L_0, NULL);
		Dictionary_2_Resize_m9A7E6DE44A18A45A6E783210B518C26336A648BC(__this, L_1, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Resize_m9A7E6DE44A18A45A6E783210B518C26336A648BC_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_newSize, bool ___1_forceNewHashCodes, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_1 = NULL;
	int32_t V_2 = 0;
	SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	{
		int32_t L_0 = ___0_newSize;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		int32_t L_2 = ___0_newSize;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_3 = (EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392*)(EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 43), (uint32_t)L_2);
		V_1 = L_3;
		int32_t L_4 = __this->____count;
		V_2 = L_4;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_5 = __this->____entries;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_6 = V_1;
		int32_t L_7 = V_2;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, L_7, NULL);
		il2cpp_codegen_initobj((&V_3), sizeof(SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724));
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_8 = V_3;
		bool L_9 = ___1_forceNewHashCodes;
		if (!((int32_t)((int32_t)false&(int32_t)L_9)))
		{
			goto IL_0084;
		}
	}
	{
		V_4 = 0;
		goto IL_007f;
	}

IL_003e:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_10 = V_1;
		int32_t L_11 = V_4;
		int32_t L_12 = ((L_10)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_11)))->___hashCode;
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_0079;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_13 = V_1;
		int32_t L_14 = V_4;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_15 = V_1;
		int32_t L_16 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724* L_17 = (SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724*)(&((L_15)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_16)))->___key);
		int32_t L_18;
		L_18 = SamplerKey_GetHashCode_m65CFF629294833D2638E8331CCD322205A3F58E6(L_17, NULL);
		((L_13)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)))->___hashCode = ((int32_t)(L_18&((int32_t)2147483647LL)));
	}

IL_0079:
	{
		int32_t L_19 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_007f:
	{
		int32_t L_20 = V_4;
		int32_t L_21 = V_2;
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_003e;
		}
	}

IL_0084:
	{
		V_5 = 0;
		goto IL_00cb;
	}

IL_0089:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_22 = V_1;
		int32_t L_23 = V_5;
		int32_t L_24 = ((L_22)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_23)))->___hashCode;
		if ((((int32_t)L_24) < ((int32_t)0)))
		{
			goto IL_00c5;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_25 = V_1;
		int32_t L_26 = V_5;
		int32_t L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___hashCode;
		int32_t L_28 = ___0_newSize;
		V_6 = ((int32_t)(L_27%L_28));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_29 = V_1;
		int32_t L_30 = V_5;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = V_0;
		int32_t L_32 = V_6;
		int32_t L_33 = L_32;
		int32_t L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		((L_29)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)))->___next = ((int32_t)il2cpp_codegen_subtract(L_34, 1));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_35 = V_0;
		int32_t L_36 = V_6;
		int32_t L_37 = V_5;
		(L_35)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_36), (int32_t)((int32_t)il2cpp_codegen_add(L_37, 1)));
	}

IL_00c5:
	{
		int32_t L_38 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00cb:
	{
		int32_t L_39 = V_5;
		int32_t L_40 = V_2;
		if ((((int32_t)L_39) < ((int32_t)L_40)))
		{
			goto IL_0089;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_41 = V_0;
		__this->____buckets = L_41;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____buckets), (void*)L_41);
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_42 = V_1;
		__this->____entries = L_42;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____entries), (void*)L_42);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m875E41231D476577C9A3B051A475870CE8A41118_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0149;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = SamplerKey_GetHashCode_m65CFF629294833D2638E8331CCD322205A3F58E6((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_0142;
	}

IL_005c:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0138;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_21;
		L_21 = EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_22 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_23 = L_22->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_26 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_27 = L_26->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0138;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_39 = V_4;
		L_39->___hashCode = (-1);
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_40 = V_4;
		int32_t L_41 = __this->____freeList;
		L_40->___next = L_41;
		goto IL_00ff;
	}

IL_00ff:
	{
	}
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_42 = V_4;
		Il2CppSharedGenericObject** L_43 = (Il2CppSharedGenericObject**)(&L_42->___value);
		il2cpp_codegen_initobj(L_43, sizeof(Il2CppSharedGenericObject*));
	}

IL_0113:
	{
		int32_t L_44 = V_3;
		__this->____freeList = L_44;
		int32_t L_45 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_45, 1));
		int32_t L_46 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_46, 1));
		return (bool)1;
	}

IL_0138:
	{
		int32_t L_47 = V_3;
		V_2 = L_47;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_48 = V_4;
		int32_t L_49 = L_48->___next;
		V_3 = L_49;
	}

IL_0142:
	{
		int32_t L_50 = V_3;
		if ((((int32_t)L_50) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0149:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_mC4785D51723EC81C40756EDF5CC4D444308C37D9_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* V_4 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	RuntimeObject* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	RuntimeObject* G_B10_0 = NULL;
	RuntimeObject* G_B9_0 = NULL;
	bool G_B11_0 = false;
	{
		goto IL_000e;
	}

IL_000e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = __this->____buckets;
		if (!L_1)
		{
			goto IL_0156;
		}
	}
	{
		RuntimeObject* L_2 = __this->____comparer;
		RuntimeObject* L_3 = L_2;
		if (L_3)
		{
			G_B5_0 = L_3;
			goto IL_0032;
		}
		G_B4_0 = L_3;
	}
	{
		int32_t L_4;
		L_4 = SamplerKey_GetHashCode_m65CFF629294833D2638E8331CCD322205A3F58E6((&___0_key), NULL);
		G_B6_0 = L_4;
		goto IL_0038;
	}

IL_0032:
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_5 = ___0_key;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker1< int32_t, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(1, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B5_0, L_5);
		G_B6_0 = L_6;
	}

IL_0038:
	{
		V_0 = ((int32_t)(G_B6_0&((int32_t)2147483647LL)));
		int32_t L_7 = V_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_8 = __this->____buckets;
		int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
		V_1 = ((int32_t)(L_7%L_9));
		V_2 = (-1);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = __this->____buckets;
		int32_t L_11 = V_1;
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12));
		V_3 = ((int32_t)il2cpp_codegen_subtract(L_13, 1));
		goto IL_014f;
	}

IL_005c:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_14 = __this->____entries;
		int32_t L_15 = V_3;
		V_4 = ((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)));
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_16 = V_4;
		int32_t L_17 = L_16->___hashCode;
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_17) == ((uint32_t)L_18))))
		{
			goto IL_0145;
		}
	}
	{
		RuntimeObject* L_19 = __this->____comparer;
		RuntimeObject* L_20 = L_19;
		if (L_20)
		{
			G_B10_0 = L_20;
			goto IL_0095;
		}
		G_B9_0 = L_20;
	}
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_21;
		L_21 = EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2));
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_22 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_23 = L_22->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_24 = ___0_key;
		bool L_25;
		L_25 = VirtualFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(8, L_21, L_23, L_24);
		G_B11_0 = L_25;
		goto IL_00a2;
	}

IL_0095:
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_26 = V_4;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_27 = L_26->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_28 = ___0_key;
		bool L_29;
		L_29 = InterfaceFuncInvoker2< bool, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 35), G_B10_0, L_27, L_28);
		G_B11_0 = L_29;
	}

IL_00a2:
	{
		if (!G_B11_0)
		{
			goto IL_0145;
		}
	}
	{
		int32_t L_30 = V_2;
		if ((((int32_t)L_30) >= ((int32_t)0)))
		{
			goto IL_00be;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_31 = __this->____buckets;
		int32_t L_32 = V_1;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_33 = V_4;
		int32_t L_34 = L_33->___next;
		(L_31)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_32), (int32_t)((int32_t)il2cpp_codegen_add(L_34, 1)));
		goto IL_00d6;
	}

IL_00be:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_35 = __this->____entries;
		int32_t L_36 = V_2;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_37 = V_4;
		int32_t L_38 = L_37->___next;
		((L_35)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_36)))->___next = L_38;
	}

IL_00d6:
	{
		Il2CppSharedGenericObject** L_39 = ___1_value;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_40 = V_4;
		Il2CppSharedGenericObject* L_41 = L_40->___value;
		*(Il2CppSharedGenericObject**)L_39 = L_41;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_39, (void*)L_41);
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_42 = V_4;
		L_42->___hashCode = (-1);
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_43 = V_4;
		int32_t L_44 = __this->____freeList;
		L_43->___next = L_44;
		goto IL_010c;
	}

IL_010c:
	{
	}
	{
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_45 = V_4;
		Il2CppSharedGenericObject** L_46 = (Il2CppSharedGenericObject**)(&L_45->___value);
		il2cpp_codegen_initobj(L_46, sizeof(Il2CppSharedGenericObject*));
	}

IL_0120:
	{
		int32_t L_47 = V_3;
		__this->____freeList = L_47;
		int32_t L_48 = __this->____freeCount;
		__this->____freeCount = ((int32_t)il2cpp_codegen_add(L_48, 1));
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return (bool)1;
	}

IL_0145:
	{
		int32_t L_50 = V_3;
		V_2 = L_50;
		Entry_t5439A92D6B668EAF7881BCFD9BA5BBBED2318134* L_51 = V_4;
		int32_t L_52 = L_51->___next;
		V_3 = L_52;
	}

IL_014f:
	{
		int32_t L_53 = V_3;
		if ((((int32_t)L_53) >= ((int32_t)0)))
		{
			goto IL_005c;
		}
	}

IL_0156:
	{
		Il2CppSharedGenericObject** L_54 = ___1_value;
		il2cpp_codegen_initobj(L_54, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m7DE4D454A4DE22F7D0CA92573CC36B6E1C73FD7A_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject** ___1_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = ___0_key;
		int32_t L_1;
		L_1 = Dictionary_2_FindEntry_mED5A493AB5D73ACD0876C1CE489136038F251C81(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 26));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0025;
		}
	}
	{
		Il2CppSharedGenericObject** L_3 = ___1_value;
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_4 = __this->____entries;
		int32_t L_5 = V_0;
		Il2CppSharedGenericObject* L_6 = ((L_4)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_5)))->___value;
		*(Il2CppSharedGenericObject**)L_3 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(Il2CppSharedGenericObject**)L_3, (void*)L_6);
		return (bool)1;
	}

IL_0025:
	{
		Il2CppSharedGenericObject** L_7 = ___1_value;
		il2cpp_codegen_initobj(L_7, sizeof(Il2CppSharedGenericObject*));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryAdd_m1AB40C64C840DD0DA419ACEEF167A121F726597E_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 ___0_key, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = ___0_key;
		Il2CppSharedGenericObject* L_1 = ___1_value;
		bool L_2;
		L_2 = Dictionary_2_TryInsert_m924E9F944F2FBDDD67322A539CEC888CE94ACA10(__this, L_0, L_1, 0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_Generic_ICollectionU3CSystem_Collections_Generic_KeyValuePairU3CTKeyU2CTValueU3EU3E_CopyTo_mA0327B4ECDC72A9E28F08C903EDB46E941350686_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_0 = ___0_array;
		int32_t L_1 = ___1_index;
		Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96(__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_ICollection_CopyTo_m9204F38ACEAEEF0D106B9A07B0FED7B14E198E52_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* V_0 = NULL;
	DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* V_1 = NULL;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_2 = NULL;
	int32_t V_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_4 = NULL;
	int32_t V_5 = 0;
	EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* V_6 = NULL;
	int32_t V_7 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(3, NULL);
	}

IL_0009:
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0018;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0018:
	{
		RuntimeArray* L_3 = ___0_array;
		int32_t L_4;
		L_4 = Array_GetLowerBound_m4FB0601E2E8A6304A42E3FC400576DF7B0F084BC(L_3, 0, NULL);
		if (!L_4)
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(6, NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_index;
		RuntimeArray* L_6 = ___0_array;
		int32_t L_7;
		L_7 = il2cpp_codegen_array_get_length(L_6);
		if ((!(((uint32_t)L_5) > ((uint32_t)L_7))))
		{
			goto IL_0035;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0035:
	{
		RuntimeArray* L_8 = ___0_array;
		int32_t L_9;
		L_9 = il2cpp_codegen_array_get_length(L_8);
		int32_t L_10 = ___1_index;
		int32_t L_11;
		L_11 = Dictionary_2_get_Count_mCD0ED4AC38DA3D2F05E2129818FC98C046B09A36(__this, NULL);
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_10))) >= ((int32_t)L_11)))
		{
			goto IL_004b;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(5, NULL);
	}

IL_004b:
	{
		RuntimeArray* L_12 = ___0_array;
		V_0 = ((KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363*)IsInstSealed((RuntimeObject*)L_12, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 36)));
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_13 = V_0;
		if (!L_13)
		{
			goto IL_005e;
		}
	}
	{
		KeyValuePair_2U5BU5D_t4D96E38E13341AFEDB8AD3F567F38595C0357363* L_14 = V_0;
		int32_t L_15 = ___1_index;
		Dictionary_2_CopyTo_m7A8F2F3A2B94B720F0BA039413877BAD7B91AC96(__this, L_14, L_15, NULL);
		return;
	}

IL_005e:
	{
		RuntimeArray* L_16 = ___0_array;
		V_1 = ((DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533*)IsInstSealed((RuntimeObject*)L_16, DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533_il2cpp_TypeInfo_var));
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_17 = V_1;
		if (!L_17)
		{
			goto IL_00c3;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_18 = __this->____entries;
		V_2 = L_18;
		V_3 = 0;
		goto IL_00b9;
	}

IL_0073:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_19 = V_2;
		int32_t L_20 = V_3;
		int32_t L_21 = ((L_19)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_20)))->___hashCode;
		if ((((int32_t)L_21) < ((int32_t)0)))
		{
			goto IL_00b5;
		}
	}
	{
		DictionaryEntryU5BU5D_t410156653E754D17B5E1161CC6CF565103B63533* L_22 = V_1;
		int32_t L_23 = ___1_index;
		int32_t L_24 = L_23;
		___1_index = ((int32_t)il2cpp_codegen_add(L_24, 1));
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_25 = V_2;
		int32_t L_26 = V_3;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_27 = ((L_25)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)))->___key;
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_28 = L_27;
		RuntimeObject* L_29 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10), &L_28);
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_30 = V_2;
		int32_t L_31 = V_3;
		Il2CppSharedGenericObject* L_32 = ((L_30)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_31)))->___value;
		DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB L_33;
		memset((&L_33), 0, sizeof(L_33));
		DictionaryEntry__ctor_m2768353E53A75C4860E34B37DAF1342120C5D1EA((&L_33), L_29, (RuntimeObject*)L_32, NULL);
		(L_22)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_24), (DictionaryEntry_t171080F37B311C25AA9E75888F9C9D703FA721BB)L_33);
	}

IL_00b5:
	{
		int32_t L_34 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00b9:
	{
		int32_t L_35 = V_3;
		int32_t L_36 = __this->____count;
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0073;
		}
	}
	{
		return;
	}

IL_00c3:
	{
		RuntimeArray* L_37 = ___0_array;
		V_4 = ((ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)IsInst((RuntimeObject*)L_37, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = V_4;
		if (L_38)
		{
			goto IL_00d4;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
	}

IL_00d4:
	{
	}
	try
	{
		{
			int32_t L_39 = __this->____count;
			V_5 = L_39;
			EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_40 = __this->____entries;
			V_6 = L_40;
			V_7 = 0;
			goto IL_0130_1;
		}

IL_00ea_1:
		{
			EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_41 = V_6;
			int32_t L_42 = V_7;
			int32_t L_43 = ((L_41)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_42)))->___hashCode;
			if ((((int32_t)L_43) < ((int32_t)0)))
			{
				goto IL_012a_1;
			}
		}
		{
			ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_44 = V_4;
			int32_t L_45 = ___1_index;
			int32_t L_46 = L_45;
			___1_index = ((int32_t)il2cpp_codegen_add(L_46, 1));
			EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_47 = V_6;
			int32_t L_48 = V_7;
			SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_49 = ((L_47)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_48)))->___key;
			EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_50 = V_6;
			int32_t L_51 = V_7;
			Il2CppSharedGenericObject* L_52 = ((L_50)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_51)))->___value;
			KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 L_53;
			memset((&L_53), 0, sizeof(L_53));
			KeyValuePair_2__ctor_m62040016A6CE2E5FDD9B8A2BF034F1319CA0379D((&L_53), L_49, L_52, NULL);
			KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2 L_54 = L_53;
			RuntimeObject* L_55 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19), &L_54);
			ArrayElementTypeCheck (L_44, L_55);
			(L_44)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_46), (RuntimeObject*)L_55);
		}

IL_012a_1:
		{
			int32_t L_56 = V_7;
			V_7 = ((int32_t)il2cpp_codegen_add(L_56, 1));
		}

IL_0130_1:
		{
			int32_t L_57 = V_7;
			int32_t L_58 = V_5;
			if ((((int32_t)L_57) < ((int32_t)L_58)))
			{
				goto IL_00ea_1;
			}
		}
		{
			goto IL_0140;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0138;
		}
		throw e;
	}

CATCH_0138:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_59 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0140;
	}

IL_0140:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IEnumerable_GetEnumerator_m103F8ECFE4C53C3CE66C7DED28FE5DA2637974AA_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6((&L_0), __this, 2, NULL);
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Dictionary_2_EnsureCapacity_m6342F9FB1FA4BC92E342DBF7406970F3BC777847_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_000b;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m9B335696876184D17D1F8D7AF94C1B5B0869AA97(((int32_t)12), NULL);
	}

IL_000b:
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_1 = __this->____entries;
		if (!L_1)
		{
			goto IL_001d;
		}
	}
	{
		EntryU5BU5D_t72906D1BA9FD4ACF3E929A4298C85528E77BD392* L_2 = __this->____entries;
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		G_B5_0 = L_3;
		goto IL_001e;
	}

IL_001d:
	{
		G_B5_0 = 0;
	}

IL_001e:
	{
		V_0 = G_B5_0;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_capacity;
		if ((((int32_t)L_4) < ((int32_t)L_5)))
		{
			goto IL_0025;
		}
	}
	{
		int32_t L_6 = V_0;
		return L_6;
	}

IL_0025:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = __this->____buckets;
		if (L_7)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_8 = ___0_capacity;
		int32_t L_9;
		L_9 = Dictionary_2_Initialize_m4C165F502F6614716E6BE8855B7D572A712E1F8B(__this, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		return L_9;
	}

IL_0035:
	{
		int32_t L_10 = ___0_capacity;
		CHECKED_LOCAL_INIT(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_StaticInit,(HashHelpers_t75606750E152DB8C7289EB4163D3A728ED1A601A_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_11;
		L_11 = HashHelpers_GetPrime_m5B7AE10D5E76267579296C8F2CB8464AC2DE8472(L_10, NULL);
		V_1 = L_11;
		int32_t L_12 = V_1;
		Dictionary_2_Resize_m9A7E6DE44A18A45A6E783210B518C26336A648BC(__this, L_12, (bool)0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 45));
		int32_t L_13 = V_1;
		return L_13;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_System_Collections_IDictionary_set_Item_m2694C4A63B77413B73628C7467A7A6FFD8EF8A63_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 V_0;
	memset((&V_0), 0, sizeof(V_0));
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 2> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_key;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(5, NULL);
	}

IL_0009:
	{
		RuntimeObject* L_1 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_1, ((int32_t)15), NULL);
	}
	try
	{
		{
			RuntimeObject* L_2 = ___0_key;
			V_0 = ((*(SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 10))));
		}
		try
		{
			SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_3 = V_0;
			RuntimeObject* L_4 = ___1_value;
			Dictionary_2_set_Item_m03B251192DEED90E69DEE07C8E616FEB8AE6F720(__this, L_3, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_4, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 49));
			goto IL_003a_1;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
			{
				IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
				goto CATCH_0027_1;
			}
			throw e;
		}

CATCH_0027_1:
		{
			InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
			RuntimeObject* L_6 = ___1_value;
			RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 50)) };
			CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
			Type_t* L_8;
			L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
			ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_003a_1;
		}

IL_003a_1:
		{
			goto IL_004f;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_003c;
		}
		throw e;
	}

CATCH_003c:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_9 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_10 = ___0_key;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 51)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		ThrowHelper_ThrowWrongKeyTypeArgumentException_m90E5BCE2CB10EEC16F254C237121C6816C4D6982(L_10, L_12, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_004f;
	}

IL_004f:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Dictionary_2_System_Collections_IDictionary_GetEnumerator_m36230E3BF4A60DF65E48FAB4A7AC7DEB0EA38025_gshared (Dictionary_2_t1DDFAF26CC68586921A9D217B69BCC2DBFF6E290* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mF3B4AE6C4B85451BB3267277B2A62B96AD64EDB6((&L_0), __this, 1, NULL);
		Enumerator_t894A4A4916B0DA6A59DB797DDE1C5A4F904D667A L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 32), &L_1);
		return (RuntimeObject*)L_2;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t InternalManagedFileHandle_GetHashCode_mE32B81694AB4072CB85B3DB3AE79CCFC80D534D4_inline (InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___handle;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* EqualityComparer_1_get_Default_m56D88D65184F0E2CB43D9A2853637D9E87D10FC5_gshared_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* V_0 = NULL;
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_0 = ((EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mDDE2C10C48FE5C71172724020C00DA2C431DBF21(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t6AF08CEAD675C05C1B701806606C7CB7CF53951F* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A KeyValuePair_2_get_Key_mEFCCF9BC1F4022E15A29A44A49E8DE3FA5180978_gshared_inline (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_tCDFD7D7B4290217F286D3AC91BDF7C2A74C8636A L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m8A4C32B0E709D6A7629FA7869F673CC94F500282_gshared_inline (KeyValuePair_2_tA18DA0C0E7B0709B9741404F85570AF6334E7295* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* EqualityComparer_1_get_Default_mB451453B7B5B4B570A9347E090AB0FAC75C0C628_gshared_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* V_0 = NULL;
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_0 = ((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m9D6667E20D4FCBB62E2725016FE2FC32442FE530(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t483FA2A5A974208961219D26E3DCCEBF150EF081* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* EqualityComparer_1_get_Default_mF252A6DD8B0E68A7EC7F6356C3007FBCDC35877D_gshared_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* V_0 = NULL;
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_0 = ((EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mB0408C395999134DEDD71AB568D127159ACF5141(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t4515F567FF8CA58A31FECE4C986C6950AAF8A2CB* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A KeyValuePair_2_get_Key_mD0027E57B606342804BAAEE3B37C9C7FC77D90E3_gshared_inline (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, const RuntimeMethod* method) 
{
	{
		ValueTuple_2_t24B04C868EB44FD9AE1FE6B403964C5697775C8A L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m1B98DA271855EDA63BE7803194E15F9A7CEA3D25_gshared_inline (KeyValuePair_2_t64E764570967C9CF8DB9472130C0647F11D963A2* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* EqualityComparer_1_get_Default_m5DCC393F5D59545D96AF9FF747F17C72EABB5D3B_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* V_0 = NULL;
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_0 = ((EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mD3D60BAB4A1E7DF8FDC8779F5A1A3104CAD5202A(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_tAAD1A76C30594C4D736E586B3D77281A53A27399* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Guid_t KeyValuePair_2_get_Key_m9203ED457651489192177BEC5EBDC178E0F26BC7_gshared_inline (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, const RuntimeMethod* method) 
{
	{
		Guid_t L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m7FE87D795A3F1AD1B2E7FD1F96E5EF2A82785D93_gshared_inline (KeyValuePair_2_t33B859F0514253F5DB6552A6B2C5730871612D1B* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* EqualityComparer_1_get_Default_mF70F6C11A35B420DFA4628EE316B087F2DCB280C_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* V_0 = NULL;
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_0 = ((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m432C82F7354C37E610794C1DA866DFA7DAC9C35E(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t8576A23859AAB111A218EAE239E10E5E9E2D66FC* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t KeyValuePair_2_get_Key_mB0ED89FC7985F9676A84AF8FDFD3C6C53F478C90_gshared_inline (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m03EB6ADF69217A5128CE44A71DAAA98C5D33B9FB_gshared_inline (KeyValuePair_2_t4454A395593798308537E86AEE2BC94179CFFF55* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* EqualityComparer_1_get_Default_m1382B31A95228129ADB9427B1EE639C76AB507FD_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* V_0 = NULL;
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_0 = ((EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m538EEAA8DA010A259CC57D5123DA0B894EFC04BE(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t548453358AEB04B7C4B4DF9EE0955156132C3E35* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 KeyValuePair_2_get_Key_m53238783BDA24C812C5D63BCE9F25FE73F867243_inline (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, const RuntimeMethod* method) 
{
	{
		InternalManagedFileHandle_t1578FEE483FEB6924F10CD3016EFAA2A1B9FD391 L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 KeyValuePair_2_get_Value_mC76FA4AB276A8B74C6EFA434FC6F564522EB9710_inline (KeyValuePair_2_tE48FEF54701661F0E884F51FD75CBB53D546CBBE* __this, const RuntimeMethod* method) 
{
	{
		Binding_t4902D3C6D27680D096CC41D83FFD0872785E57F8 L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* EqualityComparer_1_get_Default_m2B4F62EDB23031C609551EC3F4671100D30E9CEA_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* V_0 = NULL;
	{
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_0 = ((EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m596C801639AA4AC5BAEF2ADC1E5651C7F99C400F(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t3D952F433060562F64447B640B1476ED9A9D9EE9* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* EqualityComparer_1_get_Default_mBE613CC2A0FAB4C2E91A5D5D0F58BE1F5C8ABA77_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* V_0 = NULL;
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_0 = ((EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_2;
		L_2 = EqualityComparer_1_CreateComparer_m05DA1830F41332AD085B970EE82FB91C62301E40(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t9E46AE2E7B581BF75F9691DE7270992239A3A184* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D KeyValuePair_2_get_Key_m9D928DE635B050E1F97664A11F5B6C105CF16CEA_gshared_inline (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, const RuntimeMethod* method) 
{
	{
		LifecycleScopeKey_t786C4635697BF09DC1C3BA0331E34017B8BA961D L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_mF92A29002E2960965121539DE507F10FF5E2F5DB_gshared_inline (KeyValuePair_2_tCE7171DB32002B487E575F4AD167DF3446BCB80C* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* EqualityComparer_1_get_Default_m11065C8CAFD25CFE8992E80622209D63C191DC72_inline (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* V_0 = NULL;
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_0 = ((EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer;
		il2cpp_codegen_memory_barrier();
		V_0 = L_0;
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_1 = V_0;
		if (L_1)
		{
			goto IL_0019;
		}
	}
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_2;
		L_2 = EqualityComparer_1_CreateComparer_mB189012E616E6286F0B1D722223BEDF80F3610A5(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1));
		V_0 = L_2;
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_3 = V_0;
		il2cpp_codegen_memory_barrier();
		((EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&((EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___defaultComparer), (void*)L_3);
	}

IL_0019:
	{
		EqualityComparer_1_t91560CE2A016EDCC631661A230134C9E5C5DA02B* L_4 = V_0;
		return L_4;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 KeyValuePair_2_get_Key_m0FF15B8C3D281DD691CE84C587BCDE80A5074A2B_gshared_inline (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, const RuntimeMethod* method) 
{
	{
		SamplerKey_t1E2C22A61428ADB9BFE857D544D6F900981F7724 L_0 = __this->___key;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* KeyValuePair_2_get_Value_m0ABF122C4CFC34EF4B31C221C6CE07BAD9F20FDE_gshared_inline (KeyValuePair_2_t4D6AF5D56A64454BE5AD5CA01AF50644FB9F67E2* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->___value;
		return L_0;
	}
}
