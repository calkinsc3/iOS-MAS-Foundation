//
//  MASObject.h
//  MASFoundation
//
//  Copyright (c) 2016 CA. All rights reserved.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

@import Foundation;

#import "MASConstants.h"


/**
 * The `MASObject` class is a local representation of data persisted to the MAS cloud.
 * This is the main class that is used to interact with objects in your app.
 */
@interface MASObject : NSObject <NSCopying, NSCoding>

///--------------------------------------
/// @name Lifecycle
///--------------------------------------

/**
 *  Init the object with passed attributes in a form of NSDictionary
 *
 *  @param attributes NSDictionary to be used as attributes
 *
 *  @return The instance of the MASObject object
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes;



///--------------------------------------
/// @name Instance Methods
///--------------------------------------

/**
 *  Creates a new MASObject with a class name
 *
 *  @param className A class name can be any alphanumeric string that begins with a letter.
 *                   It represents an object in your app, like a 'User' or a 'Document'.
 *
 *  @return Returns the MASObject that is instantiated with the given class name.
 */
+ (instancetype)objectWithClassName:(NSString *)className;



/**
 *  Creates a new MASObject with a class name and a dictionary as the data
 *
 *  @param className  A class name can be any alphanumeric string that begins with a letter.
 *                    It represents an object in your app, like a 'User' or a 'Document'.
 *  @param dictionary A disctionary that will be used as a data
 *
 *  @return Returns the MASObject that is instantiated with the given class name and dictionary.
 */
+ (instancetype)objectWithClassName:(NSString *)className
                           withData:(NSDictionary *)dictionary;



///--------------------------------------
/// @name Managing Object Properties
///--------------------------------------

/**
 *  The class name of the object.
 */
@property (nonatomic, readonly, copy) NSString *className;


/**
 *  The id of the object.
 */
@property (nonatomic, readonly, copy) NSString *objectId;


/**
 *  List of attributes of the object.
 */
@property (nonatomic, readonly, copy) NSMutableDictionary *_attributes;



///--------------------------------------
/// @name Accessors
///--------------------------------------


/**
 *  Returns the value associated with a given key.
 *
 *  @param key The given identifying key for which to return the corresponding value.
 *
 *  @return The value associated with a given key.
 */
- (id)objectForKey:(id)key;



/**
 *  Sets the object associated with a given key.
 *
 *  @param object The object for `key`. A strong reference to the object is maintaned by MASObject.
 *                Raises an `NSInvalidArgumentException` if `object` is `nil`.
 *                If you need to represent a `nil` value - use `NSNull`.
 *
 *  @param key    The key for `object`. Raises an `NSInvalidArgumentException` if `key` is `nil`.
 */
- (void)setObject:(id)object forKey:(id <NSCopying>)key;



/**
 *  Returns the value associated with a given key.
 *
 *  @discussion This method enables usage of literal syntax on `MASObject`. E.g. `NSString *value = object[@"key"];`
 *
 *  @param key The key for which to return the corresponding value.
 *
 *  @return The value associated with a given key.
 */
- (id)objectForKeyedSubscript:(id)key;



/**
 *  Returns the value associated with a given key.
 *
 *  @discussion This method enables usage of literal syntax on `MASObject`. E.g. `object[@"key"] = @"value";`
 *
 *  @param object The object for `key`. A strong reference to the object is maintaned by PFObject.
 *                Raises an `NSInvalidArgumentException` if `object` is `nil`.
 *                If you need to represent a `nil` value - use `NSNull`.
 *
 *  @param key    key The key for `object`. Raises an `NSInvalidArgumentException` if `key` is `nil`.
 */
- (void)setObject:(id)object forKeyedSubscript:(id <NSCopying>)key;


#pragma mark - Print Attributes

/**
 *  List all attributes from the Object
 */
- (void)listAttributes;


@end
