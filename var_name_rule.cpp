#ifndef CAPTURE_WORKER_HPP
#define CAPTURE_WORKER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>   // 스마트 포인터(unique_ptr)용
#include <mutex>    // 스레드 안전용

/**
 * @brief 이미지 캡처 및 전송 준비를 담당하는 클래스
 * 국룰: PascalCase 클래스명
 */
class CaptureWorker 
{
public:
    // 1. 열거형 국룰: enum class + PascalCase
    enum class WorkerStatus 
    {
        Idle,
        Capturing,
        Error
    };

    // 2. 상수 국룰: SCREAMING_SNAKE_CASE
    static constexpr int MAX_RETRY_COUNT = 3;
    static constexpr int DEFAULT_PORT = 8000;

    // 생성자 및 소멸자
    explicit CaptureWorker(int camera_id); // explicit: 암시적 변환 방지
    ~CaptureWorker();

    // 3. 함수(메서드) 국룰: camelCase (동사로 시작)
    void startCapture();
    void stopCapture();
    
    // const: 데이터 변경이 없음을 단호하게 명시 (성능 및 안정성)
    bool isRunning() const; 

    // 4. 인자(Parameter) 국룰: snake_case
    void setServerInfo(const std::string& server_ip, int port_number);

private:
    // 5. 멤버 변수 국룰: snake_case_ (끝에 언더바)
    int camera_id_;
    bool is_running_;
    std::string server_ip_;
    
    // 스마트 포인터: 직접적인 new/delete 대신 사용 (메모리 누수 방지)
    std::unique_ptr<std::mutex> mtx_ptr_;

    // 6. 불린 변수 질문형 접두어: is_, has_, can_
    bool has_valid_frame_;

    // 내부 도우미 함수 (Private)
    void processRawData(const std::vector<unsigned char>& raw_data);
};

#endif // CAPTURE_WORKER_HPP