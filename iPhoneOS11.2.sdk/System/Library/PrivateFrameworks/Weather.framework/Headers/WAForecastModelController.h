//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary, NSMutableSet, NSOperationQueue, NSString, WFServiceConnection, WFWeatherStoreService;
@protocol OS_dispatch_queue;

__attribute__((visibility("hidden")))
@interface WAForecastModelController : NSObject
{
    NSOperationQueue *_forecastOperationQueue;
    NSObject<OS_dispatch_queue> *_incomingRequestQueue;
    NSObject<OS_dispatch_queue> *_completionHandlerQueue;
    NSMutableSet *_updatingCities;
    NSMutableDictionary *_completionHandlersForCity;
    WFServiceConnection *_connection;
    struct ct_green_tea_logger_s _greenTeaLogger;
    NSString *_trackingParameter;
    WFWeatherStoreService *_store;
}

@property(readonly) WFWeatherStoreService *store; // @synthesize store=_store;
@property(copy) NSString *trackingParameter; // @synthesize trackingParameter=_trackingParameter;
@property(nonatomic) struct ct_green_tea_logger_s greenTeaLogger; // @synthesize greenTeaLogger=_greenTeaLogger;
@property(retain, nonatomic) WFServiceConnection *connection; // @synthesize connection=_connection;
@property(retain) NSMutableDictionary *completionHandlersForCity; // @synthesize completionHandlersForCity=_completionHandlersForCity;
@property(retain) NSMutableSet *updatingCities; // @synthesize updatingCities=_updatingCities;
@property(retain) NSObject<OS_dispatch_queue> *completionHandlerQueue; // @synthesize completionHandlerQueue=_completionHandlerQueue;
@property(retain) NSObject<OS_dispatch_queue> *incomingRequestQueue; // @synthesize incomingRequestQueue=_incomingRequestQueue;
@property(retain) NSOperationQueue *forecastOperationQueue; // @synthesize forecastOperationQueue=_forecastOperationQueue;
// - (void).cxx_destruct;
- (id)_commaSeparatedUpdatingCitiesNames;
- (void)_handleForecastOperationCompletion:(id)arg1;
- (void)cancelAllFetchRequests;
- (id)_queue_executeFetchForCity:(id)arg1 completion:(id /* CDUnknownBlockType */)arg2;
- (BOOL)fetchForecastForCities:(id)arg1 completion:(id /* CDUnknownBlockType */)arg2;
- (BOOL)fetchForecastForCity:(id)arg1 completion:(id /* CDUnknownBlockType */)arg2;
- (BOOL)isCityBeingUpdated:(id)arg1;
- (void)dealloc;
- (id)init;

@end

