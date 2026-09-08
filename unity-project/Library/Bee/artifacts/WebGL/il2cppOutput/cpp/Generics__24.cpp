#include "pch-cpp.hpp"





struct VirtualActionInvoker0
{
	typedef void (*Action)(void*,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*,T1,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3
{
	typedef void (*Action)(void*,T1,T2,T3,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,p2,p3,invokeData.method);
	}
};
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
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct VirtualFuncInvoker4
{
	typedef R (*Func)(void*,T1,T2,T3,T4,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,p3,p4,invokeData.method);
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
template <typename T1, typename T2, typename T3>
struct InterfaceActionInvoker3
{
	typedef void (*Action)(void*,T1,T2,T3,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,p2,p3,invokeData.method);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct InterfaceActionInvoker4
{
	typedef void (*Action)(void*,T1,T2,T3,T4,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,p2,p3,p4,invokeData.method);
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
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
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

struct Action_3_t4C244C4561415967803DF55DE7B36C0CB6B0227F;
struct Dictionary_2_t0C9CD67BBA686A3BA7C01F6F8A21054F30DDBCAD;
struct Dictionary_2_t6800D968311CB0CFA6840BC4AA1901B84A16145C;
struct Dictionary_2_t5C8F46F5D57502270DD9E1DA8303B23C7FE85588;
struct Dictionary_2_tB427BE48400204F66ED8A4770F5E1A1F6F2CB941;
struct FlatArray_1_tEE41ABC7EF4BAF3F75854CC89C9DA988778D921A;
struct Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D;
struct Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87;
struct Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B;
struct Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0;
struct HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2;
struct HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178;
struct IEnumerable_1_t6D5FFB1B4A97F30426C5D394135AD0D2FAEAE680;
struct IEnumerable_1_t29E7244AE33B71FA0981E50D5BC73B7938F35C66;
struct IEnumerator_1_tB41B292FAFD525FC5C54D7E469F0BA1A193CA8B1;
struct IEnumerator_1_t75CB2681E18F7F2791528FA2CA60361FDB5DA08D;
struct Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32;
struct Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0;
struct List_1_tDBA15FCFA4AA5EB043D4C75BA42987C7DC2A3B33;
struct List_1_t43FB89B126C93A6B04630BC64C751BBE95AFEAF4;
struct List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A;
struct List_1_t9A2E2984B23260AECDFA90CEB1F2887075FA4DF3;
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E;
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A;
struct VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B;
struct VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA;
struct VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A;
struct VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0;
struct VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482;
struct VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23;
struct VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5;
struct VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5;
struct VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD;
struct VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229;
struct VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399;
struct VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595;
struct VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0;
struct WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180;
struct WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547;
struct WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6;
struct WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2;
struct WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B;
struct WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121;
struct WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0;
struct WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375;
struct WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174;
struct WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C;
struct WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C;
struct WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9;
struct WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336;
struct NativeArray_1U5BU5D_t495E50C84E09FD9543D64DFF017C2FA53D91C475;
struct Nullable_1U5BU5D_t0C7FC263C73AB93B212871051A356A18838DC4B5;
struct ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA;
struct Matrix4x4U5BU5DU5BU5D_t70F44F6ABA3496D9431117EA02FF3B2DD46E50CF;
struct AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A;
struct AccessorUsageU5BU5D_tC30B6A0E57269C0847DD1458DA7022005143A780;
struct AnimationClipU5BU5D_t48CE1A495BA95608745A065C735F2D5BB8DE5A0F;
struct AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322;
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct GlbBinChunkU5BU5D_t1C454B47EF77D552A6045D077D456DC8852BF385;
struct IDisposableU5BU5D_t7D2E88760CCE6C653A28D1DB1108AFA898478DEE;
struct ImageFormatU5BU5D_tEBECAF709563AF35E803D0B23708CB60E67E4367;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct MaterialU5BU5D_t2B1D11C42DB07A4400C0535F92DBB87A2E346D3D;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct Texture2DU5BU5D_t05332F1E3F7D4493E304C702201F9BE4F9236191;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;
struct AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E;
struct AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6;
struct AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071;
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
struct GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F;
struct ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A;
struct IDeferAgent_t8ACCF219690F9F367D792F7D18243B4AF1337F9D;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IDownloadProvider_tABB203130F42A9A4109AED212E3EBFD79C2CBBE5;
struct IFormatterConverter_t726606DAC82C384B08C82471313C340968DDB609;
struct IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47;
struct IMaterialGenerator_t3F9039F5306F2DF2D3D1CFA8CB7D5A6B132E1265;
struct ImportSettings_t92812D83726B63C0D0C65404A95CCA9B121CEFDE;
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
struct MeshComparer_tF00A9ABED9808868FBAF9921B2E3F3D18D82A2DA;
struct MethodInfo_t;
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct String_t;
struct Type_t;
struct VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94;
struct VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA;
struct VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC;
struct VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5;

IL2CPP_EXTERN_C RuntimeClass* AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GltfComponentType_tB7CCE9FF3B728EE7957568DA30CA8DCAC1E5CA34_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral4EBC86E0EACFCA522AEB82874860D0E248D782A5;
IL2CPP_EXTERN_C String_t* _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0;
IL2CPP_EXTERN_C String_t* _stringLiteral695F5F858DF14780BC5525F0AA16CE70EB9C45E8;
IL2CPP_EXTERN_C String_t* _stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7;
IL2CPP_EXTERN_C String_t* _stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085;
IL2CPP_EXTERN_C String_t* _stringLiteralBF92C939C85D8888B68A1C0E975839B22C2F1CA0;
IL2CPP_EXTERN_C String_t* _stringLiteralE099E35199E899B7796FB5803C6465BF879088CC;
IL2CPP_EXTERN_C String_t* _stringLiteralF25A18EECC3B71FE7DC49876B54488AEC789DC3D;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89_mB9039BDE0A62F3298ED76214B72CE46918C8255A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B_mF1D66E1214EC89ABA3AEBF8304CD6A6453ED5049_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB_mE812841C0A243B763E58AADEDE363162B8D50FB7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B_m048136BB9B52441F8CF46CFFC41E6720F229F96F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5_mE7423E2E6337C573F2A7EC531FC975B10BBC1B60_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C_m494DE9D0608D39869661FD2A829DB0D523FE094B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB_m9E18CF080F3709EFBE44FCCAA5F7E87763E609E5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForExtensions_Schedule_TisConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA_m8A8F9336ED94EAB202DA66E950B1CE9D85DAB850_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IJobParallelForExtensions_Schedule_TisConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1_mF44365369C2DA0F87C1A1DD4493B59A812AACC9E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A;
struct AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5  : public RuntimeObject
{
};
struct Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32  : public RuntimeObject
{
	int32_t ___threadId;
	int32_t ___state;
	Il2CppSharedGenericObject* ___current;
};
struct Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0 : public RuntimeObject {};
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
struct AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD  : public RuntimeObject
{
	int32_t ___count;
};
struct AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071  : public RuntimeObject
{
	uint32_t ___bufferView;
	int32_t ___byteOffset;
};
struct Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B  : public RuntimeObject
{
	int32_t ___POSITION;
	int32_t ___NORMAL;
	int32_t ___TANGENT;
	int32_t ___TEXCOORD_0;
	int32_t ___TEXCOORD_1;
	int32_t ___TEXCOORD_2;
	int32_t ___TEXCOORD_3;
	int32_t ___TEXCOORD_4;
	int32_t ___TEXCOORD_5;
	int32_t ___TEXCOORD_6;
	int32_t ___TEXCOORD_7;
	int32_t ___TEXCOORD_8;
	int32_t ___COLOR_0;
	int32_t ___JOINTS_0;
	int32_t ___WEIGHTS_0;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct NamedObject_t907D3C13C4675E1432B946C6306227637A38EA9D  : public RuntimeObject
{
	String_t* ___name;
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
struct VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC  : public RuntimeObject
{
	AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___m_Attributes;
	int32_t ___m_AttributeCount;
	bool ___calculateNormals;
	bool ___calculateTangents;
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___m_Descriptors;
	GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* ___m_GltfImport;
};
struct VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0  : public RuntimeObject
{
	RuntimeObject* ___m_Logger;
	int32_t ___U3CUVSetCountU3Ek__BackingField;
};
struct Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ____list;
	int32_t ____index;
	int32_t ____version;
	Il2CppSharedGenericObject* ____current;
};
typedef Il2CppFullySharedGenericStruct Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF;
struct NativeSlice_1_tCEC4B2B900638EC1820BB61FE436766204DFD8DA 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct NativeSlice_1_tA54E5D259EBCC7CD8512AA352C6F3709EB237B52 
{
	uint8_t* ___m_Buffer;
	int32_t ___m_Stride;
	int32_t ___m_Length;
};
struct WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	int32_t ___index;
};
struct WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6 : public RuntimeObject {};
struct WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	RuntimeObject* ___enumerator;
};
struct WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B : public RuntimeObject {};
struct WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___selector;
	int32_t ___index;
};
struct WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174 : public RuntimeObject {};
struct WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	RuntimeObject* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___selector;
	RuntimeObject* ___enumerator;
};
struct WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C : public RuntimeObject {};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 
{
	int32_t ___inputByteStride;
	uint8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B 
{
	int32_t ___inputByteStride;
	int16_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB 
{
	int32_t ___inputByteStride;
	int16_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B 
{
	int32_t ___inputByteStride;
	int8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 
{
	int32_t ___inputByteStride;
	int8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C 
{
	int32_t ___inputByteStride;
	uint8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA 
{
	int32_t ___inputByteStride;
	uint8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB 
{
	int32_t ___inputByteStride;
	uint8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
};
struct ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 
{
	int32_t ___inputByteStride;
	uint8_t* ___input;
	int32_t ___outputByteStride;
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___result;
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
struct GlbBinChunk_t3AE717BE36473336DC174C4776752F590884B2C8 
{
	int32_t ___U3CStartU3Ek__BackingField;
	uint32_t ___U3CLengthU3Ek__BackingField;
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
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
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
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
struct Nullable_1_tBAE070955BC8FB2D249B4478766DFF3B46F27F61 
{
	bool ___hasValue;
	GlbBinChunk_t3AE717BE36473336DC174C4776752F590884B2C8 ___value;
};
struct Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 
{
	bool ___hasValue;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___value;
};
struct WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 ___enumerator;
};
struct WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0 : public RuntimeObject {};
struct WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9  : public Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32
{
	List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___source;
	Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___predicate;
	Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___selector;
	Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 ___enumerator;
};
struct WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336 : public RuntimeObject {};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Center;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Extents;
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
struct GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC 
{
	intptr_t ___handle;
};
struct GCHandleType_t4CD45A3495E593D093AB0CE36EF9EC1A1572F82A 
{
	int32_t ___value__;
};
struct GltfAccessorAttributeType_t2A3EA7ADAC3332131A4850752A6719FB131FC9F1 
{
	uint8_t ___value__;
};
struct GltfComponentType_tB7CCE9FF3B728EE7957568DA30CA8DCAC1E5CA34 
{
	int32_t ___value__;
};
struct LogCode_t75D12CD0B7E7695F8F1B0312517A7EE7C9A5E4FB 
{
	uint32_t ___value__;
};
struct MeshUpdateFlags_tCCD32DF7F112AE37CA85E45959DC6CDF64444DF6 
{
	int32_t ___value__;
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
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct StreamingContextStates_t5EE358E619B251608A9327618C7BFE8638FC33C1 
{
	int32_t ___value__;
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
struct VertexAttribute_tF34C1B76F20CA4AEC9D606BCD37A8A0C4A24C9A6 
{
	int32_t ___value__;
};
struct VertexAttributeFormat_tD714C51E671502B116ACE5E23F042BA80649D32F 
{
	int32_t ___value__;
};
struct NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t15E6E9438E5B73A5BFCFCADFEBF1D3D8949C6858 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t38B974FEBDE9C6BC682E4154FA808DE4F13EF788 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F 
{
	bool ___hasValue;
	Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 ___value;
};
struct WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180  : public RuntimeObject
{
	GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC ___handle;
	bool ___trackResurrection;
};
struct AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E  : public NamedObject_t907D3C13C4675E1432B946C6306227637A38EA9D
{
	int32_t ___bufferView;
	int32_t ___byteOffset;
	int32_t ___componentType;
	bool ___normalized;
	int32_t ___count;
	String_t* ___type;
	uint8_t ___m_TypeEnum;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___max;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___min;
};
struct AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6  : public RuntimeObject
{
	uint32_t ___bufferView;
	int32_t ___byteOffset;
	int32_t ___componentType;
};
struct GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F  : public RuntimeObject
{
	RuntimeObject* ___U3CLoggerU3Ek__BackingField;
	RuntimeObject* ___U3CDeferAgentU3Ek__BackingField;
	RuntimeObject* ___m_DownloadProvider;
	RuntimeObject* ___m_MaterialGenerator;
	Dictionary_2_tB427BE48400204F66ED8A4770F5E1A1F6F2CB941* ___m_ImportInstances;
	ImportSettings_t92812D83726B63C0D0C65404A95CCA9B121CEFDE* ___m_Settings;
	ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* ___m_Buffers;
	Nullable_1U5BU5D_t0C7FC263C73AB93B212871051A356A18838DC4B5* ___m_BufferHandles;
	NativeArray_1U5BU5D_t495E50C84E09FD9543D64DFF017C2FA53D91C475* ___m_NativeBuffers;
	GlbBinChunkU5BU5D_t1C454B47EF77D552A6045D077D456DC8852BF385* ___m_BinChunks;
	Dictionary_2_t0C9CD67BBA686A3BA7C01F6F8A21054F30DDBCAD* ___m_DownloadTasks;
	Dictionary_2_t6800D968311CB0CFA6840BC4AA1901B84A16145C* ___m_TextureDownloadTasks;
	IDisposableU5BU5D_t7D2E88760CCE6C653A28D1DB1108AFA898478DEE* ___m_AccessorData;
	AccessorUsageU5BU5D_tC30B6A0E57269C0847DD1458DA7022005143A780* ___m_AccessorUsage;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___m_AccessorJobsHandle;
	List_1_t412D68746FC7AC5454627D4A724A016FB11D1B8A* ___m_MeshOrders;
	List_1_tDBA15FCFA4AA5EB043D4C75BA42987C7DC2A3B33* ___m_ImageCreateContexts;
	Texture2DU5BU5D_t05332F1E3F7D4493E304C702201F9BE4F9236191* ___m_Images;
	Texture2DU5BU5D_t05332F1E3F7D4493E304C702201F9BE4F9236191* ___m_Textures;
	ImageFormatU5BU5D_tEBECAF709563AF35E803D0B23708CB60E67E4367* ___m_ImageFormats;
	BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* ___m_ImageReadable;
	BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* ___m_ImageGamma;
	Nullable_1_tBAE070955BC8FB2D249B4478766DFF3B46F27F61 ___m_GlbBinChunk;
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___m_MaterialPointsSupport;
	bool ___m_DefaultMaterialPointsSupport;
	MaterialU5BU5D_t2B1D11C42DB07A4400C0535F92DBB87A2E346D3D* ___m_Materials;
	List_1_t9A2E2984B23260AECDFA90CEB1F2887075FA4DF3* ___m_Resources;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___m_NodeNames;
	List_1_t43FB89B126C93A6B04630BC64C751BBE95AFEAF4* ___m_Meshes;
	FlatArray_1_tEE41ABC7EF4BAF3F75854CC89C9DA988778D921A* ___m_MeshAssignments;
	Matrix4x4U5BU5DU5BU5D_t70F44F6ABA3496D9431117EA02FF3B2DD46E50CF* ___m_SkinsInverseBindMatrices;
	AnimationClipU5BU5D_t48CE1A495BA95608745A065C735F2D5BB8DE5A0F* ___m_AnimationClips;
	bool ___U3CLoadingDoneU3Ek__BackingField;
	bool ___U3CLoadingErrorU3Ek__BackingField;
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___LoadAccessorDataEvent;
	Action_3_t4C244C4561415967803DF55DE7B36C0CB6B0227F* ___MeshResultAssigned;
};
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
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
struct VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 
{
	int32_t ___U3CattributeU3Ek__BackingField;
	int32_t ___U3CformatU3Ek__BackingField;
	int32_t ___U3CdimensionU3Ek__BackingField;
	int32_t ___U3CstreamU3Ek__BackingField;
};
struct Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D  : public MulticastDelegate_t
{
};
struct Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87  : public MulticastDelegate_t
{
};
struct Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B  : public MulticastDelegate_t
{
};
struct Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0  : public MulticastDelegate_t
{
};
struct VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 ___m_Data;
};
struct VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B ___m_Data;
};
struct VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 ___m_Data;
};
struct VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 ___m_Data;
};
struct VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA ___m_Data;
};
struct VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E ___m_Data;
};
struct VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 ___m_Data;
};
struct VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 ___m_Data;
};
struct VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___m_Data;
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94  : public RuntimeObject
{
	RuntimeObject* ___m_Logger;
	NativeArray_1_t15E6E9438E5B73A5BFCFCADFEBF1D3D8949C6858 ___m_Data;
};
struct VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA  : public RuntimeObject
{
	RuntimeObject* ___m_Logger;
	NativeArray_1_t38B974FEBDE9C6BC682E4154FA808DE4F13EF788 ___m_Data;
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___Value;
};
struct List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___s_emptyArray;
};
struct List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A_StaticFields
{
	__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___s_emptyArray;
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
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5_StaticFields
{
	float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5 ___zero;
};
struct float4_t545A994996126766890C1F28B43EA823F2410190_StaticFields
{
	float4_t545A994996126766890C1F28B43EA823F2410190 ___zero;
};
struct GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F_StaticFields
{
	HashSet_1_tEFC6605F7DE53F71946C33FD371E53C3100F2178* ___k_SupportedExtensions;
	RuntimeObject* ___s_DefaultDeferAgent;
	MeshComparer_tF00A9ABED9808868FBAF9921B2E3F3D18D82A2DA* ___s_MeshComparer;
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
struct AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322  : public RuntimeArray
{
	ALIGN_FIELD (8) Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* m_Items[1];

	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A  : public RuntimeArray
{
	ALIGN_FIELD (8) AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* m_Items[1];

	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2  : public RuntimeArray
{
	ALIGN_FIELD (8) VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 m_Items[1];

	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 value)
	{
		m_Items[index] = value;
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


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mBA83AAC5DEEF6A424E816BC22A562F9F16331060 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_nativeArray, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m63843427C63B48F1A2B4A13CEC25AA5CC725EC38_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t ___3_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mDB8D148A0EF2CE914022B139EDC228BC42BA980D (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m6BDF1E860A988B4B255D8FDF639C0C4D8B2FA788 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m6ED28625050D6187E9FF635F2F0B84FAE98963DE (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m98F5B919E464DF0F3ACD4366F3DC57AF2454635E (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mF28F15854DB63F91A8E4ECE7E7046833DEECD545 (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mB26D6A63E8B3F18A77A5552D357236D2292DDC4B (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m5C4B829BA2A5130FB5C09B29AD8805155EA7C756 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m82995B1021A45DA3ADE8B42EB36038FBB092EEAF (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 Nullable_1_get_Value_mC79E0A8A7D9E70CC7ABA0073EF626DE21DFADADB (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1_fshared (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeSliceUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m4D697E26467C391B48E97587F53534941CBEA23F_fshared_inline (NativeSlice_1_tA54E5D259EBCC7CD8512AA352C6F3709EB237B52 ___0_nativeSlice, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 NativeSliceExtensions_Slice_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m6FD1AF82FBEB746F5DED414A4AFF4B8EF1E02277 (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___0_thisArray, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m1BA84A1F51723A5804D44113CB7EAFB1C8C38A99 (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A (NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_m48A57644B8C7C2218F25EC3053DCC7E84CDC8BA3 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mD862E6EE54C32A0F39ABA2451CC507C6950F4A2F (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m7A519877353656E33CB26AC5D85DAAAD9D32326F (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_m1539E19AC03F83FBB649E6433C0450530D2019B7 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mAAAC7BFBE5048F115833AE826C1F1B5E71956840 (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m1CE6848303BBFB6D48015C4B8E7EC27A93909A7C (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_m63FFEA12B3C545C2E02EA20E6AB3CAED9248630A (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m56DD83D5396928AD02F2C9497BC81582659590C5 (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mA713CEEE3BCE4E908C893B378C7A8DBF695D4FAA (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m645242E506FB0B1FBBD6AAAE0EE20BC0EF40B2B4 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mEA5D4D66C2560C2B30AE7518A57E06A5DB4AE4AC (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mE886D07391485C509485D4C62EF5D0B3D63F4B44 (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mC629E255F0C1F0E46757EFE5CDF1BEBC9FBFE9A0 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m5EEF21AC693AEF53DABCEEB364E77D6D61220E83 (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m0B10F9B756186EF986E6BD73FC5921B5A8A9FD38 (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_m35397E0E2ADB7CBDA7212AE66B429232A4696B73 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mBAECB577DDA49050F519A272C019836076ECD9FD (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m67F10B4C117E273AE2F136F5DDB7E704CC398C9A (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_m094968E374812A79B98FA421AAE34A213DAC3F8E (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m5D81A285AB38F20DA55BBB23574DCB0B284CD393 (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m80162E0F1B413106BBBFA95DA99212E07AD6C268 (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mF633A59BB6BC13197FF8A0F0BF9341D99502C9AA (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mEF42F18D1E3ECE038A60D82B2DBBA2F8B4316FE0 (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89_mB9039BDE0A62F3298ED76214B72CE46918C8255A (ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForExtensions_Schedule_TisConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1_mF44365369C2DA0F87C1A1DD4493B59A812AACC9E (ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_innerloopBatchCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB_m9E18CF080F3709EFBE44FCCAA5F7E87763E609E5 (ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForExtensions_Schedule_TisConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA_m8A8F9336ED94EAB202DA66E950B1CE9D85DAB850 (ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_innerloopBatchCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C_m494DE9D0608D39869661FD2A829DB0D523FE094B (ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB_mE812841C0A243B763E58AADEDE363162B8D50FB7 (ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B_mF1D66E1214EC89ABA3AEBF8304CD6A6453ED5049 (ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5_mE7423E2E6337C573F2A7EC531FC975B10BBC1B60 (ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B_m048136BB9B52441F8CF46CFFC41E6720F229F96F (ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, bool ___1_trackResurrection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD_gshared (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_gshared_inline (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5_gshared (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate1, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100_gshared (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9_gshared (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_gshared_inline (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25_gshared (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_gshared_inline (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mBA83AAC5DEEF6A424E816BC22A562F9F16331060 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_m330509F7AC793C43640F0649AC22729C08D9A935_inline (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7 (Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline (GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* __this, const RuntimeMethod* method) ;
inline StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline (const RuntimeMethod* method)
{
	return ((  StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* (*) (const RuntimeMethod*))Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, int32_t ___0_vertexCount, RuntimeObject* ___1_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, int32_t ___0_vertexCount, RuntimeObject* ___1_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17 (AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7 (Type_t* ___0_t, const RuntimeMethod* method) ;
inline bool VertexBufferGenerator_1_SchedulePositionsJobs_mF6C412F9AE54E68C390D715FD61E39EA0B1104C1 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared)(__this, ___0_i, ___1_vDataPtr, ___2_outputByteStride, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleNormalsJobs_m759C2CDD45A3A7E6BBB0FFE983E33A6E7D248136 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleTangentsJobs_m4D2957E9D254DF24797C4572CAE523501105225D (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B614A1018475BC3C9AE872EBB9E1AF42273AF7B (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared)(__this, ___0_att, ___1_uvSetCount, ___2_i, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleColorsJobs_mB67927A5E7B9EB64C6BDCE399C0C3FED1243331A (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m5485E785F0D0B2B49A4FA7D5CE7A8F0EA6E3BD94 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleVertexBonesJobs_m63843427C63B48F1A2B4A13CEC25AA5CC725EC38_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___0_jobs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_value, const RuntimeMethod* method) ;
inline void VertexBufferGenerator_1_CreateDescriptors_m61EB63159D587C7438A2610FCEA2BA5E5AD603A7 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, const RuntimeMethod* method)
{
	((  void (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, const RuntimeMethod*))VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, int32_t ___0_vertexCount, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___1_attributes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mDB8D148A0EF2CE914022B139EDC228BC42BA980D (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m6492C57B05D6B9FFD26772B944B2A6BEF6015483_inline (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m6BDF1E860A988B4B255D8FDF639C0C4D8B2FA788 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04 (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m6ED28625050D6187E9FF635F2F0B84FAE98963DE (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mEF24F47840037840AEF8626D31E8C4C54CEF3340_inline (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline bool VertexBufferGenerator_1_SchedulePositionsJobs_m7E7DCC6FDC1062FD769A6CE944BA2574F74354AC (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared)(__this, ___0_i, ___1_vDataPtr, ___2_outputByteStride, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleNormalsJobs_m4A6BA6C3D0065FCE7DEBA556830D0BB2C20F1050 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleTangentsJobs_m24ED9C3178F6780CE23AF897AEE13B9F83A4E24B (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B1B735D20E1FBF67AA5DE4CE83BAC26C59C0A61 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared)(__this, ___0_att, ___1_uvSetCount, ___2_i, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleColorsJobs_mC44D082A9C89E72CA01C5D92DE0918F1CADD2304 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m4C47B9E299CC29C6385691E623E31178B8FBAF0F (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleVertexBonesJobs_m63843427C63B48F1A2B4A13CEC25AA5CC725EC38_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
inline void VertexBufferGenerator_1_CreateDescriptors_m6543578CB5017D6DE58830F12C0B02C149D77C17 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, const RuntimeMethod* method)
{
	((  void (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, const RuntimeMethod*))VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m98F5B919E464DF0F3ACD4366F3DC57AF2454635E (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mF889FB0A50008701DFF815D51811D6C2FA88D506_inline (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mF28F15854DB63F91A8E4ECE7E7046833DEECD545 (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mB26D6A63E8B3F18A77A5552D357236D2292DDC4B (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m4DFB73460B0763281BB179BE6CB139906474F02E_inline (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline bool VertexBufferGenerator_1_SchedulePositionsJobs_mA272F8DC9995E815EDD688721170775AE5283213 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared)(__this, ___0_i, ___1_vDataPtr, ___2_outputByteStride, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleNormalsJobs_mDF628CAC3BCB5DEDB2AE0FCE853E7DC2FE3C621A (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleTangentsJobs_m71316553C3BA7A0DD23BBBA9A82FA54D674587FB (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m0F6AC8EC930129564B6EF188169ED570B9566729 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared)(__this, ___0_att, ___1_uvSetCount, ___2_i, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleColorsJobs_m2704633CCB9A2628480745DE8991303651C6D68F (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m9369CB86D767E2F345ECB4E02805F0F51003C400 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleVertexBonesJobs_m63843427C63B48F1A2B4A13CEC25AA5CC725EC38_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
inline void VertexBufferGenerator_1_CreateDescriptors_m615516608A7DCDC74BE1B06896D86163FB7D9173 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, const RuntimeMethod* method)
{
	((  void (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, const RuntimeMethod*))VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m5C4B829BA2A5130FB5C09B29AD8805155EA7C756 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mC5ED66430AE33CD749E7A37DF7B48DFB49976CC7_inline (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m82995B1021A45DA3ADE8B42EB36038FBB092EEAF (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F AccessorBase_TryGetBounds_mE38F5405047CC52A32D7E623A022F15BC041172F (AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 Nullable_1_get_Value_mC79E0A8A7D9E70CC7ABA0073EF626DE21DFADADB (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGeneratorBase__ctor_m1429E22E9AC280A76FC7122C1F74EC2B3D20F78C (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC* __this, int32_t ___0_primitiveCount, GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* ___1_gltfImport, const RuntimeMethod* method) ;
inline void NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1 (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method)
{
	((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, int32_t, int32_t, const RuntimeMethod*))NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1_fshared)(__this, ___0_length, ___1_allocator, ___2_options, method);
}
inline void* NativeSliceUnsafeUtility_GetUnsafeReadOnlyPtr_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m0B676DC51FACE97ED8BDBE80FDEE1D024D852A62_inline (NativeSlice_1_tCEC4B2B900638EC1820BB61FE436766204DFD8DA ___0_nativeSlice, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeSlice_1_tCEC4B2B900638EC1820BB61FE436766204DFD8DA, const RuntimeMethod*))NativeSliceUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m4D697E26467C391B48E97587F53534941CBEA23F_fshared_inline)(___0_nativeSlice, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGeneratorBase_GetVector3Job_m384C27FC3CEEA9724A64ACA91B74681180492F6E (void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float3_t7600B73F092B37F484B12910A5269F30C778D31E* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, bool ___7_ensureUnitLength, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GltfImportBase_GetAccessorSparseIndices_mE7FB97593B7F50146FED5B5D36E325B6CF35350F (GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* __this, AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* ___0_sparseIndices, void** ___1_data, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GltfImportBase_GetAccessorSparseValues_mC342B9AB4ABE0B7860543D17A7238D3A4C0CA128 (GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* __this, AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071* ___0_sparseValues, void** ___1_data, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGeneratorBase_GetVector3SparseJob_m40E689FD8B2D5E53344AA7C5F2F77B8025127D3B (void* ___0_indexBuffer, void* ___1_valueBuffer, int32_t ___2_sparseCount, int32_t ___3_indexType, int32_t ___4_valueType, float3_t7600B73F092B37F484B12910A5269F30C778D31E* ___5_output, int32_t ___6_outputByteStride, Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* ___7_dependsOn, bool ___8_normalized, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGeneratorBase_GetTangentsJob_mA4F2AA421F08AF0793274A4BEB952FB29D96C3C3 (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float4_t545A994996126766890C1F28B43EA823F2410190* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Attributes_TryGetAllUVAccessors_m30F2F2BCFC23CC3184624E1B24885C7C1D3AD90E (Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C** ___0_uvAccessors, bool* ___1_limitExceeded, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 NativeSliceExtensions_Slice_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m6FD1AF82FBEB746F5DED414A4AFF4B8EF1E02277 (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___0_thisArray, int32_t ___1_start, int32_t ___2_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferColors_ScheduleVertexColorJob_m673D604A492D73F7222130333E61F83ED9E5BE12 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, int32_t ___0_colorAccessorIndex, int32_t ___1_offset, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferBones_ScheduleVertexBonesJob_m22A29825D18AF2F4DF85CAB97E2DDBB3482F6940 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, int32_t ___0_weightsAccessorIndex, int32_t ___1_jointsAccessorIndex, int32_t ___2_offset, RuntimeObject* ___3_buffers, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* __this, int32_t ___0_attribute, int32_t ___1_format, int32_t ___2_dimension, int32_t ___3_stream, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors_AddDescriptors_m9044A5AA91D41DB1C2C11F9C4F2CD96EACA72277 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_dst, int32_t ___1_offset, int32_t ___2_stream, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones_AddDescriptors_mC6CB82E330C72295F0EBB23137C4BB088313E358 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_dst, int32_t ___1_offset, int32_t ___2_stream, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5 (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, RuntimeObject* ___0_logger, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m1BA84A1F51723A5804D44113CB7EAFB1C8C38A99 (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mF524D1423BA04CC1D82B68F03416BB0D9F2D0D07_inline (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_mD23714F4ACF855409F00B184D8BF0F5D0AF00059 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A (NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8* __this, int32_t ___0_index, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_m48A57644B8C7C2218F25EC3053DCC7E84CDC8BA3 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m47651702D651C122A2B01BB40A8E917710D3099C_inline (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mD862E6EE54C32A0F39ABA2451CC507C6950F4A2F (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m7A519877353656E33CB26AC5D85DAAAD9D32326F (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mC3FA4D9E8BCF32F7C01E4EB5D2E30CB0494ECFE0_inline (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m714FB636385FECB96FD68D3E89E390658C70B35A (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_m1539E19AC03F83FBB649E6433C0450530D2019B7 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m11DD67623A1C17A38C09B61FCB8443B2126273D5_inline (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mAAAC7BFBE5048F115833AE826C1F1B5E71956840 (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m1CE6848303BBFB6D48015C4B8E7EC27A93909A7C (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_m864C3DB8E62F9F5110732BD18D3E5DAC45A16093_inline (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_mE24F9906F76973D6EDFDC56E519F91588B781D54 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_m63FFEA12B3C545C2E02EA20E6AB3CAED9248630A (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mC4889A6EDA2EA1E75670912100F3A28E1C54270A_inline (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m56DD83D5396928AD02F2C9497BC81582659590C5 (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mA713CEEE3BCE4E908C893B378C7A8DBF695D4FAA (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m4F3CBE966077F910B854D76766D0F9E3B40DC259_inline (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m66D617942C213621B70D98DB06E73F42642725FF (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m645242E506FB0B1FBBD6AAAE0EE20BC0EF40B2B4 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mDBBB6C81ACEBB4713F52E3F60C85DAAE8C266B99_inline (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mEA5D4D66C2560C2B30AE7518A57E06A5DB4AE4AC (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mE886D07391485C509485D4C62EF5D0B3D63F4B44 (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_m572BF122881B01BA58F0828302F7C9E34FB523BD_inline (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m67CA1F5CA843DAE3BD9BD5CDFD7EBC3986E77C49 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mC629E255F0C1F0E46757EFE5CDF1BEBC9FBFE9A0 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m85CFF2F73D5E5706F85BCBB1037485A7026A9225_inline (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m5EEF21AC693AEF53DABCEEB364E77D6D61220E83 (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m0B10F9B756186EF986E6BD73FC5921B5A8A9FD38 (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mF121F63D53E6986D20AC484F9F772781A9CFA90D_inline (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m1DB52CF37090F9D45E0FE50C81E4633E62E11930 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_m35397E0E2ADB7CBDA7212AE66B429232A4696B73 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m0B33F6524B69D07CD96A38E99CBEF9756FDCA6E9_inline (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mBAECB577DDA49050F519A272C019836076ECD9FD (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m67F10B4C117E273AE2F136F5DDB7E704CC398C9A (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mBC94888599C0A0E9E128E4D0E17AE100FFA4A630_inline (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m83430940690F9260E4A94BDC76079F2BD09BB821 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_m094968E374812A79B98FA421AAE34A213DAC3F8E (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mFC27630889FC60D66A3668AE44D67DB24B6C66C5_inline (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m5D81A285AB38F20DA55BBB23574DCB0B284CD393 (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m80162E0F1B413106BBBFA95DA99212E07AD6C268 (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mEFBEC242CAB99A188E6C97C3FC1012FAACEB69F6_inline (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m7215A2D5310683F4B136223DE51A4685018980E0 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method)
{
	return ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared)(__this, ___0_input, ___1_count, ___2_inputType, ___3_inputByteStride, ___4_output, ___5_outputByteStride, ___6_normalized, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mF633A59BB6BC13197FF8A0F0BF9341D99502C9AA (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m11434044E5DFD0B1936B1F1E00B07A845CE370F4_inline (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mEF42F18D1E3ECE038A60D82B2DBBA2F8B4316FE0 (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89_mB9039BDE0A62F3298ED76214B72CE46918C8255A (ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForExtensions_Schedule_TisConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1_mF44365369C2DA0F87C1A1DD4493B59A812AACC9E (ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_innerloopBatchCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB_m9E18CF080F3709EFBE44FCCAA5F7E87763E609E5 (ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForExtensions_Schedule_TisConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA_m8A8F9336ED94EAB202DA66E950B1CE9D85DAB850 (ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_innerloopBatchCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C_m494DE9D0608D39869661FD2A829DB0D523FE094B (ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB_mE812841C0A243B763E58AADEDE363162B8D50FB7 (ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B_mF1D66E1214EC89ABA3AEBF8304CD6A6453ED5049 (ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5_mE7423E2E6337C573F2A7EC531FC975B10BBC1B60 (ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B_m048136BB9B52441F8CF46CFFC41E6720F229F96F (ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B ___0_jobData, int32_t ___1_arrayLength, int32_t ___2_indicesPerJobCount, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___3_dependsOn, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline void WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, bool ___1_trackResurrection, const RuntimeMethod* method)
{
	((  void (*) (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180*, Il2CppSharedGenericObject*, bool, const RuntimeMethod*))WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E_gshared)(__this, ___0_target, ___1_trackResurrection, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC (RuntimeObject* ___0_value, int32_t ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool SerializationInfo_GetBoolean_m8335F8E11B572AB6B5BF85A9355D6888D5847EF5 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034 (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, Type_t* ___1_type, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_mC52253CB19C98F82A26E32C941F8F20E106D4C0D (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, bool ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SerializationInfo_AddValue_m28FE9B110F21DDB8FF5F5E35A0EABD659DB22C2F (SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* __this, String_t* ___0_name, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GCHandle_Free_m1320A260E487EB1EA6D95F9E54BFFCB5A4EF83A3 (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* __this, const RuntimeMethod* method) ;
inline void Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*, const RuntimeMethod*))Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD_gshared)(__this, method);
}
inline void WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline bool Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  bool (*) (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Il2CppSharedGenericObject*, const RuntimeMethod*))Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_gshared_inline)(__this, ___0_arg, method);
}
inline Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5 (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate1, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate2, const RuntimeMethod* method)
{
	return ((  Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* (*) (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5_gshared)(___0_predicate1, ___1_predicate2, method);
}
inline void WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377 (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*, RuntimeObject*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline void Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100 (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* __this, const RuntimeMethod* method)
{
	((  void (*) (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*, const RuntimeMethod*))Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100_gshared)(__this, method);
}
inline void WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method)
{
	((  void (*) (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, const RuntimeMethod*))WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A_gshared)(__this, ___0_source, ___1_predicate, method);
}
inline Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9 (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 (*) (List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, const RuntimeMethod*))List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9_gshared)(__this, method);
}
inline Il2CppSharedGenericObject* Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*, const RuntimeMethod*))Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_gshared_inline)(__this, method);
}
inline bool Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25 (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*, const RuntimeMethod*))Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25_gshared)(__this, method);
}
inline void WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120 (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375*, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, const RuntimeMethod*))WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline Il2CppSharedGenericObject* Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method)
{
	return ((  Il2CppSharedGenericObject* (*) (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, Il2CppSharedGenericObject*, const RuntimeMethod*))Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_gshared_inline)(__this, ___0_arg, method);
}
inline void WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384 (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C*, RuntimeObject*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, const RuntimeMethod*))WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
inline void WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868 (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method)
{
	((  void (*) (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9*, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E*, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D*, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87*, const RuntimeMethod*))WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868_gshared)(__this, ___0_source, ___1_predicate, ___2_selector, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GCHandle_CanDereferenceHandle_mAAAC42D1268CEF3FDD040A3D1574773D08140579_inline (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetRef_mAC7E58E62417209DC41C99F66BA70F0C3AA18DA8_inline (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GCHandle_GetTarget_mE0AF851834410E2AEA6285B2497751570236C794 (intptr_t ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void* IntPtr_op_Explicit_m2728CBA081E79B97DDCF1D4FAD77B309CA1E94BF (intptr_t ___0_value, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBuffer_m40B0F0709D6600E8AACD96AC50E05A10D53F8615 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* G_B20_0 = NULL;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* G_B19_0 = NULL;
	int32_t G_B21_0 = 0;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* G_B21_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B25_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B55_0;
	memset((&G_B55_0), 0, sizeof(G_B55_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_mBA83AAC5DEEF6A424E816BC22A562F9F16331060((&L_1), L_0, 4, 1, NULL);
		__this->___m_Data = L_1;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 L_2 = __this->___m_Data;
		void* L_3;
		L_3 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_m330509F7AC793C43640F0649AC22729C08D9A935_inline(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0176;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0059;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_12;
		L_12 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_11, NULL);
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_004d;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_0059;
	}

IL_004d:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14;
		L_14 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_14);
	}

IL_0059:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_17 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_18 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_17)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_15, ((int32_t)il2cpp_codegen_multiply(L_16, L_18))));
		int32_t L_19 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_19, 1)))
		{
			case 0:
			{
				goto IL_008f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_00cb;
			}
			case 3:
			{
				goto IL_00e9;
			}
			case 4:
			{
				goto IL_0104;
			}
			case 5:
			{
				goto IL_011f;
			}
			case 6:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_0155;
	}

IL_008f:
	{
		int32_t L_20 = V_3;
		int32_t L_21;
		L_21 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_22 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_23;
		L_23 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_22, NULL);
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_24 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_24, L_20, L_21, L_23, NULL);
		V_7 = L_24;
		goto IL_016e;
	}

IL_00ad:
	{
		int32_t L_25 = V_3;
		int32_t L_26;
		L_26 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_27 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_28;
		L_28 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_27, NULL);
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_29 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_29, L_25, L_26, L_28, NULL);
		V_7 = L_29;
		goto IL_016e;
	}

IL_00cb:
	{
		int32_t L_30 = V_3;
		int32_t L_31;
		L_31 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_32 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_33;
		L_33 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_32, NULL);
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_34 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_34, L_30, L_31, L_33, NULL);
		V_7 = L_34;
		goto IL_016e;
	}

IL_00e9:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_38;
		L_38 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_37, NULL);
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_39 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_39, L_35, L_36, L_38, NULL);
		V_7 = L_39;
		goto IL_016e;
	}

IL_0104:
	{
		int32_t L_40 = V_3;
		int32_t L_41;
		L_41 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_42 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_43;
		L_43 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_42, NULL);
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_44 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_44, L_40, L_41, L_43, NULL);
		V_7 = L_44;
		goto IL_016e;
	}

IL_011f:
	{
		int32_t L_45 = V_3;
		int32_t L_46;
		L_46 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_47 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_48;
		L_48 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_47, NULL);
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_49 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_49, L_45, L_46, L_48, NULL);
		V_7 = L_49;
		goto IL_016e;
	}

IL_013a:
	{
		int32_t L_50 = V_3;
		int32_t L_51;
		L_51 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_52 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_53;
		L_53 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_52, NULL);
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_54 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_54, L_50, L_51, L_53, NULL);
		V_7 = L_54;
		goto IL_016e;
	}

IL_0155:
	{
		int32_t L_55 = V_3;
		int32_t L_56;
		L_56 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_57 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_58;
		L_58 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_57, NULL);
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_59 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_59, L_55, L_56, L_58, NULL);
		V_7 = L_59;
	}

IL_016e:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_60 = V_7;
		__this->___m_TexCoords = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_60);
	}

IL_0176:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		int32_t L_62 = L_61->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_62) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_63 = __this->___m_HasColors;
		if (!L_63)
		{
			goto IL_01b7;
		}
	}
	{
		int32_t L_64 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_65 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_66 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_65)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_64, L_66));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_69;
		L_69 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_68, NULL);
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_70 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_70, L_67, L_69, NULL);
		__this->___m_Colors = L_70;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_70);
	}

IL_01b7:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_71 = V_2;
		int32_t L_72 = L_71->___WEIGHTS_0;
		if ((((int32_t)L_72) < ((int32_t)0)))
		{
			G_B20_0 = __this;
			goto IL_01cf;
		}
		G_B19_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_73 = V_2;
		int32_t L_74 = L_73->___JOINTS_0;
		G_B21_0 = ((((int32_t)((((int32_t)L_74) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B21_1 = G_B19_0;
		goto IL_01d0;
	}

IL_01cf:
	{
		G_B21_0 = 0;
		G_B21_1 = G_B20_0;
	}

IL_01d0:
	{
		G_B21_1->___m_HasBones = (bool)G_B21_0;
		bool L_75 = __this->___m_HasBones;
		if (!L_75)
		{
			goto IL_0204;
		}
	}
	{
		int32_t L_76 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_77 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_78 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_77)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_76, L_78));
		int32_t L_79;
		L_79 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_80 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_81;
		L_81 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_80, NULL);
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_82 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_82, L_79, L_81, NULL);
		__this->___m_Bones = L_82;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_82);
	}

IL_0204:
	{
		V_8 = 0;
		goto IL_0291;
	}

IL_020c:
	{
		int32_t L_83 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_83, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_84 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_85 = V_8;
		int32_t L_86 = L_85;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_87 = (L_84)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_86));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_88 = __this->___m_PositionAccessors;
		int32_t L_89 = V_8;
		int32_t L_90 = L_89;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_91 = (L_88)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_90));
		bool L_92;
		L_92 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_91, NULL);
		if (!L_92)
		{
			G_B27_0 = L_87;
			goto IL_023e;
		}
		G_B25_0 = L_87;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_93 = __this->___m_PositionAccessors;
		int32_t L_94 = V_8;
		int32_t L_95 = L_94;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_96 = (L_93)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_95));
		int32_t L_97 = L_96->___bufferView;
		if ((((int32_t)L_97) < ((int32_t)0)))
		{
			G_B27_0 = G_B25_0;
			goto IL_023e;
		}
		G_B26_0 = G_B25_0;
	}
	{
		int32_t L_98 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_98, 1));
		G_B27_0 = G_B26_0;
	}

IL_023e:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_99 = G_B27_0;
		int32_t L_100 = L_99->___NORMAL;
		if ((((int32_t)L_100) < ((int32_t)0)))
		{
			G_B29_0 = L_99;
			goto IL_0252;
		}
		G_B28_0 = L_99;
	}
	{
		int32_t L_101 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_101, 1));
		__this->___m_HasNormals = (bool)1;
		G_B29_0 = G_B28_0;
	}

IL_0252:
	{
		bool L_102 = __this->___m_HasNormals;
		bool L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_102|(int32_t)L_103));
		int32_t L_104 = G_B29_0->___TANGENT;
		if ((((int32_t)L_104) < ((int32_t)0)))
		{
			goto IL_0278;
		}
	}
	{
		int32_t L_105 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0278:
	{
		bool L_106 = __this->___m_HasTangents;
		bool L_107 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_106|(int32_t)L_107));
		int32_t L_108 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_108, 1));
	}

IL_0291:
	{
		int32_t L_109 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_110 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_111 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_110)->max_length),NULL));
		if ((((int32_t)L_109) < ((int32_t)L_111)))
		{
			goto IL_020c;
		}
	}
	{
		int32_t L_112 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_112, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_113 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 2)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_114;
		L_114 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_113, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_115;
		L_115 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_114, NULL);
		V_6 = L_115;
		V_9 = 0;
		goto IL_03a2;
	}

IL_02c6:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_116 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_117 = V_9;
		int32_t L_118 = L_117;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_119 = (L_116)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_118));
		V_10 = L_119;
		int32_t L_120 = V_9;
		uint8_t* L_121 = V_0;
		int32_t L_122 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_123 = V_4;
		bool L_124;
		L_124 = VertexBufferGenerator_1_SchedulePositionsJobs_mF6C412F9AE54E68C390D715FD61E39EA0B1104C1(__this, L_120, L_121, L_122, L_123, (&V_5), NULL);
		if (L_124)
		{
			goto IL_02ed;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_125 = V_11;
		return L_125;
	}

IL_02ed:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_126 = V_10;
		int32_t L_127 = L_126->___NORMAL;
		if ((((int32_t)L_127) < ((int32_t)0)))
		{
			goto IL_0315;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_128 = V_10;
		uint8_t* L_129 = V_0;
		int32_t L_130 = V_6;
		int32_t L_131 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_132 = V_4;
		bool L_133;
		L_133 = VertexBufferGenerator_1_ScheduleNormalsJobs_m759C2CDD45A3A7E6BBB0FFE983E33A6E7D248136(__this, L_128, L_129, L_130, L_131, L_132, (&V_5), NULL);
		if (L_133)
		{
			goto IL_0315;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_134 = V_11;
		return L_134;
	}

IL_0315:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_135 = V_10;
		int32_t L_136 = L_135->___TANGENT;
		if ((((int32_t)L_136) < ((int32_t)0)))
		{
			goto IL_033d;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_137 = V_10;
		uint8_t* L_138 = V_0;
		int32_t L_139 = V_6;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = VertexBufferGenerator_1_ScheduleTangentsJobs_m4D2957E9D254DF24797C4572CAE523501105225D(__this, L_137, L_138, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033d:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_144 = __this->___m_TexCoords;
		if (!L_144)
		{
			goto IL_0356;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_145 = V_10;
		int32_t L_146 = V_3;
		int32_t L_147 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_148 = V_4;
		int32_t L_149 = V_5;
		int32_t L_150;
		L_150 = VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B614A1018475BC3C9AE872EBB9E1AF42273AF7B(__this, L_145, L_146, L_147, L_148, L_149, NULL);
		V_5 = L_150;
	}

IL_0356:
	{
		bool L_151 = __this->___m_HasColors;
		if (!L_151)
		{
			goto IL_0379;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_152 = V_10;
		int32_t L_153 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_154 = V_4;
		bool L_155;
		L_155 = VertexBufferGenerator_1_ScheduleColorsJobs_mB67927A5E7B9EB64C6BDCE399C0C3FED1243331A(__this, L_152, L_153, L_154, (&V_5), NULL);
		if (L_155)
		{
			goto IL_0379;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_156 = V_11;
		return L_156;
	}

IL_0379:
	{
		bool L_157 = __this->___m_HasBones;
		if (!L_157)
		{
			goto IL_039c;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_158 = V_10;
		int32_t L_159 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_160 = V_4;
		int32_t L_161 = V_5;
		bool L_162;
		L_162 = VertexBufferGenerator_1_ScheduleVertexBonesJobs_m5485E785F0D0B2B49A4FA7D5CE7A8F0EA6E3BD94(__this, L_158, L_159, L_160, L_161, NULL);
		if (L_162)
		{
			goto IL_039c;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_163 = V_11;
		return L_163;
	}

IL_039c:
	{
		int32_t L_164 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_164, 1));
	}

IL_03a2:
	{
		int32_t L_165 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_166 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_167 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_166)->max_length),NULL));
		if ((((int32_t)L_165) < ((int32_t)L_167)))
		{
			goto IL_02c6;
		}
	}
	{
		int32_t L_168 = V_1;
		if ((((int32_t)L_168) > ((int32_t)1)))
		{
			goto IL_03bf;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_169;
		L_169 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B55_0 = L_169;
		goto IL_03c6;
	}

IL_03bf:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_170 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_171;
		L_171 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_170, NULL);
		G_B55_0 = L_171;
	}

IL_03c6:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_172;
		memset((&L_172), 0, sizeof(L_172));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_172), G_B55_0, NULL);
		return L_172;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_mEF2EA511BF57F0C2FCD1A8778CFA38E786C5042A (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VertexBufferGenerator_1_CreateDescriptors_m61EB63159D587C7438A2610FCEA2BA5E5AD603A7(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_2 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 L_6 = __this->___m_Data;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_7 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_7)->___m_Length);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		Mesh_SetVertexBufferData_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mDB8D148A0EF2CE914022B139EDC228BC42BA980D(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_mA5FE5442E3B7D5BD915EB52D766C9814F024210D (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_0 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m6492C57B05D6B9FFD26772B944B2A6BEF6015483_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_2 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		NativeArray_1_Dispose_m6BDF1E860A988B4B255D8FDF639C0C4D8B2FA788(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBuffer_m6C80B11E752561389DC5CE7898F4A893EA86CA54 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* G_B20_0 = NULL;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* G_B19_0 = NULL;
	int32_t G_B21_0 = 0;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* G_B21_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B25_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B55_0;
	memset((&G_B55_0), 0, sizeof(G_B55_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_m6ED28625050D6187E9FF635F2F0B84FAE98963DE((&L_1), L_0, 4, 1, NULL);
		__this->___m_Data = L_1;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E L_2 = __this->___m_Data;
		void* L_3;
		L_3 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mEF24F47840037840AEF8626D31E8C4C54CEF3340_inline(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0176;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0059;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_12;
		L_12 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_11, NULL);
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_004d;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_0059;
	}

IL_004d:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14;
		L_14 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_14);
	}

IL_0059:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_17 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_18 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_17)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_15, ((int32_t)il2cpp_codegen_multiply(L_16, L_18))));
		int32_t L_19 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_19, 1)))
		{
			case 0:
			{
				goto IL_008f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_00cb;
			}
			case 3:
			{
				goto IL_00e9;
			}
			case 4:
			{
				goto IL_0104;
			}
			case 5:
			{
				goto IL_011f;
			}
			case 6:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_0155;
	}

IL_008f:
	{
		int32_t L_20 = V_3;
		int32_t L_21;
		L_21 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_22 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_23;
		L_23 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_22, NULL);
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_24 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_24, L_20, L_21, L_23, NULL);
		V_7 = L_24;
		goto IL_016e;
	}

IL_00ad:
	{
		int32_t L_25 = V_3;
		int32_t L_26;
		L_26 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_27 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_28;
		L_28 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_27, NULL);
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_29 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_29, L_25, L_26, L_28, NULL);
		V_7 = L_29;
		goto IL_016e;
	}

IL_00cb:
	{
		int32_t L_30 = V_3;
		int32_t L_31;
		L_31 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_32 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_33;
		L_33 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_32, NULL);
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_34 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_34, L_30, L_31, L_33, NULL);
		V_7 = L_34;
		goto IL_016e;
	}

IL_00e9:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_38;
		L_38 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_37, NULL);
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_39 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_39, L_35, L_36, L_38, NULL);
		V_7 = L_39;
		goto IL_016e;
	}

IL_0104:
	{
		int32_t L_40 = V_3;
		int32_t L_41;
		L_41 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_42 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_43;
		L_43 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_42, NULL);
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_44 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_44, L_40, L_41, L_43, NULL);
		V_7 = L_44;
		goto IL_016e;
	}

IL_011f:
	{
		int32_t L_45 = V_3;
		int32_t L_46;
		L_46 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_47 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_48;
		L_48 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_47, NULL);
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_49 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_49, L_45, L_46, L_48, NULL);
		V_7 = L_49;
		goto IL_016e;
	}

IL_013a:
	{
		int32_t L_50 = V_3;
		int32_t L_51;
		L_51 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_52 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_53;
		L_53 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_52, NULL);
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_54 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_54, L_50, L_51, L_53, NULL);
		V_7 = L_54;
		goto IL_016e;
	}

IL_0155:
	{
		int32_t L_55 = V_3;
		int32_t L_56;
		L_56 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_57 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_58;
		L_58 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_57, NULL);
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_59 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_59, L_55, L_56, L_58, NULL);
		V_7 = L_59;
	}

IL_016e:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_60 = V_7;
		__this->___m_TexCoords = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_60);
	}

IL_0176:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		int32_t L_62 = L_61->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_62) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_63 = __this->___m_HasColors;
		if (!L_63)
		{
			goto IL_01b7;
		}
	}
	{
		int32_t L_64 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_65 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_66 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_65)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_64, L_66));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_69;
		L_69 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_68, NULL);
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_70 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_70, L_67, L_69, NULL);
		__this->___m_Colors = L_70;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_70);
	}

IL_01b7:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_71 = V_2;
		int32_t L_72 = L_71->___WEIGHTS_0;
		if ((((int32_t)L_72) < ((int32_t)0)))
		{
			G_B20_0 = __this;
			goto IL_01cf;
		}
		G_B19_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_73 = V_2;
		int32_t L_74 = L_73->___JOINTS_0;
		G_B21_0 = ((((int32_t)((((int32_t)L_74) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B21_1 = G_B19_0;
		goto IL_01d0;
	}

IL_01cf:
	{
		G_B21_0 = 0;
		G_B21_1 = G_B20_0;
	}

IL_01d0:
	{
		G_B21_1->___m_HasBones = (bool)G_B21_0;
		bool L_75 = __this->___m_HasBones;
		if (!L_75)
		{
			goto IL_0204;
		}
	}
	{
		int32_t L_76 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_77 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_78 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_77)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_76, L_78));
		int32_t L_79;
		L_79 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_80 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_81;
		L_81 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_80, NULL);
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_82 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_82, L_79, L_81, NULL);
		__this->___m_Bones = L_82;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_82);
	}

IL_0204:
	{
		V_8 = 0;
		goto IL_0291;
	}

IL_020c:
	{
		int32_t L_83 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_83, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_84 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_85 = V_8;
		int32_t L_86 = L_85;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_87 = (L_84)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_86));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_88 = __this->___m_PositionAccessors;
		int32_t L_89 = V_8;
		int32_t L_90 = L_89;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_91 = (L_88)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_90));
		bool L_92;
		L_92 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_91, NULL);
		if (!L_92)
		{
			G_B27_0 = L_87;
			goto IL_023e;
		}
		G_B25_0 = L_87;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_93 = __this->___m_PositionAccessors;
		int32_t L_94 = V_8;
		int32_t L_95 = L_94;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_96 = (L_93)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_95));
		int32_t L_97 = L_96->___bufferView;
		if ((((int32_t)L_97) < ((int32_t)0)))
		{
			G_B27_0 = G_B25_0;
			goto IL_023e;
		}
		G_B26_0 = G_B25_0;
	}
	{
		int32_t L_98 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_98, 1));
		G_B27_0 = G_B26_0;
	}

IL_023e:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_99 = G_B27_0;
		int32_t L_100 = L_99->___NORMAL;
		if ((((int32_t)L_100) < ((int32_t)0)))
		{
			G_B29_0 = L_99;
			goto IL_0252;
		}
		G_B28_0 = L_99;
	}
	{
		int32_t L_101 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_101, 1));
		__this->___m_HasNormals = (bool)1;
		G_B29_0 = G_B28_0;
	}

IL_0252:
	{
		bool L_102 = __this->___m_HasNormals;
		bool L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_102|(int32_t)L_103));
		int32_t L_104 = G_B29_0->___TANGENT;
		if ((((int32_t)L_104) < ((int32_t)0)))
		{
			goto IL_0278;
		}
	}
	{
		int32_t L_105 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0278:
	{
		bool L_106 = __this->___m_HasTangents;
		bool L_107 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_106|(int32_t)L_107));
		int32_t L_108 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_108, 1));
	}

IL_0291:
	{
		int32_t L_109 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_110 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_111 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_110)->max_length),NULL));
		if ((((int32_t)L_109) < ((int32_t)L_111)))
		{
			goto IL_020c;
		}
	}
	{
		int32_t L_112 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_112, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_113 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 2)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_114;
		L_114 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_113, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_115;
		L_115 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_114, NULL);
		V_6 = L_115;
		V_9 = 0;
		goto IL_03a2;
	}

IL_02c6:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_116 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_117 = V_9;
		int32_t L_118 = L_117;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_119 = (L_116)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_118));
		V_10 = L_119;
		int32_t L_120 = V_9;
		uint8_t* L_121 = V_0;
		int32_t L_122 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_123 = V_4;
		bool L_124;
		L_124 = VertexBufferGenerator_1_SchedulePositionsJobs_m7E7DCC6FDC1062FD769A6CE944BA2574F74354AC(__this, L_120, L_121, L_122, L_123, (&V_5), NULL);
		if (L_124)
		{
			goto IL_02ed;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_125 = V_11;
		return L_125;
	}

IL_02ed:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_126 = V_10;
		int32_t L_127 = L_126->___NORMAL;
		if ((((int32_t)L_127) < ((int32_t)0)))
		{
			goto IL_0315;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_128 = V_10;
		uint8_t* L_129 = V_0;
		int32_t L_130 = V_6;
		int32_t L_131 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_132 = V_4;
		bool L_133;
		L_133 = VertexBufferGenerator_1_ScheduleNormalsJobs_m4A6BA6C3D0065FCE7DEBA556830D0BB2C20F1050(__this, L_128, L_129, L_130, L_131, L_132, (&V_5), NULL);
		if (L_133)
		{
			goto IL_0315;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_134 = V_11;
		return L_134;
	}

IL_0315:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_135 = V_10;
		int32_t L_136 = L_135->___TANGENT;
		if ((((int32_t)L_136) < ((int32_t)0)))
		{
			goto IL_033d;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_137 = V_10;
		uint8_t* L_138 = V_0;
		int32_t L_139 = V_6;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = VertexBufferGenerator_1_ScheduleTangentsJobs_m24ED9C3178F6780CE23AF897AEE13B9F83A4E24B(__this, L_137, L_138, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033d:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_144 = __this->___m_TexCoords;
		if (!L_144)
		{
			goto IL_0356;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_145 = V_10;
		int32_t L_146 = V_3;
		int32_t L_147 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_148 = V_4;
		int32_t L_149 = V_5;
		int32_t L_150;
		L_150 = VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B1B735D20E1FBF67AA5DE4CE83BAC26C59C0A61(__this, L_145, L_146, L_147, L_148, L_149, NULL);
		V_5 = L_150;
	}

IL_0356:
	{
		bool L_151 = __this->___m_HasColors;
		if (!L_151)
		{
			goto IL_0379;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_152 = V_10;
		int32_t L_153 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_154 = V_4;
		bool L_155;
		L_155 = VertexBufferGenerator_1_ScheduleColorsJobs_mC44D082A9C89E72CA01C5D92DE0918F1CADD2304(__this, L_152, L_153, L_154, (&V_5), NULL);
		if (L_155)
		{
			goto IL_0379;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_156 = V_11;
		return L_156;
	}

IL_0379:
	{
		bool L_157 = __this->___m_HasBones;
		if (!L_157)
		{
			goto IL_039c;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_158 = V_10;
		int32_t L_159 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_160 = V_4;
		int32_t L_161 = V_5;
		bool L_162;
		L_162 = VertexBufferGenerator_1_ScheduleVertexBonesJobs_m4C47B9E299CC29C6385691E623E31178B8FBAF0F(__this, L_158, L_159, L_160, L_161, NULL);
		if (L_162)
		{
			goto IL_039c;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_163 = V_11;
		return L_163;
	}

IL_039c:
	{
		int32_t L_164 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_164, 1));
	}

IL_03a2:
	{
		int32_t L_165 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_166 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_167 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_166)->max_length),NULL));
		if ((((int32_t)L_165) < ((int32_t)L_167)))
		{
			goto IL_02c6;
		}
	}
	{
		int32_t L_168 = V_1;
		if ((((int32_t)L_168) > ((int32_t)1)))
		{
			goto IL_03bf;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_169;
		L_169 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B55_0 = L_169;
		goto IL_03c6;
	}

IL_03bf:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_170 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_171;
		L_171 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_170, NULL);
		G_B55_0 = L_171;
	}

IL_03c6:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_172;
		memset((&L_172), 0, sizeof(L_172));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_172), G_B55_0, NULL);
		return L_172;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_m65690618C224E28490D9A61C7F6C80E1EF128D8E (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VertexBufferGenerator_1_CreateDescriptors_m6543578CB5017D6DE58830F12C0B02C149D77C17(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_2 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E L_6 = __this->___m_Data;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_7 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_7)->___m_Length);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		Mesh_SetVertexBufferData_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m98F5B919E464DF0F3ACD4366F3DC57AF2454635E(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_m02FDEB15049C12FE217BEF9499004FDE24A9534A (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_0 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mF889FB0A50008701DFF815D51811D6C2FA88D506_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_2 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		NativeArray_1_Dispose_mF28F15854DB63F91A8E4ECE7E7046833DEECD545(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBuffer_m2C0D04748474277917704AF35DD95C29A98D1E83 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* G_B20_0 = NULL;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* G_B19_0 = NULL;
	int32_t G_B21_0 = 0;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* G_B21_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B25_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B55_0;
	memset((&G_B55_0), 0, sizeof(G_B55_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_mB26D6A63E8B3F18A77A5552D357236D2292DDC4B((&L_1), L_0, 4, 1, NULL);
		__this->___m_Data = L_1;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 L_2 = __this->___m_Data;
		void* L_3;
		L_3 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m4DFB73460B0763281BB179BE6CB139906474F02E_inline(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0176;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0059;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_12;
		L_12 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_11, NULL);
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_004d;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_0059;
	}

IL_004d:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14;
		L_14 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_14);
	}

IL_0059:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_17 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_18 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_17)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_15, ((int32_t)il2cpp_codegen_multiply(L_16, L_18))));
		int32_t L_19 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_19, 1)))
		{
			case 0:
			{
				goto IL_008f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_00cb;
			}
			case 3:
			{
				goto IL_00e9;
			}
			case 4:
			{
				goto IL_0104;
			}
			case 5:
			{
				goto IL_011f;
			}
			case 6:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_0155;
	}

IL_008f:
	{
		int32_t L_20 = V_3;
		int32_t L_21;
		L_21 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_22 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_23;
		L_23 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_22, NULL);
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_24 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_24, L_20, L_21, L_23, NULL);
		V_7 = L_24;
		goto IL_016e;
	}

IL_00ad:
	{
		int32_t L_25 = V_3;
		int32_t L_26;
		L_26 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_27 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_28;
		L_28 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_27, NULL);
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_29 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_29, L_25, L_26, L_28, NULL);
		V_7 = L_29;
		goto IL_016e;
	}

