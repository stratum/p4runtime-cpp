// Copyright 2015 The TensorFlow Authors. All Rights Reserved.
// Copyright 2018-present Open Networking Foundation
// SPDX-License-Identifier: Apache-2.0

#ifndef GTL_MAP_UTIL_H_
#define GTL_MAP_UTIL_H_

namespace gtl {
// Inserts the given key and value into the given collection if and only if the
// given key did NOT already exist in the collection. If the key previously
// existed in the collection, the value is not changed. Returns true if the
// key-value pair was inserted; returns false if the key was already present.
template <class Collection>
bool InsertIfNotPresent(Collection* const collection,
                        const typename Collection::value_type& vt) {
  return collection->insert(vt).second;
}

// Same as above except the key and value are passed separately.
template <class Collection>
bool InsertIfNotPresent(
    Collection* const collection,
    const typename Collection::value_type::first_type& key,
    const typename Collection::value_type::second_type& value) {
  return InsertIfNotPresent(collection,
                            typename Collection::value_type(key, value));
}
}  // namespace gtl

#endif  // GTL_MAP_UTIL_H_
