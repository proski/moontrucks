# Moon Trucks

Simulation for a lunar Helium-3 space mining operation.

## Design features

* Every item is modeled as an object unless it's obviously unnecessary.
* There are no dependencies on external libraries.
* cmake is used for build.
* C++17 is used for the implementation.

## Implementation details

* An event queue is implemented as `std::multimap` indexed by simulated time.
* The simulated time used type `double`.
* When an event is processed, another event is added to the queue.
* The simulated time is updated to the time of the current event.
* Every event is associated with a truck. All trucks have an event associated
with them unless they are waiting in queue at an unload station.

## Limitations and possible improvements

* There is no fine grained logging.
* Events are written to the console unconditionally.
* The final statistics could be improved, but that is better done in
cooperation with the stakeholders.
* Unit tests are missing.
* The statistics collection is bolted on; it would be better to collect it
by tracking states of trucks and stations.
* Search for the shorted queue is O(m) whether m is the number of unload
stations. It should be possible to use a faster algorithm.
* The code could use `std::optional` in a some places.
* `Clock` doesn't need to be a class. Moreover, it should be possible to use
the `std::chrono` library for time conversion.

## Testing done

* Executed the program with a wide range of inputs and observed reasonable
behavior. As the number of trucks increases, they spend more time in queues and
deliver fewer loads.
* Executed the program under Valgrind to ensure there are no memory leaks and
accesses to uninitialized data.