IL_00cb:
	{
		int32_t L_30 = V_3;
		int32_t L_31;
		L_31 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_32 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_33;
		L_33 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_32, NULL);
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_34 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_34, L_30, L_31, L_33, NULL);
		V_7 = L_34;
		goto IL_016e;
	}

IL_00e9:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_38;
		L_38 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_37, NULL);
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_39 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_39, L_35, L_36, L_38, NULL);
		V_7 = L_39;
		goto IL_016e;
	}

IL_0104:
	{
		int32_t L_40 = V_3;
		int32_t L_41;
		L_41 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_42 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_43;
		L_43 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_42, NULL);
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_44 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_44, L_40, L_41, L_43, NULL);
		V_7 = L_44;
		goto IL_016e;
	}

IL_011f:
	{
		int32_t L_45 = V_3;
		int32_t L_46;
		L_46 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_47 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_48;
		L_48 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_47, NULL);
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_49 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_49, L_45, L_46, L_48, NULL);
		V_7 = L_49;
		goto IL_016e;
	}

IL_013a:
	{
		int32_t L_50 = V_3;
		int32_t L_51;
		L_51 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_52 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_53;
		L_53 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_52, NULL);
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_54 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_54, L_50, L_51, L_53, NULL);
		V_7 = L_54;
		goto IL_016e;
	}

