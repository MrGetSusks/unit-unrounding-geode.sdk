#include <Geode/Geode.hpp>
#include <Geode/modify/CCTextInputNode.hpp>
#include <string>

using namespace geode::prelude;

class $modify(MyTextInputNode, CCTextInputNode) {
    // Intercept mobile keyboard text submission
    void setString(const char* text) {
        std::string strText(text);

        // Check if mobile text delegate tries to flatten a precise value to 0
        if (strText == "0" || strText == "0.0" || strText == "0.00") {
            std::string currentText = this->getString();
            
            // If there's already an active decimal string, block the mobile auto-format override
            if (currentText.find('.') != std::string::npos && currentText != "0" && currentText != "0.0") {
                return; 
            }
        }

        CCTextInputNode::setString(text);
    }

    // Capture individual mobile touch typing events
    void insertText(const char* text, size_t length) {
        // Prevent mobile text handlers from dropping small floats early during typing
        CCTextInputNode::insertText(text, length);
    }
};