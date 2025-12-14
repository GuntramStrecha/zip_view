window.BENCHMARK_DATA = {
  "lastUpdate": 1765733648088,
  "repoUrl": "https://github.com/GuntramStrecha/zip_view",
  "entries": {
    "C++ Benchmark": [
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
          "id": "969ea8b7bd7e0e580c4736916b9d53ae3039b511",
          "message": "Add arm support for CI tests",
          "timestamp": "2025-12-14T18:31:49+01:00",
          "tree_id": "8223c66ac225f763fbb007ced4396ae1fb667d24",
          "url": "https://github.com/GuntramStrecha/zip_view/commit/969ea8b7bd7e0e580c4736916b9d53ae3039b511"
        },
        "date": 1765733647700,
        "tool": "catch2",
        "benches": [
          {
            "name": "std zip accumulate",
            "value": 84.2109,
            "range": "± 13.3998",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip accumulate",
            "value": 83.2685,
            "range": "± 12.3192",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip transform",
            "value": 287.704,
            "range": "± 41.5963",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip transform",
            "value": 229.588,
            "range": "± 47.9048",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip + sort",
            "value": 68.7833,
            "range": "± 2.88118",
            "unit": "ns",
            "extra": "100 samples\n426 iterations"
          },
          {
            "name": "gst zip + sort",
            "value": 85.8323,
            "range": "± 3.79389",
            "unit": "ns",
            "extra": "100 samples\n339 iterations"
          },
          {
            "name": "std zip + find_if",
            "value": 47.3215,
            "range": "± 2.07311",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + find_if",
            "value": 17.631,
            "range": "± 2.92934",
            "unit": "us",
            "extra": "100 samples\n2 iterations"
          },
          {
            "name": "std zip + copy",
            "value": 109.811,
            "range": "± 4.47061",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip + copy",
            "value": 43.9315,
            "range": "± 5.06669",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip construct",
            "value": 79.3304,
            "range": "± 28.3225",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip construct",
            "value": 77.2129,
            "range": "± 18.6635",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip bidi iterate",
            "value": 146.152,
            "range": "± 11.0011",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip bidi iterate",
            "value": 388.701,
            "range": "± 17.8698",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip fwd iterate",
            "value": 44.7521,
            "range": "± 3.20048",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip fwd iterate",
            "value": 47.6186,
            "range": "± 3.31219",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip rev iterate",
            "value": 50.2261,
            "range": "± 1.95833",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip rev iterate",
            "value": 62.9736,
            "range": "± 2.45273",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate",
            "value": 84.6496,
            "range": "± 15.5069",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate",
            "value": 84.3743,
            "range": "± 18.4359",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "std zip iterate 4 ranges",
            "value": 173.172,
            "range": "± 3.63307",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          },
          {
            "name": "gst zip iterate 4 ranges",
            "value": 140.863,
            "range": "± 3.07625",
            "unit": "us",
            "extra": "100 samples\n1 iterations"
          }
        ]
      }
    ]
  }
}