IL_0155:
	{
		int32_t L_55 = V_3;
		int32_t L_56;
		L_56 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_57 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_58;
		L_58 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_57, NULL);
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_59 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_59, L_55, L_56, L_58, NULL);
		V_7 = L_59;
	}

IL_016e:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_60 = V_7;
		__this->___m_TexCoords = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_60);
	}

IL_0176:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		int32_t L_62 = L_61->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_62) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_63 = __this->___m_HasColors;
		if (!L_63)
		{
			goto IL_01b7;
		}
	}
	{
		int32_t L_64 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_65 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_66 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_65)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_64, L_66));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_69;
		L_69 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_68, NULL);
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_70 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_70, L_67, L_69, NULL);
		__this->___m_Colors = L_70;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_70);
	}

IL_01b7:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_71 = V_2;
		int32_t L_72 = L_71->___WEIGHTS_0;
		if ((((int32_t)L_72) < ((int32_t)0)))
		{
			G_B20_0 = __this;
			goto IL_01cf;
		}
		G_B19_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_73 = V_2;
		int32_t L_74 = L_73->___JOINTS_0;
		G_B21_0 = ((((int32_t)((((int32_t)L_74) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B21_1 = G_B19_0;
		goto IL_01d0;
	}

IL_01cf:
	{
		G_B21_0 = 0;
		G_B21_1 = G_B20_0;
	}

IL_01d0:
	{
		G_B21_1->___m_HasBones = (bool)G_B21_0;
		bool L_75 = __this->___m_HasBones;
		if (!L_75)
		{
			goto IL_0204;
		}
	}
	{
		int32_t L_76 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_77 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_78 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_77)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_76, L_78));
		int32_t L_79;
		L_79 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_80 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_81;
		L_81 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_80, NULL);
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_82 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_82, L_79, L_81, NULL);
		__this->___m_Bones = L_82;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_82);
	}

