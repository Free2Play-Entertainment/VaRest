// Copyright 2014-2019 Vladimir Alyamkin. All Rights Reserved.

#pragma once

#include "VaRestPluginDefines.h"

#include "VaRestJsonValue.generated.h"

class UVaRestJsonObject;
class FJsonValue;

/**
 * Represents all the types a Json Value can be.
 */
UENUM(BlueprintType)
enum class EVaJson : uint8
{
	None,
	Null,
	String,
	Number,
	Boolean,
	Array,
	Object,
};

/**
 * Blueprintable FJsonValue wrapper
 */
UCLASS(BlueprintType, Blueprintable)
class VARESTPLUGIN_API UVaRestJsonValue : public UObject
{
	GENERATED_UCLASS_BODY()

	/** Create new Json Number value
	 * Attn.!! float used instead of double to make the function blueprintable! */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Json Number Value", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "VaRest|Json")
	static UVaRestJsonValue* ConstructJsonValueNumber(UObject* WorldContextObject, float Number);

	/** Create new Json String value */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Json String Value", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "VaRest|Json")
	static UVaRestJsonValue* ConstructJsonValueString(UObject* WorldContextObject, const FString& StringValue);

	/** Create new Json Bool value */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Json Bool Value", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "VaRest|Json")
	static UVaRestJsonValue* ConstructJsonValueBool(UObject* WorldContextObject, bool InValue);

	/** Create new Json Array value */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Json Array Value", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "VaRest|Json")
	static UVaRestJsonValue* ConstructJsonValueArray(UObject* WorldContextObject, const TArray<UVaRestJsonValue*>& InArray);

	/** Create new Json Object value */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Json Object Value", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "VaRest|Json")
	static UVaRestJsonValue* ConstructJsonValueObject(UObject* WorldContextObject, UVaRestJsonObject* JsonObject);

	/** Create new Json value from FJsonValue (to be used from VaRestJsonObject) */
	static UVaRestJsonValue* ConstructJsonValue(UObject* WorldContextObject, const TSharedPtr<FJsonValue>& InValue);

	/** Get the root Json value */
	TSharedPtr<FJsonValue>& GetRootValue();

	/** Set the root Json value */
	void SetRootValue(TSharedPtr<FJsonValue>& JsonValue);

	//////////////////////////////////////////////////////////////////////////
	// FJsonValue API

	/** Get type of Json value (Enum) */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	EVaJson GetType() const;

	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	EVaJson wGetType() const;

	/** Get type of Json value (String) */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	FString GetTypeString() const;

	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	FString wGetTypeString() const;

	/** Returns true if this value is a 'null' */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	bool IsNull() const;

	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	bool wIsNull() const;

	/** Returns this value as a double, throwing an error if this is not an Json Number
	 * Attn.!! float used instead of double to make the function blueprintable! */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	float AsNumber() const;
	
	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	float wAsNumber() const;

	/** Returns this value as a number, throwing an error if this is not an Json String */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	FString AsString() const;
	
	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	FString wAsString() const;

	/** Returns this value as a boolean, throwing an error if this is not an Json Bool */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	bool AsBool() const;
	
	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	bool wAsBool() const;

	/** Returns this value as an array, throwing an error if this is not an Json Array */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	TArray<UVaRestJsonValue*> AsArray() const;
	
	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	TArray<UVaRestJsonValue*> wAsArray() const;

	/** Returns this value as an object, throwing an error if this is not an Json Object */
	UFUNCTION(BlueprintPure, Category = "VaRest|Json")
	UVaRestJsonObject* AsObject();
	
	UFUNCTION(BlueprintCallable, Category = "VaRest|Json", meta=(DeprecatedFunction, DeprecationMessage="Callable getters will be removed soon. Please use pure getters instead."))
	UVaRestJsonObject* wAsObject();

	//////////////////////////////////////////////////////////////////////////
	// Data

private:
	/** Internal JSON data */
	TSharedPtr<FJsonValue> JsonVal;

	//////////////////////////////////////////////////////////////////////////
	// Helpers

protected:
	/** Simple error logger */
	void ErrorMessage(const FString& InType) const;
};
