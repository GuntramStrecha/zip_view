window.BENCHMARK_DATA = {
  "lastUpdate": 1765734615482,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark (x86_64)": [
      {
        "commit": {
          "author": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "committer": {
            "email": "6010606+GuntramStrecha@users.noreply.github.com",
            "name": "Guntram Strecha",
            "username": "GuntramStrecha"
          },
          "distinct": true,
          "id": "6a7cbd2823f2645cab07fb49b5aea967d0e4fe80",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-14T18:46:01+01:00",
          "tree_id": "e316f8f3bb299fdcc64eedc68170806c99df0874",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/6a7cbd2823f2645cab07fb49b5aea967d0e4fe80"
        },
        "date": 1765734614689,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 124.562,
            "range": "± 21.8987",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 124.414,
            "range": "± 19.0146",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 498.853,
            "range": "± 55.0835",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 499.899,
            "range": "± 56.994",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 64.7455,
            "range": "± 2.34897",
            "unit": "ns",
            "extra": "100 samples\n275 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 71.3695,
            "range": "± 2.53521",
            "unit": "ns",
            "extra": "100 samples\n252 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 56.8669,
            "range": "± 1.26054",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 21.7208,
            "range": "± 1.11863",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 115.796,
            "range": "± 6.1275",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 65.6827,
            "range": "± 7.72963",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 133.184,
            "range": "± 17.1378",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 133,
            "range": "± 15.1197",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 204.772,
            "range": "± 30.6996",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 624.931,
            "range": "± 46.9918",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 53.5417,
            "range": "± 2.781",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 53.4811,
            "range": "± 2.71553",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 53.8638,
            "range": "± 3.51893",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 57.9251,
            "range": "± 2.97993",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 129.302,
            "range": "± 18.2877",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 129.984,
            "range": "± 20.8987",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 169.077,
            "range": "± 3.51755",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 113.28,
            "range": "± 3.69333",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}