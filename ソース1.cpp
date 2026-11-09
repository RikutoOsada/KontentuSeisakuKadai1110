#include <iostream>

// 文字列s1の中から文字列s2を探し、最初に見つかった位置へのポインタを返す関数
const char* str_match(const char* s1, const char* s2) {
    // 探す対象のs2が空文字列の場合は、s1の先頭を返す（標準のstrstrの仕様に準拠）
    if (*s2 == '\0') {
        return s1;
    }

    // s1の終端に達するまでループ
    for (const char* p1 = s1; *p1 != '\0'; ++p1) {
        const char* h = p1; // s1側の比較開始位置
        const char* n = s2; // s2側の比較開始位置

        // 文字が一致している間、双方のポインタを進める
        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }

        // s2の終端に達したということは、完全に一致する部分文字列が見つかったということ
        if (*n == '\0') {
            return p1; // 一致した先頭位置へのポインタを返す
        }
    }

    // 見つからなかった場合はnullptrを返す
    return nullptr;
}

// 動作確認用のメイン関数
int main() {
    const char* s1 = "abcabcdef";
    const char* s2 = "abcd";

    const char* result = str_match(s1, s2);

    if (result != nullptr) {
        std::cout << "見つかりました: " << result << std::endl;
        std::cout << "インデックス: " << (result - s1) << " (&s1[" << (result - s1) << "])" << std::endl;
    }
    else {
        std::cout << "見つかりませんでした (nullptr)" << std::endl;
    }

    return 0;

}
