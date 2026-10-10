// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* SpeakerName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* DialogueText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* DialogueIcon;

	UPROPERTY(BlueprintReadWrite)
	float TypeDelay = 0.02f;

public:
	void SetSpeakerName(FName NewSpeakerName);

	void SetDialogueText(FText NewDialogueText);

	void SetDialogueIcon(UTexture2D* NewDialogueIcon);

	void StartTyping(FText NewDialogueText);

	void TypeNextChar();

	UFUNCTION(BlueprintCallable)
	void SkipTyping();

	UPROPERTY(BlueprintReadOnly)
	bool LineComplete = false;
	
private:
	FText FullText;

	FString FullTextString;
	
	int CurrentIndex;

	FTimerHandle TypingTimer;
};
