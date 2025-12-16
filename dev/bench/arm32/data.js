window.BENCHMARK_DATA = {
  "lastUpdate": 1765912859404,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark (arm32)": [
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
          "id": "dba44d1255c900fe2444fdac2e28ce6d2efb1a32",
          "message": "Add arm support for CI",
          "timestamp": "2025-12-16T20:16:46+01:00",
          "tree_id": "dc2eb5fd7fb44c9c0aab0bcdf9eee4d2a8db44a4",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/dba44d1255c900fe2444fdac2e28ce6d2efb1a32"
        },
        "date": 1765912858494,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 1.90739,
            "range": "± 8.15384",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 1.90724,
            "range": "± 14.7351",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 4.53933,
            "range": "± 216.347",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 4.48987,
            "range": "± 211.266",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 1.06081,
            "range": "± 5.68809",
            "unit": "us",
            "extra": "100 samples\n264 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 763.158,
            "range": "± 4.14377",
            "unit": "ns",
            "extra": "100 samples\n368 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 349.109,
            "range": "± 3.14324",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 129.674,
            "range": "± 693.657",
            "unit": "us",
            "extra": "100 samples\n3 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 474.542,
            "range": "± 8.60735",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 337.362,
            "range": "± 7.89172",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 2.10239,
            "range": "± 34.985",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 2.11066,
            "range": "± 33.3778",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 338.844,
            "range": "± 4.51764",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 888.26,
            "range": "± 4.01958",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 249.16,
            "range": "± 1.93097",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 249.025,
            "range": "± 1.66763",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 261.884,
            "range": "± 1.90866",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 262.036,
            "range": "± 2.03921",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 1.91257,
            "range": "± 7.7388",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 1.91044,
            "range": "± 7.91902",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 1.89374,
            "range": "± 10.0741",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 1.64252,
            "range": "± 3.48441",
            "unit": "ms",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}