IL_0204:
	{
		V_8 = 0;
		goto IL_0291;
	}

IL_020c:
	{
		int32_t L_83 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_83, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_84 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_85 = V_8;
		int32_t L_86 = L_85;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_87 = (L_84)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_86));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_88 = __this->___m_PositionAccessors;
		int32_t L_89 = V_8;
		int32_t L_90 = L_89;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_91 = (L_88)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_90));
		bool L_92;
		L_92 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_91, NULL);
		if (!L_92)
		{
			G_B27_0 = L_87;
			goto IL_023e;
		}
		G_B25_0 = L_87;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_93 = __this->___m_PositionAccessors;
		int32_t L_94 = V_8;
		int32_t L_95 = L_94;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_96 = (L_93)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_95));
		int32_t L_97 = L_96->___bufferView;
		if ((((int32_t)L_97) < ((int32_t)0)))
		{
			G_B27_0 = G_B25_0;
			goto IL_023e;
		}
		G_B26_0 = G_B25_0;
	}
	{
		int32_t L_98 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_98, 1));
		G_B27_0 = G_B26_0;
	}

IL_023e:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_99 = G_B27_0;
		int32_t L_100 = L_99->___NORMAL;
		if ((((int32_t)L_100) < ((int32_t)0)))
		{
			G_B29_0 = L_99;
			goto IL_0252;
		}
		G_B28_0 = L_99;
	}
	{
		int32_t L_101 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_101, 1));
		__this->___m_HasNormals = (bool)1;
		G_B29_0 = G_B28_0;
	}

IL_0252:
	{
		bool L_102 = __this->___m_HasNormals;
		bool L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_102|(int32_t)L_103));
		int32_t L_104 = G_B29_0->___TANGENT;
		if ((((int32_t)L_104) < ((int32_t)0)))
		{
			goto IL_0278;
		}
	}
	{
		int32_t L_105 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0278:
	{
		bool L_106 = __this->___m_HasTangents;
		bool L_107 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_106|(int32_t)L_107));
		int32_t L_108 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_108, 1));
	}

IL_0291:
	{
		int32_t L_109 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_110 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_111 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_110)->max_length),NULL));
		if ((((int32_t)L_109) < ((int32_t)L_111)))
		{
			goto IL_020c;
		}
	}
	{
		int32_t L_112 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_112, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_113 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 2)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_114;
		L_114 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_113, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_115;
		L_115 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_114, NULL);
		V_6 = L_115;
		V_9 = 0;
		goto IL_03a2;
	}

IL_02c6:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_116 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_117 = V_9;
		int32_t L_118 = L_117;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_119 = (L_116)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_118));
		V_10 = L_119;
		int32_t L_120 = V_9;
		uint8_t* L_121 = V_0;
		int32_t L_122 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_123 = V_4;
		bool L_124;
		L_124 = VertexBufferGenerator_1_SchedulePositionsJobs_mA272F8DC9995E815EDD688721170775AE5283213(__this, L_120, L_121, L_122, L_123, (&V_5), NULL);
		if (L_124)
		{
			goto IL_02ed;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_125 = V_11;
		return L_125;
	}

IL_02ed:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_126 = V_10;
		int32_t L_127 = L_126->___NORMAL;
		if ((((int32_t)L_127) < ((int32_t)0)))
		{
			goto IL_0315;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_128 = V_10;
		uint8_t* L_129 = V_0;
		int32_t L_130 = V_6;
		int32_t L_131 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_132 = V_4;
		bool L_133;
		L_133 = VertexBufferGenerator_1_ScheduleNormalsJobs_mDF628CAC3BCB5DEDB2AE0FCE853E7DC2FE3C621A(__this, L_128, L_129, L_130, L_131, L_132, (&V_5), NULL);
		if (L_133)
		{
			goto IL_0315;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_134 = V_11;
		return L_134;
	}

IL_0315:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_135 = V_10;
		int32_t L_136 = L_135->___TANGENT;
		if ((((int32_t)L_136) < ((int32_t)0)))
		{
			goto IL_033d;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_137 = V_10;
		uint8_t* L_138 = V_0;
		int32_t L_139 = V_6;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = VertexBufferGenerator_1_ScheduleTangentsJobs_m71316553C3BA7A0DD23BBBA9A82FA54D674587FB(__this, L_137, L_138, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033d:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_144 = __this->___m_TexCoords;
		if (!L_144)
		{
			goto IL_0356;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_145 = V_10;
		int32_t L_146 = V_3;
		int32_t L_147 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_148 = V_4;
		int32_t L_149 = V_5;
		int32_t L_150;
		L_150 = VertexBufferGenerator_1_ScheduleTexCoordJobs_m0F6AC8EC930129564B6EF188169ED570B9566729(__this, L_145, L_146, L_147, L_148, L_149, NULL);
		V_5 = L_150;
	}

IL_0356:
	{
		bool L_151 = __this->___m_HasColors;
		if (!L_151)
		{
			goto IL_0379;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_152 = V_10;
		int32_t L_153 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_154 = V_4;
		bool L_155;
		L_155 = VertexBufferGenerator_1_ScheduleColorsJobs_m2704633CCB9A2628480745DE8991303651C6D68F(__this, L_152, L_153, L_154, (&V_5), NULL);
		if (L_155)
		{
			goto IL_0379;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_156 = V_11;
		return L_156;
	}

IL_0379:
	{
		bool L_157 = __this->___m_HasBones;
		if (!L_157)
		{
			goto IL_039c;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_158 = V_10;
		int32_t L_159 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_160 = V_4;
		int32_t L_161 = V_5;
		bool L_162;
		L_162 = VertexBufferGenerator_1_ScheduleVertexBonesJobs_m9369CB86D767E2F345ECB4E02805F0F51003C400(__this, L_158, L_159, L_160, L_161, NULL);
		if (L_162)
		{
			goto IL_039c;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_163 = V_11;
		return L_163;
	}

IL_039c:
	{
		int32_t L_164 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_164, 1));
	}

IL_03a2:
	{
		int32_t L_165 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_166 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_167 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_166)->max_length),NULL));
		if ((((int32_t)L_165) < ((int32_t)L_167)))
		{
			goto IL_02c6;
		}
	}
	{
		int32_t L_168 = V_1;
		if ((((int32_t)L_168) > ((int32_t)1)))
		{
			goto IL_03bf;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_169;
		L_169 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B55_0 = L_169;
		goto IL_03c6;
	}

IL_03bf:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_170 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_171;
		L_171 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_170, NULL);
		G_B55_0 = L_171;
	}

IL_03c6:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_172;
		memset((&L_172), 0, sizeof(L_172));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_172), G_B55_0, NULL);
		return L_172;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_mAF8B8C9784C11E8242C6FC610DB23B50FC5C78F5 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VertexBufferGenerator_1_CreateDescriptors_m615516608A7DCDC74BE1B06896D86163FB7D9173(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_2 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 L_6 = __this->___m_Data;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_7 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_7)->___m_Length);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		Mesh_SetVertexBufferData_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m5C4B829BA2A5130FB5C09B29AD8805155EA7C756(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_m3B15E3D704EF350ACBA0EBFB53B709A7B9218855 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_0 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mC5ED66430AE33CD749E7A37DF7B48DFB49976CC7_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_2 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		NativeArray_1_Dispose_m82995B1021A45DA3ADE8B42EB36038FBB092EEAF(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VertexBufferGenerator_1_get_VertexCount_m665635C5B082E9A8DB6D295AE372B3E50F34300A_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0;
		L_0 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return 0;
	}

IL_000a:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1;
		L_1 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2;
		L_2 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		int32_t L_4 = ((int32_t)il2cpp_codegen_subtract(L_3, 1));
		int32_t L_5 = (L_1)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* VertexBufferGenerator_1_get_VertexIntervals_mCD3732FBC34E0839A0026E87644F191A1ED3E635_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->___U3CVertexIntervalsU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_set_VertexIntervals_m7AC6E1190422BD70D8762934C47A2B0976D8E2DE_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_value, const RuntimeMethod* method) 
{
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_value;
		__this->___U3CVertexIntervalsU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CVertexIntervalsU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_GetVertexRange_m3AFEEAB2811FD808374740F9C7F98D612943568F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_subMesh, int32_t* ___1_baseVertex, int32_t* ___2_vertexCount, const RuntimeMethod* method) 
{
	{
		int32_t* L_0 = ___1_baseVertex;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1;
		L_1 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_2 = ___0_subMesh;
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3));
		il2cpp_codegen_stind<int32_t>((int32_t*)L_0, (int32_t)L_4);
		int32_t* L_5 = ___2_vertexCount;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6;
		L_6 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_7 = ___0_subMesh;
		int32_t L_8 = ((int32_t)il2cpp_codegen_add(L_7, 1));
		int32_t L_9 = (L_6)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8));
		int32_t* L_10 = ___1_baseVertex;
		int32_t L_11 = il2cpp_codegen_ldind<int32_t, int32_t>(L_10);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_5, (int32_t)((int32_t)il2cpp_codegen_subtract(L_9, L_11)));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_TryGetBounds_m4E8310DA6CAF3F2FF0AE371AB48720448A6D5ED4_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_subMesh, Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3* ___1_bounds, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F V_0;
	memset((&V_0), 0, sizeof(V_0));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_0 = __this->___m_PositionAccessors;
		int32_t L_1 = ___0_subMesh;
		int32_t L_2 = L_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = (L_0)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_2));
		Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F L_4;
		L_4 = AccessorBase_TryGetBounds_mE38F5405047CC52A32D7E623A022F15BC041172F(L_3, NULL);
		V_0 = L_4;
		bool L_5;
		L_5 = Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline((&V_0), NULL);
		if (!L_5)
		{
			goto IL_0026;
		}
	}
	{
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3* L_6 = ___1_bounds;
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 L_7;
		L_7 = Nullable_1_get_Value_mC79E0A8A7D9E70CC7ABA0073EF626DE21DFADADB((&V_0), NULL);
		*(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3*)L_6 = L_7;
		return (bool)1;
	}

IL_0026:
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_8 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_9;
		L_9 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_8, NULL);
		RuntimeObject* L_10 = L_9;
		if (L_10)
		{
			G_B4_0 = L_10;
			goto IL_0037;
		}
		G_B3_0 = L_10;
	}
	{
		goto IL_0059;
	}

IL_0037:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_11 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = L_11;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_13 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_14 = ___0_subMesh;
		int32_t L_15 = L_14;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_16 = (L_13)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15));
		int32_t* L_17 = (int32_t*)(&L_16->___POSITION);
		String_t* L_18;
		L_18 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_17, NULL);
		(L_12)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)L_18);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)32), L_12);
	}

IL_0059:
	{
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3* L_19 = ___1_bounds;
		il2cpp_codegen_initobj(L_19, sizeof(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3));
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1__ctor_m0F9A48372F432DAAF975C0D36DC8768DA2E679F8_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_primitiveCount, GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* ___1_gltfImport, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_primitiveCount;
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_1 = ___1_gltfImport;
		VertexBufferGeneratorBase__ctor_m1429E22E9AC280A76FC7122C1F74EC2B3D20F78C((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this, L_0, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_AddPrimitive_m2F198B7CEDF11A5B43F8532ACD68A3B1CC1CA29F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_1 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_AttributeCount;
		V_0 = L_1;
		int32_t L_2 = V_0;
		((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_AttributeCount = ((int32_t)il2cpp_codegen_add(L_2, 1));
		int32_t L_3 = V_0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_4 = ___0_att;
		ArrayElementTypeCheck (L_0, L_4);
		(L_0)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*)L_4);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Initialize_mDA45C6C60D3E9FAA469DB0B79505543A548BC24D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		V_0 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_2 = (AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A*)(AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A*)SZArrayNew(AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A_il2cpp_TypeInfo_var, (uint32_t)L_1);
		__this->___m_PositionAccessors = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_PositionAccessors), (void*)L_2);
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_3 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(L_4, 1)));
		VirtualActionInvoker1< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(11, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this, L_5);
		V_1 = 0;
		goto IL_006b;
	}

IL_002e:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6;
		L_6 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_7 = V_1;
		int32_t L_8 = V_0;
		(L_6)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7), (int32_t)L_8);
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_9 = __this->___m_PositionAccessors;
		int32_t L_10 = V_1;
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_12 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_13 = V_1;
		int32_t L_14 = L_13;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_15 = (L_12)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_14));
		int32_t L_16 = L_15->___POSITION;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17;
		L_17 = InterfaceFuncInvoker1< AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E*, int32_t >::Invoke(0, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_11, L_16);
		ArrayElementTypeCheck (L_9, L_17);
		(L_9)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_10), (AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E*)L_17);
		int32_t L_18 = V_0;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_19 = __this->___m_PositionAccessors;
		int32_t L_20 = V_1;
		int32_t L_21 = L_20;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_22 = (L_19)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_21));
		int32_t L_23 = L_22->___count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_18, L_23));
		int32_t L_24 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_006b:
	{
		int32_t L_25 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_26 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_27 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_26)->max_length),NULL));
		if ((((int32_t)L_25) < ((int32_t)L_27)))
		{
			goto IL_002e;
		}
	}
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_28;
		L_28 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_29 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_30 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_29)->max_length),NULL));
		int32_t L_31 = V_0;
		(L_28)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_30), (int32_t)L_31);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBuffer_mBAE24D54C1F63486AEEBFEB1A41F6FFFA9CADC18_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* G_B20_0 = NULL;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* G_B19_0 = NULL;
	int32_t G_B21_0 = 0;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* G_B21_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B25_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B55_0;
	memset((&G_B55_0), 0, sizeof(G_B55_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1((&L_1), L_0, 4, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->___m_Data = L_1;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2 = __this->___m_Data;
		void* L_3;
		L_3 = ((  void* (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1)))(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0176;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0059;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_12;
		L_12 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_11, NULL);
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_004d;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_0059;
	}

IL_004d:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14;
		L_14 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_14);
	}

IL_0059:
	{
		int32_t L_15 = V_1;
		int32_t L_16 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_17 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_18 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_17)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_15, ((int32_t)il2cpp_codegen_multiply(L_16, L_18))));
		int32_t L_19 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_19, 1)))
		{
			case 0:
			{
				goto IL_008f;
			}
			case 1:
			{
				goto IL_00ad;
			}
			case 2:
			{
				goto IL_00cb;
			}
			case 3:
			{
				goto IL_00e9;
			}
			case 4:
			{
				goto IL_0104;
			}
			case 5:
			{
				goto IL_011f;
			}
			case 6:
			{
				goto IL_013a;
			}
		}
	}
	{
		goto IL_0155;
	}

IL_008f:
	{
		int32_t L_20 = V_3;
		int32_t L_21;
		L_21 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_22 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_23;
		L_23 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_22, NULL);
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_24 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_24, L_20, L_21, L_23, NULL);
		V_7 = L_24;
		goto IL_016e;
	}

IL_00ad:
	{
		int32_t L_25 = V_3;
		int32_t L_26;
		L_26 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_27 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_28;
		L_28 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_27, NULL);
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_29 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_29, L_25, L_26, L_28, NULL);
		V_7 = L_29;
		goto IL_016e;
	}

IL_00cb:
	{
		int32_t L_30 = V_3;
		int32_t L_31;
		L_31 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_32 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_33;
		L_33 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_32, NULL);
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_34 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_34, L_30, L_31, L_33, NULL);
		V_7 = L_34;
		goto IL_016e;
	}

IL_00e9:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_38;
		L_38 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_37, NULL);
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_39 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_39, L_35, L_36, L_38, NULL);
		V_7 = L_39;
		goto IL_016e;
	}

IL_0104:
	{
		int32_t L_40 = V_3;
		int32_t L_41;
		L_41 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_42 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_43;
		L_43 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_42, NULL);
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_44 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_44, L_40, L_41, L_43, NULL);
		V_7 = L_44;
		goto IL_016e;
	}

IL_011f:
	{
		int32_t L_45 = V_3;
		int32_t L_46;
		L_46 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_47 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_48;
		L_48 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_47, NULL);
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_49 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_49, L_45, L_46, L_48, NULL);
		V_7 = L_49;
		goto IL_016e;
	}

IL_013a:
	{
		int32_t L_50 = V_3;
		int32_t L_51;
		L_51 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_52 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_53;
		L_53 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_52, NULL);
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_54 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_54, L_50, L_51, L_53, NULL);
		V_7 = L_54;
		goto IL_016e;
	}

IL_0155:
	{
		int32_t L_55 = V_3;
		int32_t L_56;
		L_56 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_57 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_58;
		L_58 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_57, NULL);
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_59 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_59, L_55, L_56, L_58, NULL);
		V_7 = L_59;
	}

IL_016e:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_60 = V_7;
		__this->___m_TexCoords = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_60);
	}

IL_0176:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		int32_t L_62 = L_61->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_62) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_63 = __this->___m_HasColors;
		if (!L_63)
		{
			goto IL_01b7;
		}
	}
	{
		int32_t L_64 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_65 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_66 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_65)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_64, L_66));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_69;
		L_69 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_68, NULL);
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_70 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_70, L_67, L_69, NULL);
		__this->___m_Colors = L_70;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_70);
	}

IL_01b7:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_71 = V_2;
		int32_t L_72 = L_71->___WEIGHTS_0;
		if ((((int32_t)L_72) < ((int32_t)0)))
		{
			G_B20_0 = __this;
			goto IL_01cf;
		}
		G_B19_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_73 = V_2;
		int32_t L_74 = L_73->___JOINTS_0;
		G_B21_0 = ((((int32_t)((((int32_t)L_74) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B21_1 = G_B19_0;
		goto IL_01d0;
	}

IL_01cf:
	{
		G_B21_0 = 0;
		G_B21_1 = G_B20_0;
	}

IL_01d0:
	{
		G_B21_1->___m_HasBones = (bool)G_B21_0;
		bool L_75 = __this->___m_HasBones;
		if (!L_75)
		{
			goto IL_0204;
		}
	}
	{
		int32_t L_76 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_77 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_78 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_77)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_76, L_78));
		int32_t L_79;
		L_79 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_80 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_81;
		L_81 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_80, NULL);
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_82 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_82, L_79, L_81, NULL);
		__this->___m_Bones = L_82;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_82);
	}

IL_0204:
	{
		V_8 = 0;
		goto IL_0291;
	}

IL_020c:
	{
		int32_t L_83 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_83, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_84 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_85 = V_8;
		int32_t L_86 = L_85;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_87 = (L_84)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_86));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_88 = __this->___m_PositionAccessors;
		int32_t L_89 = V_8;
		int32_t L_90 = L_89;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_91 = (L_88)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_90));
		bool L_92;
		L_92 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_91, NULL);
		if (!L_92)
		{
			G_B27_0 = L_87;
			goto IL_023e;
		}
		G_B25_0 = L_87;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_93 = __this->___m_PositionAccessors;
		int32_t L_94 = V_8;
		int32_t L_95 = L_94;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_96 = (L_93)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_95));
		int32_t L_97 = L_96->___bufferView;
		if ((((int32_t)L_97) < ((int32_t)0)))
		{
			G_B27_0 = G_B25_0;
			goto IL_023e;
		}
		G_B26_0 = G_B25_0;
	}
	{
		int32_t L_98 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_98, 1));
		G_B27_0 = G_B26_0;
	}

IL_023e:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_99 = G_B27_0;
		int32_t L_100 = L_99->___NORMAL;
		if ((((int32_t)L_100) < ((int32_t)0)))
		{
			G_B29_0 = L_99;
			goto IL_0252;
		}
		G_B28_0 = L_99;
	}
	{
		int32_t L_101 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_101, 1));
		__this->___m_HasNormals = (bool)1;
		G_B29_0 = G_B28_0;
	}

IL_0252:
	{
		bool L_102 = __this->___m_HasNormals;
		bool L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_102|(int32_t)L_103));
		int32_t L_104 = G_B29_0->___TANGENT;
		if ((((int32_t)L_104) < ((int32_t)0)))
		{
			goto IL_0278;
		}
	}
	{
		int32_t L_105 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_105, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0278:
	{
		bool L_106 = __this->___m_HasTangents;
		bool L_107 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_106|(int32_t)L_107));
		int32_t L_108 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_108, 1));
	}

IL_0291:
	{
		int32_t L_109 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_110 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_111 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_110)->max_length),NULL));
		if ((((int32_t)L_109) < ((int32_t)L_111)))
		{
			goto IL_020c;
		}
	}
	{
		int32_t L_112 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_112, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_113 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 2)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_114;
		L_114 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_113, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_115;
		L_115 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_114, NULL);
		V_6 = L_115;
		V_9 = 0;
		goto IL_03a2;
	}

IL_02c6:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_116 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_117 = V_9;
		int32_t L_118 = L_117;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_119 = (L_116)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_118));
		V_10 = L_119;
		int32_t L_120 = V_9;
		uint8_t* L_121 = V_0;
		int32_t L_122 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_123 = V_4;
		bool L_124;
		L_124 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(__this, L_120, L_121, L_122, L_123, (&V_5), NULL);
		if (L_124)
		{
			goto IL_02ed;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_125 = V_11;
		return L_125;
	}

