/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2022 PeterBurgess
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 */


#include "event_dispatcher.h"
#include "event_subscriber.h"

#include <iostream>


class Event {};
class SomethingHappenedEvent {};
class StuffOccurredEvent {};


class MySubscriberClass : public event::EventSubscriber<Event, SomethingHappenedEvent, StuffOccurredEvent>
{

public:

    void handle_event(const Event& event) override {
        std::cout << "Handling event!" << std::endl;
    }

    void handle_event(const SomethingHappenedEvent& event) override {
        std::cout << "Handling something happened event!" << std::endl;
    }

    void handle_event(const StuffOccurredEvent& event) override {
        std::cout << "Handling stuff occurred event!" << std::endl;
    }
};


int main()
{
    using namespace event;

    EventDispatcher dispatcher;
    MySubscriberClass subscriber;
    Event event;
    SomethingHappenedEvent something_happened_event;
    StuffOccurredEvent stuff_occurred_event;

    dispatcher.subscribe(&subscriber);

    dispatcher.dispatch(event);
    dispatcher.dispatch(something_happened_event);
    dispatcher.dispatch(stuff_occurred_event);

    dispatcher.unsubscribe(&subscriber);

    dispatcher.dispatch(event);
    dispatcher.dispatch(something_happened_event);
    dispatcher.dispatch(stuff_occurred_event);

    return 0;
}
