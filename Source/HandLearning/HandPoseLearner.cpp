// Fill out your copyright notice in the Description page of Project Settings.

#include "HandPoseLearner.h"
#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "Runtime/JsonUtilities/Public/JsonObjectWrapper.h"
#include "Serialization/JsonWriter.h"
#include "Misc/FileHelper.h"

void UHandLearningFunctionLibrary::GetHandDataFromDevice(FHandLearningData &LeftHandData, FHandLearningData &RightHandData, bool &bLeftHandIsTracking, bool &bRightHandIsTracking)
{


	bLeftHandIsTracking = false;
	bRightHandIsTracking = false;
}

bool UHandLearningFunctionLibrary::LoadHandData(const FString& filename, FHandLearningData& data)
{
	return false;
}

bool UHandLearningFunctionLibrary::SaveHandData(const FString& filename, const FHandLearningData& data)
{
	auto jsonObj = FJsonObjectConverter::UStructToJsonObject(data, 0, 0);

	if (FFileHelper::SaveStringToFile(TEXT("Hello"), *filename))
	{
		return true;
	}

	return false;
}

//TSharedPtr<FJsonObject> UHandLearningFunctionLibrary::HandDataToJSON(const FHandLearningData& data)
//{
//	const UEnum* JointEnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EHandLearningJoint"), true);
//
//	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject());
//
//	for (const auto& item : data.Points)
//	{
//		FString jointName = JointEnumPtr->GetNameStringByValue((int64)item.Key);
//		//jsonObj->SetObjectField(jointName, HandDataPointToJSON(item.Value));
//	}
//
//	return nullptr;
//}
//
//bool UHandLearningFunctionLibrary::HandDataFromJSON(const TSharedPtr<FJsonObject>& json, FHandLearningData& data)
//{
//	return false;
//}


// Sets default values for this component's properties
UHandPoseLearner::UHandPoseLearner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHandPoseLearner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHandPoseLearner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

