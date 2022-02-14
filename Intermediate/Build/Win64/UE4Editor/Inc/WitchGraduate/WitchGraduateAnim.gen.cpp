// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WitchGraduate/Public/WitchGraduateAnim.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWitchGraduateAnim() {}
// Cross Module References
	WITCHGRADUATE_API UClass* Z_Construct_UClass_UWitchGraduateAnim_NoRegister();
	WITCHGRADUATE_API UClass* Z_Construct_UClass_UWitchGraduateAnim();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_WitchGraduate();
// End Cross Module References
	void UWitchGraduateAnim::StaticRegisterNativesUWitchGraduateAnim()
	{
	}
	UClass* Z_Construct_UClass_UWitchGraduateAnim_NoRegister()
	{
		return UWitchGraduateAnim::StaticClass();
	}
	struct Z_Construct_UClass_UWitchGraduateAnim_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWitchGraduateAnim_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_WitchGraduate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWitchGraduateAnim_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "WitchGraduateAnim.h" },
		{ "ModuleRelativePath", "Public/WitchGraduateAnim.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWitchGraduateAnim_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWitchGraduateAnim>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UWitchGraduateAnim_Statics::ClassParams = {
		&UWitchGraduateAnim::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UWitchGraduateAnim_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UWitchGraduateAnim_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWitchGraduateAnim()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UWitchGraduateAnim_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWitchGraduateAnim, 2825961213);
	template<> WITCHGRADUATE_API UClass* StaticClass<UWitchGraduateAnim>()
	{
		return UWitchGraduateAnim::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWitchGraduateAnim(Z_Construct_UClass_UWitchGraduateAnim, &UWitchGraduateAnim::StaticClass, TEXT("/Script/WitchGraduate"), TEXT("UWitchGraduateAnim"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWitchGraduateAnim);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