IL_02ed:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_126 = V_10;
		int32_t L_127 = L_126->___NORMAL;
		if ((((int32_t)L_127) < ((int32_t)0)))
		{
			goto IL_0315;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_128 = V_10;
		uint8_t* L_129 = V_0;
		int32_t L_130 = V_6;
		int32_t L_131 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_132 = V_4;
		bool L_133;
		L_133 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(__this, L_128, L_129, L_130, L_131, L_132, (&V_5), NULL);
		if (L_133)
		{
			goto IL_0315;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_134 = V_11;
		return L_134;
	}

IL_0315:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_135 = V_10;
		int32_t L_136 = L_135->___TANGENT;
		if ((((int32_t)L_136) < ((int32_t)0)))
		{
			goto IL_033d;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_137 = V_10;
		uint8_t* L_138 = V_0;
		int32_t L_139 = V_6;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(__this, L_137, L_138, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033d;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033d:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_144 = __this->___m_TexCoords;
		if (!L_144)
		{
			goto IL_0356;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_145 = V_10;
		int32_t L_146 = V_3;
		int32_t L_147 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_148 = V_4;
		int32_t L_149 = V_5;
		int32_t L_150;
		L_150 = ((  int32_t (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(__this, L_145, L_146, L_147, L_148, L_149, NULL);
		V_5 = L_150;
	}

IL_0356:
	{
		bool L_151 = __this->___m_HasColors;
		if (!L_151)
		{
			goto IL_0379;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_152 = V_10;
		int32_t L_153 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_154 = V_4;
		bool L_155;
		L_155 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(__this, L_152, L_153, L_154, (&V_5), NULL);
		if (L_155)
		{
			goto IL_0379;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_156 = V_11;
		return L_156;
	}

IL_0379:
	{
		bool L_157 = __this->___m_HasBones;
		if (!L_157)
		{
			goto IL_039c;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_158 = V_10;
		int32_t L_159 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_160 = V_4;
		int32_t L_161 = V_5;
		bool L_162;
		L_162 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, L_158, L_159, L_160, L_161, NULL);
		if (L_162)
		{
			goto IL_039c;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_163 = V_11;
		return L_163;
	}

IL_039c:
	{
		int32_t L_164 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_164, 1));
	}

IL_03a2:
	{
		int32_t L_165 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_166 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_167 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_166)->max_length),NULL));
		if ((((int32_t)L_165) < ((int32_t)L_167)))
		{
			goto IL_02c6;
		}
	}
	{
		int32_t L_168 = V_1;
		if ((((int32_t)L_168) > ((int32_t)1)))
		{
			goto IL_03bf;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_169;
		L_169 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B55_0 = L_169;
		goto IL_03c6;
	}

IL_03bf:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_170 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_171;
		L_171 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_170, NULL);
		G_B55_0 = L_171;
	}

IL_03c6:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_172;
		memset((&L_172), 0, sizeof(L_172));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_172), G_B55_0, NULL);
		return L_172;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_0;
	memset((&V_0), 0, sizeof(V_0));
	NativeSlice_1_tCEC4B2B900638EC1820BB61FE436766204DFD8DA V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	void* V_3 = NULL;
	void* V_4 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_5;
	memset((&V_5), 0, sizeof(V_5));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_0 = __this->___m_PositionAccessors;
		int32_t L_1 = ___0_i;
		int32_t L_2 = L_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = (L_0)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_2));
		int32_t L_4 = L_3->___bufferView;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0076;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_5 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_6 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_7 = ___0_i;
		int32_t L_8 = L_7;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_9 = (L_6)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_8));
		int32_t L_10 = L_9->___POSITION;
		InterfaceActionInvoker3< int32_t, NativeSlice_1_tCEC4B2B900638EC1820BB61FE436766204DFD8DA*, int32_t* >::Invoke(1, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_5, L_10, (&V_1), (&V_2));
		NativeSlice_1_tCEC4B2B900638EC1820BB61FE436766204DFD8DA L_11 = V_1;
		void* L_12;
		L_12 = NativeSliceUnsafeUtility_GetUnsafeReadOnlyPtr_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m0B676DC51FACE97ED8BDBE80FDEE1D024D852A62_inline(L_11, NULL);
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_13 = __this->___m_PositionAccessors;
		int32_t L_14 = ___0_i;
		int32_t L_15 = L_14;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_16 = (L_13)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15));
		int32_t L_17 = L_16->___count;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_18 = __this->___m_PositionAccessors;
		int32_t L_19 = ___0_i;
		int32_t L_20 = L_19;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_21 = (L_18)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_20));
		int32_t L_22 = L_21->___componentType;
		int32_t L_23 = V_2;
		uint8_t* L_24 = ___1_vDataPtr;
		int32_t L_25 = ___2_outputByteStride;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_26;
		L_26 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_27 = ___0_i;
		int32_t L_28 = L_27;
		int32_t L_29 = (L_26)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_28));
		int32_t L_30 = ___2_outputByteStride;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_31 = __this->___m_PositionAccessors;
		int32_t L_32 = ___0_i;
		int32_t L_33 = L_32;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_34 = (L_31)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_33));
		bool L_35 = L_34->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_36;
		L_36 = VertexBufferGeneratorBase_GetVector3Job_m384C27FC3CEEA9724A64ACA91B74681180492F6E(L_12, L_17, L_22, L_23, (float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_24, ((int32_t)il2cpp_codegen_multiply(L_25, L_29)))), L_30, L_35, (bool)0, NULL);
		V_0 = L_36;
	}

IL_0076:
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_37 = __this->___m_PositionAccessors;
		int32_t L_38 = ___0_i;
		int32_t L_39 = L_38;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_40 = (L_37)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_39));
		bool L_41;
		L_41 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_40, NULL);
		if (!L_41)
		{
			goto IL_0148;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_42 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_43 = __this->___m_PositionAccessors;
		int32_t L_44 = ___0_i;
		int32_t L_45 = L_44;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_46 = (L_43)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_45));
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_47;
		L_47 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_46);
		AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* L_48;
		L_48 = VirtualFuncInvoker0< AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* >::Invoke(4, L_47);
		GltfImportBase_GetAccessorSparseIndices_mE7FB97593B7F50146FED5B5D36E325B6CF35350F(L_42, L_48, (&V_3), NULL);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_49 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_50 = __this->___m_PositionAccessors;
		int32_t L_51 = ___0_i;
		int32_t L_52 = L_51;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_53 = (L_50)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_52));
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_54;
		L_54 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_53);
		AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071* L_55;
		L_55 = VirtualFuncInvoker0< AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071* >::Invoke(5, L_54);
		GltfImportBase_GetAccessorSparseValues_mC342B9AB4ABE0B7860543D17A7238D3A4C0CA128(L_49, L_55, (&V_4), NULL);
		void* L_56 = V_3;
		void* L_57 = V_4;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_58 = __this->___m_PositionAccessors;
		int32_t L_59 = ___0_i;
		int32_t L_60 = L_59;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_61 = (L_58)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_60));
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_62;
		L_62 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_61);
		int32_t L_63 = L_62->___count;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_64 = __this->___m_PositionAccessors;
		int32_t L_65 = ___0_i;
		int32_t L_66 = L_65;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_67 = (L_64)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_66));
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_68;
		L_68 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_67);
		AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* L_69;
		L_69 = VirtualFuncInvoker0< AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* >::Invoke(4, L_68);
		int32_t L_70 = L_69->___componentType;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_71 = __this->___m_PositionAccessors;
		int32_t L_72 = ___0_i;
		int32_t L_73 = L_72;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_74 = (L_71)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_73));
		int32_t L_75 = L_74->___componentType;
		uint8_t* L_76 = ___1_vDataPtr;
		int32_t L_77 = ___2_outputByteStride;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_78;
		L_78 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_79 = ___0_i;
		int32_t L_80 = L_79;
		int32_t L_81 = (L_78)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_80));
		int32_t L_82 = ___2_outputByteStride;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_83 = __this->___m_PositionAccessors;
		int32_t L_84 = ___0_i;
		int32_t L_85 = L_84;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_86 = (L_83)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_85));
		bool L_87 = L_86->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_88;
		L_88 = VertexBufferGeneratorBase_GetVector3SparseJob_m40E689FD8B2D5E53344AA7C5F2F77B8025127D3B(L_56, L_57, L_63, L_70, L_75, (float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_76, ((int32_t)il2cpp_codegen_multiply(L_77, L_81)))), L_82, (&V_0), L_87, NULL);
		V_5 = L_88;
		bool L_89;
		L_89 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_5), NULL);
		if (!L_89)
		{
			goto IL_0146;
		}
	}
	{
		int32_t* L_90 = ___4_handleIndex;
		int32_t L_91 = il2cpp_codegen_ldind<int32_t, int32_t>(L_90);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_92;
		L_92 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_5), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___3_handles))->___m_Buffer, L_91, (L_92));
		int32_t* L_93 = ___4_handleIndex;
		int32_t* L_94 = ___4_handleIndex;
		int32_t L_95 = il2cpp_codegen_ldind<int32_t, int32_t>(L_94);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_93, (int32_t)((int32_t)il2cpp_codegen_add(L_95, 1)));
		goto IL_0148;
	}

IL_0146:
	{
		return (bool)0;
	}

IL_0148:
	{
		bool L_96;
		L_96 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_0), NULL);
		if (!L_96)
		{
			goto IL_016c;
		}
	}
	{
		int32_t* L_97 = ___4_handleIndex;
		int32_t L_98 = il2cpp_codegen_ldind<int32_t, int32_t>(L_97);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_99;
		L_99 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_0), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___3_handles))->___m_Buffer, L_98, (L_99));
		int32_t* L_100 = ___4_handleIndex;
		int32_t* L_101 = ___4_handleIndex;
		int32_t L_102 = il2cpp_codegen_ldind<int32_t, int32_t>(L_101);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_100, (int32_t)((int32_t)il2cpp_codegen_add(L_102, 1)));
		goto IL_016e;
	}

IL_016c:
	{
		return (bool)0;
	}

IL_016e:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBF92C939C85D8888B68A1C0E975839B22C2F1CA0);
		s_Il2CppMethodInitialized = true;
	}
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_0 = NULL;
	void* V_1 = NULL;
	int32_t V_2 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_3;
	memset((&V_3), 0, sizeof(V_3));
	RuntimeObject* G_B3_0 = NULL;
	RuntimeObject* G_B2_0 = NULL;
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		int32_t L_2 = L_1->___NORMAL;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_0, L_2, (&V_0), (&V_1), (&V_2));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = V_0;
		bool L_4;
		L_4 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_3, NULL);
		if (!L_4)
		{
			goto IL_0045;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_5 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_6;
		L_6 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_5, NULL);
		RuntimeObject* L_7 = L_6;
		if (L_7)
		{
			G_B3_0 = L_7;
			goto IL_0030;
		}
		G_B2_0 = L_7;
	}
	{
		goto IL_0045;
	}

IL_0030:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_9 = L_8;
		(L_9)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralBF92C939C85D8888B68A1C0E975839B22C2F1CA0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B3_0, ((int32_t)42), L_9);
	}

IL_0045:
	{
		void* L_10 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_11 = V_0;
		int32_t L_12 = L_11->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_13 = V_0;
		int32_t L_14 = L_13->___componentType;
		int32_t L_15 = V_2;
		uint8_t* L_16 = ___1_vDataPtr;
		int32_t L_17 = ___2_outputByteStride;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18;
		L_18 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_19 = ___3_i;
		int32_t L_20 = L_19;
		int32_t L_21 = (L_18)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_20));
		int32_t L_22 = ___2_outputByteStride;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_23 = V_0;
		bool L_24 = L_23->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_25;
		L_25 = VertexBufferGeneratorBase_GetVector3Job_m384C27FC3CEEA9724A64ACA91B74681180492F6E(L_10, L_12, L_14, L_15, (float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_16, ((int32_t)il2cpp_codegen_multiply(L_17, L_21)))), ((int32_t)12))), L_22, L_24, (bool)1, NULL);
		V_3 = L_25;
		bool L_26;
		L_26 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_3), NULL);
		if (!L_26)
		{
			goto IL_0095;
		}
	}
	{
		int32_t* L_27 = ___5_handleIndex;
		int32_t L_28 = il2cpp_codegen_ldind<int32_t, int32_t>(L_27);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_29;
		L_29 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_3), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___4_handles))->___m_Buffer, L_28, (L_29));
		int32_t* L_30 = ___5_handleIndex;
		int32_t* L_31 = ___5_handleIndex;
		int32_t L_32 = il2cpp_codegen_ldind<int32_t, int32_t>(L_31);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_30, (int32_t)((int32_t)il2cpp_codegen_add(L_32, 1)));
		goto IL_0097;
	}

IL_0095:
	{
		return (bool)0;
	}

IL_0097:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral695F5F858DF14780BC5525F0AA16CE70EB9C45E8);
		s_Il2CppMethodInitialized = true;
	}
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_0 = NULL;
	void* V_1 = NULL;
	int32_t V_2 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_3;
	memset((&V_3), 0, sizeof(V_3));
	RuntimeObject* G_B3_0 = NULL;
	RuntimeObject* G_B2_0 = NULL;
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		int32_t L_2 = L_1->___TANGENT;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_0, L_2, (&V_0), (&V_1), (&V_2));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = V_0;
		bool L_4;
		L_4 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_3, NULL);
		if (!L_4)
		{
			goto IL_0045;
		}
	}
	{
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_5 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		RuntimeObject* L_6;
		L_6 = GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline(L_5, NULL);
		RuntimeObject* L_7 = L_6;
		if (L_7)
		{
			G_B3_0 = L_7;
			goto IL_0030;
		}
		G_B2_0 = L_7;
	}
	{
		goto IL_0045;
	}

IL_0030:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_9 = L_8;
		(L_9)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral695F5F858DF14780BC5525F0AA16CE70EB9C45E8);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B3_0, ((int32_t)42), L_9);
	}

IL_0045:
	{
		void* L_10 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_11 = V_0;
		int32_t L_12 = L_11->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_13 = V_0;
		int32_t L_14 = L_13->___componentType;
		int32_t L_15 = V_2;
		uint8_t* L_16 = ___1_vDataPtr;
		int32_t L_17 = ___2_outputByteStride;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_18;
		L_18 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_19 = ___3_i;
		int32_t L_20 = L_19;
		int32_t L_21 = (L_18)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_20));
		int32_t L_22 = ___2_outputByteStride;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_23 = V_0;
		bool L_24 = L_23->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_25;
		L_25 = VertexBufferGeneratorBase_GetTangentsJob_mA4F2AA421F08AF0793274A4BEB952FB29D96C3C3((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this, L_10, L_12, L_14, L_15, (float4_t545A994996126766890C1F28B43EA823F2410190*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_16, ((int32_t)il2cpp_codegen_multiply(L_17, L_21)))), ((int32_t)24))), L_22, L_24, NULL);
		V_3 = L_25;
		bool L_26;
		L_26 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_3), NULL);
		if (!L_26)
		{
			goto IL_0095;
		}
	}
	{
		int32_t* L_27 = ___5_handleIndex;
		int32_t L_28 = il2cpp_codegen_ldind<int32_t, int32_t>(L_27);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_29;
		L_29 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_3), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___4_handles))->___m_Buffer, L_28, (L_29));
		int32_t* L_30 = ___5_handleIndex;
		int32_t* L_31 = ___5_handleIndex;
		int32_t L_32 = il2cpp_codegen_ldind<int32_t, int32_t>(L_31);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_30, (int32_t)((int32_t)il2cpp_codegen_add(L_32, 1)));
		goto IL_0097;
	}

IL_0095:
	{
		return (bool)0;
	}

IL_0097:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method) 
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	bool V_1 = false;
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_0 = ___0_att;
		bool L_1;
		L_1 = Attributes_TryGetAllUVAccessors_m30F2F2BCFC23CC3184624E1B24885C7C1D3AD90E(L_0, (&V_0), (&V_1), NULL);
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_2 = __this->___m_TexCoords;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3;
		L_3 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_4 = ___2_i;
		int32_t L_5 = L_4;
		int32_t L_6 = (L_3)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_5));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_0;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_8 = ___3_handles;
		int32_t L_9 = ___4_handleIndex;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10 = V_0;
		int32_t L_11 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_10)->max_length),NULL));
		NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 L_12;
		L_12 = NativeSliceExtensions_Slice_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m6FD1AF82FBEB746F5DED414A4AFF4B8EF1E02277(L_8, L_9, L_11, NULL);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_13 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		bool L_14;
		L_14 = VirtualFuncInvoker4< bool, int32_t, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8, RuntimeObject* >::Invoke(5, L_2, L_6, L_7, L_12, L_13);
		int32_t L_15 = ___4_handleIndex;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_16 = V_0;
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		___4_handleIndex = ((int32_t)il2cpp_codegen_add(L_15, L_17));
		int32_t L_18 = ___4_handleIndex;
		return L_18;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method) 
{
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_0 = __this->___m_Colors;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		int32_t L_2 = L_1->___COLOR_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3;
		L_3 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_4 = ___1_i;
		int32_t L_5 = L_4;
		int32_t L_6 = (L_3)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_5));
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_7 = ___2_handles;
		int32_t* L_8 = ___3_handleIndex;
		int32_t L_9 = il2cpp_codegen_ldind<int32_t, int32_t>(L_8);
		NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 L_10;
		L_10 = NativeSliceExtensions_Slice_TisJobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08_m6FD1AF82FBEB746F5DED414A4AFF4B8EF1E02277(L_7, L_9, 1, NULL);
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		bool L_12;
		L_12 = VertexBufferColors_ScheduleVertexColorJob_m673D604A492D73F7222130333E61F83ED9E5BE12(L_0, L_2, L_6, L_10, L_11, NULL);
		if (L_12)
		{
			goto IL_002d;
		}
	}
	{
		return (bool)0;
	}

IL_002d:
	{
		int32_t* L_13 = ___3_handleIndex;
		int32_t* L_14 = ___3_handleIndex;
		int32_t L_15 = il2cpp_codegen_ldind<int32_t, int32_t>(L_14);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_13, (int32_t)((int32_t)il2cpp_codegen_add(L_15, 1)));
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m63843427C63B48F1A2B4A13CEC25AA5CC725EC38_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t ___3_handleIndex, const RuntimeMethod* method) 
{
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_0 = __this->___m_Bones;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		int32_t L_2 = L_1->___WEIGHTS_0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_3 = ___0_att;
		int32_t L_4 = L_3->___JOINTS_0;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5;
		L_5 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_6 = ___1_i;
		int32_t L_7 = L_6;
		int32_t L_8 = (L_5)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_7));
		GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* L_9 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_GltfImport;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_10;
		L_10 = VertexBufferBones_ScheduleVertexBonesJob_m22A29825D18AF2F4DF85CAB97E2DDBB3482F6940(L_0, L_2, L_4, L_8, L_9, NULL);
		V_0 = L_10;
		bool L_11;
		L_11 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_0), NULL);
		if (!L_11)
		{
			goto IL_0041;
		}
	}
	{
		int32_t L_12 = ___3_handleIndex;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_13;
		L_13 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_0), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___2_handles))->___m_Buffer, L_12, (L_13));
		goto IL_0043;
	}

IL_0041:
	{
		return (bool)0;
	}

IL_0043:
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = 1;
		bool L_0 = __this->___m_HasNormals;
		if (!L_0)
		{
			goto IL_000e;
		}
	}
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_000e:
	{
		bool L_2 = __this->___m_HasTangents;
		if (!L_2)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_3 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_001a:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_4 = __this->___m_TexCoords;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = V_0;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		int32_t L_7;
		L_7 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(L_6, NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, L_7));
	}

IL_0030:
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_8 = __this->___m_Colors;
		if (!L_8)
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_003c:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_10 = __this->___m_Bones;
		if (!L_10)
		{
			goto IL_0048;
		}
	}
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 2));
	}

IL_0048:
	{
		int32_t L_12 = V_0;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_13 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2_il2cpp_TypeInfo_var, (uint32_t)L_12);
		((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors), (void*)L_13);
		V_1 = 0;
		V_2 = 0;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_14 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_15 = V_1;
		int32_t L_16 = V_2;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_17;
		memset((&L_17), 0, sizeof(L_17));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_17), 0, 0, 3, L_16, NULL);
		(L_14)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_15), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_17);
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_18, 1));
		bool L_19 = __this->___m_HasNormals;
		if (!L_19)
		{
			goto IL_0092;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_20 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_21 = V_1;
		int32_t L_22 = V_2;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_23;
		memset((&L_23), 0, sizeof(L_23));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_23), 1, 0, 3, L_22, NULL);
		(L_20)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_21), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_23);
		int32_t L_24 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_0092:
	{
		bool L_25 = __this->___m_HasTangents;
		if (!L_25)
		{
			goto IL_00b3;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_26 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_27 = V_1;
		int32_t L_28 = V_2;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_29;
		memset((&L_29), 0, sizeof(L_29));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_29), 2, 0, 4, L_28, NULL);
		(L_26)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_27), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_29);
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00b3:
	{
		int32_t L_31 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_31, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_32 = __this->___m_Colors;
		if (!L_32)
		{
			goto IL_00da;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_33 = __this->___m_Colors;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_34 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_35 = V_1;
		int32_t L_36 = V_2;
		VertexBufferColors_AddDescriptors_m9044A5AA91D41DB1C2C11F9C4F2CD96EACA72277(L_33, L_34, L_35, L_36, NULL);
		int32_t L_37 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_37, 1));
		int32_t L_38 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00da:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_39 = __this->___m_TexCoords;
		if (!L_39)
		{
			goto IL_00fa;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_40 = __this->___m_TexCoords;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_41 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_42 = V_2;
		VirtualActionInvoker3< VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*, int32_t*, int32_t >::Invoke(6, L_40, L_41, (&V_1), L_42);
		int32_t L_43 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_43, 1));
	}

IL_00fa:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_44 = __this->___m_Bones;
		if (!L_44)
		{
			goto IL_0115;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_45 = __this->___m_Bones;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_46 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_47 = V_1;
		int32_t L_48 = V_2;
		VertexBufferBones_AddDescriptors_mC6CB82E330C72295F0EBB23137C4BB088313E358(L_45, L_46, L_47, L_48, NULL);
	}

