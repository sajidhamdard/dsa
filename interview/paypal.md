# PayPal Interview Experience – Technical Round (3-4 Years Experience, 45 mins)

## Core Java & Data Structures
- Explain the internal working of `ConcurrentHashMap`. How does it achieve thread safety, and what are its performance trade-offs?
- Describe the differences between `WeakHashMap` and `HashMap`. When would you use each?
- Given a large dataset (millions of records), how would you efficiently search for duplicate transactions?
- How does the Java Memory Model impact multi-threaded applications?
- Design an in-memory key-value store that supports TTL (time to live) for entries.

## Multithreading & Concurrency
- How would you design a thread pool from scratch?
- Explain how Java handles false sharing in multi-core processors.
- What are the main drawbacks of using synchronized methods? How does `ReentrantLock` improve performance?
- Implement a multi-threaded rate limiter that handles API requests.
- How would you handle thread starvation in high-throughput applications?

## Spring Boot & Microservices
- How does Spring Boot’s auto-configuration determine which beans to load?
- What is Circuit Breaker, and how does it prevent cascading failures in microservices?
- How would you handle blue-green deployments in a Spring Boot microservices setup?
- Explain Eventual Consistency. How would you ensure data consistency across distributed services?
- Implement a rate-limited API in Spring Boot that handles 10,000 requests per second.

## APIs & RESTful Services
- How would you design an API Gateway to handle dynamic routing and security policies?
- Explain the challenges of handling pagination in REST APIs for massive datasets.
- How would you manage API timeouts and retries in a distributed system?
- What’s the best way to implement WebSockets in a fintech application?
- How would you enforce idempotency in payment APIs?

## System Design Basics
- Design a high-throughput, low-latency order-matching system for a stock exchange.
- How would you ensure data integrity in a multi-region database setup?
- Explain Leader Election. How would you implement it in a microservices-based system?
- What are the trade-offs between CQRS and traditional CRUD-based systems?
- How does a Distributed Message Queue (like Kafka) handle backpressure?

### **Tip:**
They look for scalability thinking, real-world problem-solving, and strong system design intuition. If you’re aiming for backend-heavy fintech roles, focus on concurrency, API optimizations, and microservices resilience patterns. And don’t forget system design!
