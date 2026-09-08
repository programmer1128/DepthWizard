#include "pch-cpp.hpp"





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
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*,T1,T2,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
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
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4;
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct InvokerFuncInvoker4<R, T1*, T2*, T3, T4>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3 p3, T4 p4)
	{
		R ret;
		void* params[4] = { p1, p2, &p3, &p4 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA;
struct Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4;
struct Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26;
struct Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75;
struct Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42;
struct Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5;
struct Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49;
struct Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3;
struct Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096;
struct Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3;
struct Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149;
struct ICollection_1_t2F3175F40296CA95AA8A5C57C142799F5E97B72D;
struct ICollection_1_t87485DA1BEDDEE4A8A7DA58E319F4191BABFC90E;
struct ICollection_1_t2F6DA5DC6268B254F0F306EAF9BC9938C0DDBF6D;
struct ICollection_1_t9ABDB7CFC022637CE635605675B689FD11182922;
struct ICollection_1_t31D65E205F8ED6E750D4A03D6638C7BC4BA4AC20;
struct ICollection_1_t58D5B5A564BF08CD3C8EE106100AC0D7B8C4508B;
struct ICollection_1_tB388ED908E2D241F56264CA971F25D9ADC1ADEC3;
struct ICollection_1_t7E71F1CA7971B264996E675DD23421D9B7165B6A;
struct ICollection_1_tA62A86C840971AC7E1018DED53CE9ECDE4B25035;
struct ICollection_1_t17FF839BF7E6E58666DFD1EF4BA5F4D216E5C16E;
struct ICollection_1_t423E33F1AAD9A8A6F88E4F39157863A3CDD81A96;
struct IComparer_1_tB8CD725562B920AC45F8E68E3A1052B58C5AD6FB;
struct IComparer_1_t9BAEEC72DF9894B1A0F3826CF6812F208068244D;
struct IComparer_1_t9DF9354BC388D0E545E4BBB3AAAD5A3AB709D94B;
struct IComparer_1_t8FAA43D4B9AB767E9923CC028420EAAB3BAD33E4;
struct IComparer_1_tAD74A890D5F3F781104F638EF5687D1DA40A0884;
struct IComparer_1_t3B0F39D062C0830CA6D3DD5C771FEF9D2E6F5DEF;
struct IComparer_1_tCA720E7837F12C38065A4AB632B5FAAD19EC30AA;
struct IComparer_1_t9A1CC2C8D88CCF81FC46F2CAF5CF3E1D9B82EFF9;
struct IComparer_1_t65DE0390A9D7CDEE5D1FA583A8AAC417A8B00F3F;
struct IComparer_1_t5C8ADB6DF803417A1731826FA07541C9E165AB71;
struct IComparer_1_t159FEB1B1070E2EE853CD70A3DAF125998EE03D3;
struct IEnumerable_1_t38653E65BFB6CE747A02D783EA1BEA73B4995B2B;
struct IEnumerable_1_t3F61FDEEAE104A39891E5CA9B338496257BADB95;
struct IEnumerable_1_tA2FC4917A884AB24D48B9CBA31A50DAD9ECD3EF2;
struct IEnumerable_1_t03F85466526BD0AB0636FF1CE70183856290B59E;
struct IEnumerable_1_tC2B9E01657A45403632F06E30115C40F92560A9A;
struct IEnumerable_1_t6D5FFB1B4A97F30426C5D394135AD0D2FAEAE680;
struct IEnumerable_1_t29E7244AE33B71FA0981E50D5BC73B7938F35C66;
struct IEnumerable_1_t9C73E2DA2A24734B7BEE3997930B156A82172C56;
struct IEnumerable_1_tEA49AFF11AE5182E575D731B33B5BBEE9EB916BD;
struct IEnumerable_1_t616D8494D191E02CD416B710E4C06389401F060C;
struct IEnumerable_1_t2D229B7B352B16330C5D8E4DAF312BE0526EBE44;
struct IEnumerator_1_t29A8CA7355FCD9DC17EBB7F096703BD8AD63C49F;
struct IEnumerator_1_t499CF02DC56C1921A0D86B172CC97758330CB992;
struct IEnumerator_1_tC47DEBDC515D4E344A7DCB28F43483CC5DC9F60D;
struct IEnumerator_1_tAFB9FBA3034F90362F7C09F78083B4ACC168DA5D;
struct IEnumerator_1_tB312AB790DDD5639D028F0FA6117392C85C40600;
struct IEnumerator_1_tB41B292FAFD525FC5C54D7E469F0BA1A193CA8B1;
struct IEnumerator_1_t75CB2681E18F7F2791528FA2CA60361FDB5DA08D;
struct IEnumerator_1_tF74C952F97E24A4AFD21162637D82942513CB35B;
struct IEnumerator_1_tD347B69D3F9B752863168A9BA3E7E7A42DBAEC81;
struct IEnumerator_1_tFA909B65895E40AAB1C8DD427FCA2D3EE869603F;
struct IEnumerator_1_t9C4BEE74A726ABB541B6A2B81ABEBF11CEA37C93;
struct IList_1_t835678CC92AE010F685ED67544269873DF628481;
struct IList_1_tD099B4DD7987C41E5C323C9C59337344B5F4041F;
struct IList_1_t53786F6CF126EF6AC995781BDA6501B2B14568EB;
struct IList_1_t33182A656A45B33468B108DFA2D9750890CBEC0F;
struct IList_1_tB2A201B6363DB5BFC62510E5B64E05F329955751;
struct IList_1_t7DC7A22F42EEFA1E8D796516A9F22282DF4EB5FA;
struct IList_1_t8AC59FFD0F90EC2DAD4C3FA39B2A5851F9D2987A;
struct IList_1_t4D7D7DAB02DB631C876CF3E68462F0FD9F9A8985;
struct IList_1_t166E7698F41C5D0654B5D8B28A6701DCEEBCB91F;
struct IList_1_t7B3BE05FF22559A6D63B8878D1E20E1F73864551;
struct IList_1_tD27D8B7ADCEC5D64ADFBFA86505E4FE8D79AE399;
struct List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366;
struct List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A;
struct List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D;
struct List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674;
struct List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696;
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255;
struct List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50;
struct List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A;
struct List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF;
struct Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1;
struct Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E;
struct Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844;
struct Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733;
struct Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0;
struct Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88;
struct Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107;
struct Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2;
struct Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C;
struct Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0;
struct Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C;
struct ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4;
struct ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A;
struct ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39;
struct ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649;
struct ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7;
struct ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263;
struct ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8;
struct ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8;
struct ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293;
struct ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E;
struct ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC;
struct MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885;
struct MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665;
struct ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297;
struct AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560;
struct OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88;
struct SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6;
struct Awaitable_t690337FEC1C411606E233EA36A41337B931C23CB;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MeshGeneratorBase_t6C56954644A9457966575809E396AF2F1BD746B2;
struct MeshPrimitiveBase_t26E5A8BE9E97DA0039445DC858015950DB66A500;
struct MethodInfo_t;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Type_t;
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeObject_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC;
struct MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885;
struct MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665;
struct ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918;
struct SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297;
struct AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560;
struct OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88;
struct SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366  : public RuntimeObject
{
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A  : public RuntimeObject
{
	MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D  : public RuntimeObject
{
	MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674  : public RuntimeObject
{
	ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696  : public RuntimeObject
{
	SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E  : public RuntimeObject
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A  : public RuntimeObject
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255  : public RuntimeObject
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50  : public RuntimeObject
{
	AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A  : public RuntimeObject
{
	OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF  : public RuntimeObject
{
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF  : public RuntimeObject
{
	RuntimeObject* ___list;
	RuntimeObject* ____syncRoot;
};
struct MemberInfo_t  : public RuntimeObject
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
struct Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ____list;
	int32_t ____index;
	int32_t ____version;
	Il2CppSharedGenericObject* ____current;
};
typedef Il2CppFullySharedGenericStruct Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF;
struct Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 
{
	List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ____list;
	int32_t ____index;
	int32_t ____version;
	int32_t ____current;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
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
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 
{
	MeshGeneratorBase_t6C56954644A9457966575809E396AF2F1BD746B2* ___generator;
	List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* ___m_Recipients;
};
struct MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_marshaled_pinvoke
{
	MeshGeneratorBase_t6C56954644A9457966575809E396AF2F1BD746B2* ___generator;
	List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* ___m_Recipients;
};
struct MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_marshaled_com
{
	MeshGeneratorBase_t6C56954644A9457966575809E396AF2F1BD746B2* ___generator;
	List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* ___m_Recipients;
};
struct MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 
{
	int32_t ___meshIndex;
	int32_t ___meshNumeration;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___primitives;
};
struct MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_marshaled_pinvoke
{
	int32_t ___meshIndex;
	int32_t ___meshNumeration;
	Il2CppSafeArray* ___primitives;
};
struct MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_marshaled_com
{
	int32_t ___meshIndex;
	int32_t ___meshNumeration;
	Il2CppSafeArray* ___primitives;
};
struct ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 
{
	uint64_t ___value;
};
struct SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A 
{
	MeshPrimitiveBase_t26E5A8BE9E97DA0039445DC858015950DB66A500* ___U3CPrimitiveU3Ek__BackingField;
	int32_t ___U3CVertexBufferIndexU3Ek__BackingField;
};
struct SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_marshaled_pinvoke
{
	MeshPrimitiveBase_t26E5A8BE9E97DA0039445DC858015950DB66A500* ___U3CPrimitiveU3Ek__BackingField;
	int32_t ___U3CVertexBufferIndexU3Ek__BackingField;
};
struct SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_marshaled_com
{
	MeshPrimitiveBase_t26E5A8BE9E97DA0039445DC858015950DB66A500* ___U3CPrimitiveU3Ek__BackingField;
	int32_t ___U3CVertexBufferIndexU3Ek__BackingField;
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
struct AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 
{
	Awaitable_t690337FEC1C411606E233EA36A41337B931C23CB* ___U3CAwaitableU3Ek__BackingField;
	int32_t ___U3CFrameIndexU3Ek__BackingField;
};
struct AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_marshaled_pinvoke
{
	Awaitable_t690337FEC1C411606E233EA36A41337B931C23CB* ___U3CAwaitableU3Ek__BackingField;
	int32_t ___U3CFrameIndexU3Ek__BackingField;
};
struct AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_marshaled_com
{
	Awaitable_t690337FEC1C411606E233EA36A41337B931C23CB* ___U3CAwaitableU3Ek__BackingField;
	int32_t ___U3CFrameIndexU3Ek__BackingField;
};
struct OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 
{
	int32_t ___order;
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___callback;
};
struct OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_marshaled_pinvoke
{
	int32_t ___order;
	Il2CppMethodPointer ___callback;
};
struct OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_marshaled_com
{
	int32_t ___order;
	Il2CppMethodPointer ___callback;
};
struct SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC 
{
	Il2CppChar ___First;
	Il2CppChar ___Last;
};
struct SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_marshaled_pinvoke
{
	uint8_t ___First;
	uint8_t ___Last;
};
struct SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_marshaled_com
{
	uint8_t ___First;
	uint8_t ___Last;
};
struct Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 
{
	List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* ____list;
	int32_t ____index;
	int32_t ____version;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ____current;
};
struct Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 
{
	List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* ____list;
	int32_t ____index;
	int32_t ____version;
	MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ____current;
};
struct Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 
{
	List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* ____list;
	int32_t ____index;
	int32_t ____version;
	MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ____current;
};
struct Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C 
{
	List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* ____list;
	int32_t ____index;
	int32_t ____version;
	ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ____current;
};
struct Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E 
{
	List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* ____list;
	int32_t ____index;
	int32_t ____version;
	SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ____current;
};
struct Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 
{
	List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* ____list;
	int32_t ____index;
	int32_t ____version;
	AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ____current;
};
struct Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 
{
	List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* ____list;
	int32_t ____index;
	int32_t ____version;
	OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ____current;
};
struct Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 
{
	List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* ____list;
	int32_t ____index;
	int32_t ____version;
	SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ____current;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
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
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA  : public MulticastDelegate_t
{
};
struct Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4  : public MulticastDelegate_t
{
};
struct Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26  : public MulticastDelegate_t
{
};
struct Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75  : public MulticastDelegate_t
{
};
struct Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42  : public MulticastDelegate_t
{
};
struct Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5  : public MulticastDelegate_t
{
};
struct Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49  : public MulticastDelegate_t
{
};
struct Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3  : public MulticastDelegate_t
{
};
struct Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096  : public MulticastDelegate_t
{
};
struct Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3  : public MulticastDelegate_t
{
};
struct Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149  : public MulticastDelegate_t
{
};
struct Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1  : public MulticastDelegate_t
{
};
struct Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E  : public MulticastDelegate_t
{
};
struct Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844  : public MulticastDelegate_t
{
};
struct Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733  : public MulticastDelegate_t
{
};
struct Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0  : public MulticastDelegate_t
{
};
struct Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88  : public MulticastDelegate_t
{
};
struct Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107  : public MulticastDelegate_t
{
};
struct Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2  : public MulticastDelegate_t
{
};
struct Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C  : public MulticastDelegate_t
{
};
struct Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0  : public MulticastDelegate_t
{
};
struct Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C  : public MulticastDelegate_t
{
};
struct ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields
{
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___s_emptyArray;
};
struct List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields
{
	MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___s_emptyArray;
};
struct List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields
{
	MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___s_emptyArray;
};
struct List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields
{
	ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___s_emptyArray;
};
struct List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields
{
	SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___s_emptyArray;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
};
struct List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___s_emptyArray;
};
struct List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields
{
	AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___s_emptyArray;
};
struct List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields
{
	OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___s_emptyArray;
};
struct List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields
{
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___s_emptyArray;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
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
struct JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC  : public RuntimeArray
{
	ALIGN_FIELD (8) JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 m_Items[1];

	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 value)
	{
		m_Items[index] = value;
	}
};
struct MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885  : public RuntimeArray
{
	ALIGN_FIELD (8) MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 m_Items[1];

	inline MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___generator), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Recipients), (void*)NULL);
		#endif
	}
	inline MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___generator), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___m_Recipients), (void*)NULL);
		#endif
	}
};
struct MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665  : public RuntimeArray
{
	ALIGN_FIELD (8) MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 m_Items[1];

	inline MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___primitives), (void*)NULL);
	}
	inline MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___primitives), (void*)NULL);
	}
};
struct ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918  : public RuntimeArray
{
	ALIGN_FIELD (8) ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 m_Items[1];

	inline ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 value)
	{
		m_Items[index] = value;
	}
};
struct SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE  : public RuntimeArray
{
	ALIGN_FIELD (8) SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A m_Items[1];

	inline SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CPrimitiveU3Ek__BackingField), (void*)NULL);
	}
	inline SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CPrimitiveU3Ek__BackingField), (void*)NULL);
	}
};
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppSharedGenericObject* m_Items[1];

	inline Il2CppSharedGenericObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Il2CppSharedGenericObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + il2cpp_array_calc_byte_offset(this, index);
	}
};
struct __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297  : public RuntimeArray
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
struct AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560  : public RuntimeArray
{
	ALIGN_FIELD (8) AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 m_Items[1];

	inline AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CAwaitableU3Ek__BackingField), (void*)NULL);
	}
	inline AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CAwaitableU3Ek__BackingField), (void*)NULL);
	}
};
struct OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88  : public RuntimeArray
{
	ALIGN_FIELD (8) OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 m_Items[1];