IL_0115:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_mED500EA07DAC8DAD2EDB8ACDE15C00A10318EFF2_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		((  void (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)))(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_2, NULL);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_6 = __this->___m_Data;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_7 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_7, NULL);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		((  void (*) (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_m7F8396D3755837F43218752397D6D2C8A5C40745_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_0 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		bool L_1;
		L_1 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)))(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m1BA84A1F51723A5804D44113CB7EAFB1C8C38A99((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_m6D80F0AAF63F45A21BC3C963B449C4D1BC8FAF17 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_mF524D1423BA04CC1D82B68F03416BB0D9F2D0D07_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_mD23714F4ACF855409F00B184D8BF0F5D0AF00059(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_mB41FCF57FBE322FD93B61DCE1CCA2A7D009A99A5 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 L_1 = __this->___m_Data;
		NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* L_2 = (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord1_tBE16AAD03CD6B8049B1D88CA01AC26B34D71F4A9_m48A57644B8C7C2218F25EC3053DCC7E84CDC8BA3(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m3F08FF86C13E19663514690924795CF0D097094F (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* L_0 = (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m47651702D651C122A2B01BB40A8E917710D3099C_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313* L_2 = (NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313*)(&__this->___m_Data);
		NativeArray_1_Dispose_mD862E6EE54C32A0F39ABA2451CC507C6950F4A2F(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m7A519877353656E33CB26AC5D85DAAAD9D32326F((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_mBC7C4625816D4691B55DA51B80D51F8FC5FF296B (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_mC3FA4D9E8BCF32F7C01E4EB5D2E30CB0494ECFE0_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_m714FB636385FECB96FD68D3E89E390658C70B35A(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_m45E1042076405145B2D700BF39CA89968BFF046D (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B L_1 = __this->___m_Data;
		NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* L_2 = (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord2_tB42C28FB21409F1B17B9EC52611E806B1448A32F_m1539E19AC03F83FBB649E6433C0450530D2019B7(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_mBAD4CB21B9DAEF3A94487C255C47A6CDC695FF81 (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* L_0 = (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m11DD67623A1C17A38C09B61FCB8443B2126273D5_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B* L_2 = (NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B*)(&__this->___m_Data);
		NativeArray_1_Dispose_mAAAC7BFBE5048F115833AE826C1F1B5E71956840(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m1CE6848303BBFB6D48015C4B8E7EC27A93909A7C((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_m8B08B125DB58D03D1954AD5A5E3E87D951DF75F7 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_m864C3DB8E62F9F5110732BD18D3E5DAC45A16093_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_mE24F9906F76973D6EDFDC56E519F91588B781D54(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_mD522AD1E7790637C84D04064DCDE8F35223B266C (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 L_1 = __this->___m_Data;
		NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* L_2 = (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord3_t23C06BAE19A49E85054EBFF08306F033BA2F8A99_m63FFEA12B3C545C2E02EA20E6AB3CAED9248630A(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m63A915E534226D2B74B8996DFD5E9C8E3E5F314B (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* L_0 = (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mC4889A6EDA2EA1E75670912100F3A28E1C54270A_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997* L_2 = (NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997*)(&__this->___m_Data);
		NativeArray_1_Dispose_m56DD83D5396928AD02F2C9497BC81582659590C5(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_mA713CEEE3BCE4E908C893B378C7A8DBF695D4FAA((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_m068730627E071624787AB38A6B208CA9BF11ED73 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m4F3CBE966077F910B854D76766D0F9E3B40DC259_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_m66D617942C213621B70D98DB06E73F42642725FF(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_mA3689F7515200BBAD557E76F20D7986A00504FBC (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 L_1 = __this->___m_Data;
		NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* L_2 = (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord4_t51AFA490F6A6C9873FA004708F05494896C54580_m645242E506FB0B1FBBD6AAAE0EE20BC0EF40B2B4(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m2671D9B443FFBBBFF0F55FDD29334005F4D566B7 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* L_0 = (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mDBBB6C81ACEBB4713F52E3F60C85DAAE8C266B99_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8* L_2 = (NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8*)(&__this->___m_Data);
		NativeArray_1_Dispose_mEA5D4D66C2560C2B30AE7518A57E06A5DB4AE4AC(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_mE886D07391485C509485D4C62EF5D0B3D63F4B44((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_m8F5702B9C4057C99EC1E6B2A3AF3EFD6859234F7 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_m572BF122881B01BA58F0828302F7C9E34FB523BD_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_m67CA1F5CA843DAE3BD9BD5CDFD7EBC3986E77C49(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_m95E72B5199719611F9C38B5BCCE072F9D0325B7D (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA L_1 = __this->___m_Data;
		NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* L_2 = (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord5_tE358DE82F1D37D33E97995A7B5FB9E00F1E28EFD_mC629E255F0C1F0E46757EFE5CDF1BEBC9FBFE9A0(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m9C1194F335E44F1D6EF248754A73C2A838AA9AA2 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* L_0 = (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m85CFF2F73D5E5706F85BCBB1037485A7026A9225_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA* L_2 = (NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA*)(&__this->___m_Data);
		NativeArray_1_Dispose_m5EEF21AC693AEF53DABCEEB364E77D6D61220E83(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m0B10F9B756186EF986E6BD73FC5921B5A8A9FD38((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_m3441C7B8E504C247CE3B3D9214C78F3675E2E032 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_mF121F63D53E6986D20AC484F9F772781A9CFA90D_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_m1DB52CF37090F9D45E0FE50C81E4633E62E11930(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_m4EBAE86BB00E67D030D02F8C6E7322B6B547473E (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E L_1 = __this->___m_Data;
		NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* L_2 = (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord6_t2AD1051BBDF6B66E7D396FFAA1B39C13E57D70AC_m35397E0E2ADB7CBDA7212AE66B429232A4696B73(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m50CF47884A75424BDF3FC9F4FE235CC576B12771 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* L_0 = (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m0B33F6524B69D07CD96A38E99CBEF9756FDCA6E9_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E* L_2 = (NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E*)(&__this->___m_Data);
		NativeArray_1_Dispose_mBAECB577DDA49050F519A272C019836076ECD9FD(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m67F10B4C117E273AE2F136F5DDB7E704CC398C9A((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_mDC4F9E39E85F329A663F5AB3C47CC0786923D217 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_mBC94888599C0A0E9E128E4D0E17AE100FFA4A630_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_m83430940690F9260E4A94BDC76079F2BD09BB821(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_m9FE10D3CE7D820ED955BE67EF226C0C7601EFE49 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 L_1 = __this->___m_Data;
		NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* L_2 = (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord7_t12B2801C4A9C33E067902786D20AEE2FC6A904D2_m094968E374812A79B98FA421AAE34A213DAC3F8E(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_mA3328F41B58098FFCFCD58D348F60A94F1CA89CC (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* L_0 = (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mFC27630889FC60D66A3668AE44D67DB24B6C66C5_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172* L_2 = (NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172*)(&__this->___m_Data);
		NativeArray_1_Dispose_m5D81A285AB38F20DA55BBB23574DCB0B284CD393(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5(__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline(__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m80162E0F1B413106BBBFA95DA99212E07AD6C268((&L_3), L_2, 4, 1, NULL);
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_mCCEAD53F52205F93FB34FDBC6DA36DC597492EAC (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 L_0 = __this->___m_Data;
		void* L_1;
		L_1 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mEFBEC242CAB99A188E6C97C3FC1012FAACEB69F6_inline(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = VertexBufferTexCoords_1_GetUvsJob_m7215A2D5310683F4B136223DE51A4685018980E0(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_m13EC78F6DA381A80C8DD5F3B9CAF3C300E0CE197 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 L_1 = __this->___m_Data;
		NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* L_2 = (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		Mesh_SetVertexBufferData_TisVTexCoord8_t1B079585887E52F75BB2C8ADFF46102E02C6E23D_mF633A59BB6BC13197FF8A0F0BF9341D99502C9AA(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m76C9F3E9654874FA0170EA455E45D4325FB6110C (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* L_0 = (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m11434044E5DFD0B1936B1F1E00B07A845CE370F4_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827* L_2 = (NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827*)(&__this->___m_Data);
		NativeArray_1_Dispose_mEF42F18D1E3ECE038A60D82B2DBBA2F8B4316FE0(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m293A2CF1E0B878C37E655CEA2471A254F36D7C74_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___2_logger;
		VertexBufferTexCoordsBase__ctor_mA682BA6A3A3EC590E91298EFFA1CD36D561550C5((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this, L_0, NULL);
		int32_t L_1 = ___0_uvSetCount;
		VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this, L_1, NULL);
		int32_t L_2 = ___1_vertexCount;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_3;
		memset((&L_3), 0, sizeof(L_3));
		NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1((&L_3), L_2, 4, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__this->___m_Data = L_3;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferTexCoords_1_ScheduleVertexUVJobs_m8083DA7EE4A52DC484D96F777DF6B62944277158_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, int32_t ___0_offset, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___1_uvAccessorIndices, NativeSlice_1_t7591FC942F923C6C3D5066DBCE25E2B91AAD3BD8 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		s_Il2CppMethodInitialized = true;
	}
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_4 = NULL;
	void* V_5 = NULL;
	int32_t V_6 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_7;
	memset((&V_7), 0, sizeof(V_7));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_0 = __this->___m_Data;
		void* L_1;
		L_1 = ((  void* (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1)))(L_0, NULL);
		V_0 = (uint8_t*)L_1;
		int32_t L_2;
		L_2 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this, NULL);
		uint32_t L_3 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		V_1 = ((int32_t)il2cpp_codegen_multiply(L_2, (int32_t)L_3));
		V_2 = 0;
		goto IL_00af;
	}

IL_0021:
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_4 = ___1_uvAccessorIndices;
		int32_t L_5 = V_2;
		int32_t L_6 = L_5;
		int32_t L_7 = (L_4)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_6));
		V_3 = L_7;
		RuntimeObject* L_8 = ___3_buffers;
		int32_t L_9 = V_3;
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_8, L_9, (&V_4), (&V_5), (&V_6));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_4;
		bool L_11;
		L_11 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_10, NULL);
		if (!L_11)
		{
			goto IL_005f;
		}
	}
	{
		RuntimeObject* L_12 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_13 = L_12;
		if (L_13)
		{
			G_B4_0 = L_13;
			goto IL_0048;
		}
		G_B3_0 = L_13;
	}
	{
		goto IL_005d;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_14 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_15 = L_14;
		(L_15)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralE099E35199E899B7796FB5803C6465BF879088CC);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)42), L_15);
	}

IL_005d:
	{
		return (bool)0;
	}

IL_005f:
	{
		void* L_16 = V_5;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17 = V_4;
		int32_t L_18 = L_17->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_19 = V_4;
		int32_t L_20 = L_19->___componentType;
		int32_t L_21 = V_6;
		uint8_t* L_22 = V_0;
		int32_t L_23 = V_1;
		int32_t L_24 = ___0_offset;
		int32_t L_25 = V_2;
		uint32_t L_26 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		int32_t L_27 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_28 = V_4;
		bool L_29 = L_28->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_30;
		L_30 = ((  Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 (*) (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0*, void*, int32_t, int32_t, int32_t, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*, int32_t, bool, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(__this, L_16, L_18, L_20, L_21, (float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_22, ((int32_t)il2cpp_codegen_multiply(L_23, L_24)))), ((int32_t)il2cpp_codegen_multiply(L_25, (int32_t)L_26)))), L_27, L_29, NULL);
		V_7 = L_30;
		bool L_31;
		L_31 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_7), NULL);
		if (!L_31)
		{
			goto IL_00a9;
		}
	}
	{
		int32_t L_32 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_33;
		L_33 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_7), NULL);
		NativeSlice_1_set_Item_m4136C1EFFCBE42A205C02C31DF940F5950F69E2A((&___2_handles), L_32, L_33, NULL);
		goto IL_00ab;
	}

IL_00a9:
	{
		return (bool)0;
	}

IL_00ab:
	{
		int32_t L_34 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_34, 1));
	}

IL_00af:
	{
		int32_t L_35 = V_2;
		int32_t L_36;
		L_36 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this, NULL);
		if ((((int32_t)L_35) < ((int32_t)L_36)))
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_AddDescriptors_mE861661D31FA2A1BBAE96404972146EAD9A53DA1_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_dst, int32_t* ___1_offset, int32_t ___2_stream, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		V_0 = 0;
		goto IL_0023;
	}

IL_0004:
	{
		int32_t L_0 = V_0;
		V_1 = ((int32_t)il2cpp_codegen_add(4, L_0));
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_1 = ___0_dst;
		int32_t* L_2 = ___1_offset;
		int32_t L_3 = il2cpp_codegen_ldind<int32_t, int32_t>(L_2);
		int32_t L_4 = V_1;
		int32_t L_5 = ___2_stream;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_6;
		memset((&L_6), 0, sizeof(L_6));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_6), L_4, 0, 2, L_5, NULL);
		(L_1)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_6);
		int32_t* L_7 = ___1_offset;
		int32_t* L_8 = ___1_offset;
		int32_t L_9 = il2cpp_codegen_ldind<int32_t, int32_t>(L_8);
		il2cpp_codegen_stind<int32_t>((int32_t*)L_7, (int32_t)((int32_t)il2cpp_codegen_add(L_9, 1)));
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0023:
	{
		int32_t L_11 = V_0;
		int32_t L_12;
		L_12 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this, NULL);
		if ((((int32_t)L_11) < ((int32_t)L_12)))
		{
			goto IL_0004;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_ApplyOnMesh_m4C9622E33527A139B708E1CE424C906B495B301F_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) 
{
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_0 = ___0_msh;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_1 = __this->___m_Data;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 3)))(L_2, NULL);
		int32_t L_4 = ___1_stream;
		int32_t L_5 = ___2_flags;
		((  void (*) (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_0, L_1, 0, 0, L_3, L_4, L_5, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1_Dispose_m38E3F170DABBCF85AA1E08F071BA6A23FA39AF82_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_0 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		bool L_1;
		L_1 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
	}

IL_0018:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferTexCoords_1_GetUvsJob_m9C664A1835C3E36BD6BAF3F496E0C820FBB8C5F9_fshared (VertexBufferTexCoords_1_t79E195CDADDB2290A9B415FE7D84F5458D0308A0* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GltfComponentType_tB7CCE9FF3B728EE7957568DA30CA8DCAC1E5CA34_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89_mB9039BDE0A62F3298ED76214B72CE46918C8255A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B_mF1D66E1214EC89ABA3AEBF8304CD6A6453ED5049_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB_mE812841C0A243B763E58AADEDE363162B8D50FB7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B_m048136BB9B52441F8CF46CFFC41E6720F229F96F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5_mE7423E2E6337C573F2A7EC531FC975B10BBC1B60_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C_m494DE9D0608D39869661FD2A829DB0D523FE094B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB_m9E18CF080F3709EFBE44FCCAA5F7E87763E609E5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForExtensions_Schedule_TisConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA_m8A8F9336ED94EAB202DA66E950B1CE9D85DAB850_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IJobParallelForExtensions_Schedule_TisConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1_mF44365369C2DA0F87C1A1DD4493B59A812AACC9E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF25A18EECC3B71FE7DC49876B54488AEC789DC3D);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 V_1;
	memset((&V_1), 0, sizeof(V_1));
	ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 V_2;
	memset((&V_2), 0, sizeof(V_2));
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_3;
	memset((&V_3), 0, sizeof(V_3));
	ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 V_4;
	memset((&V_4), 0, sizeof(V_4));
	ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 V_5;
	memset((&V_5), 0, sizeof(V_5));
	ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB V_6;
	memset((&V_6), 0, sizeof(V_6));
	ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB V_7;
	memset((&V_7), 0, sizeof(V_7));
	ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA V_8;
	memset((&V_8), 0, sizeof(V_8));
	ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA V_9;
	memset((&V_9), 0, sizeof(V_9));
	ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C V_10;
	memset((&V_10), 0, sizeof(V_10));
	ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C V_11;
	memset((&V_11), 0, sizeof(V_11));
	ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB V_12;
	memset((&V_12), 0, sizeof(V_12));
	ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB V_13;
	memset((&V_13), 0, sizeof(V_13));
	ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B V_14;
	memset((&V_14), 0, sizeof(V_14));
	ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B V_15;
	memset((&V_15), 0, sizeof(V_15));
	ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 V_16;
	memset((&V_16), 0, sizeof(V_16));
	ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 V_17;
	memset((&V_17), 0, sizeof(V_17));
	ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B V_18;
	memset((&V_18), 0, sizeof(V_18));
	ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B V_19;
	memset((&V_19), 0, sizeof(V_19));
	ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89* G_B4_0 = NULL;
	ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89* G_B3_0 = NULL;
	uint32_t G_B5_0 = 0;
	ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89* G_B5_1 = NULL;
	ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1* G_B9_0 = NULL;
	ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1* G_B8_0 = NULL;
	int32_t G_B10_0 = 0;
	ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1* G_B10_1 = NULL;
	ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB* G_B13_0 = NULL;
	ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB* G_B12_0 = NULL;
	int32_t G_B14_0 = 0;
	ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB* G_B14_1 = NULL;
	ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA* G_B18_0 = NULL;
	ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA* G_B17_0 = NULL;
	int32_t G_B19_0 = 0;
	ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA* G_B19_1 = NULL;
	ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C* G_B22_0 = NULL;
	ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C* G_B21_0 = NULL;
	int32_t G_B23_0 = 0;
	ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C* G_B23_1 = NULL;
	ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB* G_B27_0 = NULL;
	ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB* G_B26_0 = NULL;
	int32_t G_B28_0 = 0;
	ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB* G_B28_1 = NULL;
	ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B* G_B31_0 = NULL;
	ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B* G_B30_0 = NULL;
	int32_t G_B32_0 = 0;
	ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B* G_B32_1 = NULL;
	ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5* G_B36_0 = NULL;
	ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5* G_B35_0 = NULL;
	int32_t G_B37_0 = 0;
	ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5* G_B37_1 = NULL;
	ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B* G_B40_0 = NULL;
	ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B* G_B39_0 = NULL;
	int32_t G_B41_0 = 0;
	ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B* G_B41_1 = NULL;
	RuntimeObject* G_B44_0 = NULL;
	RuntimeObject* G_B43_0 = NULL;
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		int32_t L_0 = ___2_inputType;
		switch (((int32_t)il2cpp_codegen_subtract((int32_t)L_0, ((int32_t)5120))))
		{
			case 0:
			{
				goto IL_02b2;
			}
			case 1:
			{
				goto IL_0090;
			}
			case 2:
			{
				goto IL_01fc;
			}
			case 3:
			{
				goto IL_0146;
			}
			case 4:
			{
				goto IL_0365;
			}
			case 5:
			{
				goto IL_0365;
			}
			case 6:
			{
				goto IL_0035;
			}
		}
	}
	{
		goto IL_0365;
	}

IL_0035:
	{
		il2cpp_codegen_initobj((&V_2), sizeof(ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89));
		int32_t L_1 = ___3_inputByteStride;
		if ((((int32_t)L_1) > ((int32_t)0)))
		{
			G_B4_0 = (&V_2);
			goto IL_004c;
		}
		G_B3_0 = (&V_2);
	}
	{
		uint32_t L_2 = sizeof(float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5);
		G_B5_0 = L_2;
		G_B5_1 = G_B3_0;
		goto IL_004e;
	}

IL_004c:
	{
		int32_t L_3 = ___3_inputByteStride;
		G_B5_0 = ((uint32_t)(L_3));
		G_B5_1 = G_B4_0;
	}

IL_004e:
	{
		G_B5_1->___inputByteStride = (int32_t)G_B5_0;
		void* L_4 = ___0_input;
		(&V_2)->___input = (uint8_t*)L_4;
		int32_t L_5 = ___5_outputByteStride;
		(&V_2)->___outputByteStride = L_5;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_6 = ___4_output;
		(&V_2)->___result = L_6;
		ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 L_7 = V_2;
		V_1 = L_7;
		ConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89 L_8 = V_1;
		int32_t L_9 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_11;
		L_11 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89_mB9039BDE0A62F3298ED76214B72CE46918C8255A(L_8, L_9, ((int32_t)512), L_10, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsFloatToFloatInterleavedJob_t6E0677FF814369772F0F1090A4312E6D488D8A89_mB9039BDE0A62F3298ED76214B72CE46918C8255A_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_11, NULL);
		goto IL_0396;
	}

IL_0090:
	{
		bool L_12 = ___6_normalized;
		if (!L_12)
		{
			goto IL_00ed;
		}
	}
	{
		il2cpp_codegen_initobj((&V_5), sizeof(ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1));
		int32_t L_13 = ___3_inputByteStride;
		if ((((int32_t)L_13) > ((int32_t)0)))
		{
			G_B9_0 = (&V_5);
			goto IL_00a6;
		}
		G_B8_0 = (&V_5);
	}
	{
		G_B10_0 = 2;
		G_B10_1 = G_B8_0;
		goto IL_00a8;
	}

IL_00a6:
	{
		int32_t L_14 = ___3_inputByteStride;
		G_B10_0 = L_14;
		G_B10_1 = G_B9_0;
	}

IL_00a8:
	{
		G_B10_1->___inputByteStride = G_B10_0;
		void* L_15 = ___0_input;
		(&V_5)->___input = (uint8_t*)L_15;
		int32_t L_16 = ___5_outputByteStride;
		(&V_5)->___outputByteStride = L_16;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_17 = ___4_output;
		(&V_5)->___result = L_17;
		ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 L_18 = V_5;
		V_4 = L_18;
		ConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1 L_19 = V_4;
		int32_t L_20 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_21 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_22;
		L_22 = IJobParallelForExtensions_Schedule_TisConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1_mF44365369C2DA0F87C1A1DD4493B59A812AACC9E(L_19, L_20, ((int32_t)512), L_21, IJobParallelForExtensions_Schedule_TisConvertUVsUInt8ToFloatInterleavedNormalizedJob_t0CE4884558CC313B747A01AFD04C9EEC7A9394E1_mF44365369C2DA0F87C1A1DD4493B59A812AACC9E_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_22, NULL);
		goto IL_0396;
	}

IL_00ed:
	{
		il2cpp_codegen_initobj((&V_7), sizeof(ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB));
		int32_t L_23 = ___3_inputByteStride;
		if ((((int32_t)L_23) > ((int32_t)0)))
		{
			G_B13_0 = (&V_7);
			goto IL_00ff;
		}
		G_B12_0 = (&V_7);
	}
	{
		G_B14_0 = 2;
		G_B14_1 = G_B12_0;
		goto IL_0101;
	}

IL_00ff:
	{
		int32_t L_24 = ___3_inputByteStride;
		G_B14_0 = L_24;
		G_B14_1 = G_B13_0;
	}

IL_0101:
	{
		G_B14_1->___inputByteStride = G_B14_0;
		void* L_25 = ___0_input;
		(&V_7)->___input = (uint8_t*)L_25;
		int32_t L_26 = ___5_outputByteStride;
		(&V_7)->___outputByteStride = L_26;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_27 = ___4_output;
		(&V_7)->___result = L_27;
		ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB L_28 = V_7;
		V_6 = L_28;
		ConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB L_29 = V_6;
		int32_t L_30 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_31 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_32;
		L_32 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB_m9E18CF080F3709EFBE44FCCAA5F7E87763E609E5(L_29, L_30, ((int32_t)512), L_31, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt8ToFloatInterleavedJob_t66FF22C4D8270F5A2E90D543E1CF1439DC2CA0BB_m9E18CF080F3709EFBE44FCCAA5F7E87763E609E5_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_32, NULL);
		goto IL_0396;
	}

IL_0146:
	{
		bool L_33 = ___6_normalized;
		if (!L_33)
		{
			goto IL_01a3;
		}
	}
	{
		il2cpp_codegen_initobj((&V_9), sizeof(ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA));
		int32_t L_34 = ___3_inputByteStride;
		if ((((int32_t)L_34) > ((int32_t)0)))
		{
			G_B18_0 = (&V_9);
			goto IL_015c;
		}
		G_B17_0 = (&V_9);
	}
	{
		G_B19_0 = 4;
		G_B19_1 = G_B17_0;
		goto IL_015e;
	}

IL_015c:
	{
		int32_t L_35 = ___3_inputByteStride;
		G_B19_0 = L_35;
		G_B19_1 = G_B18_0;
	}

IL_015e:
	{
		G_B19_1->___inputByteStride = G_B19_0;
		void* L_36 = ___0_input;
		(&V_9)->___input = (uint8_t*)L_36;
		int32_t L_37 = ___5_outputByteStride;
		(&V_9)->___outputByteStride = L_37;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_38 = ___4_output;
		(&V_9)->___result = L_38;
		ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA L_39 = V_9;
		V_8 = L_39;
		ConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA L_40 = V_8;
		int32_t L_41 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_42 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_43;
		L_43 = IJobParallelForExtensions_Schedule_TisConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA_m8A8F9336ED94EAB202DA66E950B1CE9D85DAB850(L_40, L_41, ((int32_t)512), L_42, IJobParallelForExtensions_Schedule_TisConvertUVsUInt16ToFloatInterleavedNormalizedJob_t55E7D37CC67ED8C82ECB3FF1BD3D831469F2B3DA_m8A8F9336ED94EAB202DA66E950B1CE9D85DAB850_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_43, NULL);
		goto IL_0396;
	}

IL_01a3:
	{
		il2cpp_codegen_initobj((&V_11), sizeof(ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C));
		int32_t L_44 = ___3_inputByteStride;
		if ((((int32_t)L_44) > ((int32_t)0)))
		{
			G_B22_0 = (&V_11);
			goto IL_01b5;
		}
		G_B21_0 = (&V_11);
	}
	{
		G_B23_0 = 4;
		G_B23_1 = G_B21_0;
		goto IL_01b7;
	}

IL_01b5:
	{
		int32_t L_45 = ___3_inputByteStride;
		G_B23_0 = L_45;
		G_B23_1 = G_B22_0;
	}

IL_01b7:
	{
		G_B23_1->___inputByteStride = G_B23_0;
		void* L_46 = ___0_input;
		(&V_11)->___input = (uint8_t*)L_46;
		int32_t L_47 = ___5_outputByteStride;
		(&V_11)->___outputByteStride = L_47;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_48 = ___4_output;
		(&V_11)->___result = L_48;
		ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C L_49 = V_11;
		V_10 = L_49;
		ConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C L_50 = V_10;
		int32_t L_51 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_52 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_53;
		L_53 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C_m494DE9D0608D39869661FD2A829DB0D523FE094B(L_50, L_51, ((int32_t)512), L_52, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsUInt16ToFloatInterleavedJob_tB98A497510FC2E2713281D2CA95C357121F3731C_m494DE9D0608D39869661FD2A829DB0D523FE094B_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_53, NULL);
		goto IL_0396;
	}

IL_01fc:
	{
		bool L_54 = ___6_normalized;
		if (!L_54)
		{
			goto IL_0259;
		}
	}
	{
		il2cpp_codegen_initobj((&V_13), sizeof(ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB));
		int32_t L_55 = ___3_inputByteStride;
		if ((((int32_t)L_55) > ((int32_t)0)))
		{
			G_B27_0 = (&V_13);
			goto IL_0212;
		}
		G_B26_0 = (&V_13);
	}
	{
		G_B28_0 = 4;
		G_B28_1 = G_B26_0;
		goto IL_0214;
	}

IL_0212:
	{
		int32_t L_56 = ___3_inputByteStride;
		G_B28_0 = L_56;
		G_B28_1 = G_B27_0;
	}

IL_0214:
	{
		G_B28_1->___inputByteStride = G_B28_0;
		void* L_57 = ___0_input;
		(&V_13)->___input = (int16_t*)L_57;
		int32_t L_58 = ___5_outputByteStride;
		(&V_13)->___outputByteStride = L_58;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_59 = ___4_output;
		(&V_13)->___result = L_59;
		ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB L_60 = V_13;
		V_12 = L_60;
		ConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB L_61 = V_12;
		int32_t L_62 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_63 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_64;
		L_64 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB_mE812841C0A243B763E58AADEDE363162B8D50FB7(L_61, L_62, ((int32_t)512), L_63, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedNormalizedJob_tCD3AB5CA56CE6A0BF5D79BC364D4C191EF1EA1CB_mE812841C0A243B763E58AADEDE363162B8D50FB7_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_64, NULL);
		goto IL_0396;
	}

IL_0259:
	{
		il2cpp_codegen_initobj((&V_15), sizeof(ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B));
		int32_t L_65 = ___3_inputByteStride;
		if ((((int32_t)L_65) > ((int32_t)0)))
		{
			G_B31_0 = (&V_15);
			goto IL_026b;
		}
		G_B30_0 = (&V_15);
	}
	{
		G_B32_0 = 4;
		G_B32_1 = G_B30_0;
		goto IL_026d;
	}

IL_026b:
	{
		int32_t L_66 = ___3_inputByteStride;
		G_B32_0 = L_66;
		G_B32_1 = G_B31_0;
	}

IL_026d:
	{
		G_B32_1->___inputByteStride = G_B32_0;
		void* L_67 = ___0_input;
		(&V_15)->___input = (int16_t*)L_67;
		int32_t L_68 = ___5_outputByteStride;
		(&V_15)->___outputByteStride = L_68;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_69 = ___4_output;
		(&V_15)->___result = L_69;
		ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B L_70 = V_15;
		V_14 = L_70;
		ConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B L_71 = V_14;
		int32_t L_72 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_73 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_74;
		L_74 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B_mF1D66E1214EC89ABA3AEBF8304CD6A6453ED5049(L_71, L_72, ((int32_t)512), L_73, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt16ToFloatInterleavedJob_tA6EB65E57B040AC71C8BFCC308A50E423B86365B_mF1D66E1214EC89ABA3AEBF8304CD6A6453ED5049_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_74, NULL);
		goto IL_0396;
	}

IL_02b2:
	{
		bool L_75 = ___6_normalized;
		if (!L_75)
		{
			goto IL_030f;
		}
	}
	{
		il2cpp_codegen_initobj((&V_17), sizeof(ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5));
		int32_t L_76 = ___3_inputByteStride;
		if ((((int32_t)L_76) > ((int32_t)0)))
		{
			G_B36_0 = (&V_17);
			goto IL_02c8;
		}
		G_B35_0 = (&V_17);
	}
	{
		G_B37_0 = 2;
		G_B37_1 = G_B35_0;
		goto IL_02ca;
	}

IL_02c8:
	{
		int32_t L_77 = ___3_inputByteStride;
		G_B37_0 = L_77;
		G_B37_1 = G_B36_0;
	}

IL_02ca:
	{
		G_B37_1->___inputByteStride = G_B37_0;
		void* L_78 = ___0_input;
		(&V_17)->___input = (int8_t*)L_78;
		int32_t L_79 = ___5_outputByteStride;
		(&V_17)->___outputByteStride = L_79;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_80 = ___4_output;
		(&V_17)->___result = L_80;
		ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 L_81 = V_17;
		V_16 = L_81;
		ConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5 L_82 = V_16;
		int32_t L_83 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_84 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_85;
		L_85 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5_mE7423E2E6337C573F2A7EC531FC975B10BBC1B60(L_82, L_83, ((int32_t)512), L_84, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedNormalizedJob_t6DF1ED634DC0F94F9BC44A20BFEBD40E507F9EC5_mE7423E2E6337C573F2A7EC531FC975B10BBC1B60_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_85, NULL);
		goto IL_0396;
	}

IL_030f:
	{
		il2cpp_codegen_initobj((&V_19), sizeof(ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B));
		int32_t L_86 = ___3_inputByteStride;
		if ((((int32_t)L_86) > ((int32_t)0)))
		{
			G_B40_0 = (&V_19);
			goto IL_0321;
		}
		G_B39_0 = (&V_19);
	}
	{
		G_B41_0 = 2;
		G_B41_1 = G_B39_0;
		goto IL_0323;
	}

IL_0321:
	{
		int32_t L_87 = ___3_inputByteStride;
		G_B41_0 = L_87;
		G_B41_1 = G_B40_0;
	}

IL_0323:
	{
		G_B41_1->___inputByteStride = G_B41_0;
		void* L_88 = ___0_input;
		(&V_19)->___input = (int8_t*)L_88;
		int32_t L_89 = ___5_outputByteStride;
		(&V_19)->___outputByteStride = L_89;
		float2_t3398D7209CB6D09FEA5C49AC55070C5E7BE0B2A5* L_90 = ___4_output;
		(&V_19)->___result = L_90;
		ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B L_91 = V_19;
		V_18 = L_91;
		ConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B L_92 = V_18;
		int32_t L_93 = ___1_count;
		il2cpp_codegen_initobj((&V_3), sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_94 = V_3;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_95;
		L_95 = IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B_m048136BB9B52441F8CF46CFFC41E6720F229F96F(L_92, L_93, ((int32_t)512), L_94, IJobParallelForBatchExtensions_ScheduleBatch_TisConvertUVsInt8ToFloatInterleavedJob_t1875D3CA8BCEA0953FDD159DA7E2DD05552F403B_m048136BB9B52441F8CF46CFFC41E6720F229F96F_RuntimeMethod_var);
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&V_0), L_95, NULL);
		goto IL_0396;
	}

IL_0365:
	{
		RuntimeObject* L_96 = ((VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0*)__this)->___m_Logger;
		RuntimeObject* L_97 = L_96;
		if (L_97)
		{
			G_B44_0 = L_97;
			goto IL_0371;
		}
		G_B43_0 = L_97;
	}
	{
		goto IL_0396;
	}

IL_0371:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_98 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)2);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_99 = L_98;
		(L_99)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralF25A18EECC3B71FE7DC49876B54488AEC789DC3D);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_100 = L_99;
		Il2CppFakeBox<int32_t> L_101(GltfComponentType_tB7CCE9FF3B728EE7957568DA30CA8DCAC1E5CA34_il2cpp_TypeInfo_var, ___2_inputType);
		String_t* L_102;
		L_102 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_101), NULL);
		(L_100)->SetAtUnchecked(static_cast<il2cpp_array_size_t>(1), (String_t*)L_102);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B44_0, ((int32_t)49), L_100);
	}

IL_0396:
	{
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_103 = V_0;
		return L_103;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m2DF2E9240755AD44CD007215336336988FB94970_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = ___0_target;
		WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E(__this, L_0, (bool)0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m56E7381CF8F98C0E7BAE715681E43557C38E841E_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, Il2CppSharedGenericObject* ___0_target, bool ___1_trackResurrection, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		bool L_0 = ___1_trackResurrection;
		__this->___trackResurrection = L_0;
		bool L_1 = ___1_trackResurrection;
		if (L_1)
		{
			goto IL_0013;
		}
	}
	{
		G_B3_0 = 0;
		goto IL_0014;
	}

IL_0013:
	{
		G_B3_0 = 1;
	}

IL_0014:
	{
		V_0 = G_B3_0;
		Il2CppSharedGenericObject* L_2 = ___0_target;
		int32_t L_3 = V_0;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_4;
		L_4 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC((RuntimeObject*)L_2, L_3, NULL);
		__this->___handle = L_4;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1__ctor_m26B6C20B9417150055843B01C492BE853F888ED6_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t G_B5_0 = 0;
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2((RuntimeObject*)__this, NULL);
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_0014;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_0014:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		bool L_3;
		L_3 = SerializationInfo_GetBoolean_m8335F8E11B572AB6B5BF85A9355D6888D5847EF5(L_2, _stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7, NULL);
		__this->___trackResurrection = L_3;
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_4 = ___0_info;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_5 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 1)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_6;
		L_6 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_5, NULL);
		RuntimeObject* L_7;
		L_7 = SerializationInfo_GetValue_mE6091C2E906E113455D05E734C86F43B8E1D1034(L_4, _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0, L_6, NULL);
		V_0 = L_7;
		bool L_8 = __this->___trackResurrection;
		if (L_8)
		{
			goto IL_0046;
		}
	}
	{
		G_B5_0 = 0;
		goto IL_0047;
	}

IL_0046:
	{
		G_B5_0 = 1;
	}

IL_0047:
	{
		V_1 = G_B5_0;
		RuntimeObject* L_9 = V_0;
		int32_t L_10 = V_1;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC L_11;
		L_11 = GCHandle_Alloc_m3BFD398427352FC756FFE078F01A504B681352EC(L_9, L_10, NULL);
		__this->___handle = L_11;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1_GetObjectData_m12FA42C2A3928DF070B0FB1604D23E96E650100B_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ___0_info, StreamingContext_t56760522A751890146EE45F82F866B55B7E33677 ___1_context, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7);
		s_Il2CppMethodInitialized = true;
	}
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_0 = ___0_info;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA7B00F7F25C375B2501A6ADBC86D092B23977085)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, method);
	}

IL_000e:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_2 = ___0_info;
		bool L_3 = __this->___trackResurrection;
		SerializationInfo_AddValue_mC52253CB19C98F82A26E32C941F8F20E106D4C0D(L_2, _stringLiteral7D20B8219CA0491872B2E811B262066A5DD875A7, L_3, NULL);
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_4 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		bool L_5;
		L_5 = GCHandle_get_IsAllocated_m241908103D8D867E11CCAB73C918729825E86843_inline(L_4, NULL);
		if (!L_5)
		{
			goto IL_0043;
		}
	}
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_6 = ___0_info;
		GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_7 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
		RuntimeObject* L_8;
		L_8 = GCHandle_get_Target_m481F9508DA5E384D33CD1F4450060DC56BBD4CD5_inline(L_7, NULL);
		SerializationInfo_AddValue_m28FE9B110F21DDB8FF5F5E35A0EABD659DB22C2F(L_6, _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0, L_8, NULL);
		return;
	}

IL_0043:
	{
		SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* L_9 = ___0_info;
		SerializationInfo_AddValue_m28FE9B110F21DDB8FF5F5E35A0EABD659DB22C2F(L_9, _stringLiteral5CA6E7C0AE72196B2817D93A78C719652EC691C0, NULL, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WeakReference_1_Finalize_m7E4CC88F283E425189EB1C8BC510906088E6FBE8_gshared (WeakReference_1_t1F6FA975EAE72BD674152D029627A536B687C180* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_000d:
			{
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2((RuntimeObject*)__this, NULL);
				return;
			}
		});
		try
		{
			GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC* L_0 = (GCHandle_tC44F6F72EE68BD4CFABA24309DA7A179D41127DC*)(&__this->___handle);
			GCHandle_Free_m1320A260E487EB1EA6D95F9E54BFFCB5A4EF83A3(L_0, NULL);
			goto IL_0014;
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

IL_0014:
	{
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereArrayIterator_1_Clone_mE31EE28C8C3AF73A465E9182B4EE6DA783E0DCC8_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, const RuntimeMethod* method) 
{
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* L_2 = (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F(L_2, L_0, L_1, NULL);
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m2CC945527E27709DF2A77749EF065B340B1DAABF_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, const RuntimeMethod* method) 
{
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		int32_t L_3 = L_2;
		Il2CppSharedGenericObject* L_4 = (L_1)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_6 = __this->___predicate;
		Il2CppSharedGenericObject* L_7 = V_0;
		bool L_8;
		L_8 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_6, L_7, NULL);
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		Il2CppSharedGenericObject* L_9 = V_0;
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_9);
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = __this->___index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_11 = __this->___source;
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		if ((((int32_t)L_10) < ((int32_t)L_12)))
		{
			goto IL_000b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mACF36D740BA7870CDEF62F71205CC9B7AA921FCB_gshared (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_2 = ___0_predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_3;
		L_3 = Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5(L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547* L_4 = (WhereArrayIterator_1_t1058A0FE615541593E1259BC6FD75D42B1865547*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereArrayIterator_1__ctor_m4A9B8B4E9C52A089FB47DF5F2DC936EF61EAF07F(L_4, L_0, L_3, NULL);
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereArrayIterator_1__ctor_mD8BDE04F9897AAED299EE4DC32BF3879F2CBB668_fshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_source;
		il2cpp_codegen_write_field_data<__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereArrayIterator_1_Clone_m1D80001794E47D2DF00A77273FD71D61987E8A44_fshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* L_2 = (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_2, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereArrayIterator_1_MoveNext_m42FC055181A1CDD12BBB46A9EE9ED76C6048BA07_fshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	const Il2CppFullySharedGenericAny L_9 = L_4;
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	memset(V_0, 0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_0058;
		}
	}
	{
		goto IL_0042;
	}

IL_000b:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		int32_t L_2 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7));
		int32_t L_3 = L_2;
		il2cpp_codegen_memcpy(L_4, (L_1)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		il2cpp_codegen_memcpy(V_0, L_4, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		int32_t L_5 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7));
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7), ((int32_t)il2cpp_codegen_add(L_5, 1)));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		il2cpp_codegen_memcpy(L_7, V_0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		bool L_8;
		L_8 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9), L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8)) ? L_7: *(void**)L_7));
		if (!L_8)
		{
			goto IL_0042;
		}
	}
	{
		il2cpp_codegen_memcpy(L_9, V_0, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 10), L_9, SizeOf_TSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A);
		return (bool)1;
	}

IL_0042:
	{
		int32_t L_10 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_11 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		int32_t L_12 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_11)->max_length),NULL));
		if ((((int32_t)L_10) < ((int32_t)L_12)))
		{
			goto IL_000b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0058:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereArrayIterator_1_Where_mB2C59E78355E518D359A6D5035BCD6254337B84E_fshared (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11));
		WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6* L_4 = (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereArrayIterator_1_tA7187088CE8DF4724576F6B7F633203C144505F6*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_4, L_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereEnumerableIterator_1_Clone_m147E8C6841D1F56383B65AB9442D5F8572E0C4A0_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_2 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_2, L_0, L_1, NULL);
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_mB5CFE2E915EAE2A54092B3BF72CF0AE757569B0C_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m3E17222A4C6715CC745CCE37FDA4B1F349DDA260_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 9), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		Il2CppSharedGenericObject* L_6;
		L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 11), L_5);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_1;
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, NULL);
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		Il2CppSharedGenericObject* L_10 = V_1;
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_10);
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = __this->___enumerator;
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_m6827EA1DFE793999773F608F522A3DAC4E550561_gshared (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_2 = ___0_predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_3;
		L_3 = Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5(L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_4 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_4, L_0, L_3, NULL);
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1__ctor_m2DD2BB86C5517EDD8C051BBF8CE38C43D712A8D6_fshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_0 = ___0_source;
		il2cpp_codegen_write_field_data<RuntimeObject*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereEnumerableIterator_1_Clone_m0317D203B88386A9A479C72FA9D62763FD0A91D3_fshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_2 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_2, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereEnumerableIterator_1_Dispose_m2583FECFDC8EDFE66C959C7C386F99E287C5763E_fshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		il2cpp_codegen_write_field_data<RuntimeObject*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5), (RuntimeObject*)NULL);
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereEnumerableIterator_1_MoveNext_m1A18D4050C069B6C4310DAB9857281E37DCB2C69_fshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	const Il2CppFullySharedGenericAny L_10 = L_6;
	const Il2CppFullySharedGenericAny L_8 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	memset(V_1, 0, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 8));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		RuntimeObject* L_3 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 9), L_3);
		il2cpp_codegen_write_field_data<RuntimeObject*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5), L_4);
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 8), 2);
		goto IL_004e;
	}

IL_002b:
	{
		RuntimeObject* L_5 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 11), L_5, (Il2CppFullySharedGenericAny*)L_6);
		il2cpp_codegen_memcpy(V_1, L_6, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		il2cpp_codegen_memcpy(L_8, V_1, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 13)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		il2cpp_codegen_memcpy(L_10, V_1, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 7),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 15), L_10, SizeOf_TSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB);
		return (bool)1;
	}

IL_004e:
	{
		RuntimeObject* L_11 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 5));
		bool L_12;
		L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_11);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereEnumerableIterator_1_Where_mC623267514B4299E409A01161DBBDA5362CEDFC2_fshared (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16)))(L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_4 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_4, L_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereListIterator_1_Clone_mD1DC0907762FD59A96CDD4DDC5DF1C2BB20818A8_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, const RuntimeMethod* method) 
{
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* L_2 = (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A(L_2, L_0, L_1, NULL);
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mA5874C778A5BE1094329ADAA040BFD8EDD1FBCE0_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_3 = __this->___source;
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_4;
		L_4 = List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9(L_3, NULL);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_004e;
	}

IL_002b:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_5 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		Il2CppSharedGenericObject* L_6;
		L_6 = Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline(L_5, NULL);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_1;
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, NULL);
		if (!L_9)
		{
			goto IL_004e;
		}
	}
	{
		Il2CppSharedGenericObject* L_10 = V_1;
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_10;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_10);
		return (bool)1;
	}

IL_004e:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_11 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		bool L_12;
		L_12 = Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25(L_11, NULL);
		if (L_12)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_m14EE1FAA82AE63BE42B030236807F4DA4B8D5520_gshared (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_2 = ___0_predicate;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_3;
		L_3 = Enumerable_CombinePredicates_TisIl2CppSharedGenericObject_mB19C4BC845EA4B1A994D49127DEAD390E9D1D3F5(L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121* L_4 = (WhereListIterator_1_tD6AC6F805CA10186E04E5B47FB806E4B91D79121*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereListIterator_1__ctor_m02289C26CC479D5E26D8B625E633C0EB9BC4F00A(L_4, L_0, L_3, NULL);
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereListIterator_1__ctor_mC075454926AF320E4679335A1B81D3F56ACEFC0C_fshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___0_source;
		il2cpp_codegen_write_field_data<List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_1);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereListIterator_1_Clone_mAA3ED56493E5FF2F49FE37EB7CDF6C0A957698B5_fshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, const RuntimeMethod* method) 
{
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* L_2 = (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_2, L_0, L_1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereListIterator_1_MoveNext_mB5E4EB089AD8CF7156B8972C7FB61739C466ED5E_fshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11));
	const uint32_t SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	const Il2CppFullySharedGenericAny L_9 = L_5;
	const Il2CppFullySharedGenericAny L_7 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_4 = alloca(SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	memset(V_1, 0, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_004e;
		}
	}
	{
		goto IL_0061;
	}

IL_0011:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_3 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		InvokerActionInvoker1< Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7), L_3, (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_4);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 9), L_4, SizeOf_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E);
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6), 2);
		goto IL_004e;
	}

