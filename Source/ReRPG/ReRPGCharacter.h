// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "component.h"
#include "InventoryData.h"
#include "ResourceData.h"
#include "TransformComponent.h"
#include "TransformData.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "Animation/AnimInstance.h"
#include "ReRPGCharacter.generated.h"



class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;
class UProgressionComponent;
class UAttributesComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class AReRPGCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	// Your ECS runtime component
	TransformComponent LTransform;
	ResourceComponent LResources;
	
protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

	/** Charged Attack Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* AttackAction;
	
	/** Combo Attack Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* ComboAttackAction;

	/** Charged Attack Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* ChargedAttackAction;
	
	/** AnimMontage that will play for charged attacks */
	UPROPERTY(EditAnywhere, Category="Melee Attack|Normal")
	UAnimMontage* AttackMontage;
	
	/** AnimMontage that will play for combo attacks */
	UPROPERTY(EditAnywhere, Category="Melee Attack|Combo")
	UAnimMontage* ComboAttackMontage;

	/** AnimMontage that will play for charged attacks */
	UPROPERTY(EditAnywhere, Category="Melee Attack|Charged")
	UAnimMontage* ChargedAttackMontage;

	/** Name of the AnimMontage section that corresponds to the charge loop */
	UPROPERTY(EditAnywhere, Category="Melee Attack|Charged")
	FName ChargeLoopSection;

	/** Name of the AnimMontage section that corresponds to the attack */
	UPROPERTY(EditAnywhere, Category="Melee Attack|Charged")
	FName ChargeAttackSection;

	/** Attack montage ended delegate */
	FOnMontageEnded OnAttackMontageEnded;

	/** If true, the character is currently playing an attack animation */
	bool bIsAttacking = false;

	/** Time at which an attack button was last pressed */
	float CachedAttackInputTime = 0.0f;

	/** Flag that determines if the player is currently holding the charged attack input */
	bool bIsChargingAttack = false;
	
	/** If true, the charged attack hold check has been tested at least once */
	bool bHasLoopedChargedAttack = false;

	/** Index of the current stage of the melee attack combo */
	int32 ComboCount = 0;

	void Attack();
	
	void DoAttack();
	
	void AttackPressed();
	
	void DoComboAttackStart();

	void DoComboAttackEnd();
	
	void DoChargedAttackStart();

	void DoChargedAttackEnd();

	void ComboAttack();

	void ChargedAttack();
	
	void ComboAttackPressed();

	void ChargedAttackPressed();

	void ChargedAttackReleased();

	void CheckChargedAttack();

	//
	
	virtual void BeginPlay() override;

public:

	/** Constructor */
	AReRPGCharacter();
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ECS")
	// FCTransformDater InitialTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Resources")
	FResourceComponent InitialResources;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Inventory")
	UInventoryAuthoringComponent* InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UResources")
	UResourcesComponent* ResourcesComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Progression")
	UProgressionComponent* CurrentProgress;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Attributes")
	UAttributesComponent* AttributesComponent;

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

public:

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

public:

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

