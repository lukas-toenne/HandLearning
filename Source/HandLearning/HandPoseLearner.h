// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HandPoseLearner.generated.h"

class FJsonObject;


UENUM(BlueprintType)
enum class EHandLearningJoint : uint8
{
	ThumbMetacarpal,
	ThumbProximal,
	ThumbDistal,
	ThumbTip,
	IndexMetacarpal,
	IndexProximal,
	IndexIntermediate,
	IndexDistal,
	IndexTip,
	MiddleMetacarpal,
	MiddleProximal,
	MiddleIntermediate,
	MiddleDistal,
	MiddleTip,
	RingMetacarpal,
	RingProximal,
	RingIntermediate,
	RingDistal,
	RingTip,
	PinkyMetacarpal,
	PinkyProximal,
	PinkyIntermediate,
	PinkyDistal,
	PinkyTip
};


USTRUCT(BlueprintType)
struct HANDLEARNING_API FHandLearningDataPoint
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector position;
};


USTRUCT(BlueprintType)
struct HANDLEARNING_API FHandLearningData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EHandLearningJoint, FHandLearningDataPoint> Points;
};


UCLASS()
class HANDLEARNING_API UHandLearningFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static bool LoadHandData(const FString &filename, FHandLearningData& data);
	UFUNCTION(BlueprintCallable)
	static bool SaveHandData(const FString& filename, const FHandLearningData& data);

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HANDLEARNING_API UHandPoseLearner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHandPoseLearner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
