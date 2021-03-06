
#ifndef __PLATFORM_IOS__WEBVIEWIMPL_H_
#define __PLATFORM_IOS__WEBVIEWIMPL_H_

#include "platform/CCPlatformConfig.h"
#include "view/CAWebView.h"
#include <iosfwd>
#include <string>
#include <map>
#include <stdlib.h>

NS_CC_BEGIN

class CC_DLL CAWebViewImpl: public CAObject
{
public:
    
	CAWebViewImpl(CAWebView *webView);

	virtual ~CAWebViewImpl();

    void setJavascriptInterfaceScheme(const std::string &scheme);

    void loadHTMLString(const std::string &string, const std::string &baseURL);

    void loadURL(const std::string &url);

    void loadFile(const std::string &fileName);

    void stopLoading();

    void reload();

    bool canGoBack();

    bool canGoForward();

    void goBack();

    void goForward();

    void evaluateJS(const std::string &js);

    void setScalesPageToFit(const bool scalesPageToFit);

	virtual void update(float dt);

    virtual void setVisible(bool visible);

	CAImageView* getWebViewImage();

    static bool shouldStartLoading(void* pWebViewWrapper, const std::string &url);
    static void didFinishLoading(void* pWebViewWrapper, const std::string &url);
	static void onLoadHtmlSource(void* pWebViewWrapper, const std::string &htmlSource);
    static void didFailLoading(void* pWebViewWrapper, const std::string &url);
    static void onJsCallback(void* pWebViewWrapper, const std::string &message);

private:
    
    void* m_pWebViewWrapper;
    
    CAWebView* m_pWebView;
};


NS_CC_END

#endif /* __PLATFORM_IOS__WEBVIEWIMPL_H_ */
