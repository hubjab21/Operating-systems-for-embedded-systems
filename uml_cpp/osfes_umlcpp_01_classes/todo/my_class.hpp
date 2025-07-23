#pragma once

struct MyClass {
    int publicAttribute{};

    void setPrivateAttribute(int PrivateAttributeValue) {
        privateAttribute = PrivateAttributeValue;
    }

    int getPrivateAttribute() {
        return privateAttribute;
    }

    long multiply() {
        return publicAttribute * privateAttribute;
    }
    long multiply(long a) {
        return a * privateAttribute;
    }

  private:
    int privateAttribute{};
};