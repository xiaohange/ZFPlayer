//
//  UIScrollView+ZFPlayer.h
//  ZFPlayer
//
// Copyright (c) 2016年 任子丰 ( http://github.com/renzifeng )
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

#import <UIKit/UIKit.h>
#import "ZFPlayerController.h"

NS_ASSUME_NONNULL_BEGIN

/*
 * The scroll derection of scrollView.
 */
typedef NS_ENUM(NSUInteger, ZFPlayerScrollDerection) {
    ZFPlayerScrollDerectionNone = 0,
    ZFPlayerScrollDerectionUp = 1,    // Scroll up
    ZFPlayerScrollDerectionDown = 2   // Scroll Down
};

@interface UIScrollView (ZFPlayer)

/// Rolling direction switch
@property (nonatomic) BOOL enableDirection;

/// The indexPath is playing
@property (nonatomic, strong, nullable) NSIndexPath *playingIndexPath;

/// The indexPath that should play, the one that lights up.
@property (nonatomic, strong, nullable) NSIndexPath *shouldPlayIndexPath;

/// WWANA networks play automatically,default NO.
@property (nonatomic, getter=isWWANAutoPlay) BOOL WWANAutoPlay;

/// The view tag that the player displays.
@property (nonatomic) NSInteger playerViewTag;

/// Is the video playing.
@property (nonatomic, readonly, getter=isPlaying) BOOL playing;

/// The scroll derection of scrollView.
@property (nonatomic) ZFPlayerScrollDerection scrollDerection;

/// Does the currently playing cell stop playing when the cell has slid off the screen，defalut is YES.
@property (nonatomic) BOOL stopWhileNotVisible;

/// The block invoked When the player will appear.
@property (nonatomic, copy, nullable) void(^playerWillAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did appeared half.
@property (nonatomic, copy, nullable) void(^playerAppearHalfInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did appeared.
@property (nonatomic, copy, nullable) void(^playerDidAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player will disappear.
@property (nonatomic, copy, nullable) void(^playerWillDisappearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did disappeared half.
@property (nonatomic, copy, nullable) void(^playerDisappearHalfInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did disappeared.
@property (nonatomic, copy, nullable) void(^playerDidDisappearInScrollView)(NSIndexPath *indexPath);

/// Filter the cell that should be played when the scroll is stopped (to play when the scroll is stopped)
- (void)zf_filterShouldPlayCellWhileScrolled:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Filter the cell that should be played while scrolling (you can use this to filter the highlighted cell)
- (void)zf_filterShouldPlayCellWhileScrolling:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Get the cell according to indexPath
- (UIView *)zf_getCellForIndexPath:(NSIndexPath *)indexPath;

/// Scroll to indexPath with animations.
- (void)zf_scrollToRowAtIndexPath:(NSIndexPath *)indexPath;

- (void)zf_scrollViewDidScroll;

@end

NS_ASSUME_NONNULL_END
