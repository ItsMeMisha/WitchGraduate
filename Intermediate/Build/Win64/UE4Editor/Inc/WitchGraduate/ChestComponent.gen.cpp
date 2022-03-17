// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WitchGraduate/Public/ChestComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChestComponent() {}
// Cross Module References
	WITCHGRADUATE_API UClass* Z_Construct_UClass_UChestComponent_NoRegister();
	WITCHGRADUATE_API UClass* Z_Construct_UClass_UChestComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_WitchGraduate();
// End Cross Module References
	void UChestComponent::StaticRegisterNativesUChestComponent()
	{
	}
	UClass* Z_Construct_UClass_UChestComponent_NoRegister()
	{
		return UChestComponent::StaticClass();
	}
	struct Z_Construct_UClass_UChestComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UChestComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_WitchGraduate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UChestComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ChestComponent.h" },
		{ "ModuleRelativePath", "Public/ChestComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UChestComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UChestComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UChestComponent_Statics::ClassParams = {
		&UChestComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UChestComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UChestComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UChestComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UChestComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UChestComponent, 1377787008);
	template<> WITCHGRADUATE_API UClass* StaticClass<UChestComponent>()
	{
		return UChestComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UChestComponent(Z_Construct_UClass_UChestComponent, &UChestComponent::StaticClass, TEXT("/Script/WitchGraduate"), TEXT("UChestComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UChestComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