IL_002b:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10), (((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 9)))), (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_1, L_5, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		il2cpp_codegen_memcpy(L_7, V_1, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		bool L_8;
		L_8 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12), L_6, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 11)) ? L_7: *(void**)L_7));
		if (!L_8)
		{
			goto IL_004e;
		}
	}
	{
		il2cpp_codegen_memcpy(L_9, V_1, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 5),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 13), L_9, SizeOf_TSource_t85B7C93A555823AE666813BFFC5FEC432E108956);
		return (bool)1;
	}

IL_004e:
	{
		bool L_10;
		L_10 = ((  bool (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))((((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 9)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		if (L_10)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0061:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereListIterator_1_Where_mC767815DE2249E70B38D6D172A0C61B028D7A44B_fshared (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_2 = ___0_predicate;
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_3;
		L_3 = ((  Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* (*) (Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0* L_4 = (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereListIterator_1_tD37742ECD2F53395BA8B668C2671C4C82E8E85F0*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4)))(L_4, L_0, L_3, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 4));
		return (RuntimeObject*)L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectArrayIterator_2_Clone_m129509AA57628EC2BAACE1BAD0FE298C284E14FA_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, const RuntimeMethod* method) 
{
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = __this->___selector;
		WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* L_3 = (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereSelectArrayIterator_2__ctor_m26CDB54B705AA05B43649E3E7388F4EBBE61B120(L_3, L_0, L_1, L_2, NULL);
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_m2D19DEC399673E08D0C217881BF0416EEE5356E9_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, const RuntimeMethod* method) 
{
	Il2CppSharedGenericObject* V_0 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_1 = __this->___source;
		int32_t L_2 = __this->___index;
		int32_t L_3 = L_2;
		Il2CppSharedGenericObject* L_4 = (L_1)->GetAtUnchecked(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		int32_t L_5 = __this->___index;
		__this->___index = ((int32_t)il2cpp_codegen_add(L_5, 1));
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_6 = __this->___predicate;
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		Il2CppSharedGenericObject* L_8 = V_0;
		bool L_9;
		L_9 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_7, L_8, NULL);
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_10 = __this->___selector;
		Il2CppSharedGenericObject* L_11 = V_0;
		Il2CppSharedGenericObject* L_12;
		L_12 = Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline(L_10, L_11, NULL);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_12);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = __this->___index;
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_14 = __this->___source;
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mFB641A55162A05D1965399C37BE6A3C15EA3992F_gshared (WhereSelectArrayIterator_2_t683CE530AC127C0638FB749D7F6917FA13DAA375* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 14));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, NULL);
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectArrayIterator_2__ctor_mB15DB27A8DC3B4E00BCA6E8F63F00F7E374F76A4_fshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = ___0_source;
		il2cpp_codegen_write_field_data<__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4), L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectArrayIterator_2_Clone_mFBF81AE0E2B6F7A7A79FC98398E7A6AC0FD330E9_fshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, const RuntimeMethod* method) 
{
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_0 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* L_3 = (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174*, __Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectArrayIterator_2_MoveNext_mEF7E8E7B117D6D1147C53CAE838836974171392C_fshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
	const uint32_t SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12));
	const Il2CppFullySharedGenericAny L_4 = alloca(SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	const Il2CppFullySharedGenericAny L_8 = L_4;
	const Il2CppFullySharedGenericAny L_11 = L_4;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425);
	Il2CppFullySharedGenericAny V_0 = alloca(SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	memset(V_0, 0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7));
		if ((!(((uint32_t)L_0) == ((uint32_t)1))))
		{
			goto IL_006b;
		}
	}
	{
		goto IL_0055;
	}

IL_000b:
	{
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_1 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		int32_t L_2 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 8));
		int32_t L_3 = L_2;
		il2cpp_codegen_memcpy(L_4, (L_1)->GetAddressAtUnchecked(static_cast<il2cpp_array_size_t>(L_3)), SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		il2cpp_codegen_memcpy(V_0, L_4, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		int32_t L_5 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 8));
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 8), ((int32_t)il2cpp_codegen_add(L_5, 1)));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		if (!L_6)
		{
			goto IL_0041;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		il2cpp_codegen_memcpy(L_8, V_0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_0055;
		}
	}

