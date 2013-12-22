// TTTStringInflector.h
//
// Copyright (c) 2013 Mattt Thompson (http://mattt.me)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/**
 
 */
@interface TTTStringInflector : NSObject

/**
 
 */
+ (instancetype)defaultInflector;

///=========================
/// @name Inflecting Strings
///=========================

/**
 Usage of autoupdatingCurrentLocale is by copy to avoid any issues midstream inside a method.
 */
	// Use autoupdatingCurrentLocale (change with the system.)
- (NSString *)singularize:(NSString *)string;
	// YES == use current locale. NO == use above method.
- (NSString *)singularize:(NSString *)string withCurrentLocale:(BOOL)useCurrentLocale;
	// Supply the locale, or nil, to use the autoupdatingCurrentLocale copy.
- (NSString *)singularize:(NSString *)string withLocale:(NSLocale *)locale;

/**
 
 */
	// Use autoupdatingCurrentLocale (change with the system.)
- (NSString *)pluralize:(NSString *)string;
	// YES == use current locale. NO == use above method.
- (NSString *)pluralize:(NSString *)string withCurrentLocale:(BOOL)useCurrentLocale;
	// Supply the locale, or nil, to use the autoupdatingCurrentLocale copy.
- (NSString *)pluralize:(NSString *)string withLocale:(NSLocale *)locale;
///===================
/// @name Adding Rules
///===================

/**
 
 */
- (void)addSingularRule:(NSString *)rule
        withReplacement:(NSString *)replacement;

- (void)addSingularRule:(NSString *)rule
        withReplacement:(NSString *)replacement
	  withCurrentLocale:(BOOL)useCurrentLocale;

- (void)addSingularRule:(NSString *)rule
        withReplacement:(NSString *)replacement forLocale:(NSLocale *)locale;

/**
 
 */
- (void)addPluralRule:(NSString *)rule
      withReplacement:(NSString *)replacement;

- (void)addPluralRule:(NSString *)rule
      withReplacement:(NSString *)replacement forLocale:(NSLocale *)locale;

/**
 
 */
- (void)addIrregularWithSingular:(NSString *)singular
                          plural:(NSString *)plural;

- (void)addIrregularWithSingular:(NSString *)singular
                          plural:(NSString *)plural forLocale:(NSLocale *)locale;

/**
 
 */
- (void)addUncountable:(NSString *)word;

- (void)addUncountable:(NSString *)word forLocale:(NSLocale *)locale;

@end