	inline OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___callback), (void*)NULL);
	}
	inline OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___callback), (void*)NULL);
	}
};
struct SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6  : public RuntimeArray
{
	ALIGN_FIELD (8) SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC m_Items[1];

	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC value)
	{
		m_Items[index] = value;
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m2B50D2C1D98DB40C529D7FE996EC7FEEC6352987 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 List_1_get_Item_m0C23C6923A01AF75684D6525409AEDE89F2DC43A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m7A59D91E09158E9F2EA14F7AFEB7F85E1A33E991 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mA7050FBBF764D7C2348D5C56EE6D5627827138FC (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m1AB47453401D23D3A09953C553FCC6114A68E6AC (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB2D00B8E4BC3D697FA727086AACBC28AAA1606F2_inline (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m45500246518715C5163937DD4F88B9E83C8FDCD2 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* __this, RuntimeObject* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m41D7127A668569920CAA0CE3A83FA6BCE7302347 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mE7D9087840ED42201AD016B57A1E7BC84CE0C185 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mC0DCAD2245FED3A39A8ACA137B3CD1CB8CC7152E (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m45A5B6A69CD56F9924919CA096EDBA357C65D75A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m2C93E027F6C3A135BB88D85AB891DCE3395EA99F (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m798E5A0C143433BFCAF602F2FFEC4B7DA1932BB5_inline (Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mAFFE93EC5DE0EEB64AC0A88BDF6A137BBF7F39C6 (Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5* __this, List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mCD89004E22CB4FEB73672DD2830E315DDA4DA3BE (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m363B214B205FDF1A10DFB2AD28449D3A3A573352 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mEF7CA22D83DD6F0A16EDDCA311C51A00D106D2C1 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAFB3BAC249C296F3A7EEEC88F411F6778EF9FBD5 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9EFEB672652EFD451C646ED0D66FA66C8AEA5DAE (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m72083CFA42FDE71DFAAF45904EAA134C889E43E8 (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mCF3B2040A3635457AFCEBFCFC234F823464E0536 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m3B906B4372F67902D2B72C42125E132BB2E2149F (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m645207130D9695240E4F77E44F1743B8369997ED (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mD7C118A83F4784EC66EB43D7A8B700015DCD398B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 List_1_get_Item_mD3B34BD1058003A2FC43C62F59E07B072C97AA58 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mEEF54CA41E38545E629EBB0374D6E430EABEAF1F (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m50870FEFDAE3AFFDC15A9581BDB14F881D63C504 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m558B41D2F2078B4DA929652106E89D5677D85DCD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mAA147597B0A6147B89C99C55D9DFA93A8AE79D26_inline (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m0475AC2C14A7B4FB4FAF0D6233A5782301AC48D3 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m77BA02C38C869607A5A2939A6A4F54C07F703495 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m0E65F65ACB45DC1A077B1798336BCF5B5B702184 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m814BAC895FA3E4F5098F22A9D33E8C9BFFBFB0BC (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mFB6F8456DD804108255872FAA0513D909B08050B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m0D5C6A44576D63BD85484E84C4E6CFFF935067DD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m757CF429A07F24116D98E8A834EE7D2EB3D3315E_inline (Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m4B9AB13F18ADC5263C10CB458E2597AA2784A2B7 (Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349* __this, List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_m6793F227DC9835EB5670F546DF97C0067C4236E7 (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m1B00558DE5FBE0526AD54D7A0A0151E9AC629FB7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m42406B184BCFD8B07CB5E22E79319A23CBDE7364 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mEA589FD44B8A9073BCFD186FFAAC46AA7911A19F (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9FB23CE117B4CF6DDD423E39A236480D810B3282 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mF1978C21CF5FA17E42C679D8BB57D636AC23F6C5 (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mE9545D4ADD4ADB084A98373037F4BE24734E098E (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_m5AAF0F2CACE2984B8C26664CF5F0A63446534288 (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m3AD6D0B2420C89E417F45A3CF8D1050B0A8DB0EA (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m257232CDC0FA2092642566E880B6A8F8460AAF9C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 List_1_get_Item_m32848DA458A095251347E07C9FD1C51F61620CA2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m4E7CEEF7D8FA269C8F796E920E93F2D618598881 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m57BEC2D922431257A06EC60BE8FBCACA58965ED9 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mE5072267E528FE731CDE3FF1E7FDA08392A07B86 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m85AF4AC8BAFE2D698178F1CC64EBF5587C8C501B_inline (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m402027003A6F9027A1F261FEC78D1396BE4B8CD7 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m7EB1ECC074B3AF437C63AD042B76592D81316E4D (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mC6F7CC8E9ADF553B42A35F3122037BE3C62F8C70 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4B7DA9C244F266A0DA8E5E4020AD0B366A8C3437 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m1047F3DD0314BDB3C4A459FD468B668C3289D67F (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mF5C6590EFA98412BDA86C1F83C117F811D68004C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mB1CA85C8D3E3D6E0E2236B0CEE4C32387ACF690B_inline (Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mAFCDB0F6CA2E77D7A2E959C24FFEEC052AAE4DEE (Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1* __this, List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m70030F87B9DDCD44A4CB969B6B2D1C5F368241F2 (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mDF7643E5C561584BA74E27A20C2F68716DAAD6C2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m74729BC4F6DF62D8A9A45F18D2A66CDC597446D7 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mC3AED5A1C5D19EBA136856CA89192AE43ACAD5E6 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m4617AE24F45FCDF94C51574002B2954595221181 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m38DB51F29444C606428313B22FAF8F1C80E1AEBB (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m3E46FDA75F13334644C38A5C0E10761FF1489DB1 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m16BC1A4D1FEC2786910CF8CFE949C41132CC607C (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_mA8C548AF368EBC4C8D499C23D1411C95D8AD9A7F (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m4E122E2502A8627C778FE4556937C624B46C7997 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 List_1_get_Item_mD173DE9CD6A82455F2B1CB9778BE90B63FF73391 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_mA91A20BD242392A65004CD8897E77F0A9BA80940 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mB2BEDCB542156BEC23496A84CFE200BC8782E57D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m28AFC3F6D5F6FE74B5CC7A3E42AC5CC6FFE0F2B8 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mF04CCC12DEF9C866AC5DC5330FDC48AB65CCA024_inline (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m2E53EA9AC569CA67C76F3C118E063BBCF7704CAE (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m69A02C552A18C10D19C781295373AB8A8AEE5031 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m4F61B731116EA18BCF77D3B5EA97CC7F6B74BA8E (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mD8BB26D8A824572630E9C0E3F4D1DC9A3120F44A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5206BE528EF098F0A05B20F06F65AF72FD28CC3D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m7B4E901E789CE8CC54DA8AEDA0C3E6080E58EA7A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m34AFEF07BE56D23BA7F5BA2338AC3C3F1ED777CF_inline (Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m835D87EAED18476EAAF9606BFFC75C69A7EF65A8 (Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C* __this, List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m8332FAAEA1F00BD676F75CB7D21BDDE5EB8108FC (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m87451DF4EDEDCFD7A4F723FD3862823FC8208F03 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m193AD81345965E50C83F85222E0549DC26D12328 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mCE97C009362B0A9CD4552C1B51C5E2A86246CA15 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m6AFF276121D16C2E2B20450B50341A6290ADEB1A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m21433AAF5C37ED5C37B245798D8BED8D43C21BF4 (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m741493F9355B59A4913E75FC9DBAF48FF66DFA57 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m15B3CC39BEC812E83A1A2CE71AE193200A9E1762 (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m7051900D4D21A46096B77E03BE73D6D5907DA7E4 (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m000A063D523E65A4E1203650A1E641FBAB58A3A4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A List_1_get_Item_m5C5E1087CA1987F3BE88388D61E2519540515D8B (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m2FF5778E81554EE8518E94C1558A2151BE61E882 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m2DD04D9528C97840C206D163D7AB4C4746B3AC76 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mA45CBC1217C83D9A3C45A71418C0C0A0CAB84CB2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mF7AE8B1682DB8CD2AC096A7E9C663F5B3BE8C1DD_inline (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m26941567807B2151919C524E13D4C4E8E42F26F2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mDA90966E8C972CE14F1DE68EC09D9707DE7E765F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m7968A21E8BC7720D75B4A7DC9CB7993BA34CEF33 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mBCE4AAC95175F191A52172F644F3FFF322464C1B (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m68606F21AB0128430A2ED0424923862135939AD1 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA42311457F2CCA0F203C805138AEFEE0693553A6 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m3F752265B16661803674C43E5FDFFD81C013F9A4_inline (Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m91240E54A2967AC6B72557637B8A364E9D0F393B (Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E* __this, List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m499630D76B859F59FAE8A81C60907432FA38D379 (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m3FC18BE3FD757F2B4D57CA1B9589C8427445BEF8 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m8A7E83E4842DBB59FAF2DFADFB4DC664C0948DCA (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m5FA9171FC0D0CB0563B035E48CA180082E5982A4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m08CDE27F94AF0C016011BB7D8DE3456C30D833D4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m1F4D1131DC87845F783651159C17228A913048CF (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mBDDC76902E0EB7C0EBE4574128461479E50C44AC (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m0D98180CBD3D2C2DF5A5735C6CFC7330C902D5D5 (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_mA38A719A6AD2F29AF7125A22D7CD26CC32657EC3 (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054_gshared (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_gshared_inline (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9_gshared (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, Il2CppSharedGenericObject* ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970_gshared (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50_fshared (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m70DD3FB3C4E302AA0AACC45C39BCEC4C2A9DB230_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m835718C92D2C5DA2051794F6922D21453EAC493E_gshared (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mCDBFFAC056B77CBE377B26CAED3E893C131F4EFB_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m3B53F17525936469654379AC0F1F0B19EC3DCCE5_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m24BA4DEDED426A5B0C6A4AB3E523C876B0B918A6_gshared_inline (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m99F96BAC4A4EE626A6141612A5C6793BE37E006C_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m61A085CF349BFF87A90BE6FEE413C548F3F9E567_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m7AA13FF7BE1A11F437B16EAE3E1FA50DBFC902AE_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mC9F71DEB213A8D42EBC3A47798AAF6CD140438CA_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_gshared_inline (Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* __this, int32_t ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m0B844022E6FED4C6DA8CD7C270989D9D34800C69_gshared (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m9AE979627DAA17E8B9E3EF440A130C1B9C245059_gshared (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m8C3391D73E5396E7FD12A5DA1CEDDD0A83EAAB79_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mBA121E6727BDC54EB17A84709997D6920BBE4D10_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAF82A7B6E01FEB6F200C76071F76554EE4B35DB8_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m34A5681B1296F6E4F08C9F0986F4E4F1CF23FBE4_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mA4406A8C17BBC29625F80F783EA91C3AECF7E3EA_gshared (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m29868C70BFD9DDFB44E31BF13302FB7AB5244913_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE004CFE5BA4856AC83A08DEA9F09D3224F3EDD7B_gshared (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_mCDDF2BDFA2ACB2C2254C52BBD32AD774C7C05CDC_gshared (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mB565A7AD8E82EBD46650B3F0E052900CE12DF2C5 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 List_1_get_Item_m4077C3878C73CFD2C37863B24FFABC93CCB538C2 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m668408E30034D9AF162BA065A1B8A9190CCB854C (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9EE840E6FBE06791D954E7A69D53CE90EFCB863D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCA55981D47453F8483BD503CA53B0DABBDB8844D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mC35682C02D89984B864B24B3BB4F92B5C2374273_inline (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m830DE1B798DA2F877FBFF052C8841D220839E942 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mCB5DDE85A3BF1B0AE48D46EB6E22999A0E4D060D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9AA36809C4850F3957B1A0B552645A8F328B7158 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m82EC683EFB57714A07D26CB6E17D84FFAE7C82AE (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m3332E89182E608A4BF6BE672CB719B8B0067984C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m6C63371ECE0863BF14A70E4012C6A62D66B5F5D7 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m8D40905BAEF5849C9DF55268BB4FD2C8CB0A1A79_inline (Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m3B885E0CB5C32229381BEF0AD2CE4682713CA0EC (Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5* __this, List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m075DCC6CC6C5E2D552CC01B5A5D93D761529CC5E (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mFF1B561AB8F89B1761C15D1863C00ED3AD7BF324 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m252525485F467F26DB5C91A957EA9F842D005C40 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mA7E179931948DD88B825B2851F0BB01856B70460 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mBDDBB14EC973F164BA222AEB240F57B8460DAC1C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_mB7050783F04AD0453F190FBF1F3F6A2B6CB59506 (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m1CAB75B85D1547C184E1CA824E4A29E11269376E (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m9D7F79A00D6CDEEE91A7009E9C83C8A9190FCA23 (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m46BFEDFA8C5CE90310AFB562E0DE7A7E83E3BFEF (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mA6E73354873BEAC5429A80AE43CB210589A7EC7E (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 List_1_get_Item_mB65D799560ADD289EA08E717412A24EFADA7FB57 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m054615FD6A62EE7702B344B2E24BA8423FEF9621 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m7533012D6C4CE083D5CAF670259B97F6D5D506F4 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m8B3D79788ADC2B54C9B12CC9EC1158E6A04CDEBC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB308EE5BFFD89A7B8C251644D76CA547456F3012_inline (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m9AA9E2C5627FB6CD9F3493CA8A99588EDA08125D (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mFA6A5CD427374237339591ED8A5218B6E7EA7F4C (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mA2F95E82C59734A475035EF3B9DD4BCE9F8429DB (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m590D7926DA2B45C95850710F87644BCD235F1A70 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mC49015D45A78A39909C4541BDB84DAA369E6A4C1 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA5DDCB0CBD1B539DB3213A4B3AE1C72E519C98A8 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m182E0ACAA85455151F5750CE87F942DA6E3DD3D6_inline (Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mCAD56839187542C3B25E2C1493BBD62861333E4E (Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251* __this, List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m972A3CE5298A6193E512B34C64201444B051D8E9 (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mF138D66498A5DE06E21A7149C35FA14729F4F5E1 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m30CC1D4CA1984DCAEDBCD2228B538A0503AF854A (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m02DCEAFFE826B31F80767A9D191CB4587D82F7BC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m5903E8D5CE5B92A29530763E182314BDFA781664 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_mDCB49D07F30FD9D952124968159FDF346234BD04 (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mEBED487B845A66E3298CA30654B7EC17F7481995 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m438D9EDDBF93A09C81E89458C2362F85487923EC (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m4A8362BBA870329F45001F17310B50E583BFF19F (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mDF2147E522AD80A7B6A79CF8E7F00EC7DBF8A032 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC List_1_get_Item_mAAE7FBDBD94CC48BA01C01ACFC3C66EE219110D0 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m85CB6FEF509A4859399929F09F545FA1133C3051 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m58893707EC3B663186D1550A23DE96C818416CBD (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m594A4155F206677F45ECD9AAE7E9EFD0AE6137ED (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m624C469B79ADC28E429B7A3CA96DA72345621643_inline (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m8C743BAB2CDB84037FE830DF12A8B561EFEEEA60 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mF5A7DA78EA07100BDE8044CA37C505F36AD7ACB1 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mC9CB5EB21839923C050E6922FE7050867F374865 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mA5832B215E464CAC8345E7ECC45562E884AE146D (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m40FE27C2AB4F6F5F863957210FA90C1BF581D293 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA8A19319FB31E9FB37C309AB8938A9FE57AA5C9F (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mADD6CFDE192E3E822D5296926054ED8A41DB09C4_inline (Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m159144864209387AA18DEABE7B7985388F8F3452 (Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9* __this, List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m5A2EB67A073F2BFF5B3DCDDBD15D75BC3CFB909C (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC8E7189F3D9D95975CFE821AC3B560B2EA7AB7A8 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m911F1AFFA59FD181BA9363E0B6C8B5B95067EC3B (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mA8E72E7CFB72101AA88E01A84F746ECBD8E91B3F (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m6558ECB96638BF339DAB6BDB70413BA7570A84F9 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_mD8F006C0A007C05BB69E417FA65A5A66965F997C (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m4F48B52D720DB8E76904DB4647F7BDA63FDEC552 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_mE6A4B57DE0CB3DEC8371BDC3DAAAD29D6C9E3B2B (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m3182DABDA1EFACFF8268887837CA976A3577C3E6 (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149* ___3_comparer, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F (int32_t ___0_argument, int32_t ___1_resource, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC (int32_t ___0_argument, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m2B50D2C1D98DB40C529D7FE996EC7FEEC6352987 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41 (RuntimeArray* ___0_sourceArray, int32_t ___1_sourceIndex, RuntimeArray* ___2_destinationArray, int32_t ___3_destinationIndex, int32_t ___4_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 List_1_get_Item_m0C23C6923A01AF75684D6525409AEDE89F2DC43A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m7A59D91E09158E9F2EA14F7AFEB7F85E1A33E991 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mA7050FBBF764D7C2348D5C56EE6D5627827138FC (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910 (RuntimeObject* ___0_value, Type_t* ___1_targetType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m1AB47453401D23D3A09953C553FCC6114A68E6AC (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB2D00B8E4BC3D697FA727086AACBC28AAA1606F2_inline (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m4E48119598FA460677D2C289DC20E34CA77CF88B_inline (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m45500246518715C5163937DD4F88B9E83C8FDCD2 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m8C7151A8D9C1BC6806FD1F287DB6B84C525580BD (ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m41D7127A668569920CAA0CE3A83FA6BCE7302347 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mE7D9087840ED42201AD016B57A1E7BC84CE0C185 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mC0DCAD2245FED3A39A8ACA137B3CD1CB8CC7152E (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_mB41442EF87F813746221E22F4BCE10475E99BAAA (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366*, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m45A5B6A69CD56F9924919CA096EDBA357C65D75A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m2C93E027F6C3A135BB88D85AB891DCE3395EA99F (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* ___2_match, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7 (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m798E5A0C143433BFCAF602F2FFEC4B7DA1932BB5_inline (Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mAFFE93EC5DE0EEB64AC0A88BDF6A137BBF7F39C6 (Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5* __this, List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mCD89004E22CB4FEB73672DD2830E315DDA4DA3BE (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m363B214B205FDF1A10DFB2AD28449D3A3A573352 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mEF7CA22D83DD6F0A16EDDCA311C51A00D106D2C1 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAFB3BAC249C296F3A7EEEC88F411F6778EF9FBD5 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA (int32_t ___0_resource, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9EFEB672652EFD451C646ED0D66FA66C8AEA5DAE (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m72083CFA42FDE71DFAAF45904EAA134C889E43E8 (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mCF3B2040A3635457AFCEBFCFC234F823464E0536 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m3B906B4372F67902D2B72C42125E132BB2E2149F (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m645207130D9695240E4F77E44F1743B8369997ED (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mD7C118A83F4784EC66EB43D7A8B700015DCD398B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 List_1_get_Item_mD3B34BD1058003A2FC43C62F59E07B072C97AA58 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mEEF54CA41E38545E629EBB0374D6E430EABEAF1F (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m50870FEFDAE3AFFDC15A9581BDB14F881D63C504 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m558B41D2F2078B4DA929652106E89D5677D85DCD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mAA147597B0A6147B89C99C55D9DFA93A8AE79D26_inline (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m2ACC476BFEA27BBE68DA9C9C58C962EBBA411D15_inline (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m0475AC2C14A7B4FB4FAF0D6233A5782301AC48D3 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m3771FF52DBB5BC05AFD2504630EF17DDC9619B85 (ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m77BA02C38C869607A5A2939A6A4F54C07F703495 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m0E65F65ACB45DC1A077B1798336BCF5B5B702184 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m814BAC895FA3E4F5098F22A9D33E8C9BFFBFB0BC (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m1D96B6E41C3609C753D7BC5958F9D84F0B4AC28D (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A*, MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mFB6F8456DD804108255872FAA0513D909B08050B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m0D5C6A44576D63BD85484E84C4E6CFFF935067DD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m757CF429A07F24116D98E8A834EE7D2EB3D3315E_inline (Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m4B9AB13F18ADC5263C10CB458E2597AA2784A2B7 (Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349* __this, List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_m6793F227DC9835EB5670F546DF97C0067C4236E7 (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m1B00558DE5FBE0526AD54D7A0A0151E9AC629FB7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m42406B184BCFD8B07CB5E22E79319A23CBDE7364 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mEA589FD44B8A9073BCFD186FFAAC46AA7911A19F (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9FB23CE117B4CF6DDD423E39A236480D810B3282 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mF1978C21CF5FA17E42C679D8BB57D636AC23F6C5 (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mE9545D4ADD4ADB084A98373037F4BE24734E098E (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_m5AAF0F2CACE2984B8C26664CF5F0A63446534288 (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m3AD6D0B2420C89E417F45A3CF8D1050B0A8DB0EA (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m257232CDC0FA2092642566E880B6A8F8460AAF9C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 List_1_get_Item_m32848DA458A095251347E07C9FD1C51F61620CA2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m4E7CEEF7D8FA269C8F796E920E93F2D618598881 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m57BEC2D922431257A06EC60BE8FBCACA58965ED9 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mE5072267E528FE731CDE3FF1E7FDA08392A07B86 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m85AF4AC8BAFE2D698178F1CC64EBF5587C8C501B_inline (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_mC59DC4CDF255755CEADE65B05E09EBDFD3D213C8_inline (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m402027003A6F9027A1F261FEC78D1396BE4B8CD7 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m80A07CEFE2201F368C4819FEDFDA2D7B33CB9340 (ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m7EB1ECC074B3AF437C63AD042B76592D81316E4D (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mC6F7CC8E9ADF553B42A35F3122037BE3C62F8C70 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4B7DA9C244F266A0DA8E5E4020AD0B366A8C3437 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_mD784AB7B5A8C0265310092FA4DDC3ECEA422E1F2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D*, MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m1047F3DD0314BDB3C4A459FD468B668C3289D67F (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mF5C6590EFA98412BDA86C1F83C117F811D68004C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mB1CA85C8D3E3D6E0E2236B0CEE4C32387ACF690B_inline (Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mAFCDB0F6CA2E77D7A2E959C24FFEEC052AAE4DEE (Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1* __this, List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m70030F87B9DDCD44A4CB969B6B2D1C5F368241F2 (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mDF7643E5C561584BA74E27A20C2F68716DAAD6C2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m74729BC4F6DF62D8A9A45F18D2A66CDC597446D7 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mC3AED5A1C5D19EBA136856CA89192AE43ACAD5E6 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m4617AE24F45FCDF94C51574002B2954595221181 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m38DB51F29444C606428313B22FAF8F1C80E1AEBB (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m3E46FDA75F13334644C38A5C0E10761FF1489DB1 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m16BC1A4D1FEC2786910CF8CFE949C41132CC607C (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_mA8C548AF368EBC4C8D499C23D1411C95D8AD9A7F (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m4E122E2502A8627C778FE4556937C624B46C7997 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 List_1_get_Item_mD173DE9CD6A82455F2B1CB9778BE90B63FF73391 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_mA91A20BD242392A65004CD8897E77F0A9BA80940 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mB2BEDCB542156BEC23496A84CFE200BC8782E57D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m28AFC3F6D5F6FE74B5CC7A3E42AC5CC6FFE0F2B8 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mF04CCC12DEF9C866AC5DC5330FDC48AB65CCA024_inline (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m9F65F44EDFFE199D00E71A358851A11FBF35CA0D_inline (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m2E53EA9AC569CA67C76F3C118E063BBCF7704CAE (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_mD5AEE0B0FFB019B42DCCDB57A1C2F680C1FD1702 (ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m69A02C552A18C10D19C781295373AB8A8AEE5031 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m4F61B731116EA18BCF77D3B5EA97CC7F6B74BA8E (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mD8BB26D8A824572630E9C0E3F4D1DC9A3120F44A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m991F7CA6913952712B14D32980B84A10304DCFC0 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674*, ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5206BE528EF098F0A05B20F06F65AF72FD28CC3D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m7B4E901E789CE8CC54DA8AEDA0C3E6080E58EA7A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m34AFEF07BE56D23BA7F5BA2338AC3C3F1ED777CF_inline (Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m835D87EAED18476EAAF9606BFFC75C69A7EF65A8 (Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C* __this, List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m8332FAAEA1F00BD676F75CB7D21BDDE5EB8108FC (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m87451DF4EDEDCFD7A4F723FD3862823FC8208F03 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m193AD81345965E50C83F85222E0549DC26D12328 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mCE97C009362B0A9CD4552C1B51C5E2A86246CA15 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m6AFF276121D16C2E2B20450B50341A6290ADEB1A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m21433AAF5C37ED5C37B245798D8BED8D43C21BF4 (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m741493F9355B59A4913E75FC9DBAF48FF66DFA57 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m15B3CC39BEC812E83A1A2CE71AE193200A9E1762 (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m7051900D4D21A46096B77E03BE73D6D5907DA7E4 (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m000A063D523E65A4E1203650A1E641FBAB58A3A4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A List_1_get_Item_m5C5E1087CA1987F3BE88388D61E2519540515D8B (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m2FF5778E81554EE8518E94C1558A2151BE61E882 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m2DD04D9528C97840C206D163D7AB4C4746B3AC76 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mA45CBC1217C83D9A3C45A71418C0C0A0CAB84CB2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mF7AE8B1682DB8CD2AC096A7E9C663F5B3BE8C1DD_inline (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m4776AE016DEBA009A6380C97D690FCD4F31FDFA8_inline (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m26941567807B2151919C524E13D4C4E8E42F26F2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m104CDCAAC255F5457FF6A064CCA66855BB2FED8F (ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mDA90966E8C972CE14F1DE68EC09D9707DE7E765F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m7968A21E8BC7720D75B4A7DC9CB7993BA34CEF33 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mBCE4AAC95175F191A52172F644F3FFF322464C1B (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_mEEA1C37F8203884D4AF5B98E4DE6E296C4D8B8EA (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696*, SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m68606F21AB0128430A2ED0424923862135939AD1 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA42311457F2CCA0F203C805138AEFEE0693553A6 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m3F752265B16661803674C43E5FDFFD81C013F9A4_inline (Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m91240E54A2967AC6B72557637B8A364E9D0F393B (Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E* __this, List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m499630D76B859F59FAE8A81C60907432FA38D379 (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m3FC18BE3FD757F2B4D57CA1B9589C8427445BEF8 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m8A7E83E4842DBB59FAF2DFADFB4DC664C0948DCA (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m5FA9171FC0D0CB0563B035E48CA180082E5982A4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m08CDE27F94AF0C016011BB7D8DE3456C30D833D4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m1F4D1131DC87845F783651159C17228A913048CF (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mBDDC76902E0EB7C0EBE4574128461479E50C44AC (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m0D98180CBD3D2C2DF5A5735C6CFC7330C902D5D5 (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_mA38A719A6AD2F29AF7125A22D7CD26CC32657EC3 (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42* ___3_comparer, const RuntimeMethod* method) ;
inline void List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, RuntimeObject*, const RuntimeMethod*))List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79_gshared)(__this, ___0_enumerable, method);
}
inline Il2CppSharedGenericObject* List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515_gshared)(__this, ___0_index, method);
}
inline void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054_gshared)(___0_value, ___1_argName, method);
}
inline void List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF_gshared)(__this, ___0_index, ___1_value, method);
}
inline void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared)(__this, ___0_item, method);
}
inline void List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_min, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5_gshared)(__this, ___0_min, method);
}
inline void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline)(__this, ___0_item, method);
}
inline int32_t List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
inline void List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804_gshared)(__this, ___0_index, ___1_collection, method);
}
inline void ReadOnlyCollection_1__ctor_mC1890FAC00703F47A655C35CBCB613C74A811580 (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
inline int32_t List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9_gshared)(__this, ___0_item, method);
}
inline bool List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26 (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26_gshared)(___0_value, method);
}
inline bool List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE_gshared)(__this, ___0_item, method);
}
inline void List_1_CopyTo_m75919E1737F4EC8D7DD329629C11CACA64EF5BE3 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
inline void List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6_gshared)(__this, ___0_value, method);
}
inline int32_t List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88*, const RuntimeMethod*))List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D_gshared)(__this, ___0_startIndex, ___1_count, ___2_match, method);
}
inline bool Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88*, Il2CppSharedGenericObject*, const RuntimeMethod*))Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_gshared_inline)(__this, ___0_obj, method);
}
inline void Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9 (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, const RuntimeMethod*))Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9_gshared)(__this, ___0_list, method);
}
inline int32_t Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, Il2CppSharedGenericObject* ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Il2CppSharedGenericObject*, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline void List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E_gshared)(__this, ___0_index, ___1_item, method);
}
inline void List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, const RuntimeMethod*))List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C_gshared)(__this, ___0_index, method);
}
inline bool List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Il2CppSharedGenericObject*, const RuntimeMethod*))List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796_gshared)(__this, ___0_item, method);
}
inline void List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, const RuntimeMethod*))List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99_gshared)(__this, ___0_index, ___1_count, method);
}
inline void Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method)
{
	((  void (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, const RuntimeMethod*))Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541_gshared)(___0_array, ___1_index, ___2_length, method);
}
inline void List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method)
{
	((  void (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A_gshared)(__this, ___0_index, ___1_count, ___2_comparer, method);
}
inline void Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61_gshared)(___0_array, ___1_index, ___2_length, ___3_comparer, method);
}
inline void ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970 (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t, int32_t, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5*, const RuntimeMethod*))ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970_gshared)(___0_keys, ___1_index, ___2_length, ___3_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58 (const RuntimeMethod* method) ;
inline void Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50 (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50_fshared)(__this, ___0_list, method);
}
inline void List_1_AddEnumerable_m70DD3FB3C4E302AA0AACC45C39BCEC4C2A9DB230 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, RuntimeObject*, const RuntimeMethod*))List_1_AddEnumerable_m70DD3FB3C4E302AA0AACC45C39BCEC4C2A9DB230_gshared)(__this, ___0_enumerable, method);
}
inline int32_t List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75_gshared)(__this, ___0_index, method);
}
inline void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m835718C92D2C5DA2051794F6922D21453EAC493E (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method)
{
	((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m835718C92D2C5DA2051794F6922D21453EAC493E_gshared)(___0_value, ___1_argName, method);
}
inline void List_1_set_Item_mCDBFFAC056B77CBE377B26CAED3E893C131F4EFB (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, int32_t, const RuntimeMethod*))List_1_set_Item_mCDBFFAC056B77CBE377B26CAED3E893C131F4EFB_gshared)(__this, ___0_index, ___1_value, method);
}
inline void List_1_AddWithResize_m3B53F17525936469654379AC0F1F0B19EC3DCCE5 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_AddWithResize_m3B53F17525936469654379AC0F1F0B19EC3DCCE5_gshared)(__this, ___0_item, method);
}
inline void List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_min, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF_gshared)(__this, ___0_min, method);
}
inline void List_1_Add_m24BA4DEDED426A5B0C6A4AB3E523C876B0B918A6_inline (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_Add_m24BA4DEDED426A5B0C6A4AB3E523C876B0B918A6_gshared_inline)(__this, ___0_item, method);
}
inline int32_t List_1_get_Count_m8719A0E4E1F227424476DE81DF6DF6B58CA1CD71_inline (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
inline void List_1_InsertRange_m99F96BAC4A4EE626A6141612A5C6793BE37E006C (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_InsertRange_m99F96BAC4A4EE626A6141612A5C6793BE37E006C_gshared)(__this, ___0_index, ___1_collection, method);
}
inline void ReadOnlyCollection_1__ctor_m401D0350AA4E4ACE83F75DE82712FF72120418D4 (ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
inline int32_t List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7_gshared)(__this, ___0_item, method);
}
inline bool List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D (RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D_gshared)(___0_value, method);
}
inline bool List_1_Contains_m61A085CF349BFF87A90BE6FEE413C548F3F9E567 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_Contains_m61A085CF349BFF87A90BE6FEE413C548F3F9E567_gshared)(__this, ___0_item, method);
}
inline void List_1_CopyTo_m02DA9C05536AB370B550B399953F68908C934B06 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
inline void List_1_set_Capacity_m7AA13FF7BE1A11F437B16EAE3E1FA50DBFC902AE (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_set_Capacity_m7AA13FF7BE1A11F437B16EAE3E1FA50DBFC902AE_gshared)(__this, ___0_value, method);
}
inline int32_t List_1_FindIndex_mC9F71DEB213A8D42EBC3A47798AAF6CD140438CA (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* ___2_match, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, int32_t, Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2*, const RuntimeMethod*))List_1_FindIndex_mC9F71DEB213A8D42EBC3A47798AAF6CD140438CA_gshared)(__this, ___0_startIndex, ___1_count, ___2_match, method);
}
inline bool Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_inline (Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* __this, int32_t ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2*, int32_t, const RuntimeMethod*))Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_gshared_inline)(__this, ___0_obj, method);
}
inline void Enumerator__ctor_m0B844022E6FED4C6DA8CD7C270989D9D34800C69 (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6* __this, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6*, List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, const RuntimeMethod*))Enumerator__ctor_m0B844022E6FED4C6DA8CD7C270989D9D34800C69_gshared)(__this, ___0_list, method);
}
inline int32_t Array_IndexOf_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m9AE979627DAA17E8B9E3EF440A130C1B9C245059 (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method)
{
	return ((  int32_t (*) (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t, int32_t, int32_t, const RuntimeMethod*))Array_IndexOf_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m9AE979627DAA17E8B9E3EF440A130C1B9C245059_gshared)(___0_array, ___1_value, ___2_startIndex, ___3_count, method);
}
inline void List_1_Insert_m8C3391D73E5396E7FD12A5DA1CEDDD0A83EAAB79 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, int32_t, const RuntimeMethod*))List_1_Insert_m8C3391D73E5396E7FD12A5DA1CEDDD0A83EAAB79_gshared)(__this, ___0_index, ___1_item, method);
}
inline void List_1_RemoveAt_mBA121E6727BDC54EB17A84709997D6920BBE4D10 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_RemoveAt_mBA121E6727BDC54EB17A84709997D6920BBE4D10_gshared)(__this, ___0_index, method);
}
inline bool List_1_Remove_mAF82A7B6E01FEB6F200C76071F76554EE4B35DB8 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method)
{
	return ((  bool (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, const RuntimeMethod*))List_1_Remove_mAF82A7B6E01FEB6F200C76071F76554EE4B35DB8_gshared)(__this, ___0_item, method);
}
inline void List_1_Reverse_m34A5681B1296F6E4F08C9F0986F4E4F1CF23FBE4 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, int32_t, const RuntimeMethod*))List_1_Reverse_m34A5681B1296F6E4F08C9F0986F4E4F1CF23FBE4_gshared)(__this, ___0_index, ___1_count, method);
}
inline void Array_Reverse_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mA4406A8C17BBC29625F80F783EA91C3AECF7E3EA (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method)
{
	((  void (*) (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t, int32_t, const RuntimeMethod*))Array_Reverse_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mA4406A8C17BBC29625F80F783EA91C3AECF7E3EA_gshared)(___0_array, ___1_index, ___2_length, method);
}
inline void List_1_Sort_m29868C70BFD9DDFB44E31BF13302FB7AB5244913 (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method)
{
	((  void (*) (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))List_1_Sort_m29868C70BFD9DDFB44E31BF13302FB7AB5244913_gshared)(__this, ___0_index, ___1_count, ___2_comparer, method);
}
inline void Array_Sort_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE004CFE5BA4856AC83A08DEA9F09D3224F3EDD7B (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))Array_Sort_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE004CFE5BA4856AC83A08DEA9F09D3224F3EDD7B_gshared)(___0_array, ___1_index, ___2_length, ___3_comparer, method);
}
inline void ArraySortHelper_1_Sort_mCDDF2BDFA2ACB2C2254C52BBD32AD774C7C05CDC (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3* ___3_comparer, const RuntimeMethod* method)
{
	((  void (*) (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t, int32_t, Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3*, const RuntimeMethod*))ArraySortHelper_1_Sort_mCDDF2BDFA2ACB2C2254C52BBD32AD774C7C05CDC_gshared)(___0_keys, ___1_index, ___2_length, ___3_comparer, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mB565A7AD8E82EBD46650B3F0E052900CE12DF2C5 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 List_1_get_Item_m4077C3878C73CFD2C37863B24FFABC93CCB538C2 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m668408E30034D9AF162BA065A1B8A9190CCB854C (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9EE840E6FBE06791D954E7A69D53CE90EFCB863D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCA55981D47453F8483BD503CA53B0DABBDB8844D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mC35682C02D89984B864B24B3BB4F92B5C2374273_inline (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m5F8DAD406CF36D0DEEB854A55C356D94762E30CB_inline (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m830DE1B798DA2F877FBFF052C8841D220839E942 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_mB3BFC6EBF26339300AE50AEA966E9B13DA92D54F (ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mCB5DDE85A3BF1B0AE48D46EB6E22999A0E4D060D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9AA36809C4850F3957B1A0B552645A8F328B7158 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m82EC683EFB57714A07D26CB6E17D84FFAE7C82AE (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_mBB5FC483C17D644A9362EDE7FB61DD1D6233000C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50*, AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m3332E89182E608A4BF6BE672CB719B8B0067984C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m6C63371ECE0863BF14A70E4012C6A62D66B5F5D7 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m8D40905BAEF5849C9DF55268BB4FD2C8CB0A1A79_inline (Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m3B885E0CB5C32229381BEF0AD2CE4682713CA0EC (Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5* __this, List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m075DCC6CC6C5E2D552CC01B5A5D93D761529CC5E (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mFF1B561AB8F89B1761C15D1863C00ED3AD7BF324 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m252525485F467F26DB5C91A957EA9F842D005C40 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mA7E179931948DD88B825B2851F0BB01856B70460 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mBDDBB14EC973F164BA222AEB240F57B8460DAC1C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_mB7050783F04AD0453F190FBF1F3F6A2B6CB59506 (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m1CAB75B85D1547C184E1CA824E4A29E11269376E (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m9D7F79A00D6CDEEE91A7009E9C83C8A9190FCA23 (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m46BFEDFA8C5CE90310AFB562E0DE7A7E83E3BFEF (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mA6E73354873BEAC5429A80AE43CB210589A7EC7E (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 List_1_get_Item_mB65D799560ADD289EA08E717412A24EFADA7FB57 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m054615FD6A62EE7702B344B2E24BA8423FEF9621 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m7533012D6C4CE083D5CAF670259B97F6D5D506F4 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m8B3D79788ADC2B54C9B12CC9EC1158E6A04CDEBC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB308EE5BFFD89A7B8C251644D76CA547456F3012_inline (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m905EB6FD0B91CEE1CC0165F1EBB8C1309AEE4BEC_inline (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m9AA9E2C5627FB6CD9F3493CA8A99588EDA08125D (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m5D03D2E5CE6AAFA9914B3F1E1707393948DA34CB (ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mFA6A5CD427374237339591ED8A5218B6E7EA7F4C (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mA2F95E82C59734A475035EF3B9DD4BCE9F8429DB (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m590D7926DA2B45C95850710F87644BCD235F1A70 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m96F4BF1E6FF691338A44AAB62506964ACAD70715 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A*, OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mC49015D45A78A39909C4541BDB84DAA369E6A4C1 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA5DDCB0CBD1B539DB3213A4B3AE1C72E519C98A8 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m182E0ACAA85455151F5750CE87F942DA6E3DD3D6_inline (Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_mCAD56839187542C3B25E2C1493BBD62861333E4E (Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251* __this, List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m972A3CE5298A6193E512B34C64201444B051D8E9 (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mF138D66498A5DE06E21A7149C35FA14729F4F5E1 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m30CC1D4CA1984DCAEDBCD2228B538A0503AF854A (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m02DCEAFFE826B31F80767A9D191CB4587D82F7BC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m5903E8D5CE5B92A29530763E182314BDFA781664 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_mDCB49D07F30FD9D952124968159FDF346234BD04 (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mEBED487B845A66E3298CA30654B7EC17F7481995 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m438D9EDDBF93A09C81E89458C2362F85487923EC (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m4A8362BBA870329F45001F17310B50E583BFF19F (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mDF2147E522AD80A7B6A79CF8E7F00EC7DBF8A032 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC List_1_get_Item_mAAE7FBDBD94CC48BA01C01ACFC3C66EE219110D0 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m85CB6FEF509A4859399929F09F545FA1133C3051 (RuntimeObject* ___0_value, int32_t ___1_argName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m58893707EC3B663186D1550A23DE96C818416CBD (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m594A4155F206677F45ECD9AAE7E9EFD0AE6137ED (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_min, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m624C469B79ADC28E429B7A3CA96DA72345621643_inline (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_mF3540C84790DAB9D381F00753BA20A85694C3446_inline (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF*, const RuntimeMethod*))List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m8C743BAB2CDB84037FE830DF12A8B561EFEEEA60 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) ;
inline void ReadOnlyCollection_1__ctor_m236FFEDF5196507C82BBA262351A75F0337621F3 (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* __this, RuntimeObject* ___0_list, const RuntimeMethod* method)
{
	((  void (*) (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF*, RuntimeObject*, const RuntimeMethod*))ReadOnlyCollection_1__ctor_m903CF4492D6E4F6EE0D865BB7AA36A0DDB888355_fshared)(__this, ___0_list, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mF5A7DA78EA07100BDE8044CA37C505F36AD7ACB1 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mC9CB5EB21839923C050E6922FE7050867F374865 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mA5832B215E464CAC8345E7ECC45562E884AE146D (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
inline void List_1_CopyTo_m15B9FC56E0418F730FC3A37C8E482F7108D73B62 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method)
{
	((  void (*) (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF*, SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*, int32_t, const RuntimeMethod*))List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared)(__this, ___0_array, ___1_arrayIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m40FE27C2AB4F6F5F863957210FA90C1BF581D293 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA8A19319FB31E9FB37C309AB8938A9FE57AA5C9F (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* ___2_match, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mADD6CFDE192E3E822D5296926054ED8A41DB09C4_inline (Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator__ctor_m159144864209387AA18DEABE7B7985388F8F3452 (Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9* __this, List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* ___0_list, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_IndexOf_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m5A2EB67A073F2BFF5B3DCDDBD15D75BC3CFB909C (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_value, int32_t ___2_startIndex, int32_t ___3_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC8E7189F3D9D95975CFE821AC3B560B2EA7AB7A8 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m911F1AFFA59FD181BA9363E0B6C8B5B95067EC3B (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mA8E72E7CFB72101AA88E01A84F746ECBD8E91B3F (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m6558ECB96638BF339DAB6BDB70413BA7570A84F9 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Reverse_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_mD8F006C0A007C05BB69E417FA65A5A66965F997C (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m4F48B52D720DB8E76904DB4647F7BDA63FDEC552 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Sort_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_mE6A4B57DE0CB3DEC8371BDC3DAAAD29D6C9E3B2B (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, int32_t ___1_index, int32_t ___2_length, RuntimeObject* ___3_comparer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArraySortHelper_1_Sort_m3182DABDA1EFACFF8268887837CA976A3577C3E6 (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_keys, int32_t ___1_index, int32_t ___2_length, Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149* ___3_comparer, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m87C3D83E9C8DA88E01D3A700E60AB74F734DFEE3 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mD605338B92482BDA80D2FCD42F0124A3A39466CB (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_2 = ((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_4 = (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)(JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mAD38BED85D3BB939D91CC76F994D9B154B40363F (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_6 = ((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_8 = (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)(JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_10 = __this->____items;
		InterfaceActionInvoker2< JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_12 = ((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m2B50D2C1D98DB40C529D7FE996EC7FEEC6352987(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m45A5B6A69CD56F9924919CA096EDBA357C65D75A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_7 = (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)(JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_9 = __this->____items;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_13 = ((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 List_1_get_Item_m0C23C6923A01AF75684D6525409AEDE89F2DC43A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mA7050FBBF764D7C2348D5C56EE6D5627827138FC (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mE7D9087840ED42201AD016B57A1E7BC84CE0C185 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m411954EB1B854076C9F91DD00E12BE4161F98962 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_1;
		L_1 = List_1_get_Item_m0C23C6923A01AF75684D6525409AEDE89F2DC43A(__this, L_0, NULL);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m46A948E75949742CC5B82E54E6312A9E2D466A7F (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m7A59D91E09158E9F2EA14F7AFEB7F85E1A33E991(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_mA7050FBBF764D7C2348D5C56EE6D5627827138FC(__this, L_1, ((*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mB2D00B8E4BC3D697FA727086AACBC28AAA1606F2 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) 
{
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_7 = V_0;
		int32_t L_8 = V_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_9);
		return;
	}

IL_0034:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = ___0_item;
		List_1_AddWithResize_m1AB47453401D23D3A09953C553FCC6114A68E6AC(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m1AB47453401D23D3A09953C553FCC6114A68E6AC (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_3 = __this->____items;
		int32_t L_4 = V_0;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m5CAD30893F4D552A7EB463C891C05EF7B000D530 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m7A59D91E09158E9F2EA14F7AFEB7F85E1A33E991(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_mB2D00B8E4BC3D697FA727086AACBC28AAA1606F2_inline(__this, ((*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m4E48119598FA460677D2C289DC20E34CA77CF88B_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m8063618E6500CFC22571808AC4153C9597F5BA9F (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m45500246518715C5163937DD4F88B9E83C8FDCD2(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4* List_1_AsReadOnly_m67AB24AF8A7F83A7413926785AF8CC22428A8A30 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4* L_0 = (ReadOnlyCollection_1_t0298DDA093ECBA0BAF4483F8766A744D428757C4*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m8C7151A8D9C1BC6806FD1F287DB6B84C525580BD(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m140E03ED6A3A556B3FB64CD38AA19CEEC575B1F9 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mC0DCAD2245FED3A39A8ACA137B3CD1CB8CC7152E (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m41D7127A668569920CAA0CE3A83FA6BCE7302347(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m856FCB9375464F9F376BD53E52C0DE3D1B4CDB4B (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mE7D9087840ED42201AD016B57A1E7BC84CE0C185(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mC0DCAD2245FED3A39A8ACA137B3CD1CB8CC7152E(__this, ((*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mBF4FAF5B467901738C275C794671CAEE390492F3 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* ___0_array, const RuntimeMethod* method) 
{
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = ___0_array;
		List_1_CopyTo_mB41442EF87F813746221E22F4BCE10475E99BAAA(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m45A5B6A69CD56F9924919CA096EDBA357C65D75A(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA9FFC62325883C774E2E8080DB69CC80D61F5ED2 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m2C93E027F6C3A135BB88D85AB891DCE3395EA99F(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m2C93E027F6C3A135BB88D85AB891DCE3395EA99F (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* L_10 = ___2_match;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m798E5A0C143433BFCAF602F2FFEC4B7DA1932BB5_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 List_1_GetEnumerator_m2CA4349BDC0553A98A2FCBFB87B745603E32308A (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mAFFE93EC5DE0EEB64AC0A88BDF6A137BBF7F39C6((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mB5EA01275B12C5AB1771BB652C8E8E9AB92DEDBE (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mAFFE93EC5DE0EEB64AC0A88BDF6A137BBF7F39C6((&L_0), __this, NULL);
		Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m06606F6042D768F0256608AFA7A72B3BC34949B0 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mAFFE93EC5DE0EEB64AC0A88BDF6A137BBF7F39C6((&L_0), __this, NULL);
		Enumerator_t1035173233ABD47455848A1128DA762F10EF56C5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m41D7127A668569920CAA0CE3A83FA6BCE7302347 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) 
{
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = __this->____items;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_mCD89004E22CB4FEB73672DD2830E315DDA4DA3BE(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mF75C5FBCAF6BEEEA41F55F1BE61E0A67E3C24950 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mE7D9087840ED42201AD016B57A1E7BC84CE0C185(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m41D7127A668569920CAA0CE3A83FA6BCE7302347(__this, ((*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m363B214B205FDF1A10DFB2AD28449D3A3A573352 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_mAE46A0B857FDF3D82902CB5293760120EBD0378D (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m7A59D91E09158E9F2EA14F7AFEB7F85E1A33E991(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m363B214B205FDF1A10DFB2AD28449D3A3A573352(__this, L_1, ((*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m45500246518715C5163937DD4F88B9E83C8FDCD2 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_20 = __this->____items;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_45;
				L_45 = InterfaceFuncInvoker0< JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_m363B214B205FDF1A10DFB2AD28449D3A3A573352(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m2B50D2C1D98DB40C529D7FE996EC7FEEC6352987(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAFB3BAC249C296F3A7EEEC88F411F6778EF9FBD5 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m41D7127A668569920CAA0CE3A83FA6BCE7302347(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_mEF7CA22D83DD6F0A16EDDCA311C51A00D106D2C1(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m897A048CAF1660E599AB9AF5B01E60A8C175DB74 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mE7D9087840ED42201AD016B57A1E7BC84CE0C185(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mAFB3BAC249C296F3A7EEEC88F411F6778EF9FBD5(__this, ((*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m7E342F1AB60FCB0E7E504889C93F374CA9350565 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* L_4 = ___0_match;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m798E5A0C143433BFCAF602F2FFEC4B7DA1932BB5_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* L_16 = ___0_match;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m798E5A0C143433BFCAF602F2FFEC4B7DA1932BB5_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mEF7CA22D83DD6F0A16EDDCA311C51A00D106D2C1 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mE1CF3802B55E7381B51B8D532D43AA425DF74324 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m8DD7879BB9FFEE74F3EA8BD870BF5E2B13ED99B5 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4E48119598FA460677D2C289DC20E34CA77CF88B_inline(__this, NULL);
		List_1_Reverse_m9EFEB672652EFD451C646ED0D66FA66C8AEA5DAE(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9EFEB672652EFD451C646ED0D66FA66C8AEA5DAE (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m72083CFA42FDE71DFAAF45904EAA134C889E43E8(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mD0F775F97F58410BCB6566B520EC59E04E5EF0F9 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4E48119598FA460677D2C289DC20E34CA77CF88B_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_mCF3B2040A3635457AFCEBFCFC234F823464E0536(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mCF3B2040A3635457AFCEBFCFC234F823464E0536 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m3B906B4372F67902D2B72C42125E132BB2E2149F(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m66173D90E12FCB452EFD2EF6D66065E03A082787 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t6DF161EEC609BA6986464FEC2A77BEF0530A20DA* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m645207130D9695240E4F77E44F1743B8369997ED(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* List_1_ToArray_m2662234B1E3E5AF0A925B1D573894959F1896F4C (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_1 = ((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_3 = (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)(JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_4 = __this->____items;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m2B50D2C1D98DB40C529D7FE996EC7FEEC6352987 (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_6;
				L_6 = InterfaceFuncInvoker0< JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m50C29608B8388824203E98B36F71E3D74CFF523C(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mB429ABE1A21F14E4A1D4D3293245EDED4EBEBF5F (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_0 = (JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)(JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m2E2734FA74E3CB680D86DCA477988C13169C604A (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_0 = ((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mEC56EBFEDE97AC1668A18F4BF89B67437A91FDAA (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_2 = ((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_4 = (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)(MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m0FF7CEC867B044DDFDAFA0E90129E71941A37AAD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_6 = ((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_8 = (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)(MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_10 = __this->____items;
		InterfaceActionInvoker2< MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_12 = ((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_mD7C118A83F4784EC66EB43D7A8B700015DCD398B(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mFB6F8456DD804108255872FAA0513D909B08050B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_7 = (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)(MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_9 = __this->____items;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_13 = ((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 List_1_get_Item_mD3B34BD1058003A2FC43C62F59E07B072C97AA58 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m50870FEFDAE3AFFDC15A9581BDB14F881D63C504 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m0E65F65ACB45DC1A077B1798336BCF5B5B702184 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61));
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m3AE927261B1B409E7878E5A6D2FF86110917CD24 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_1;
		L_1 = List_1_get_Item_mD3B34BD1058003A2FC43C62F59E07B072C97AA58(__this, L_0, NULL);
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mB8B021F9BFDBA803D390698A2218F36742374843 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mEEF54CA41E38545E629EBB0374D6E430EABEAF1F(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m50870FEFDAE3AFFDC15A9581BDB14F881D63C504(__this, L_1, ((*(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mAA147597B0A6147B89C99C55D9DFA93A8AE79D26 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) 
{
	MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_7 = V_0;
		int32_t L_8 = V_1;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_9);
		return;
	}

IL_0034:
	{
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_10 = ___0_item;
		List_1_AddWithResize_m558B41D2F2078B4DA929652106E89D5677D85DCD(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m558B41D2F2078B4DA929652106E89D5677D85DCD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_3 = __this->____items;
		int32_t L_4 = V_0;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m3A0B5BFF2D97B2E3AFF922661270163BC6545BE6 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mEEF54CA41E38545E629EBB0374D6E430EABEAF1F(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_mAA147597B0A6147B89C99C55D9DFA93A8AE79D26_inline(__this, ((*(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m2ACC476BFEA27BBE68DA9C9C58C962EBBA411D15_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_mB3A499649D1BE7978618D8BB1B4B00EBD81C8D70 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m0475AC2C14A7B4FB4FAF0D6233A5782301AC48D3(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A* List_1_AsReadOnly_m0B9E332F0EF6794E040D3A3A4F24A194ED30C562 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A* L_0 = (ReadOnlyCollection_1_t258F9C9686190A8A27ACA00B70B5753B637DA36A*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m3771FF52DBB5BC05AFD2504630EF17DDC9619B85(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m822C424B231CE62C9F15179F79357FBAD2C0311E (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m814BAC895FA3E4F5098F22A9D33E8C9BFFBFB0BC (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m77BA02C38C869607A5A2939A6A4F54C07F703495(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m132147AF5BAF3687BCA47D619A470390D46673A5 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m0E65F65ACB45DC1A077B1798336BCF5B5B702184(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m814BAC895FA3E4F5098F22A9D33E8C9BFFBFB0BC(__this, ((*(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m6A38349F97CDB2D225F90D63EABDEB0681CC1378 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* ___0_array, const RuntimeMethod* method) 
{
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_0 = ___0_array;
		List_1_CopyTo_m1D96B6E41C3609C753D7BC5958F9D84F0B4AC28D(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_mFB6F8456DD804108255872FAA0513D909B08050B(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m70F78E6036CC54194AEB0E02BB18602FC5D242E7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m0D5C6A44576D63BD85484E84C4E6CFFF935067DD(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m0D5C6A44576D63BD85484E84C4E6CFFF935067DD (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* L_10 = ___2_match;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m757CF429A07F24116D98E8A834EE7D2EB3D3315E_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 List_1_GetEnumerator_m4D1CA180C27D527E9566191DC8A355C4BB22506C (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4B9AB13F18ADC5263C10CB458E2597AA2784A2B7((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m34245C216B8414AF5F4F7B6F09B269CBB972F8D2 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4B9AB13F18ADC5263C10CB458E2597AA2784A2B7((&L_0), __this, NULL);
		Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m63C230B6F420A154143D91FFAED237B4D0E71B4C (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m4B9AB13F18ADC5263C10CB458E2597AA2784A2B7((&L_0), __this, NULL);
		Enumerator_tB836E7407615CFF0BC179DF9434097D57A694349 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m77BA02C38C869607A5A2939A6A4F54C07F703495 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) 
{
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_0 = __this->____items;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_m6793F227DC9835EB5670F546DF97C0067C4236E7(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m3180A0FFF74A3BF819611CF86D94783D98F6B514 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m0E65F65ACB45DC1A077B1798336BCF5B5B702184(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m77BA02C38C869607A5A2939A6A4F54C07F703495(__this, ((*(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m1B00558DE5FBE0526AD54D7A0A0151E9AC629FB7 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m9B95E18AC15CC752E580894A7232B9D28D543663 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mEEF54CA41E38545E629EBB0374D6E430EABEAF1F(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m1B00558DE5FBE0526AD54D7A0A0151E9AC629FB7(__this, L_1, ((*(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m0475AC2C14A7B4FB4FAF0D6233A5782301AC48D3 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_20 = __this->____items;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_45;
				L_45 = InterfaceFuncInvoker0< MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_m1B00558DE5FBE0526AD54D7A0A0151E9AC629FB7(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_mD7C118A83F4784EC66EB43D7A8B700015DCD398B(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mEA589FD44B8A9073BCFD186FFAAC46AA7911A19F (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m77BA02C38C869607A5A2939A6A4F54C07F703495(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m42406B184BCFD8B07CB5E22E79319A23CBDE7364(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mC6801D45C7A7695D79EB0701387A829F0367B4DA (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m0E65F65ACB45DC1A077B1798336BCF5B5B702184(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mEA589FD44B8A9073BCFD186FFAAC46AA7911A19F(__this, ((*(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_mF188CEFC7EB4891CE4A5611B74BB689767C01B9B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* L_4 = ___0_match;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m757CF429A07F24116D98E8A834EE7D2EB3D3315E_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* L_16 = ___0_match;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m757CF429A07F24116D98E8A834EE7D2EB3D3315E_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m42406B184BCFD8B07CB5E22E79319A23CBDE7364 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61));
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_13 = V_0;
		(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mE82A07E5F002F539A61209DC77580F692A80B701 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mA903C19ED2DE191A295FD7BD2B150D37C37C6923 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m2ACC476BFEA27BBE68DA9C9C58C962EBBA411D15_inline(__this, NULL);
		List_1_Reverse_m9FB23CE117B4CF6DDD423E39A236480D810B3282(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9FB23CE117B4CF6DDD423E39A236480D810B3282 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_mF1978C21CF5FA17E42C679D8BB57D636AC23F6C5(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m7612F3247EC951792A88F1F5618A73144F8B4DD0 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m2ACC476BFEA27BBE68DA9C9C58C962EBBA411D15_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_mE9545D4ADD4ADB084A98373037F4BE24734E098E(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mE9545D4ADD4ADB084A98373037F4BE24734E098E (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisMeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61_m5AAF0F2CACE2984B8C26664CF5F0A63446534288(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m88DF6E9125AEF89CF77F97999816DF823C2787B0 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t5FBF0274E15E0A05AC9314210514D704D9C572E4* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m3AD6D0B2420C89E417F45A3CF8D1050B0A8DB0EA(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* List_1_ToArray_m33BC2F66454D3686270EACCA17F8391DD07AC439 (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_1 = ((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_3 = (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)(MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_4 = __this->____items;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mD7C118A83F4784EC66EB43D7A8B700015DCD398B (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_6;
				L_6 = InterfaceFuncInvoker0< MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m83EC1F0DDB3D8C22C95808CA8606D75ED6DCBFB7(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mB8B95AD4F05CD9BF40F0C9C19314A7994909F7FA (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_0 = (MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)(MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7012C13E28DC956E352DA77BABB1E4615E7AFAE3 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_0 = ((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m8CD04FD1BAB1285CBBDEE62F72C5F2EFFE9C8475 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_2 = ((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_4 = (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)(MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m5CD2B2107C59599EED7064D03B75E327B73E7758 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_6 = ((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_8 = (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)(MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_10 = __this->____items;
		InterfaceActionInvoker2< MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_12 = ((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m257232CDC0FA2092642566E880B6A8F8460AAF9C(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m1047F3DD0314BDB3C4A459FD468B668C3289D67F (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_7 = (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)(MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_9 = __this->____items;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_13 = ((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 List_1_get_Item_m32848DA458A095251347E07C9FD1C51F61620CA2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m57BEC2D922431257A06EC60BE8FBCACA58965ED9 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mC6F7CC8E9ADF553B42A35F3122037BE3C62F8C70 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4));
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m80E97A7CAE3CF7406D1890D756F4204AFBD3A495 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_1;
		L_1 = List_1_get_Item_m32848DA458A095251347E07C9FD1C51F61620CA2(__this, L_0, NULL);
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m5FF706E2F72B238F9008CAD657E8EF718CFA5A6E (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m4E7CEEF7D8FA269C8F796E920E93F2D618598881(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m57BEC2D922431257A06EC60BE8FBCACA58965ED9(__this, L_1, ((*(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m85AF4AC8BAFE2D698178F1CC64EBF5587C8C501B (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) 
{
	MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_7 = V_0;
		int32_t L_8 = V_1;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_9);
		return;
	}

IL_0034:
	{
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_10 = ___0_item;
		List_1_AddWithResize_mE5072267E528FE731CDE3FF1E7FDA08392A07B86(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mE5072267E528FE731CDE3FF1E7FDA08392A07B86 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_3 = __this->____items;
		int32_t L_4 = V_0;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m214C5732784F5D75ACBE106245AEC48240DFA2AF (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m4E7CEEF7D8FA269C8F796E920E93F2D618598881(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m85AF4AC8BAFE2D698178F1CC64EBF5587C8C501B_inline(__this, ((*(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_mC59DC4CDF255755CEADE65B05E09EBDFD3D213C8_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_mAD8F6298089BC5C5AEA1340198E6ABB11802B45C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m402027003A6F9027A1F261FEC78D1396BE4B8CD7(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39* List_1_AsReadOnly_m26B7E6C4782E190674C8767D63BBC4FDC8EE1B00 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39* L_0 = (ReadOnlyCollection_1_tC4A6AFE60001EC0506103983D0AD465A3DFCBC39*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m80A07CEFE2201F368C4819FEDFDA2D7B33CB9340(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m3D190A661CE3C3F9D34CFB5A82A97A9F37C10801 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m4B7DA9C244F266A0DA8E5E4020AD0B366A8C3437 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m7EB1ECC074B3AF437C63AD042B76592D81316E4D(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_mABF1FD9B6F8FB9F4441F78784CE1AA5C04E3BC38 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mC6F7CC8E9ADF553B42A35F3122037BE3C62F8C70(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m4B7DA9C244F266A0DA8E5E4020AD0B366A8C3437(__this, ((*(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m059B11270C91C12E0484C4437056D9D7D90EBF2E (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* ___0_array, const RuntimeMethod* method) 
{
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_0 = ___0_array;
		List_1_CopyTo_mD784AB7B5A8C0265310092FA4DDC3ECEA422E1F2(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m1047F3DD0314BDB3C4A459FD468B668C3289D67F(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mCBA4FE0487CC4E12C06ACA803A17489F0F1DC339 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mF5C6590EFA98412BDA86C1F83C117F811D68004C(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mF5C6590EFA98412BDA86C1F83C117F811D68004C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* L_10 = ___2_match;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_mB1CA85C8D3E3D6E0E2236B0CEE4C32387ACF690B_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 List_1_GetEnumerator_m31910B3C405476C7FA0E7CE4196B6E073B480766 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mAFCDB0F6CA2E77D7A2E959C24FFEEC052AAE4DEE((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mC44FF46996B8994B0E8586978726476B6181B87D (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mAFCDB0F6CA2E77D7A2E959C24FFEEC052AAE4DEE((&L_0), __this, NULL);
		Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m295A53AEAEB5B46CE149CCDD87D8B3CA8700E858 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mAFCDB0F6CA2E77D7A2E959C24FFEEC052AAE4DEE((&L_0), __this, NULL);
		Enumerator_t729C3FB89612497427CE1BCB9F8D244ED4BA8BB1 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m7EB1ECC074B3AF437C63AD042B76592D81316E4D (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) 
{
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_0 = __this->____items;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m70030F87B9DDCD44A4CB969B6B2D1C5F368241F2(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m4BC1C9ADC5D8600A01A29CA246BCB3962EA0ED04 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mC6F7CC8E9ADF553B42A35F3122037BE3C62F8C70(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m7EB1ECC074B3AF437C63AD042B76592D81316E4D(__this, ((*(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mDF7643E5C561584BA74E27A20C2F68716DAAD6C2 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m9189769A54F7E974C1EAC78052FDF34B7332B698 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m4E7CEEF7D8FA269C8F796E920E93F2D618598881(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mDF7643E5C561584BA74E27A20C2F68716DAAD6C2(__this, L_1, ((*(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m402027003A6F9027A1F261FEC78D1396BE4B8CD7 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_20 = __this->____items;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_45;
				L_45 = InterfaceFuncInvoker0< MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_mDF7643E5C561584BA74E27A20C2F68716DAAD6C2(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m257232CDC0FA2092642566E880B6A8F8460AAF9C(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mC3AED5A1C5D19EBA136856CA89192AE43ACAD5E6 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m7EB1ECC074B3AF437C63AD042B76592D81316E4D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m74729BC4F6DF62D8A9A45F18D2A66CDC597446D7(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mF06BBA40F9E0A5F8671E28A33932BCC9DB72FC5A (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mC6F7CC8E9ADF553B42A35F3122037BE3C62F8C70(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mC3AED5A1C5D19EBA136856CA89192AE43ACAD5E6(__this, ((*(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_mF7FE5B8A8FE384023173903124311C3F8F850288 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* L_4 = ___0_match;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_mB1CA85C8D3E3D6E0E2236B0CEE4C32387ACF690B_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* L_16 = ___0_match;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_mB1CA85C8D3E3D6E0E2236B0CEE4C32387ACF690B_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m74729BC4F6DF62D8A9A45F18D2A66CDC597446D7 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4));
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_13 = V_0;
		(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mEFD6944481E6BEA879DA45E3D3C50D17FCD8AAC5 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m0E487C5C1956CB9B97F2E57AA46F89CB4EC7C30C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mC59DC4CDF255755CEADE65B05E09EBDFD3D213C8_inline(__this, NULL);
		List_1_Reverse_m4617AE24F45FCDF94C51574002B2954595221181(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m4617AE24F45FCDF94C51574002B2954595221181 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m38DB51F29444C606428313B22FAF8F1C80E1AEBB(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mC2C15518A51F40EE98E0F548F9AC3D4706BE2757 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mC59DC4CDF255755CEADE65B05E09EBDFD3D213C8_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m3E46FDA75F13334644C38A5C0E10761FF1489DB1(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m3E46FDA75F13334644C38A5C0E10761FF1489DB1 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisMeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4_m16BC1A4D1FEC2786910CF8CFE949C41132CC607C(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m66DD3B0B9948314C8F7C56262F0E075D85F8015B (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tCC387C7E3F27B5C6326F622527E5173C2F587A26* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_mA8C548AF368EBC4C8D499C23D1411C95D8AD9A7F(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* List_1_ToArray_m448777F4C4B482C90F2FD2A50F85EA01FBAF0462 (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_1 = ((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_3 = (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)(MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_4 = __this->____items;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m257232CDC0FA2092642566E880B6A8F8460AAF9C (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_6;
				L_6 = InterfaceFuncInvoker0< MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m5749776BE837900000C10AD7C705157AE94B3857(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m1412986253E4DC3A7BA818012CA9FDBE98F086F9 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_0 = (MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)(MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m514A917546C862D189702294180E2CD8F1EC7920 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_0 = ((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mBB1736A52639A5F2DB93050D54A1E96F9ABDEE47 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_2 = ((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_4 = (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)(ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m3B39D0F5983BD0822EDB07C5EDE75EDFD699DE14 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_6 = ((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_8 = (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)(ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_10 = __this->____items;
		InterfaceActionInvoker2< ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_12 = ((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m4E122E2502A8627C778FE4556937C624B46C7997(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m5206BE528EF098F0A05B20F06F65AF72FD28CC3D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_7 = (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)(ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_9 = __this->____items;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_13 = ((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 List_1_get_Item_mD173DE9CD6A82455F2B1CB9778BE90B63FF73391 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mB2BEDCB542156BEC23496A84CFE200BC8782E57D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m4F61B731116EA18BCF77D3B5EA97CC7F6B74BA8E (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8));
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m04B457695937A66E06396700583FD6C35835CB74 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_1;
		L_1 = List_1_get_Item_mD173DE9CD6A82455F2B1CB9778BE90B63FF73391(__this, L_0, NULL);
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m45071D63DE985740B34DC7F52D98FF648E13A24D (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_mA91A20BD242392A65004CD8897E77F0A9BA80940(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_mB2BEDCB542156BEC23496A84CFE200BC8782E57D(__this, L_1, ((*(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mF04CCC12DEF9C866AC5DC5330FDC48AB65CCA024 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) 
{
	ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_7 = V_0;
		int32_t L_8 = V_1;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_9);
		return;
	}

IL_0034:
	{
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_10 = ___0_item;
		List_1_AddWithResize_m28AFC3F6D5F6FE74B5CC7A3E42AC5CC6FFE0F2B8(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m28AFC3F6D5F6FE74B5CC7A3E42AC5CC6FFE0F2B8 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_3 = __this->____items;
		int32_t L_4 = V_0;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mD419C884DEA6D2C1C6974E8ED706971AF1408C55 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_mA91A20BD242392A65004CD8897E77F0A9BA80940(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_mF04CCC12DEF9C866AC5DC5330FDC48AB65CCA024_inline(__this, ((*(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m9F65F44EDFFE199D00E71A358851A11FBF35CA0D_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m1ACAE9867614B2E7CB67475FC6E5C5F95C738E32 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m2E53EA9AC569CA67C76F3C118E063BBCF7704CAE(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649* List_1_AsReadOnly_mEFCB5C5FB0CDE9D03B929BD46DD638BC7D53A7F8 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649* L_0 = (ReadOnlyCollection_1_tD135EE58ED40F5EAAC6EDA3F5432A8EE5DD0D649*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_mD5AEE0B0FFB019B42DCCDB57A1C2F680C1FD1702(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m927431BEB00B7E74BCD1DA47335D5202240D05AF (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mD8BB26D8A824572630E9C0E3F4D1DC9A3120F44A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m69A02C552A18C10D19C781295373AB8A8AEE5031(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_mC832E4768CCD26C924DAF74400A6C9090B2F3883 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m4F61B731116EA18BCF77D3B5EA97CC7F6B74BA8E(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mD8BB26D8A824572630E9C0E3F4D1DC9A3120F44A(__this, ((*(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m95F78FD27E79415CD43804407EFCFFB195316572 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* ___0_array, const RuntimeMethod* method) 
{
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_0 = ___0_array;
		List_1_CopyTo_m991F7CA6913952712B14D32980B84A10304DCFC0(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m5206BE528EF098F0A05B20F06F65AF72FD28CC3D(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mDD96F8A07BE8B68C1A00389A827B0CF79D7398E4 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m7B4E901E789CE8CC54DA8AEDA0C3E6080E58EA7A(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m7B4E901E789CE8CC54DA8AEDA0C3E6080E58EA7A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* L_10 = ___2_match;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m34AFEF07BE56D23BA7F5BA2338AC3C3F1ED777CF_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C List_1_GetEnumerator_m0A297383A3371D391B0AE99556E2F20608C24CAE (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m835D87EAED18476EAAF9606BFFC75C69A7EF65A8((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m9256A844FA404945E1BA436E3225DC63937E53EE (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m835D87EAED18476EAAF9606BFFC75C69A7EF65A8((&L_0), __this, NULL);
		Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_mDEF9E0A67C74C2B363EAAAB72784DCB15492321A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m835D87EAED18476EAAF9606BFFC75C69A7EF65A8((&L_0), __this, NULL);
		Enumerator_t1F35D895285609CB64A4AE42EEBBACABF575870C L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m69A02C552A18C10D19C781295373AB8A8AEE5031 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) 
{
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_0 = __this->____items;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m8332FAAEA1F00BD676F75CB7D21BDDE5EB8108FC(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mDA5087B460A66C84E4A517B99343E2D19FA42059 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m4F61B731116EA18BCF77D3B5EA97CC7F6B74BA8E(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m69A02C552A18C10D19C781295373AB8A8AEE5031(__this, ((*(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m87451DF4EDEDCFD7A4F723FD3862823FC8208F03 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m18278F2BB420F203F3AFB1FFC583ECEFD4BF5626 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_mA91A20BD242392A65004CD8897E77F0A9BA80940(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m87451DF4EDEDCFD7A4F723FD3862823FC8208F03(__this, L_1, ((*(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m2E53EA9AC569CA67C76F3C118E063BBCF7704CAE (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_20 = __this->____items;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_45;
				L_45 = InterfaceFuncInvoker0< ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_m87451DF4EDEDCFD7A4F723FD3862823FC8208F03(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m4E122E2502A8627C778FE4556937C624B46C7997(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mCE97C009362B0A9CD4552C1B51C5E2A86246CA15 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m69A02C552A18C10D19C781295373AB8A8AEE5031(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m193AD81345965E50C83F85222E0549DC26D12328(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m99835BE81DC65A02636F44A5718B27D58037726C (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m4F61B731116EA18BCF77D3B5EA97CC7F6B74BA8E(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mCE97C009362B0A9CD4552C1B51C5E2A86246CA15(__this, ((*(ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m32FA8F9FEE2CD99C7589A668A706A0352E9D22B1 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* L_4 = ___0_match;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m34AFEF07BE56D23BA7F5BA2338AC3C3F1ED777CF_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* L_16 = ___0_match;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m34AFEF07BE56D23BA7F5BA2338AC3C3F1ED777CF_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m193AD81345965E50C83F85222E0549DC26D12328 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m252809FF329AD4AAE34D73B6496515FD0E7E5334 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m8EB00C91873F5440D1C39B14267B28051271F91C (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9F65F44EDFFE199D00E71A358851A11FBF35CA0D_inline(__this, NULL);
		List_1_Reverse_m6AFF276121D16C2E2B20450B50341A6290ADEB1A(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m6AFF276121D16C2E2B20450B50341A6290ADEB1A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m21433AAF5C37ED5C37B245798D8BED8D43C21BF4(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA59C056D989DEE48434B5C0FE6AB215B53424390 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9F65F44EDFFE199D00E71A358851A11FBF35CA0D_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m741493F9355B59A4913E75FC9DBAF48FF66DFA57(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m741493F9355B59A4913E75FC9DBAF48FF66DFA57 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8_m15B3CC39BEC812E83A1A2CE71AE193200A9E1762(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mE7B9AECBA7713C680FFDC0D1FFC16486EB2E57AD (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tDCA291E0A9EC3450564AE324BB4A8232F7171A75* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m7051900D4D21A46096B77E03BE73D6D5907DA7E4(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* List_1_ToArray_m36E61E82525E3D419991039822CAA987D5B8745A (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_1 = ((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_3 = (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)(ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_4 = __this->____items;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m4E122E2502A8627C778FE4556937C624B46C7997 (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_6;
				L_6 = InterfaceFuncInvoker0< ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m5056E5ED803534E727AD5E9FAEC838428ACC47FB(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mFB54BAF5F843CEF0ACB359DE97ADE45DAFAD1812 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_0 = (ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)(ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m86C111FD8EB5C512E5E4CF748E11C6416575BC67 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_0 = ((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m9342CFFA3D0BC6C93C9BDA1401859B6E4DF1C861 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_2 = ((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_4 = (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)(SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mCB960A54EA21D2A88616632437CC6EB2FFE6542F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_6 = ((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_8 = (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)(SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_10 = __this->____items;
		InterfaceActionInvoker2< SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_12 = ((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m000A063D523E65A4E1203650A1E641FBAB58A3A4(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m68606F21AB0128430A2ED0424923862135939AD1 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_7 = (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)(SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_9 = __this->____items;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_13 = ((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A List_1_get_Item_m5C5E1087CA1987F3BE88388D61E2519540515D8B (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m2DD04D9528C97840C206D163D7AB4C4746B3AC76 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m7968A21E8BC7720D75B4A7DC9CB7993BA34CEF33 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A));
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m9FE5EFD1EF44414E1079D65ABAFD6985E7FD0DD6 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_1;
		L_1 = List_1_get_Item_m5C5E1087CA1987F3BE88388D61E2519540515D8B(__this, L_0, NULL);
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mE172AC223F2D7A33BCE8B99E5C0207047977B12D (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m2FF5778E81554EE8518E94C1558A2151BE61E882(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m2DD04D9528C97840C206D163D7AB4C4746B3AC76(__this, L_1, ((*(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mF7AE8B1682DB8CD2AC096A7E9C663F5B3BE8C1DD (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) 
{
	SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_7 = V_0;
		int32_t L_8 = V_1;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_9);
		return;
	}

IL_0034:
	{
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_10 = ___0_item;
		List_1_AddWithResize_mA45CBC1217C83D9A3C45A71418C0C0A0CAB84CB2(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mA45CBC1217C83D9A3C45A71418C0C0A0CAB84CB2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_3 = __this->____items;
		int32_t L_4 = V_0;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m61683D0A2357947220FD7970E81FDFCE5940452D (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m2FF5778E81554EE8518E94C1558A2151BE61E882(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_mF7AE8B1682DB8CD2AC096A7E9C663F5B3BE8C1DD_inline(__this, ((*(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m4776AE016DEBA009A6380C97D690FCD4F31FDFA8_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m1B0CC4361E920E871B8684101B254B08C4F8D94E (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m26941567807B2151919C524E13D4C4E8E42F26F2(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7* List_1_AsReadOnly_m04E0732670CC8F2C2FC38917D43247A5CCB6ADE0 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7* L_0 = (ReadOnlyCollection_1_tFAACBEE5CE47C34D1DA10F68422B399FAE36D5D7*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m104CDCAAC255F5457FF6A064CCA66855BB2FED8F(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mAAB9FE1F05E4B4AC60134E1A9C6C459D5A374FAE (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mBCE4AAC95175F191A52172F644F3FFF322464C1B (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mDA90966E8C972CE14F1DE68EC09D9707DE7E765F(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_mD85D953C6300C4C8A2399687B7CAF38AAAEEF1AE (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m7968A21E8BC7720D75B4A7DC9CB7993BA34CEF33(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mBCE4AAC95175F191A52172F644F3FFF322464C1B(__this, ((*(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m576037E63F5B21FAE682CE9175DD4DE6C368A9E2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* ___0_array, const RuntimeMethod* method) 
{
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_0 = ___0_array;
		List_1_CopyTo_mEEA1C37F8203884D4AF5B98E4DE6E296C4D8B8EA(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m68606F21AB0128430A2ED0424923862135939AD1(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m4558119E2767B99B4F8A87B8DED1638BFA3A802C (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mA42311457F2CCA0F203C805138AEFEE0693553A6(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA42311457F2CCA0F203C805138AEFEE0693553A6 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* L_10 = ___2_match;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m3F752265B16661803674C43E5FDFFD81C013F9A4_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E List_1_GetEnumerator_m42F5F6871D8D83F8E539DCD20DE1895A8D258505 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m91240E54A2967AC6B72557637B8A364E9D0F393B((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m8C8365C0BC51E127ACA845490B9CB9C1F911125C (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m91240E54A2967AC6B72557637B8A364E9D0F393B((&L_0), __this, NULL);
		Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m64A88B4A17B20EAFB996B168D478FC8C69060522 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m91240E54A2967AC6B72557637B8A364E9D0F393B((&L_0), __this, NULL);
		Enumerator_tB4D87E93C1696094F6864CB70DB300C4E888487E L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mDA90966E8C972CE14F1DE68EC09D9707DE7E765F (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) 
{
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_0 = __this->____items;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m499630D76B859F59FAE8A81C60907432FA38D379(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m94C638AF7E03E26D8EB05BB91C413B0431C5AE73 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m7968A21E8BC7720D75B4A7DC9CB7993BA34CEF33(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mDA90966E8C972CE14F1DE68EC09D9707DE7E765F(__this, ((*(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m3FC18BE3FD757F2B4D57CA1B9589C8427445BEF8 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m6A6AC79C07DBADA805E12D228D8B4F7EB86BAECE (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m2FF5778E81554EE8518E94C1558A2151BE61E882(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m3FC18BE3FD757F2B4D57CA1B9589C8427445BEF8(__this, L_1, ((*(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m26941567807B2151919C524E13D4C4E8E42F26F2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_20 = __this->____items;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_45;
				L_45 = InterfaceFuncInvoker0< SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_m3FC18BE3FD757F2B4D57CA1B9589C8427445BEF8(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m000A063D523E65A4E1203650A1E641FBAB58A3A4(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m5FA9171FC0D0CB0563B035E48CA180082E5982A4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mDA90966E8C972CE14F1DE68EC09D9707DE7E765F(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m8A7E83E4842DBB59FAF2DFADFB4DC664C0948DCA(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m0E4E25393C4D6230D1A363FB94ABFA09B65407D7 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m7968A21E8BC7720D75B4A7DC9CB7993BA34CEF33(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m5FA9171FC0D0CB0563B035E48CA180082E5982A4(__this, ((*(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m366D3863A092249C623DEA1B9D9D89F321F63D6A (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* L_4 = ___0_match;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m3F752265B16661803674C43E5FDFFD81C013F9A4_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* L_16 = ___0_match;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m3F752265B16661803674C43E5FDFFD81C013F9A4_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m8A7E83E4842DBB59FAF2DFADFB4DC664C0948DCA (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A));
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_13 = V_0;
		(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mC4E0AFC567AF7616A0BD7630EA1729B39B3F1707 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m9D776805F35EE4468AD9DD49398FE3C63AF657A1 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4776AE016DEBA009A6380C97D690FCD4F31FDFA8_inline(__this, NULL);
		List_1_Reverse_m08CDE27F94AF0C016011BB7D8DE3456C30D833D4(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m08CDE27F94AF0C016011BB7D8DE3456C30D833D4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m1F4D1131DC87845F783651159C17228A913048CF(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m9456AF5134FD6F4750D0DEE40D6AA72196B6452A (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m4776AE016DEBA009A6380C97D690FCD4F31FDFA8_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_mBDDC76902E0EB7C0EBE4574128461479E50C44AC(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mBDDC76902E0EB7C0EBE4574128461479E50C44AC (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisSubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A_m0D98180CBD3D2C2DF5A5735C6CFC7330C902D5D5(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m7D3722A03B3A06E6ACF33F784C2565E77697A227 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t6C07E57ADFC027FF85DA828DE7915F4568D4ED42* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_mA38A719A6AD2F29AF7125A22D7CD26CC32657EC3(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* List_1_ToArray_m288AE23146B291D33EC5B912CA49E40FF25779B2 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_1 = ((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_3 = (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)(SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_4 = __this->____items;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m000A063D523E65A4E1203650A1E641FBAB58A3A4 (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_6;
				L_6 = InterfaceFuncInvoker0< SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mC52CE4FF1E2C7295157A490368F06BA0DA92D66F(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mA84CFD48BC0EA45397471C55FD977437C2FB17D8 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_0 = (SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)(SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7378BA5FBCA1E88080985FB810820B3F47DAD54C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m54D719307910A9DC9CD4DEFA8AE2626F49EB7516_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m4D165FBE2796C395527CD5404B0C5D0F2828736A_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_6 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = __this->____items;
		InterfaceActionInvoker2< __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_9 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_13 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		Il2CppSharedGenericObject* L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		Il2CppSharedGenericObject* L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (Il2CppSharedGenericObject*)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		RuntimeObject* L_0 = ___0_value;
		if (((Il2CppSharedGenericObject*)IsInst((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_2 = V_0;
		return (bool)((((RuntimeObject*)(Il2CppSharedGenericObject*)L_2) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m78BCF727FD3CF47C4FE97D00AFAD2781B6A7F004_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		Il2CppSharedGenericObject* L_1;
		L_1 = List_1_get_Item_m02336594E8F76D7313E2BCB7A3ED5ABD13B4D515(__this, L_0, NULL);
		return (RuntimeObject*)L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m5E8C43852B62BD7E2A9582754B44057F224BD12D_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_mCD8F7775F9C4842958A7188EBC0EBF1BE03101EF(__this, L_1, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		int32_t L_8 = V_1;
		Il2CppSharedGenericObject* L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (Il2CppSharedGenericObject*)L_9);
		return;
	}

IL_0034:
	{
		Il2CppSharedGenericObject* L_10 = ___0_item;
		List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Il2CppSharedGenericObject* L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (Il2CppSharedGenericObject*)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mC916FB88482D2EF5E43527D9840C8E67FAC4D4CB_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_inline(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m655A34E010FCB41069350D2D616558180A0C0AFF_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* List_1_AsReadOnly_m55F73F8553E9885F803507A3650967BE90AA81C9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263* L_0 = (ReadOnlyCollection_1_t06F71F2F3EBC6E0A34714E0A7EB3367B6D248263*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_mC1890FAC00703F47A655C35CBCB613C74A811580(L_0, (RuntimeObject*)__this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mCCC05B98943E8F4E0F6FBF47063A269048AE71E5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		Il2CppSharedGenericObject* L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m7E4E8EA0E50007EC7F90752FBB913B35DBD8C00B_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m63E643DC9A821297E2EBF9085D93B39BFC2F9DCE(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m04A1E702FBAB126758881A6A6D42052295136DCD_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_array, const RuntimeMethod* method) 
{
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_array;
		List_1_CopyTo_m75919E1737F4EC8D7DD329629C11CACA64EF5BE3(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m4B62593B8671BB60809057D57DC60568557315E6(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mD56F0607D7DAD9622F7DE2C6C8957D9C7847EEC5_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m701B15E692EF4FFE95A773C8246D55779CB00B2D_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_10 = ___2_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		Il2CppSharedGenericObject* L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mBF03CBE09BFBA1E25B3E040FC761F6674F19D793_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9((&L_0), __this, NULL);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m2B6B507A19EBC0BBE5E87F276DB25C8B3388EC75_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mB0C2B8891214015BE286DC32F260DEBDFAD317E9((&L_0), __this, NULL);
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->____items;
		Il2CppSharedGenericObject* L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisIl2CppSharedGenericObject_m0C73DE72012C676D6E4354C82EA6550BBADC3D33(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m1C5FA1B6E2917EF7F5DDC5BF65147FE6EF7F8517_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, Il2CppSharedGenericObject* ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		Il2CppSharedGenericObject* L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (Il2CppSharedGenericObject*)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m09D3F4F2042326635CFB5369AC8F9760A7F81CE2_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisIl2CppSharedGenericObject_mE7A1EEC53480BA1ED6C827938ADAF45B127DD054(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E(__this, L_1, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m7B9D6C4AB69B4EA07C23832C6109C25C21E99804_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_20 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				Il2CppSharedGenericObject* L_45;
				L_45 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_mC5A8238645AD1D203E75313802D4DC78BDE7857E(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		Il2CppSharedGenericObject* L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m4B13B6BE7AA6327431F1BE406264329892975DE9(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mCBBBF61C9D398AB54A3B84E64145D65DF44BA716_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9E5E0DF2443D88570595AEA0FEF7D7122455EB26(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m0AC731A08F1400089DD478E2D366804833660796(__this, ((Il2CppSharedGenericObject*)Castclass((RuntimeObject*)L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m4EE2013145E54D7A4FC8DC18C59D96E7DB7766FC_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_4 = ___0_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		Il2CppSharedGenericObject* L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* L_16 = ___0_match;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		Il2CppSharedGenericObject* L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		Il2CppSharedGenericObject* L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (Il2CppSharedGenericObject*)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m36F68EA689DB109415094085A496D5EA21E2F23C_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(Il2CppSharedGenericObject*));
		Il2CppSharedGenericObject* L_13 = V_0;
		(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12), (Il2CppSharedGenericObject*)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m62CC0A9594355982BB7665FB6F070950D3B89C30_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m5D2819AF5937BFF72667A9AC1F0D657F4AFF58BC_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m97197478E9535E327B4509C065B30BB0DD6F1F99_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisIl2CppSharedGenericObject_mFAAB0AB623769BB8245CDF219832F2FE75427541(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA11C7B54C894C91320394703D2B0BB90E5FBF21B_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m9832942FE310479E64D9D0D23F29C65305BE1622_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m15AB808AB5390BF8B6D7A057EDA17A54A80A1A6A_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisIl2CppSharedGenericObject_m8C8A5C187776FEA1D5CC7F053F0DC63B32764D61(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m5DC9EDD762287204259B029E98F1409BC3A63A81_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tC9FBFF747FA0455CD35BD7D097691DE20DDCC2B5* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m745CBFE82472049A441AC9522C4B8FA33F5AF970(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* List_1_ToArray_m90E6D9E57256EC0FB6B36FDC40F65B0F59D7B671_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = ((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_3 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = __this->____items;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m44B5C2177E9403DB0E3DC2BC6E590CDA7266BE79_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	Il2CppSharedGenericObject* V_1 = NULL;
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				Il2CppSharedGenericObject* L_6;
				L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m89719BB37EEDA80E6AD7FAC5D1AAC5A47DDE86B5(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				Il2CppSharedGenericObject* L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (Il2CppSharedGenericObject*)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mF9EC44C2DCE6FA8CA8EFEC794130234F42A1D6DB_gshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = (__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)(__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m0AFBAEA7EC427E32CC9CA267B1930DC5DF67A374_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m3069CACB5775E013107F559C825422266A09F9E8_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mACCB7726C2E9728AE336F99C68B334459F9F30FB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_6 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = __this->____items;
		InterfaceActionInvoker2< __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Capacity_m5BE6D733C76E1AB093FB6D2783220A5B96EF61DF_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mD365C22FA3D32D70A2088AB13116E7BA5FBF0BFB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_9 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_13 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_Generic_ICollectionU3CTU3E_get_IsReadOnly_m3F886C476FAC47C7E0B22BBEFA863E6E28CB6967_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_get_IsReadOnly_m14CBA0E79745928530A7F91F920E3B29BF5977C2_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_ICollection_get_SyncRoot_m81521F85F116B00354BB0F726158451F3F1543F8_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____syncRoot;
		if (L_0)
		{
			goto IL_001a;
		}
	}
	{
		RuntimeObject** L_1 = (RuntimeObject**)(&__this->____syncRoot);
		RuntimeObject* L_2 = (RuntimeObject*)il2cpp_codegen_object_new(RuntimeObject_il2cpp_TypeInfo_var);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(L_2, NULL);
		RuntimeObject* L_3;
		L_3 = il2cpp_intrinsic_interlocked_compare_exchange(L_1, L_2, NULL);
	}

IL_001a:
	{
		RuntimeObject* L_4 = __this->____syncRoot;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_get_Item_m6E4BA37C1FB558E4A62AE4324212E45D09C5C937_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, Il2CppFullySharedGenericAny* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		il2cpp_codegen_memcpy(L_5, (L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(il2cppRetVal, L_5, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9A958091885CC5363CCFE9F0BC472EAFCB56C813_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_value, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		il2cpp_codegen_memcpy(L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___1_value : &___1_value), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy((L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)), L_4, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_2)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)), (void*)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mF063A5AC0A6B869965B78A300A210C77D7D85A9E_fshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_0, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInst((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(L_2, V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		bool L_3 = !il2cpp_codegen_would_box_to_non_null(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), L_2);
		bool L_4 = L_3;
		return L_4;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m9468A95C180AB56C22EF37B808E722B82FA5DA1D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = ___0_index;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7), __this, L_0, (Il2CppFullySharedGenericAny*)L_1);
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_1);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m0F05BC227468EA87CF5E5E2D0707EFEDD6DB1D48_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(L_0, ((int32_t)15), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9), __this, L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_6 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mD4F3498FBD3BDD3F03CBCFB38041CBAC9C28CAFC_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_9 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_10 = L_9;
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = V_0;
		int32_t L_8 = V_1;
		il2cpp_codegen_memcpy(L_9, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy((L_7)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_8)), L_9, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_7)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_8)), (void*)L_9);
		return;
	}

IL_0034:
	{
		il2cpp_codegen_memcpy(L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_10: *(void**)L_10));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mA6DFDBC2B22D6318212C6989A34784BD8303AF33_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		int32_t L_4 = V_0;
		il2cpp_codegen_memcpy(L_5, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy((L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)), L_5, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_3)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_4)), (void*)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m16AFA75CCE3355CE51D428B0931951485666BF3D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_2 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(L_0, ((int32_t)20), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		void* L_3 = UnBox_Any(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_2);
		InvokerActionInvoker1< Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_3)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_3))));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_4 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_5 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_6 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_7;
		L_7 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_6, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_5, L_7, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_8;
		L_8 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_8, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m44DED39FFEBC8F2ACF6162DB065B649E888B9C57_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* List_1_AsReadOnly_m7815E4F80542F2F7532AD847F4AA17739E5A7158_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8* L_0 = (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		((  void (*) (ReadOnlyCollection_1_t5B7AA4E006906DE6818A44873F2D5987EFBF3AB8*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17)))(L_0, (RuntimeObject*)__this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mD615D1BCB2C9DD91DAD86A2F9E5CF1DFFCBF7925_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		bool L_1;
		L_1 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		if (!L_1)
		{
			goto IL_0035;
		}
	}
	{
		int32_t L_2 = __this->____size;
		V_0 = L_2;
		__this->____size = 0;
		int32_t L_3 = V_0;
		if ((((int32_t)L_3) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		int32_t L_5 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_4, 0, L_5, NULL);
		return;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m8DA550B703DFB328B69C4712064C667D7CA33DF1_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_2;
		L_2 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_1: *(void**)L_1));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m20FD9B23AB202EAE6A3EBD3271A64B10BB21C5D9_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m9632CAFAB9E06DBDE71886CC36E6C910F8350F9C_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_array;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 22)))(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_ICollection_CopyTo_mAAA2256D3B50B6A712DFB270B01B470759AB4FE9_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeArray* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeArray* L_0 = ___0_array;
		if (!L_0)
		{
			goto IL_0012;
		}
	}
	{
		RuntimeArray* L_1 = ___0_array;
		int32_t L_2;
		L_2 = il2cpp_codegen_array_get_rank(L_1);
		if ((((int32_t)L_2) == ((int32_t)1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(7, NULL);
	}

IL_0012:
	{
	}
	try
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		RuntimeArray* L_4 = ___0_array;
		int32_t L_5 = ___1_arrayIndex;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_3, 0, L_4, L_5, L_6, NULL);
		goto IL_0031;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0029;
		}
		throw e;
	}

CATCH_0029:
	{
		ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1* L_7 = ((ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*)IL2CPP_GET_ACTIVE_EXCEPTION(ArrayTypeMismatchException_t95F1723A5A166E62D3FBEF9734DEFBF61594F8F1*));;
		ThrowHelper_ThrowArgumentException_Argument_InvalidArrayType_m469A6A5731A0F1E94D8B609ED9D001C3A1652A58(NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0031;
	}

IL_0031:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m5180D7A430072A21034A0692CDD1D565ADEE2ABB_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_array, int32_t ___1_arrayIndex, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = ___0_array;
		int32_t L_2 = ___1_arrayIndex;
		int32_t L_3 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_0, 0, (RuntimeArray*)L_1, L_2, L_3, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m0116C3A6AF6FB7DCF2E909AD859A0ADC86A60C66_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23)))(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mE810B96CFE4683761086D777FD5947FA66EA9255_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_1 = ___0_match;
		int32_t L_2;
		L_2 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24)))(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 24));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m63AAB8CE007CDF25CF1952FBF0F1FF7234695BD0_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___2_match, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_10 = ___2_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		il2cpp_codegen_memcpy(L_14, (L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		bool L_15;
		L_15 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_14: *(void**)L_14));
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_GetEnumerator_m8B2A92ACD4FBA5FBDC3F6F4F5C23A0DDF491DA61_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* il2cppRetVal, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26));
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_0 = alloca(SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
	{
		memset(L_0, 0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		il2cpp_codegen_memcpy(il2cppRetVal, L_0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mF8AB18BC6656CC469BFB6E837C001C2DE0833859_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26));
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_0 = alloca(SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
	{
		memset(L_0, 0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), L_0);
		return (RuntimeObject*)L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m83A6D1115899BF6BA842C33FE41FAD8D6EB43ED9_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26));
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_0 = alloca(SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
	{
		memset(L_0, 0, SizeOf_Enumerator_t4982EA6BF5A270D5544CF8876DE60B125EDF8FB9);
		Enumerator__ctor_m5C66A91DC68887BE203985B56EF2F74222E9AF50((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_0, __this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 27));
		RuntimeObject* L_1 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), L_0);
		return (RuntimeObject*)L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m1FFA888B47CE3256B0AC301302FAD79AAAFC0818_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = __this->____items;
		il2cpp_codegen_memcpy(L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = InvokerFuncInvoker4< int32_t, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Il2CppFullySharedGenericAny, int32_t, int32_t >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28), NULL, L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_1: *(void**)L_1), 0, L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mF0601617A54C360278652B7AEE34E69F21B5ADDA_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		int32_t L_5;
		L_5 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		return L_5;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mB8862677E04375531A30F3EC07AC2372FCE61F55_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, Il2CppFullySharedGenericAny ___1_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_16 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		il2cpp_codegen_memcpy(L_16, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___1_item : &___1_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy((L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)), L_16, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_14)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_15)), (void*)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m3A5BCE3337DF64C89354C0CDF5DB4EE39A30BCA7_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		((  void (*) (RuntimeObject*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(L_0, ((int32_t)20), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8));
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_1, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_5 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_6 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_6, L_8, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m729639E2C8D1AA7579AC78D259085921E7DC72F2_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_45 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_20 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44, (Il2CppFullySharedGenericAny*)L_45);
				InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29), __this, L_43, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_45: *(void**)L_45));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m9BCE8CEF94E6F2BF8624D65214FF4F3CA686D60C_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Il2CppFullySharedGenericAny ___0_item, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_0 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	int32_t V_0 = 0;
	{
		il2cpp_codegen_memcpy(L_0, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? ___0_item : &___0_item), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		int32_t L_1;
		L_1 = InvokerFuncInvoker1< int32_t, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_0: *(void**)L_0));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34)))(__this, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 34));
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m69B0EB46209420A0DF794AE7598F8C3E02515509_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_3 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		void* L_4 = UnBox_Any(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), L_3);
		bool L_5;
		L_5 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35), __this, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? (((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4)): *(void**)(((Il2CppFullySharedGenericAny)(Il2CppFullySharedGenericAny*)L_4))));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m64ACE8FD442E00A79160BB070C0133B43A8C4075_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* ___0_match, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_20 = L_8;
	const Il2CppFullySharedGenericAny L_31 = L_8;
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_4 = ___0_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		il2cpp_codegen_memcpy(L_8, (L_5)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_7)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25), L_4, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t81499D2838AC2641B3FA14CD4DBF7E1594A9E107* L_16 = ___0_match;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		il2cpp_codegen_memcpy(L_20, (L_17)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_19)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		bool L_21;
		L_21 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 25), L_16, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)) ? L_20: *(void**)L_20));
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		il2cpp_codegen_memcpy(L_31, (L_27)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_30)), SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy((L_24)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)), L_31, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_24)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_26)), (void*)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		bool L_34;
		L_34 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		if (!L_34)
		{
			goto IL_00ad;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_35 = __this->____items;
		int32_t L_36 = V_0;
		int32_t L_37 = __this->____size;
		int32_t L_38 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_35, L_36, ((int32_t)il2cpp_codegen_subtract(L_37, L_38)), NULL);
	}

IL_00ad:
	{
		int32_t L_39 = __this->____size;
		int32_t L_40 = V_0;
		int32_t L_41 = V_0;
		__this->____size = L_41;
		int32_t L_42 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_42, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_39, L_40));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mF6C23E9072D8CBE2872705E7E4D08BDB78770F5C_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_14 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_0, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		bool L_11;
		L_11 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		if (!L_11)
		{
			goto IL_0063;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_12 = __this->____items;
		int32_t L_13 = __this->____size;
		il2cpp_codegen_initobj((Il2CppFullySharedGenericAny*)V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy(L_14, V_0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		il2cpp_codegen_memcpy((L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)), L_14, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
		Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_12)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_13)), (void*)L_14);
	}

IL_0063:
	{
		int32_t L_15 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_15, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mCD6121D4FDE143767E6F0EC89183A9A349884DFF_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		bool L_19;
		L_19 = il2cpp_codegen_is_reference_or_contains_references(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 18));
		if (!L_19)
		{
			goto IL_008d;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_20 = __this->____items;
		int32_t L_21 = __this->____size;
		int32_t L_22 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_20, L_21, L_22, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m31924FC6445F9A1633DA40A8930F89E271B477F2_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36)))(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m4F224F8A44C29751CCF7ED914FC00BFE7F27CD01_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37)))(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mCBEFEE4479438557E591F7AEF3BFDE2297DA269D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38)))(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m851B4290E563560C0037434A52D469666ABDE79D_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39)))(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mF939EF9300267AF108323ABAECB490A27894309B_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, int32_t, int32_t, Comparison_1_tE94B5C4AE59DE10B7A54AD7C3291462A05D5CD49*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40)))(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* List_1_ToArray_m5160526E5983BD8ED24DFFE47C33B141C1B3187A_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = ((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_3 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_4 = __this->____items;
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mFD4E2919839A27C7CEACADF62222C63701302D02_fshared (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	const Il2CppFullySharedGenericAny L_15 = L_6;
	RuntimeObject* V_0 = NULL;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	memset(V_1, 0, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5, (Il2CppFullySharedGenericAny*)L_6);
				il2cpp_codegen_memcpy(V_1, L_6, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
				int32_t L_7 = __this->____size;
				__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				((  void (*) (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				il2cpp_codegen_memcpy(L_15, V_1, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
				il2cpp_codegen_memcpy((L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)), L_15, SizeOf_T_t664E2061A913AF1FEE499655BC64F0FDE10D2A5E);
				Il2CppCodeGenWriteBarrierForClass(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), (void**)(L_11)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_14)), (void*)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mFBD61154F711CE4EF252AA0B8B504EFC3E7E5B37_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = (__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m21C393E89D2891A0B17DA7721D14F694C8E87F0E_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = ((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mBEC4BB23DEF62EFA5D66833D82CEB6FABDD96E04_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_2 = ((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_4 = (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)(__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m4176A00C23FE40B9269F7306A7F8170510EA966F_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_6 = ((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_8 = (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)(__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_10 = __this->____items;
		InterfaceActionInvoker2< __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_12 = ((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_m70DD3FB3C4E302AA0AACC45C39BCEC4C2A9DB230(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m7AA13FF7BE1A11F437B16EAE3E1FA50DBFC902AE_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_7 = (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)(__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_9 = __this->____items;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_13 = ((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		int32_t L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_mCDBFFAC056B77CBE377B26CAED3E893C131F4EFB_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (int32_t)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D_gshared (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	int32_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(int32_t));
		int32_t L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m44527B1273F26E0B2A6025EAB639B8177DCBAD63_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1;
		L_1 = List_1_get_Item_mEAF67AD94AB1E060C2D03D7A6820C47270E06B75(__this, L_0, NULL);
		int32_t L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mC92CD521E4329D204BCF0192DDFFBA3FE02D79E7_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m835718C92D2C5DA2051794F6922D21453EAC493E(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_mCDBFFAC056B77CBE377B26CAED3E893C131F4EFB(__this, L_1, ((*(int32_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m24BA4DEDED426A5B0C6A4AB3E523C876B0B918A6_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_7 = V_0;
		int32_t L_8 = V_1;
		int32_t L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (int32_t)L_9);
		return;
	}

IL_0034:
	{
		int32_t L_10 = ___0_item;
		List_1_AddWithResize_m3B53F17525936469654379AC0F1F0B19EC3DCCE5(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m3B53F17525936469654379AC0F1F0B19EC3DCCE5_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_3 = __this->____items;
		int32_t L_4 = V_0;
		int32_t L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (int32_t)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mBCF4F1C3031249C6D89E84F02EA59D632DDA997C_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m835718C92D2C5DA2051794F6922D21453EAC493E(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m24BA4DEDED426A5B0C6A4AB3E523C876B0B918A6_inline(__this, ((*(int32_t*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m8719A0E4E1F227424476DE81DF6DF6B58CA1CD71_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m9E2CD0E840D68FFF2E93915D330EB9681A0E0721_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m99F96BAC4A4EE626A6141612A5C6793BE37E006C(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8* List_1_AsReadOnly_m25EFCCC51703B079DBFEBF80EE3C8012FBBF1AA3_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8* L_0 = (ReadOnlyCollection_1_tA097AD399F1ED95CBDEFC0663790A10C4A43DFB8*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m401D0350AA4E4ACE83F75DE82712FF72120418D4(L_0, (RuntimeObject*)__this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m4E96FC2CDBD626013EB39C0428C26B9D88359E19_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m61A085CF349BFF87A90BE6FEE413C548F3F9E567_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m34CA912991B08316DC2FF3362B1E0BE2B10A180A_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m61A085CF349BFF87A90BE6FEE413C548F3F9E567(__this, ((*(int32_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mAFEE5FF355F693C782528635F3A5D4C7407F3E59_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* ___0_array, const RuntimeMethod* method) 
{
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = ___0_array;
		List_1_CopyTo_m02DA9C05536AB370B550B399953F68908C934B06(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m7AA13FF7BE1A11F437B16EAE3E1FA50DBFC902AE(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m334C39F1B647D613EE0A8043D6B30A64B63E713C_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mC9F71DEB213A8D42EBC3A47798AAF6CD140438CA(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mC9F71DEB213A8D42EBC3A47798AAF6CD140438CA_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* L_10 = ___2_match;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		int32_t L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 List_1_GetEnumerator_mEF61540761E14807B2930879741EF5E1E973FCE8_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0B844022E6FED4C6DA8CD7C270989D9D34800C69((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m78062C379A1F46A464E795C0849AB4EDFF868B42_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0B844022E6FED4C6DA8CD7C270989D9D34800C69((&L_0), __this, NULL);
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m45DBBE789A3F8786F76C5A2585457FD2639A75A6_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m0B844022E6FED4C6DA8CD7C270989D9D34800C69((&L_0), __this, NULL);
		Enumerator_t038D231EFD33CA6827B72B0B493F822DC96F8AC6 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = __this->____items;
		int32_t L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m9AE979627DAA17E8B9E3EF440A130C1B9C245059(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m4782CB7C7B19993DDAFEA39DB1C1E199BB6FF519_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7(__this, ((*(int32_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_m8C3391D73E5396E7FD12A5DA1CEDDD0A83EAAB79_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (int32_t)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m1DF6E9F34E488816C096E628611633BEB631D2F9_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_m835718C92D2C5DA2051794F6922D21453EAC493E(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_m8C3391D73E5396E7FD12A5DA1CEDDD0A83EAAB79(__this, L_1, ((*(int32_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m99F96BAC4A4EE626A6141612A5C6793BE37E006C_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_20 = __this->____items;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				int32_t L_45;
				L_45 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_m8C3391D73E5396E7FD12A5DA1CEDDD0A83EAAB79(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_m70DD3FB3C4E302AA0AACC45C39BCEC4C2A9DB230(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mAF82A7B6E01FEB6F200C76071F76554EE4B35DB8_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_m22A847FE310BE1BA056D9344E43A4E5BB88759D7(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_mBA121E6727BDC54EB17A84709997D6920BBE4D10(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m4E9543E3637A1201432E256AEBD495300BC773C2_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mD81F4794E5BA5AD31C7A25CA1B456BA04E37EC1D(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mAF82A7B6E01FEB6F200C76071F76554EE4B35DB8(__this, ((*(int32_t*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_mCBA2DA3F26920D654BB85DCAF8EEFE5BE16377AE_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* L_4 = ___0_match;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* L_16 = ___0_match;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		int32_t L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		int32_t L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (int32_t)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_mBA121E6727BDC54EB17A84709997D6920BBE4D10_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m91A4C1021000C5BFE7D3463F5495536BED08D81B_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mE349E70153E21A54521C2E763EB22799EE479401_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m8719A0E4E1F227424476DE81DF6DF6B58CA1CD71_inline(__this, NULL);
		List_1_Reverse_m34A5681B1296F6E4F08C9F0986F4E4F1CF23FBE4(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m34A5681B1296F6E4F08C9F0986F4E4F1CF23FBE4_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mA4406A8C17BBC29625F80F783EA91C3AECF7E3EA(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m9E9FB3F1E5821F9FFDDD6736D17DF336D7EB9553_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m8719A0E4E1F227424476DE81DF6DF6B58CA1CD71_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m29868C70BFD9DDFB44E31BF13302FB7AB5244913(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m29868C70BFD9DDFB44E31BF13302FB7AB5244913_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_Tis__Il2CppInt32Enum_tE5E90BB5D60D5281C33DB29D9DCBD70D5E2E1F7B_mE004CFE5BA4856AC83A08DEA9F09D3224F3EDD7B(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m37D4F3D2CBBCCB67F7E9AE1408053354CCADACB3_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t0F283DBF0EC45EE18464332F2713E3E393EED6C3* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_mCDDF2BDFA2ACB2C2254C52BBD32AD774C7C05CDC(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR __Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* List_1_ToArray_m043FE949D46CFF539CD3838BF2282014737B5DDB_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_1 = ((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_3 = (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)(__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_4 = __this->____items;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_m70DD3FB3C4E302AA0AACC45C39BCEC4C2A9DB230_gshared (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				int32_t L_6;
				L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mB5CE702B99DFF8E1BB13570D69ADA436D814DBBF(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				int32_t L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (int32_t)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m9AA83899E865730828F96BB9658D55D09C2D86E0_gshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_0 = (__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)(__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m36D6C2C549C181076288DA383CC7B03DECFF997B (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_0 = ((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m963DC069890378B6A3E3359D767115A12793B2D5 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_2 = ((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_4 = (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)(AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m2D3B6D64E158185039022CF1DC6BF81232E4ECDD (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_6 = ((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_8 = (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)(AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_10 = __this->____items;
		InterfaceActionInvoker2< AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_12 = ((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_mB565A7AD8E82EBD46650B3F0E052900CE12DF2C5(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m3332E89182E608A4BF6BE672CB719B8B0067984C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_7 = (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)(AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_9 = __this->____items;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_13 = ((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 List_1_get_Item_m4077C3878C73CFD2C37863B24FFABC93CCB538C2 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m9EE840E6FBE06791D954E7A69D53CE90EFCB863D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_m9AA36809C4850F3957B1A0B552645A8F328B7158 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161));
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m947597FE12E4BA2A85804F95A352ACF345C94885 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_1;
		L_1 = List_1_get_Item_m4077C3878C73CFD2C37863B24FFABC93CCB538C2(__this, L_0, NULL);
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mD832AF33855D28D59717DB409E91D8526478AF36 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m668408E30034D9AF162BA065A1B8A9190CCB854C(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m9EE840E6FBE06791D954E7A69D53CE90EFCB863D(__this, L_1, ((*(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mC35682C02D89984B864B24B3BB4F92B5C2374273 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) 
{
	AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_7 = V_0;
		int32_t L_8 = V_1;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_9);
		return;
	}

IL_0034:
	{
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_10 = ___0_item;
		List_1_AddWithResize_mCA55981D47453F8483BD503CA53B0DABBDB8844D(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_mCA55981D47453F8483BD503CA53B0DABBDB8844D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_3 = __this->____items;
		int32_t L_4 = V_0;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_m8D6A9580DC8157A4B26413CB8E937EE0B1FD4673 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m668408E30034D9AF162BA065A1B8A9190CCB854C(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_mC35682C02D89984B864B24B3BB4F92B5C2374273_inline(__this, ((*(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m5F8DAD406CF36D0DEEB854A55C356D94762E30CB_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m28CF9B6487F02A6E0944A0A371459D954C3E7408 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m830DE1B798DA2F877FBFF052C8841D220839E942(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293* List_1_AsReadOnly_m89FA24319273BE413C39340547C288F96196F0A6 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293* L_0 = (ReadOnlyCollection_1_t0072B9B1BE9DDF9C8BF0ABE59E7EEBD11BFAA293*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_mB3BFC6EBF26339300AE50AEA966E9B13DA92D54F(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m88B956AEE7318EDD5FCB2CE2E870F681D69A4E4D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m82EC683EFB57714A07D26CB6E17D84FFAE7C82AE (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mCB5DDE85A3BF1B0AE48D46EB6E22999A0E4D060D(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m5A1933A3C5DEB75534FB49094CC9BAC2A3A7D0C5 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9AA36809C4850F3957B1A0B552645A8F328B7158(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m82EC683EFB57714A07D26CB6E17D84FFAE7C82AE(__this, ((*(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_mD3E6E1675B5D239D04EDEBDCC3BEC9ED314E0784 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* ___0_array, const RuntimeMethod* method) 
{
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_0 = ___0_array;
		List_1_CopyTo_mBB5FC483C17D644A9362EDE7FB61DD1D6233000C(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m3332E89182E608A4BF6BE672CB719B8B0067984C(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m26711BD95F0847B161016ECEBA1123F477AD8E11 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_m6C63371ECE0863BF14A70E4012C6A62D66B5F5D7(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m6C63371ECE0863BF14A70E4012C6A62D66B5F5D7 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* L_10 = ___2_match;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m8D40905BAEF5849C9DF55268BB4FD2C8CB0A1A79_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 List_1_GetEnumerator_m71067EDD82FBD477E1BE9694B892C63B2B999C71 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m3B885E0CB5C32229381BEF0AD2CE4682713CA0EC((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mAA21DAF2832F61083599B8B7B0452AE2526F6244 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m3B885E0CB5C32229381BEF0AD2CE4682713CA0EC((&L_0), __this, NULL);
		Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m6424C877E306A6AC27A249CC52D90BA718E4E7B7 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m3B885E0CB5C32229381BEF0AD2CE4682713CA0EC((&L_0), __this, NULL);
		Enumerator_t6630402C90E9E1872D41DA78B1CA17C07D89A9F5 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mCB5DDE85A3BF1B0AE48D46EB6E22999A0E4D060D (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) 
{
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_0 = __this->____items;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m075DCC6CC6C5E2D552CC01B5A5D93D761529CC5E(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mCE1105AAD9EAF0BAABBACF5D4F76F8647C74ECDC (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9AA36809C4850F3957B1A0B552645A8F328B7158(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mCB5DDE85A3BF1B0AE48D46EB6E22999A0E4D060D(__this, ((*(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mFF1B561AB8F89B1761C15D1863C00ED3AD7BF324 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m0840EEFEF9E5209E46C901C4BB6D266DFFF506B8 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m668408E30034D9AF162BA065A1B8A9190CCB854C(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mFF1B561AB8F89B1761C15D1863C00ED3AD7BF324(__this, L_1, ((*(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m830DE1B798DA2F877FBFF052C8841D220839E942 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_20 = __this->____items;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_45;
				L_45 = InterfaceFuncInvoker0< AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_mFF1B561AB8F89B1761C15D1863C00ED3AD7BF324(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_mB565A7AD8E82EBD46650B3F0E052900CE12DF2C5(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mA7E179931948DD88B825B2851F0BB01856B70460 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mCB5DDE85A3BF1B0AE48D46EB6E22999A0E4D060D(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m252525485F467F26DB5C91A957EA9F842D005C40(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m105698B1E1A84AD80594BDDC45CF25703B4D5B99 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_m9AA36809C4850F3957B1A0B552645A8F328B7158(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mA7E179931948DD88B825B2851F0BB01856B70460(__this, ((*(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_mE7121022B2FC3DE26CB98396D8E84A04A66A1CF5 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* L_4 = ___0_match;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m8D40905BAEF5849C9DF55268BB4FD2C8CB0A1A79_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* L_16 = ___0_match;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m8D40905BAEF5849C9DF55268BB4FD2C8CB0A1A79_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m252525485F467F26DB5C91A957EA9F842D005C40 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161));
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_13 = V_0;
		(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m2654478C22CA96104BAEF5400FC0008E9E36F941 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m02298A1EF154FB8CDFCD47E1750CD852896CBF6C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m5F8DAD406CF36D0DEEB854A55C356D94762E30CB_inline(__this, NULL);
		List_1_Reverse_mBDDBB14EC973F164BA222AEB240F57B8460DAC1C(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mBDDBB14EC973F164BA222AEB240F57B8460DAC1C (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_mB7050783F04AD0453F190FBF1F3F6A2B6CB59506(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m4520F1071319806EC9F0F933DECDC8A87686A181 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m5F8DAD406CF36D0DEEB854A55C356D94762E30CB_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m1CAB75B85D1547C184E1CA824E4A29E11269376E(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m1CAB75B85D1547C184E1CA824E4A29E11269376E (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisAwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161_m9D7F79A00D6CDEEE91A7009E9C83C8A9190FCA23(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m7B6AA41984EC619E52012A1FB09301CFE446CB02 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_t53C7968EAD02BE23D913BD2C7F7F58BBBDD8D096* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m46BFEDFA8C5CE90310AFB562E0DE7A7E83E3BFEF(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* List_1_ToArray_m689FD9633B8CA4B6D791D424C63EB1E4A628D9F2 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_1 = ((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_3 = (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)(AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_4 = __this->____items;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mB565A7AD8E82EBD46650B3F0E052900CE12DF2C5 (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_6;
				L_6 = InterfaceFuncInvoker0< AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mC9206E89715229E345A1542F94AC519D11E191D3(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_m97A6896725C5440AA408FFCB9ED5252043CB839A (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_0 = (AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)(AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mF5CCF832B2A17822B9C64E78D9814190165C1D7B (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_0 = ((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m3F4723F3305F67834CE85E425907F53C7AB30484 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_2 = ((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_4 = (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)(OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m704785946C26F21A75CF1D70A2DF69E177349DEC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_6 = ((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_8 = (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)(OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_10 = __this->____items;
		InterfaceActionInvoker2< OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_12 = ((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_mA6E73354873BEAC5429A80AE43CB210589A7EC7E(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_mC49015D45A78A39909C4541BDB84DAA369E6A4C1 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_7 = (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)(OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_9 = __this->____items;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_13 = ((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 List_1_get_Item_mB65D799560ADD289EA08E717412A24EFADA7FB57 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m7533012D6C4CE083D5CAF670259B97F6D5D506F4 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mA2F95E82C59734A475035EF3B9DD4BCE9F8429DB (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837));
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m1E70F596E00E1A551FAA8FBC581829AC9F9C5380 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_1;
		L_1 = List_1_get_Item_mB65D799560ADD289EA08E717412A24EFADA7FB57(__this, L_0, NULL);
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_m1DA92BD10C1F7E8C92A5ADDC41B5B59E38B45DEC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m054615FD6A62EE7702B344B2E24BA8423FEF9621(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m7533012D6C4CE083D5CAF670259B97F6D5D506F4(__this, L_1, ((*(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_mB308EE5BFFD89A7B8C251644D76CA547456F3012 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) 
{
	OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_7 = V_0;
		int32_t L_8 = V_1;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_9);
		return;
	}

IL_0034:
	{
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_10 = ___0_item;
		List_1_AddWithResize_m8B3D79788ADC2B54C9B12CC9EC1158E6A04CDEBC(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m8B3D79788ADC2B54C9B12CC9EC1158E6A04CDEBC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_3 = __this->____items;
		int32_t L_4 = V_0;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mAC1736DC5831C59BD64FC09C14F03AF5B9802CBF (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m054615FD6A62EE7702B344B2E24BA8423FEF9621(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_mB308EE5BFFD89A7B8C251644D76CA547456F3012_inline(__this, ((*(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_m905EB6FD0B91CEE1CC0165F1EBB8C1309AEE4BEC_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m4C28D7F5EE927CF1E9858BE460EA4DFB7F5D3AFA (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m9AA9E2C5627FB6CD9F3493CA8A99588EDA08125D(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E* List_1_AsReadOnly_m3E59B457103D2F1A4D283713A62EFBFC7F91322C (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E* L_0 = (ReadOnlyCollection_1_t00EFCE24C7E2AF195B108C1FC1E1BE4F7007EC1E*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m5D03D2E5CE6AAFA9914B3F1E1707393948DA34CB(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_mFCE2A5F0F23BC41E5B1E6F8ABA41D99A8A5AABA9 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_m590D7926DA2B45C95850710F87644BCD235F1A70 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mFA6A5CD427374237339591ED8A5218B6E7EA7F4C(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_m04EF9F1B5EB5475A55429F987420A7AE443BE0BB (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mA2F95E82C59734A475035EF3B9DD4BCE9F8429DB(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_m590D7926DA2B45C95850710F87644BCD235F1A70(__this, ((*(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m901F0963BA82CF65FCD89C086C5D7B3ABA3765C2 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* ___0_array, const RuntimeMethod* method) 
{
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_0 = ___0_array;
		List_1_CopyTo_m96F4BF1E6FF691338A44AAB62506964ACAD70715(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_mC49015D45A78A39909C4541BDB84DAA369E6A4C1(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_m8E32928E07448E4DE50B13A27ABDF776DE8F4DDD (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mA5DDCB0CBD1B539DB3213A4B3AE1C72E519C98A8(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA5DDCB0CBD1B539DB3213A4B3AE1C72E519C98A8 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* L_10 = ___2_match;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_m182E0ACAA85455151F5750CE87F942DA6E3DD3D6_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 List_1_GetEnumerator_mBE57F88655594CAF946932CCDC95E8773FC4C4A6 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mCAD56839187542C3B25E2C1493BBD62861333E4E((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_m8956517C0AA90A843C73167BF6CF0156995ADB13 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mCAD56839187542C3B25E2C1493BBD62861333E4E((&L_0), __this, NULL);
		Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m8D77CF72C1A81595B4557A40BD1877C3EC630AA3 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_mCAD56839187542C3B25E2C1493BBD62861333E4E((&L_0), __this, NULL);
		Enumerator_t389EF10F90069ED924478E5694DFE1BB5CBCF251 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mFA6A5CD427374237339591ED8A5218B6E7EA7F4C (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) 
{
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_0 = __this->____items;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m972A3CE5298A6193E512B34C64201444B051D8E9(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_m3FAB7DEDF1376DCB40FF595ECE24A82D09D133E9 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mA2F95E82C59734A475035EF3B9DD4BCE9F8429DB(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mFA6A5CD427374237339591ED8A5218B6E7EA7F4C(__this, ((*(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mF138D66498A5DE06E21A7149C35FA14729F4F5E1 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_m22B1E1E9ABC66027ABDF98D71BAC7AE153F67C15 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m054615FD6A62EE7702B344B2E24BA8423FEF9621(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mF138D66498A5DE06E21A7149C35FA14729F4F5E1(__this, L_1, ((*(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m9AA9E2C5627FB6CD9F3493CA8A99588EDA08125D (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_20 = __this->____items;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_45;
				L_45 = InterfaceFuncInvoker0< OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_mF138D66498A5DE06E21A7149C35FA14729F4F5E1(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_mA6E73354873BEAC5429A80AE43CB210589A7EC7E(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_m02DCEAFFE826B31F80767A9D191CB4587D82F7BC (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mFA6A5CD427374237339591ED8A5218B6E7EA7F4C(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m30CC1D4CA1984DCAEDBCD2228B538A0503AF854A(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_m2E22ECF19C2591E73B083E2B26EED5B2E4B8B3BB (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mA2F95E82C59734A475035EF3B9DD4BCE9F8429DB(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_m02DCEAFFE826B31F80767A9D191CB4587D82F7BC(__this, ((*(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m99F96CEBE01EC91E6838BFE939CF7B3C41D67CAE (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* L_4 = ___0_match;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_m182E0ACAA85455151F5750CE87F942DA6E3DD3D6_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* L_16 = ___0_match;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_m182E0ACAA85455151F5750CE87F942DA6E3DD3D6_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_34 = __this->____items;
		int32_t L_35 = V_0;
		int32_t L_36 = __this->____size;
		int32_t L_37 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_34, L_35, ((int32_t)il2cpp_codegen_subtract(L_36, L_37)), NULL);
	}

IL_00ad:
	{
		int32_t L_38 = __this->____size;
		int32_t L_39 = V_0;
		int32_t L_40 = V_0;
		__this->____size = L_40;
		int32_t L_41 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_41, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_38, L_39));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m30CC1D4CA1984DCAEDBCD2228B538A0503AF854A (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_11 = __this->____items;
		int32_t L_12 = __this->____size;
		il2cpp_codegen_initobj((&V_0), sizeof(OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837));
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_13 = V_0;
		(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_12), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_13);
	}

IL_0063:
	{
		int32_t L_14 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_mC34416B52737986556034E2111A5817EDEE0C189 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_19 = __this->____items;
		int32_t L_20 = __this->____size;
		int32_t L_21 = ___1_count;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_19, L_20, L_21, NULL);
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_mFF087DD699EA7B98F8636ED593ED83D64ABE078F (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m905EB6FD0B91CEE1CC0165F1EBB8C1309AEE4BEC_inline(__this, NULL);
		List_1_Reverse_m5903E8D5CE5B92A29530763E182314BDFA781664(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m5903E8D5CE5B92A29530763E182314BDFA781664 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_mDCB49D07F30FD9D952124968159FDF346234BD04(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mC839D031A5AAA84A68243F93E39544BA3A966203 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_m905EB6FD0B91CEE1CC0165F1EBB8C1309AEE4BEC_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_mEBED487B845A66E3298CA30654B7EC17F7481995(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mEBED487B845A66E3298CA30654B7EC17F7481995 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisOrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837_m438D9EDDBF93A09C81E89458C2362F85487923EC(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m014D10ACC5ECFB795A9812357A6AD9FFF19F3C47 (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tC8BBA462D5337723AC34773EEE343018753C7FF3* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m4A8362BBA870329F45001F17310B50E583BFF19F(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* List_1_ToArray_m5E0DDBEF3289BA470AD71416C050605CE275FF3B (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_1 = ((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_3 = (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)(OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_4 = __this->____items;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mA6E73354873BEAC5429A80AE43CB210589A7EC7E (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_6;
				L_6 = InterfaceFuncInvoker0< OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_mB6EB012362AA419CAA8BF0C488F1010486273A69(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mBA1A334B4DB00D75CD4BF205DE68E28F92477FF0 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_0 = (OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)(OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mFEF8BE0609A5B0185A946E4BE78E3AE078DCDFDF (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_0 = ((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m9D4C783EADEFE471AE4694A264FC274077D002B4 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_capacity, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		int32_t L_0 = ___0_capacity;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)12), 4, NULL);
	}

IL_0012:
	{
		int32_t L_1 = ___0_capacity;
		if (L_1)
		{
			goto IL_0021;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_2 = ((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_2);
		return;
	}

IL_0021:
	{
		int32_t L_3 = ___0_capacity;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_4 = (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)(SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_3);
		__this->____items = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m9B0EBFC1936470C69C4E10C853BDA10392BBB663 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_collection;
		if (L_0)
		{
			goto IL_000f;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_000f:
	{
		RuntimeObject* L_1 = ___0_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_2 = V_0;
		if (!L_2)
		{
			goto IL_0050;
		}
	}
	{
		RuntimeObject* L_3 = V_0;
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_3);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_002f;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_6 = ((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_6);
		return;
	}

IL_002f:
	{
		int32_t L_7 = V_1;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_8 = (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)(SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_7);
		__this->____items = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_8);
		RuntimeObject* L_9 = V_0;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_10 = __this->____items;
		InterfaceActionInvoker2< SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_9, L_10, 0);
		int32_t L_11 = V_1;
		__this->____size = L_11;
		return;
	}

IL_0050:
	{
		__this->____size = 0;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_12 = ((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		RuntimeObject* L_13 = ___0_collection;
		List_1_AddEnumerable_mDF2147E522AD80A7B6A79CF8E7F00EC7DBF8A032(__this, L_13, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Capacity_m40FE27C2AB4F6F5F863957210FA90C1BF581D293 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* V_0 = NULL;
	{
		int32_t L_0 = ___0_value;
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)15), ((int32_t)21), NULL);
	}

IL_0012:
	{
		int32_t L_2 = ___0_value;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((((int32_t)L_2) == ((int32_t)L_4)))
		{
			goto IL_0058;
		}
	}
	{
		int32_t L_5 = ___0_value;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_004d;
		}
	}
	{
		int32_t L_6 = ___0_value;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_7 = (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)(SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_6);
		V_0 = L_7;
		int32_t L_8 = __this->____size;
		if ((((int32_t)L_8) <= ((int32_t)0)))
		{
			goto IL_0045;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_9 = __this->____items;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_10 = V_0;
		int32_t L_11 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_9, 0, (RuntimeArray*)L_10, 0, L_11, NULL);
	}

IL_0045:
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_12 = V_0;
		__this->____items = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_12);
		return;
	}

IL_004d:
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_13 = ((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		__this->____items = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____items), (void*)L_13);
	}

IL_0058:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC List_1_get_Item_mAAE7FBDBD94CC48BA01C01ACFC3C66EE219110D0 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_5 = (L_2)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m58893707EC3B663186D1550A23DE96C818416CBD (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_2 = __this->____items;
		int32_t L_3 = ___0_index;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_4 = ___1_value;
		(L_2)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_4);
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_IsCompatibleObject_mC9CB5EB21839923C050E6922FE7050867F374865 (RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		RuntimeObject* L_0 = ___0_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6))))
		{
			goto IL_001f;
		}
	}
	{
		RuntimeObject* L_1 = ___0_value;
		if (L_1)
		{
			goto IL_001d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_0), sizeof(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC));
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_2 = V_0;
		return false;
	}

IL_001d:
	{
		return (bool)0;
	}

IL_001f:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IList_get_Item_m328466F241E01D12C4560BF873B0DCB364184FAC (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_1;
		L_1 = List_1_get_Item_mAAE7FBDBD94CC48BA01C01ACFC3C66EE219110D0(__this, L_0, NULL);
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_2 = L_1;
		RuntimeObject* L_3 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6), &L_2);
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_set_Item_mC8AC62D168434E9AB15DF194B4259FE7913CD978 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_value;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m85CB6FEF509A4859399929F09F545FA1133C3051(L_0, ((int32_t)15), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		List_1_set_Item_m58893707EC3B663186D1550A23DE96C818416CBD(__this, L_1, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), NULL);
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_value;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Add_m624C469B79ADC28E429B7A3CA96DA72345621643 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) 
{
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_7 = V_0;
		int32_t L_8 = V_1;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_9);
		return;
	}

IL_0034:
	{
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_10 = ___0_item;
		List_1_AddWithResize_m594A4155F206677F45ECD9AAE7E9EFD0AE6137ED(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m594A4155F206677F45ECD9AAE7E9EFD0AE6137ED (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____size;
		V_0 = L_0;
		int32_t L_1 = V_0;
		List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_2 = V_0;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_2, 1));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_3 = __this->____items;
		int32_t L_4 = V_0;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_5 = ___0_item;
		(L_3)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_5);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_Add_mA3942A650A2BBD4285AB8BCB8F6E3C9AC3C4C6C4 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___0_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m85CB6FEF509A4859399929F09F545FA1133C3051(L_0, ((int32_t)20), NULL);
	}
	try
	{
		RuntimeObject* L_1 = ___0_item;
		List_1_Add_m624C469B79ADC28E429B7A3CA96DA72345621643_inline(__this, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_1, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13));
		goto IL_0029;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0016;
		}
		throw e;
	}

CATCH_0016:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_2 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_3 = ___0_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_4 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_5;
		L_5 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_4, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_3, L_5, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0029;
	}

IL_0029:
	{
		int32_t L_6;
		L_6 = List_1_get_Count_mF3540C84790DAB9D381F00753BA20A85694C3446_inline(__this, NULL);
		return ((int32_t)il2cpp_codegen_subtract(L_6, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddRange_m6C9383E6FC71D115A5C539DD079A91E2472A7DB0 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		RuntimeObject* L_1 = ___0_collection;
		List_1_InsertRange_m8C743BAB2CDB84037FE830DF12A8B561EFEEEA60(__this, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* List_1_AsReadOnly_m95A11E2B168BD4F033EE85776867849761D059CA (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	{
		ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF* L_0 = (ReadOnlyCollection_1_tB4D9A0CDCFB95FF39CF5E7E6C0BA76B3178ECBDF*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 16));
		ReadOnlyCollection_1__ctor_m236FFEDF5196507C82BBA262351A75F0337621F3(L_0, __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Clear_m21752AD1C5AFF444A40956A05C1AC41FB9F88DCB (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		goto IL_0035;
	}

IL_0035:
	{
		__this->____size = 0;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Contains_mA5832B215E464CAC8345E7ECC45562E884AE146D (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_1 = ___0_item;
		int32_t L_2;
		L_2 = List_1_IndexOf_mF5A7DA78EA07100BDE8044CA37C505F36AD7ACB1(__this, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (bool)((((int32_t)((((int32_t)L_2) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}

IL_0016:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_System_Collections_IList_Contains_mED517429468C156C8F8C5608555F8420C755EEF1 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mC9CB5EB21839923C050E6922FE7050867F374865(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Contains_mA5832B215E464CAC8345E7ECC45562E884AE146D(__this, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 21));
		return L_3;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_CopyTo_m3BE7B292C99B3D90B11E5E2B982FC38BEDB111F1 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* ___0_array, const RuntimeMethod* method) 
{
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_0 = ___0_array;
		List_1_CopyTo_m15B9FC56E0418F730FC3A37C8E482F7108D73B62(__this, L_0, 0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_min, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B4_0 = 0;
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_0 = __this->____items;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		int32_t L_2 = ___0_min;
		if ((((int32_t)L_1) >= ((int32_t)L_2)))
		{
			goto IL_003d;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_3 = __this->____items;
		if (!(((RuntimeArray*)L_3)->max_length))
		{
			goto IL_0020;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_4 = __this->____items;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		G_B4_0 = ((int32_t)il2cpp_codegen_multiply(L_5, 2));
		goto IL_0021;
	}

IL_0020:
	{
		G_B4_0 = 4;
	}

IL_0021:
	{
		V_0 = G_B4_0;
		int32_t L_6 = V_0;
		if ((!(((uint32_t)L_6) > ((uint32_t)((int32_t)2146435071)))))
		{
			goto IL_0030;
		}
	}
	{
		V_0 = ((int32_t)2146435071);
	}

IL_0030:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___0_min;
		if ((((int32_t)L_7) >= ((int32_t)L_8)))
		{
			goto IL_0036;
		}
	}
	{
		int32_t L_9 = ___0_min;
		V_0 = L_9;
	}

IL_0036:
	{
		int32_t L_10 = V_0;
		List_1_set_Capacity_m40FE27C2AB4F6F5F863957210FA90C1BF581D293(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 23));
	}

IL_003d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mF2AFA5B913B4B2AA7DD0D1016973A79A93BBFD38 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* ___0_match, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* L_1 = ___0_match;
		int32_t L_2;
		L_2 = List_1_FindIndex_mA8A19319FB31E9FB37C309AB8938A9FE57AA5C9F(__this, 0, L_0, L_1, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_FindIndex_mA8A19319FB31E9FB37C309AB8938A9FE57AA5C9F (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_startIndex, int32_t ___1_count, Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* ___2_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		int32_t L_0 = ___0_startIndex;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowStartIndexArgumentOutOfRange_ArgumentOutOfRange_Index_m94BADCC6D7EBBD12BE8323775FFB43AF01499B0F(NULL);
	}

IL_000e:
	{
		int32_t L_2 = ___1_count;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_001d;
		}
	}
	{
		int32_t L_3 = ___0_startIndex;
		int32_t L_4 = __this->____size;
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_3) <= ((int32_t)((int32_t)il2cpp_codegen_subtract(L_4, L_5)))))
		{
			goto IL_0022;
		}
	}

IL_001d:
	{
		ThrowHelper_ThrowCountArgumentOutOfRange_ArgumentOutOfRange_Count_m6C4A7F645BDD8EB62B50CB76E84416D94620DCC7(NULL);
	}

IL_0022:
	{
		Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* L_6 = ___2_match;
		if (L_6)
		{
			goto IL_002b;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_002b:
	{
		int32_t L_7 = ___0_startIndex;
		int32_t L_8 = ___1_count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		int32_t L_9 = ___0_startIndex;
		V_1 = L_9;
		goto IL_004d;
	}

IL_0033:
	{
		Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* L_10 = ___2_match;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_11 = __this->____items;
		int32_t L_12 = V_1;
		int32_t L_13 = L_12;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_14 = (L_11)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_13));
		bool L_15;
		L_15 = Predicate_1_Invoke_mADD6CFDE192E3E822D5296926054ED8A41DB09C4_inline(L_10, L_14, NULL);
		if (!L_15)
		{
			goto IL_0049;
		}
	}
	{
		int32_t L_16 = V_1;
		return L_16;
	}

IL_0049:
	{
		int32_t L_17 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_004d:
	{
		int32_t L_18 = V_1;
		int32_t L_19 = V_0;
		if ((((int32_t)L_18) < ((int32_t)L_19)))
		{
			goto IL_0033;
		}
	}
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 List_1_GetEnumerator_mAAAF1FE8DEBF77859AC0663A4C794BB8570C9930 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m159144864209387AA18DEABE7B7985388F8F3452((&L_0), __this, NULL);
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_Generic_IEnumerableU3CTU3E_GetEnumerator_mBCEC03D60D1DB36D692026A18BEB259489900E5C (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m159144864209387AA18DEABE7B7985388F8F3452((&L_0), __this, NULL);
		Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_System_Collections_IEnumerable_GetEnumerator_m2720314B086456588769D3DE8AFB012759038C96 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	{
		Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 L_0;
		memset((&L_0), 0, sizeof(L_0));
		Enumerator__ctor_m159144864209387AA18DEABE7B7985388F8F3452((&L_0), __this, NULL);
		Enumerator_t59E02176F2EE4E264A4750514AA127E2E21FF5D9 L_1 = L_0;
		RuntimeObject* L_2 = Box(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 26), &L_1);
		return (RuntimeObject*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_IndexOf_mF5A7DA78EA07100BDE8044CA37C505F36AD7ACB1 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) 
{
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_0 = __this->____items;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_1 = ___0_item;
		int32_t L_2 = __this->____size;
		int32_t L_3;
		L_3 = Array_IndexOf_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m5A2EB67A073F2BFF5B3DCDDBD15D75BC3CFB909C(L_0, L_1, 0, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 28));
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_System_Collections_IList_IndexOf_mB8E1E8E1A197395AD882409A03CD6F2D4B9BE328 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mC9CB5EB21839923C050E6922FE7050867F374865(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		int32_t L_3;
		L_3 = List_1_IndexOf_mF5A7DA78EA07100BDE8044CA37C505F36AD7ACB1(__this, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return L_3;
	}

IL_0015:
	{
		return (-1);
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Insert_mC8E7189F3D9D95975CFE821AC3B560B2EA7AB7A8 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___1_item, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) > ((uint32_t)L_1))))
		{
			goto IL_0012;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)13), ((int32_t)27), NULL);
	}

IL_0012:
	{
		int32_t L_2 = __this->____size;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_3 = __this->____items;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		if ((!(((uint32_t)L_2) == ((uint32_t)L_4))))
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = __this->____size;
		List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058(__this, ((int32_t)il2cpp_codegen_add(L_5, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
	}

IL_0030:
	{
		int32_t L_6 = ___0_index;
		int32_t L_7 = __this->____size;
		if ((((int32_t)L_6) >= ((int32_t)L_7)))
		{
			goto IL_0056;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_8 = __this->____items;
		int32_t L_9 = ___0_index;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_10 = __this->____items;
		int32_t L_11 = ___0_index;
		int32_t L_12 = __this->____size;
		int32_t L_13 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_8, L_9, (RuntimeArray*)L_10, ((int32_t)il2cpp_codegen_add(L_11, 1)), ((int32_t)il2cpp_codegen_subtract(L_12, L_13)), NULL);
	}

IL_0056:
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_16 = ___1_item;
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_16);
		int32_t L_17 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_17, 1));
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Insert_mBD8DBA214029319A0AED43030E4EDE7B27E12C6A (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, RuntimeObject* ___1_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(Type_t_StaticInit);
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		RuntimeObject* L_0 = ___1_item;
		ThrowHelper_IfNullAndNullsAreIllegalThenThrow_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_m85CB6FEF509A4859399929F09F545FA1133C3051(L_0, ((int32_t)20), NULL);
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_item;
		List_1_Insert_mC8E7189F3D9D95975CFE821AC3B560B2EA7AB7A8(__this, L_1, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
		goto IL_002a;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0017;
		}
		throw e;
	}

CATCH_0017:
	{
		InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E* L_3 = ((InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*)IL2CPP_GET_ACTIVE_EXCEPTION(InvalidCastException_t47FC62F21A3937E814D20381DDACEF240E95AC2E*));;
		RuntimeObject* L_4 = ___1_item;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 10)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		ThrowHelper_ThrowWrongValueTypeArgumentException_mC1A6BBE43C360583C1E2C463D5B0AADF1E3E1910(L_4, L_6, NULL);
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_002a;
	}

IL_002a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_InsertRange_m8C743BAB2CDB84037FE830DF12A8B561EFEEEA60 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, RuntimeObject* ___1_collection, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	RuntimeObject* V_2 = NULL;
	{
		RuntimeObject* L_0 = ___1_collection;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(6, NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___0_index;
		int32_t L_2 = __this->____size;
		if ((!(((uint32_t)L_1) > ((uint32_t)L_2))))
		{
			goto IL_0017;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_0017:
	{
		RuntimeObject* L_3 = ___1_collection;
		V_0 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 2)));
		RuntimeObject* L_4 = V_0;
		if (!L_4)
		{
			goto IL_00bc;
		}
	}
	{
		RuntimeObject* L_5 = V_0;
		int32_t L_6;
		L_6 = InterfaceFuncInvoker0< int32_t >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_5);
		V_1 = L_6;
		int32_t L_7 = V_1;
		if ((((int32_t)L_7) <= ((int32_t)0)))
		{
			goto IL_00fb;
		}
	}
	{
		int32_t L_8 = __this->____size;
		int32_t L_9 = V_1;
		List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058(__this, ((int32_t)il2cpp_codegen_add(L_8, L_9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_10 = ___0_index;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_12 = __this->____items;
		int32_t L_13 = ___0_index;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = V_1;
		int32_t L_17 = __this->____size;
		int32_t L_18 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_12, L_13, (RuntimeArray*)L_14, ((int32_t)il2cpp_codegen_add(L_15, L_16)), ((int32_t)il2cpp_codegen_subtract(L_17, L_18)), NULL);
	}

IL_0066:
	{
		RuntimeObject* L_19 = V_0;
		if ((!(((RuntimeObject*)(List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF*)__this) == ((RuntimeObject*)(RuntimeObject*)L_19))))
		{
			goto IL_009f;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_20 = __this->____items;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_21 = __this->____items;
		int32_t L_22 = ___0_index;
		int32_t L_23 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_20, 0, (RuntimeArray*)L_21, L_22, L_23, NULL);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_24 = __this->____items;
		int32_t L_25 = ___0_index;
		int32_t L_26 = V_1;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_27 = __this->____items;
		int32_t L_28 = ___0_index;
		int32_t L_29 = __this->____size;
		int32_t L_30 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_24, ((int32_t)il2cpp_codegen_add(L_25, L_26)), (RuntimeArray*)L_27, ((int32_t)il2cpp_codegen_multiply(L_28, 2)), ((int32_t)il2cpp_codegen_subtract(L_29, L_30)), NULL);
		goto IL_00ac;
	}

IL_009f:
	{
		RuntimeObject* L_31 = V_0;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_32 = __this->____items;
		int32_t L_33 = ___0_index;
		InterfaceActionInvoker2< SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*, int32_t >::Invoke(5, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 2), L_31, L_32, L_33);
	}

IL_00ac:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_34, L_35));
		goto IL_00fb;
	}

IL_00bc:
	{
		int32_t L_36 = ___0_index;
		int32_t L_37 = __this->____size;
		if ((((int32_t)L_36) >= ((int32_t)L_37)))
		{
			goto IL_00f4;
		}
	}
	{
		RuntimeObject* L_38 = ___1_collection;
		RuntimeObject* L_39;
		L_39 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_38);
		V_2 = L_39;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ea:
			{
				{
					RuntimeObject* L_40 = V_2;
					if (!L_40)
					{
						goto IL_00f3;
					}
				}
				{
					RuntimeObject* L_41 = V_2;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_41);
				}

IL_00f3:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_00e0_1;
			}

IL_00ce_1:
			{
				int32_t L_42 = ___0_index;
				int32_t L_43 = L_42;
				___0_index = ((int32_t)il2cpp_codegen_add(L_43, 1));
				RuntimeObject* L_44 = V_2;
				SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_45;
				L_45 = InterfaceFuncInvoker0< SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_44);
				List_1_Insert_mC8E7189F3D9D95975CFE821AC3B560B2EA7AB7A8(__this, L_43, L_45, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 29));
			}

IL_00e0_1:
			{
				RuntimeObject* L_46 = V_2;
				bool L_47;
				L_47 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_46);
				if (L_47)
				{
					goto IL_00ce_1;
				}
			}
			{
				goto IL_00fb;
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

IL_00f4:
	{
		RuntimeObject* L_48 = ___1_collection;
		List_1_AddEnumerable_mDF2147E522AD80A7B6A79CF8E7F00EC7DBF8A032(__this, L_48, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
	}

IL_00fb:
	{
		int32_t L_49 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_49, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool List_1_Remove_mA8E72E7CFB72101AA88E01A84F746ECBD8E91B3F (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_0 = ___0_item;
		int32_t L_1;
		L_1 = List_1_IndexOf_mF5A7DA78EA07100BDE8044CA37C505F36AD7ACB1(__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		V_0 = L_1;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) < ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		int32_t L_3 = V_0;
		List_1_RemoveAt_m911F1AFFA59FD181BA9363E0B6C8B5B95067EC3B(__this, L_3, NULL);
		return (bool)1;
	}

IL_0015:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_System_Collections_IList_Remove_mF11CDACF173F28EBB282A0E10465306215533D69 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	{
		RuntimeObject* L_0 = ___0_item;
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = List_1_IsCompatibleObject_mC9CB5EB21839923C050E6922FE7050867F374865(L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		RuntimeObject* L_2 = ___0_item;
		bool L_3;
		L_3 = List_1_Remove_mA8E72E7CFB72101AA88E01A84F746ECBD8E91B3F(__this, ((*(SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC*)UnBox(L_2, il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 35));
	}

IL_0015:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t List_1_RemoveAll_m942EE1B1849CFF13050D5AC9C5543626606E41FD (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* ___0_match, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* L_0 = ___0_match;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(8, NULL);
	}

IL_0009:
	{
		V_0 = 0;
		goto IL_0011;
	}

IL_000d:
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_0011:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = __this->____size;
		if ((((int32_t)L_2) >= ((int32_t)L_3)))
		{
			goto IL_002e;
		}
	}
	{
		Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* L_4 = ___0_match;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_5 = __this->____items;
		int32_t L_6 = V_0;
		int32_t L_7 = L_6;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		bool L_9;
		L_9 = Predicate_1_Invoke_mADD6CFDE192E3E822D5296926054ED8A41DB09C4_inline(L_4, L_8, NULL);
		if (!L_9)
		{
			goto IL_000d;
		}
	}

IL_002e:
	{
		int32_t L_10 = V_0;
		int32_t L_11 = __this->____size;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_0039;
		}
	}
	{
		return 0;
	}

IL_0039:
	{
		int32_t L_12 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(L_12, 1));
		goto IL_0089;
	}

IL_003f:
	{
		int32_t L_13 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0043:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = __this->____size;
		if ((((int32_t)L_14) >= ((int32_t)L_15)))
		{
			goto IL_0060;
		}
	}
	{
		Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* L_16 = ___0_match;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_17 = __this->____items;
		int32_t L_18 = V_1;
		int32_t L_19 = L_18;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_20 = (L_17)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_19));
		bool L_21;
		L_21 = Predicate_1_Invoke_mADD6CFDE192E3E822D5296926054ED8A41DB09C4_inline(L_16, L_20, NULL);
		if (L_21)
		{
			goto IL_003f;
		}
	}

IL_0060:
	{
		int32_t L_22 = V_1;
		int32_t L_23 = __this->____size;
		if ((((int32_t)L_22) >= ((int32_t)L_23)))
		{
			goto IL_0089;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_24 = __this->____items;
		int32_t L_25 = V_0;
		int32_t L_26 = L_25;
		V_0 = ((int32_t)il2cpp_codegen_add(L_26, 1));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_27 = __this->____items;
		int32_t L_28 = V_1;
		int32_t L_29 = L_28;
		V_1 = ((int32_t)il2cpp_codegen_add(L_29, 1));
		int32_t L_30 = L_29;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_31 = (L_27)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30));
		(L_24)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_26), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_31);
	}

IL_0089:
	{
		int32_t L_32 = V_1;
		int32_t L_33 = __this->____size;
		if ((((int32_t)L_32) < ((int32_t)L_33)))
		{
			goto IL_0043;
		}
	}
	{
		goto IL_00ad;
	}

IL_00ad:
	{
		int32_t L_34 = __this->____size;
		int32_t L_35 = V_0;
		int32_t L_36 = V_0;
		__this->____size = L_36;
		int32_t L_37 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_37, 1));
		return ((int32_t)il2cpp_codegen_subtract(L_34, L_35));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveAt_m911F1AFFA59FD181BA9363E0B6C8B5B95067EC3B (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		int32_t L_0 = ___0_index;
		int32_t L_1 = __this->____size;
		if ((!(((uint32_t)L_0) >= ((uint32_t)L_1))))
		{
			goto IL_000e;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRange_IndexException_mC7661B8C6DD827679C95FC6B6C08F8724174936D(NULL);
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_2, 1));
		int32_t L_3 = ___0_index;
		int32_t L_4 = __this->____size;
		if ((((int32_t)L_3) >= ((int32_t)L_4)))
		{
			goto IL_0042;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_5 = __this->____items;
		int32_t L_6 = ___0_index;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_7 = __this->____items;
		int32_t L_8 = ___0_index;
		int32_t L_9 = __this->____size;
		int32_t L_10 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_5, ((int32_t)il2cpp_codegen_add(L_6, 1)), (RuntimeArray*)L_7, L_8, ((int32_t)il2cpp_codegen_subtract(L_9, L_10)), NULL);
	}

IL_0042:
	{
		goto IL_0063;
	}

IL_0063:
	{
		int32_t L_11 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_11, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_RemoveRange_m5B47428142038A77A46C58F4673D5B84A07CEA92 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_008d;
		}
	}
	{
		int32_t L_6 = __this->____size;
		int32_t L_7 = __this->____size;
		int32_t L_8 = ___1_count;
		__this->____size = ((int32_t)il2cpp_codegen_subtract(L_7, L_8));
		int32_t L_9 = ___0_index;
		int32_t L_10 = __this->____size;
		if ((((int32_t)L_9) >= ((int32_t)L_10)))
		{
			goto IL_0066;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_11 = __this->____items;
		int32_t L_12 = ___0_index;
		int32_t L_13 = ___1_count;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_14 = __this->____items;
		int32_t L_15 = ___0_index;
		int32_t L_16 = __this->____size;
		int32_t L_17 = ___0_index;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_11, ((int32_t)il2cpp_codegen_add(L_12, L_13)), (RuntimeArray*)L_14, L_15, ((int32_t)il2cpp_codegen_subtract(L_16, L_17)), NULL);
	}

IL_0066:
	{
		int32_t L_18 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_18, 1));
		goto IL_008d;
	}

IL_008d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m615589F6FA55D03C1E49CD0793C4579B1EA8ACB9 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mF3540C84790DAB9D381F00753BA20A85694C3446_inline(__this, NULL);
		List_1_Reverse_m6558ECB96638BF339DAB6BDB70413BA7570A84F9(__this, 0, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 36));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Reverse_m6558ECB96638BF339DAB6BDB70413BA7570A84F9 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0038;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		Array_Reverse_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_mD8F006C0A007C05BB69E417FA65A5A66965F997C(L_6, L_7, L_8, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 37));
	}

IL_0038:
	{
		int32_t L_9 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_9, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m73682F7A633F3DDE4C73BA091D7DF9A6B37C9EDF (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0;
		L_0 = List_1_get_Count_mF3540C84790DAB9D381F00753BA20A85694C3446_inline(__this, NULL);
		RuntimeObject* L_1 = ___0_comparer;
		List_1_Sort_m4F48B52D720DB8E76904DB4647F7BDA63FDEC552(__this, 0, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 38));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_m4F48B52D720DB8E76904DB4647F7BDA63FDEC552 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, int32_t ___0_index, int32_t ___1_count, RuntimeObject* ___2_comparer, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) >= ((int32_t)0)))
		{
			goto IL_0009;
		}
	}
	{
		ThrowHelper_ThrowIndexArgumentOutOfRange_NeedNonNegNumException_m57AAB1E093F20BFC64BDDBD90FB5B592F582B82F(NULL);
	}

IL_0009:
	{
		int32_t L_1 = ___1_count;
		if ((((int32_t)L_1) >= ((int32_t)0)))
		{
			goto IL_0015;
		}
	}
	{
		ThrowHelper_ThrowArgumentOutOfRangeException_m5430BC879B9D99E39DED788BB9451B8EF029756F(((int32_t)16), 4, NULL);
	}

IL_0015:
	{
		int32_t L_2 = __this->____size;
		int32_t L_3 = ___0_index;
		int32_t L_4 = ___1_count;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract(L_2, L_3))) >= ((int32_t)L_4)))
		{
			goto IL_0027;
		}
	}
	{
		ThrowHelper_ThrowArgumentException_m698044D4F664D7D0DDB88124EEEE2D052AF628BA(((int32_t)23), NULL);
	}

IL_0027:
	{
		int32_t L_5 = ___1_count;
		if ((((int32_t)L_5) <= ((int32_t)1)))
		{
			goto IL_0039;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_6 = __this->____items;
		int32_t L_7 = ___0_index;
		int32_t L_8 = ___1_count;
		RuntimeObject* L_9 = ___2_comparer;
		Array_Sort_TisSingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC_mE6A4B57DE0CB3DEC8371BDC3DAAAD29D6C9E3B2B(L_6, L_7, L_8, L_9, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 39));
	}

IL_0039:
	{
		int32_t L_10 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_10, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_Sort_mA14F47787ACFCA9DBDE6F5227BC1070CC0AC6E24 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149* ___0_comparison, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit);
	{
		Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149* L_0 = ___0_comparison;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		ThrowHelper_ThrowArgumentNullException_m05B7DB75576C421D7CA84FA73F84D7E114974CEC(((int32_t)34), NULL);
	}

IL_000a:
	{
		int32_t L_1 = __this->____size;
		if ((((int32_t)L_1) <= ((int32_t)1)))
		{
			goto IL_0026;
		}
	}
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_2 = __this->____items;
		int32_t L_3 = __this->____size;
		Comparison_1_tA6E38F9B8A5E125EC6515F9679C2079C747A0149* L_4 = ___0_comparison;
		CHECKED_LOCAL_INIT(ArraySortHelper_1_t0B69B36E8E1F97490E6BE32C23AE1784AB1ADA3A_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 41)),il2cpp_codegen_runtime_class_init_inline);
		ArraySortHelper_1_Sort_m3182DABDA1EFACFF8268887837CA976A3577C3E6(L_2, 0, L_3, L_4, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 40));
	}

IL_0026:
	{
		int32_t L_5 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* List_1_ToArray_m60A0D5DD91FC53DD96E7949CE29E6FA9724180F2 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit);
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* V_0 = NULL;
	{
		int32_t L_0 = __this->____size;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		CHECKED_LOCAL_INIT(List_1_tA054E80C004998BFCB1ED5377160B32E4A19B78C_StaticInit,(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)),il2cpp_codegen_runtime_class_init_inline);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_1 = ((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 0)))->___s_emptyArray;
		return L_1;
	}

IL_000e:
	{
		int32_t L_2 = __this->____size;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_3 = (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)(SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)SZArrayNew(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1), (uint32_t)L_2);
		V_0 = L_3;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_4 = __this->____items;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_5 = V_0;
		int32_t L_6 = __this->____size;
		Array_Copy_mB4904E17BD92E320613A3251C0205E0786B3BF41((RuntimeArray*)L_4, 0, (RuntimeArray*)L_5, 0, L_6, NULL);
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_7 = V_0;
		return L_7;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_AddEnumerable_mDF2147E522AD80A7B6A79CF8E7F00EC7DBF8A032 (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, RuntimeObject* ___0_enumerable, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		RuntimeObject* L_1 = ___0_enumerable;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 30), L_1);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					RuntimeObject* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					RuntimeObject* L_4 = V_0;
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0059_1;
			}

IL_0017_1:
			{
				RuntimeObject* L_5 = V_0;
				SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_6;
				L_6 = InterfaceFuncInvoker0< SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 32), L_5);
				V_1 = L_6;
				int32_t L_7 = __this->____size;
				SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_8 = __this->____items;
				int32_t L_9 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_8)->max_length),NULL));
				if ((!(((uint32_t)L_7) == ((uint32_t)L_9))))
				{
					goto IL_003c_1;
				}
			}
			{
				int32_t L_10 = __this->____size;
				List_1_EnsureCapacity_m1A140613D2D236E9CF413F81D549E39415DF0058(__this, ((int32_t)il2cpp_codegen_add(L_10, 1)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
			}

IL_003c_1:
			{
				SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_11 = __this->____items;
				int32_t L_12 = __this->____size;
				V_2 = L_12;
				int32_t L_13 = V_2;
				__this->____size = ((int32_t)il2cpp_codegen_add(L_13, 1));
				int32_t L_14 = V_2;
				SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_15 = V_1;
				(L_11)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_15);
			}

IL_0059_1:
			{
				RuntimeObject* L_16 = V_0;
				bool L_17;
				L_17 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_16);
				if (L_17)
				{
					goto IL_0017_1;
				}
			}
			{
				goto IL_006d;
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

IL_006d:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__cctor_mC80073FB316593C1A68C371348A1661067257614 (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	{
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_0 = (SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)(SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6*)SZArrayNew(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 1), (uint32_t)0);
		((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_emptyArray), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB2D00B8E4BC3D697FA727086AACBC28AAA1606F2_inline (List_1_t4A3FBCBC51814DA87A56C303277E401A0E9A8366* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_item, const RuntimeMethod* method) 
{
	JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		JobHandleU5BU5D_tE3F0B60D91B15CD5B332314268E9315F48F79CEC* L_7 = V_0;
		int32_t L_8 = V_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08)L_9);
		return;
	}

IL_0034:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = ___0_item;
		List_1_AddWithResize_m1AB47453401D23D3A09953C553FCC6114A68E6AC(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_mD2ED26ACAF3BAF386FFEA83893BA51DB9FD8BA30_fshared_inline (List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m798E5A0C143433BFCAF602F2FFEC4B7DA1932BB5_inline (Predicate_1_t96B0E83ED07DCCD20CB37957C682248FA4DA9ED1* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mAA147597B0A6147B89C99C55D9DFA93A8AE79D26_inline (List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_item, const RuntimeMethod* method) 
{
	MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		MeshOrderU5BU5D_t030EA9445D04DA28598850329E580A6C4B41B885* L_7 = V_0;
		int32_t L_8 = V_1;
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61)L_9);
		return;
	}

IL_0034:
	{
		MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 L_10 = ___0_item;
		List_1_AddWithResize_m558B41D2F2078B4DA929652106E89D5677D85DCD(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m757CF429A07F24116D98E8A834EE7D2EB3D3315E_inline (Predicate_1_tA6F798EA95C7EAF47073184B77FBF0F14509855E* __this, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61 ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, MeshOrder_tB779C84E6BFA22CA15B56BEFBC9660B156004C61, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m85AF4AC8BAFE2D698178F1CC64EBF5587C8C501B_inline (List_1_t26A5CDC6FF907547B9813C82B6749D89C7E3EE7D* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_item, const RuntimeMethod* method) 
{
	MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		MeshSubsetU5BU5D_t7B87100ECF6A895FB669F91417D60B6BDD14E665* L_7 = V_0;
		int32_t L_8 = V_1;
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4)L_9);
		return;
	}

IL_0034:
	{
		MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 L_10 = ___0_item;
		List_1_AddWithResize_mE5072267E528FE731CDE3FF1E7FDA08392A07B86(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mB1CA85C8D3E3D6E0E2236B0CEE4C32387ACF690B_inline (Predicate_1_t2307630B91460F961E7ADC5865FEA090243D0844* __this, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4 ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, MeshSubset_tD2542C6FEC8BC7D7FFE0A5803856CB5BCE5CB9A4, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mF04CCC12DEF9C866AC5DC5330FDC48AB65CCA024_inline (List_1_t480A595B8D45A9019FF0E9A33AD53D81F7355674* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_item, const RuntimeMethod* method) 
{
	ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		ResourceHandleU5BU5D_tD8EAD492F528F246F46563C67691360F9F2B0918* L_7 = V_0;
		int32_t L_8 = V_1;
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8)L_9);
		return;
	}

IL_0034:
	{
		ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 L_10 = ___0_item;
		List_1_AddWithResize_m28AFC3F6D5F6FE74B5CC7A3E42AC5CC6FFE0F2B8(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m34AFEF07BE56D23BA7F5BA2338AC3C3F1ED777CF_inline (Predicate_1_tD559AF1002ABFFC541AF884654337A564D28B733* __this, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8 ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, ResourceHandle_tAB7888F3AB5071C94127D0D46AAB3D702BC4B9F8, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mF7AE8B1682DB8CD2AC096A7E9C663F5B3BE8C1DD_inline (List_1_t82213084D105CDEFA880C12D631CDAF1D6EA0696* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_item, const RuntimeMethod* method) 
{
	SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		SubMeshAssignmentU5BU5D_t003704746B1FF1DA9D52D28FB39D1B5B455E3AEE* L_7 = V_0;
		int32_t L_8 = V_1;
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A)L_9);
		return;
	}

IL_0034:
	{
		SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A L_10 = ___0_item;
		List_1_AddWithResize_mA45CBC1217C83D9A3C45A71418C0C0A0CAB84CB2(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m3F752265B16661803674C43E5FDFFD81C013F9A4_inline (Predicate_1_t176BCBC79372D2CD30C107702A66A3CA90D946D0* __this, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, SubMeshAssignment_t4556AD967B147BFE093B621DB26E48C18BF4809A, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m0CE6E39234ED33F5195AABC8029D06D4756C75C1_gshared_inline (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, Il2CppSharedGenericObject* ___0_item, const RuntimeMethod* method) 
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_7 = V_0;
		int32_t L_8 = V_1;
		Il2CppSharedGenericObject* L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (Il2CppSharedGenericObject*)L_9);
		return;
	}

IL_0034:
	{
		Il2CppSharedGenericObject* L_10 = ___0_item;
		List_1_AddWithResize_mCC24A812DFC30C3DE2230E3C8EE705871C1DFF81(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mDF332C0CEB003C0D86A1E3A194ECFA96D424E34C_gshared_inline (Predicate_1_t586817D6627D147076FFDCC73DA7BEC23132FA88* __this, Il2CppSharedGenericObject* ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m24BA4DEDED426A5B0C6A4AB3E523C876B0B918A6_gshared_inline (List_1_t4225839FAF98FA4E886FF2A1469F9292D739E255* __this, int32_t ___0_item, const RuntimeMethod* method) 
{
	__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		__Il2CppInt32EnumU5BU5D_t8FBDB13799B3615AA893F06F601FF09189B04297* L_7 = V_0;
		int32_t L_8 = V_1;
		int32_t L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (int32_t)L_9);
		return;
	}

IL_0034:
	{
		int32_t L_10 = ___0_item;
		List_1_AddWithResize_m3B53F17525936469654379AC0F1F0B19EC3DCCE5(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m0D65AFF43065FE03318CBDDB2A1E63B51476FB9A_gshared_inline (Predicate_1_tEFC0F0C58D1FDF98911A6A55B2C9A9F6A4AB3EE2* __this, int32_t ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mC35682C02D89984B864B24B3BB4F92B5C2374273_inline (List_1_t55FBBCA3B61F4092747F5BB1DE63DCF56C27DE50* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_item, const RuntimeMethod* method) 
{
	AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		AwaitableAndFrameIndexU5BU5D_tFE5E09101F753E8B28D639C161FBC4D34F939560* L_7 = V_0;
		int32_t L_8 = V_1;
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161)L_9);
		return;
	}

IL_0034:
	{
		AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 L_10 = ___0_item;
		List_1_AddWithResize_mCA55981D47453F8483BD503CA53B0DABBDB8844D(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m8D40905BAEF5849C9DF55268BB4FD2C8CB0A1A79_inline (Predicate_1_t3F38457B9EC912152CADD8A303B97559060B734C* __this, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161 ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, AwaitableAndFrameIndex_t5B42EA520B0415D199F9487706ABCD53407C0161, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mB308EE5BFFD89A7B8C251644D76CA547456F3012_inline (List_1_tB663AF9B0DBD0D685E595C4B50CF1535137C768A* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_item, const RuntimeMethod* method) 
{
	OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		OrderBlockU5BU5D_tD67C39FB212889AFAAB991BE1AE144ED8D35EE88* L_7 = V_0;
		int32_t L_8 = V_1;
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837)L_9);
		return;
	}

IL_0034:
	{
		OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 L_10 = ___0_item;
		List_1_AddWithResize_m8B3D79788ADC2B54C9B12CC9EC1158E6A04CDEBC(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_m182E0ACAA85455151F5750CE87F942DA6E3DD3D6_inline (Predicate_1_t8194F57B81937B278B5EFEF0F5B667BBB054B0D0* __this, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837 ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, OrderBlock_t62FD6F6544F34B5298DEF2F77AAE446F269B7837, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_m624C469B79ADC28E429B7A3CA96DA72345621643_inline (List_1_tDB6FA8EDA7A26227B5CA100203EF7BAFA0FDBDDF* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_item, const RuntimeMethod* method) 
{
	SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_4 = V_0;
		int32_t L_5 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_4)->max_length),NULL));
		if ((!(((uint32_t)L_3) < ((uint32_t)L_5))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_6 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_6, 1));
		SingleRangeU5BU5D_t9F938F2249733D85C4F97842A125778D69A843D6* L_7 = V_0;
		int32_t L_8 = V_1;
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_9 = ___0_item;
		(L_7)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8), (SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC)L_9);
		return;
	}

IL_0034:
	{
		SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC L_10 = ___0_item;
		List_1_AddWithResize_m594A4155F206677F45ECD9AAE7E9EFD0AE6137ED(__this, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Predicate_1_Invoke_mADD6CFDE192E3E822D5296926054ED8A41DB09C4_inline (Predicate_1_t107748E0E0D2277266234EAF67AC068394C4351C* __this, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC ___0_obj, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, SingleRange_tB50C1C2B62BDC445BDBA41FD3CDC77A45A211BBC, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
