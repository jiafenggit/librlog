//
// Created by Giuseppe Persico on 12/04/2018.
//

#ifndef RLOG_MESSAGE_HPP
#define RLOG_MESSAGE_HPP

#include <string>
#include <sstream>

#include "key_value.hpp"

namespace remlog {
    namespace message {

        class stream {
        private:
            std::stringstream message_stream;
        public:
            stream() = default;
            std::string get() const noexcept;
            template<class T> std::ostream &operator<<(const remlog::message::key_value<T> &);
        };

        template<class T>
        std::ostream &remlog::message::stream::operator<<(const remlog::message::key_value<T> &kvp) {
            this->message_stream << kvp.get();
            return this->message_stream;
        }
    }
}

#endif //RLOG_MESSAGE_HPP