IL_0041:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_10 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		il2cpp_codegen_memcpy(L_11, V_0, SizeOf_TSource_t21BF09076F270DC063711DE3ABB52B001A331F78);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericAny*)L_12);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 13), L_12, SizeOf_TResult_t278B55150BC17BB45D33B605F011F4D96EFE5425);
		return (bool)1;
	}

IL_0055:
	{
		int32_t L_13 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 8));
		__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC* L_14 = *(__Il2CppFullySharedGenericTypeU5BU5D_tCAB6D060972DD49223A834B7EEFEB9FE2D003BEC**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_13) < ((int32_t)L_15)))
		{
			goto IL_000b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_006b:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectArrayIterator_2_Where_mD81DB59B1D07BC8DDB099A652B22BA9C1538D7A3_fshared (WhereSelectArrayIterator_2_tBE026CE497BB8F36E31685722BBD7CB567570174* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 14));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, RuntimeObject* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		RuntimeObject* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectEnumerableIterator_2_Clone_m820E73DBEE027CB08633E586A635098AAD4B0243_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = __this->___selector;
		WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* L_3 = (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereSelectEnumerableIterator_2__ctor_mECCDD8DA6646F701A2A3D4FB5B23F8763CAB1384(L_3, L_0, L_1, L_2, NULL);
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m811F2ABD9BC8A5CEEA64C0123A2887B865BF5823_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = __this->___enumerator;
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = __this->___enumerator;
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		__this->___enumerator = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)(RuntimeObject*)NULL);
		Iterator_1_Dispose_m3FF3E0013D3AFCD08A82EF3E6376086A3EF89100((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_m1504811E695B69625751EA73048935D19FA8114E_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = __this->___source;
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 10), L_3);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___enumerator), (void*)L_4);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = __this->___enumerator;
		Il2CppSharedGenericObject* L_6;
		L_6 = InterfaceFuncInvoker0< Il2CppSharedGenericObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 12), L_5);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_8 = __this->___predicate;
		Il2CppSharedGenericObject* L_9 = V_1;
		bool L_10;
		L_10 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_11 = __this->___selector;
		Il2CppSharedGenericObject* L_12 = V_1;
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline(L_11, L_12, NULL);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = __this->___enumerator;
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mC9CB40941D1E86FB75CBB2F3A1101759C942F24F_gshared (WhereSelectEnumerableIterator_2_t7498B95D87F85E9A85C46A5E7C49DF65B0193B3C* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, NULL);
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2__ctor_m9A4AF54DC527FA1CEF8B803C8DDA5E632838B06F_fshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, RuntimeObject* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		RuntimeObject* L_0 = ___0_source;
		il2cpp_codegen_write_field_data<RuntimeObject*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4), L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectEnumerableIterator_2_Clone_mD773B8B24D1459B11BA4462A6DD68865514ADC9E_fshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* L_3 = (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectEnumerableIterator_2_Dispose_m640FAC111BC786414B40480BB03E4F84B2FFB179_fshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		if (!L_0)
		{
			goto IL_0013;
		}
	}
	{
		RuntimeObject* L_1 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, (RuntimeObject*)L_1);
	}

IL_0013:
	{
		il2cpp_codegen_write_field_data<RuntimeObject*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6), (RuntimeObject*)NULL);
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectEnumerableIterator_2_MoveNext_mB384EFAF6366166F28EDFDBA272EEC1089E1A115_fshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	const uint32_t SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 14));
	const uint32_t SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 17));
	const Il2CppFullySharedGenericAny L_6 = alloca(SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	const Il2CppFullySharedGenericAny L_9 = L_6;
	const Il2CppFullySharedGenericAny L_12 = L_6;
	const Il2CppFullySharedGenericAny L_13 = alloca(SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	memset(V_1, 0, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 9));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		RuntimeObject* L_3 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		RuntimeObject* L_4;
		L_4 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 10), L_3);
		il2cpp_codegen_write_field_data<RuntimeObject*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6), L_4);
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 9), 2);
		goto IL_0061;
	}

IL_002b:
	{
		RuntimeObject* L_5 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		InterfaceActionInvoker1Invoker< Il2CppFullySharedGenericAny* >::Invoke(0, il2cpp_rgctx_data_init(il2cpp_codegen_method_rgctx(method), 12), L_5, (Il2CppFullySharedGenericAny*)L_6);
		il2cpp_codegen_memcpy(V_1, L_6, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_8 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		il2cpp_codegen_memcpy(L_9, V_1, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		bool L_10;
		L_10 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15), L_8, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 14)) ? L_9: *(void**)L_9));
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_11 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		il2cpp_codegen_memcpy(L_12, V_1, SizeOf_TSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16), L_11, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 14)) ? L_12: *(void**)L_12), (Il2CppFullySharedGenericAny*)L_13);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 8),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 18), L_13, SizeOf_TResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520);
		return (bool)1;
	}

IL_0061:
	{
		RuntimeObject* L_14 = *(RuntimeObject**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 6));
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, (RuntimeObject*)L_14);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectEnumerableIterator_2_Where_mB8ACBBFA48460E67B18647EF16E6EE4D0BE08679_fshared (WhereSelectEnumerableIterator_2_t1FBA58379B31F544881FB4C45B2D102F32A71E1C* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 19));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 20));
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* ___0_source, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___1_predicate, Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* ___2_selector, const RuntimeMethod* method) 
{
	{
		Iterator_1__ctor_m5DFE58EF25FE086001D22A22DB4AD981515DD4CD((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this, NULL);
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = ___0_source;
		__this->___source = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___source), (void*)L_0);
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = ___1_predicate;
		__this->___predicate = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___predicate), (void*)L_1);
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = ___2_selector;
		__this->___selector = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___selector), (void*)L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32* WhereSelectListIterator_2_Clone_mA526287F988AD67F1AFD8DDA6ED50D6223EB1F01_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, const RuntimeMethod* method) 
{
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_0 = __this->___source;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_1 = __this->___predicate;
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_2 = __this->___selector;
		WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* L_3 = (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		WhereSelectListIterator_2__ctor_mED7281169C838528A02E92FA050F9B60918EB868(L_3, L_0, L_1, L_2, NULL);
		return (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_m330FDD6ED7F4BEE49DCBC8A651E09A6A353C395E_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppSharedGenericObject* V_1 = NULL;
	{
		int32_t L_0 = ((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state;
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_t6959D78D53022948E65A4FDA6291D7F38FEFA02E* L_3 = __this->___source;
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9 L_4;
		L_4 = List_1_GetEnumerator_mD48177D95D4B5D6A9D8E84E2477668C2850DD5D9(L_3, NULL);
		__this->___enumerator = L_4;
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____list), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&__this->___enumerator))->____current), (void*)NULL);
		#endif
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___state = 2;
		goto IL_0061;
	}

IL_002b:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_5 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		Il2CppSharedGenericObject* L_6;
		L_6 = Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_inline(L_5, NULL);
		V_1 = L_6;
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_7 = __this->___predicate;
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_8 = __this->___predicate;
		Il2CppSharedGenericObject* L_9 = V_1;
		bool L_10;
		L_10 = Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_inline(L_8, L_9, NULL);
		if (!L_10)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* L_11 = __this->___selector;
		Il2CppSharedGenericObject* L_12 = V_1;
		Il2CppSharedGenericObject* L_13;
		L_13 = Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_inline(L_11, L_12, NULL);
		((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this)->___current), (void*)L_13);
		return (bool)1;
	}

IL_0061:
	{
		Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* L_14 = (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9*)(&__this->___enumerator);
		bool L_15;
		L_15 = Enumerator_MoveNext_m2B096A69E95EF2C7A223BA853D66AEC59C4A5C25(L_14, NULL);
		if (L_15)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t097FE23281C8F47A8C5B6EA3CECBD0986B7E6B32*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m188F9A25121C29C31230434548BA57C395C1C9DE_gshared (WhereSelectListIterator_2_t48846732A4E5DA4823ED35B3AC44BFDCACD8F4F9* __this, Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2* L_1 = (WhereEnumerableIterator_1_t1018A44926137B37FCCA9BE3C6BF3477F22144F2*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
		WhereEnumerableIterator_1__ctor_m8DC2E0C9C8437B73783D2D9F6E2DDF2CE0F37377(L_1, (RuntimeObject*)__this, L_0, NULL);
		return (RuntimeObject*)L_1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void WhereSelectListIterator_2__ctor_m6BFCBB5460270ED1896D24DC7E3B83F4950D2140_fshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* ___0_source, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___1_predicate, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* ___2_selector, const RuntimeMethod* method) 
{
	{
		((  void (*) (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))((Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = ___0_source;
		il2cpp_codegen_write_field_data<List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),0), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2), L_0);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = ___1_predicate;
		il2cpp_codegen_write_field_data<Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3), L_1);
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = ___2_selector;
		il2cpp_codegen_write_field_data<Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4), L_2);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0* WhereSelectListIterator_2_Clone_m8EC8E684FFDC3BC579DF37C08993B7F80966639D_fshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, const RuntimeMethod* method) 
{
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_0 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_1 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_2 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* L_3 = (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1));
		((  void (*) (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336*, List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(L_3, L_0, L_1, L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5));
		return (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool WhereSelectListIterator_2_MoveNext_mBB81EEF5DFFEBDDB1AC24116FAD1D13505525569_fshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, const RuntimeMethod* method) 
{
	const uint32_t SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12));
	const uint32_t SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 9));
	const uint32_t SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05 = il2cpp_codegen_sizeof(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 15));
	const Il2CppFullySharedGenericAny L_5 = alloca(SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	const Il2CppFullySharedGenericAny L_8 = L_5;
	const Il2CppFullySharedGenericAny L_11 = L_5;
	const Il2CppFullySharedGenericAny L_12 = alloca(SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05);
	const Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF L_4 = alloca(SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716);
	int32_t V_0 = 0;
	Il2CppFullySharedGenericAny V_1 = alloca(SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	memset(V_1, 0, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
	{
		int32_t L_0 = *(int32_t*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7));
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((((int32_t)L_1) == ((int32_t)1)))
		{
			goto IL_0011;
		}
	}
	{
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) == ((int32_t)2)))
		{
			goto IL_0061;
		}
	}
	{
		goto IL_0074;
	}

IL_0011:
	{
		List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A* L_3 = *(List_1_tDBA89B0E21BAC58CFBD3C1F76E4668E3B562761A**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 2));
		InvokerActionInvoker1< Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8), L_3, (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)L_4);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 1),3), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 10), L_4, SizeOf_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716);
		il2cpp_codegen_write_field_data<int32_t, false>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6),1), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 7), 2);
		goto IL_0061;
	}

IL_002b:
	{
		InvokerActionInvoker1< Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11), (((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 10)))), (Il2CppFullySharedGenericAny*)L_5);
		il2cpp_codegen_memcpy(V_1, L_5, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_6 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		if (!L_6)
		{
			goto IL_004d;
		}
	}
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_7 = *(Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 3));
		il2cpp_codegen_memcpy(L_8, V_1, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		bool L_9;
		L_9 = InvokerFuncInvoker1< bool, Il2CppFullySharedGenericAny >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13), L_7, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)) ? L_8: *(void**)L_8));
		if (!L_9)
		{
			goto IL_0061;
		}
	}

IL_004d:
	{
		Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0* L_10 = *(Func_2_t7F5F5324CE2DDB7001B68FFE29A5D9F907139FB0**)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 4));
		il2cpp_codegen_memcpy(L_11, V_1, SizeOf_TSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3);
		InvokerActionInvoker2< Il2CppFullySharedGenericAny, Il2CppFullySharedGenericAny* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14), L_10, (il2cpp_codegen_class_is_value_type(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 12)) ? L_11: *(void**)L_11), (Il2CppFullySharedGenericAny*)L_12);
		il2cpp_codegen_write_field_data<true>(__this, il2cpp_rgctx_field(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 6),2), il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 16), L_12, SizeOf_TResult_t11AC9139084FDCB528CAF75FE5166467D3329A05);
		return (bool)1;
	}

IL_0061:
	{
		bool L_13;
		L_13 = ((  bool (*) (Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17)))((((Enumerator_tF5AC6CD19D283FBD724440520CEE68FE2602F7AF*)il2cpp_codegen_get_field_data_pointer(__this, il2cpp_rgctx_offset(il2cpp_codegen_method_rgctx(method), 10)))), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 17));
		if (L_13)
		{
			goto IL_002b;
		}
	}
	{
		VirtualActionInvoker0::Invoke(12, (Iterator_1_t0F1D8198E840368AC82131EC1FF03EB76BCE73B0*)__this);
	}

IL_0074:
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* WhereSelectListIterator_2_Where_m1739BDD134D3AF5A55DBB06AEE130B0C58E47014_fshared (WhereSelectListIterator_2_t86EE6817E8A1706688C6D82D82C9D44BC99CC336* __this, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* ___0_predicate, const RuntimeMethod* method) 
{
	{
		Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B* L_0 = ___0_predicate;
		WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B* L_1 = (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*)il2cpp_codegen_object_new(il2cpp_rgctx_data(il2cpp_codegen_method_rgctx(method), 18));
		((  void (*) (WhereEnumerableIterator_1_t8B24528558F527941435C4FE1D046216FE4F277B*, RuntimeObject*, Func_2_t19E50C11C3E1F20B5A8FDB85D7DD353B6DFF868B*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19)))(L_1, (RuntimeObject*)__this, L_0, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 19));
		return (RuntimeObject*)L_1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* GltfImportBase_get_Logger_m8C1704494D33FF309078B56C4A2593E8D42EDFB7_inline (GltfImportBase_tB5A00DFF4A659A2C76E7BF7B91F29DF106A6B67F* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CLoggerU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CUVSetCountU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void VertexBufferTexCoordsBase_set_UVSetCount_m03DB0730A1A62DCAE3771CD47158C61E75A99D82_inline (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CUVSetCountU3Ek__BackingField = L_0;
		return;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_nativeArray, const RuntimeMethod* method) 
{
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_0 = ___0_nativeArray;
		void* L_1 = L_0.___m_Buffer;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(EmptyArray_1_t6C301AAECD8237FCD6328D15A5BC0071D53D11A1_StaticInit);
	{
		CHECKED_LOCAL_INIT(EmptyArray_1_t6C301AAECD8237FCD6328D15A5BC0071D53D11A1_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ((EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 0)))->___Value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, const RuntimeMethod* method) 
{
	{
		void* L_0 = __this->___m_Buffer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___hasValue;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeSliceUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m4D697E26467C391B48E97587F53534941CBEA23F_fshared_inline (NativeSlice_1_tA54E5D259EBCC7CD8512AA352C6F3709EB237B52 ___0_nativeSlice, const RuntimeMethod* method) 
{
	{
		NativeSlice_1_tA54E5D259EBCC7CD8512AA352C6F3709EB237B52 L_0 = ___0_nativeSlice;
		uint8_t* L_1 = L_0.___m_Buffer;
		return (void*)(L_1);
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___hasValue;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Func_2_Invoke_mDFD235952DAD602D1DFB25297EC22590CE99B6F5_gshared_inline (Func_2_t9411B5EEDC5B4099FE9226A3C6B92CA846F8991D* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Enumerator_get_Current_mA50CED82C4671CC4E1D82333FAC2587F700565D0_gshared_inline (Enumerator_tC367FBE981D257FF6A6357382526F6EC9FF3B2F9* __this, const RuntimeMethod* method) 
{
	{
		Il2CppSharedGenericObject* L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Il2CppSharedGenericObject* Func_2_Invoke_m0E8D5B2914DF50FFC02B2CFEF6FF956D55AC12DE_gshared_inline (Func_2_tBE6BE5A4E4F7FED7B1EE3446A907877305B72A87* __this, Il2CppSharedGenericObject* ___0_arg, const RuntimeMethod* method) 
{
	typedef Il2CppSharedGenericObject* (*FunctionPointerType) (RuntimeObject*, Il2CppSharedGenericObject*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_arg, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = ___0_value1;
		intptr_t L_1 = ___1_value2;
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
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
